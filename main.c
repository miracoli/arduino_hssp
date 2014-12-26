// filename: main.c
#include "ISSP_Revision.h"
#ifdef PROJECT_REV_230
/* Copyright 2006-2010, Cypress Semiconductor Corporation.
//
// This software is owned by Cypress Semiconductor Corporation (Cypress)
// and is protected by and subject to worldwide patent protection (United
// States and foreign), United States copyright laws and international 
// treaty provisions. Cypress hereby grants to licensee a personal, 
// non-exclusive, non-transferable license to copy, use, modify, create 
// derivative works of, and compile the Cypress Source Code and derivative 
// works for the sole purpose of creating custom software in support of 
// licensee product to be used only in conjunction with a Cypress integrated 
// circuit as specified in the applicable agreement. Any reproduction, 
// modification, translation, compilation, or representation of this 
// software except as specified above is prohibited without the express 
// written permission of Cypress.
//
// Disclaimer: CYPRESS MAKES NO WARRANTY OF ANY KIND,EXPRESS OR IMPLIED, 
// WITH REGARD TO THIS MATERIAL, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
// Cypress reserves the right to make changes without further notice to the
// materials described herein. Cypress does not assume any liability arising
// out of the application or use of any product or circuit described herein.
// Cypress does not authorize its products for use as critical components in
// life-support systems where a malfunction or failure may reasonably be
// expected to result in significant injury to the user. The inclusion of
// Cypress product in a life-support systems application implies that the
// manufacturer assumes all risk of such use and in doing so indemnifies
// Cypress against all charges.
//
// Use may be limited by and subject to the applicable Cypress software
// license agreement.
//
//---------------------------------------------------------------------------*/

/* ############################################################################
   ###################  CRITICAL PROJECT CONSTRAINTS   ########################
   ############################################################################ 

   ISSP programming can only occur within a temperature range of 5C to 50C.
   - This project is written without temperature compensation and using
     programming pulse-widths that match those used by programmers such as the
     Mini-Prog and the ISSP Programmer.
     This means that the die temperature of the PSoC device cannot be outside
     of the above temperature range.
     If a wider temperature range is required, contact your Cypress Semi-
     conductor FAE or sales person for assistance.

   The project can be configured to program devices at 5V or at 3.3V.
   - Initialization of the device is different for different voltages. The 
     initialization is hardcoded and can only be set for one voltage range.
     The supported voltages ranges are 3.3V (3.0V to 3.6V) and 5V (4.75V to
     5.25V). See the device datasheet for more details. If varying voltage
     ranges must be supported, contact your Cypress Semiconductor FAE or sales
     person for assistance.
   - ISSP programming for the 2.7V range (2.7V to 3.0V) is not supported.

   This program does not support programming all PSoC Devices 
   - It does not support obsoleted PSoC devices. A list of devices that are
     not supported is shown here:
         CY8C22x13 - not supported
         CY8C24x23 - not supported (CY8C24x23A is supported)
         CY8C24x33 - not supported
         CY8C25x43 - not supported
         CY8C26x43 - not supported
		 
   - Note: There is another application note (AN59389) that supports HSSP programming
     for CY8C20xx6, CY8CTMG2xx, CY8CTST2xx.
	 
   - It does not suport devices that have not been released for sale at the 
     time this version was created. If you need to ISSP program a newly released
     device, please contact Cypress Semiconductor Applications, your FAE or 
     sales person for assistance.
     The CY8C20x23 devices are not supported at the time of this release.

   ############################################################################ 
   ##########################################################################*/

     
/* This program uses information found in Cypress Semiconductor application 
// notes "Programming - In-System Serial Programming Protocol", AN2026.  The 
// version of this application note that applies to the specific PSoC that is
// being In-System Serial Programmed should be read and and understood when 
// using this program. (http://www.cypress.com)

// This project is included with releases of PSoC Programmer software. It is 
// important to confirm that the latest revision of this software is used when
// it is used. The revision of this copy can be found in the Project History 
// table below.
*/

/*/////////////////////////////////////////////////////////////////////////////
//  PROJECT HISTORY
//  date      revision  author  description
//  --------  --------  ------  -----------------------------------------------
//
//  12/06/10  ?2.30?     vvsk   1. Added support for CY8C21x45, CY8C22x45, CY8C23x33 
//
//                              2. Changed Revision to REV230
// 
//  xx/xx/10  ?2.20?     xch    1. Added support for CY8C20x34, CY8CTST110, CY8CTST120, 
//                              CY8CTMG110, CY8CTMG120, CY8CTMA120, 
//
//                              2. Aligned the order of parameters for LoadProgramData 
//                                 per CDT45137 
//
//                              3. Changed timing equation since CPU is now at 12MHz
//                                 instead of 24MHz.  Equation is now 2x+7 was 1x+3
//
//                              4. Changed Revision to REV220
//
//	02/09/09  2.12       fkl    1. Added vectors and constant defs for CY8C28xxx.
//
//								2. Changed constant definitions in files
//								issp_directives.h, issp_vectors.h and issp_defs.h.
//
//								3. Changed version number to REV212
//
//  09/23/07  2.11       dkn    1. Added searchable comments for the HSSP app note.
//
//                              2. Added new device vectors.
//
//                              3. Verified write and erase pulsewidths.
//
//                              4. Modified some functions for easier porting to
//                              other processors.
//
//  09/23/06  2.10       mwl    1. Added #define SECURITY_BYTES_PER_BANK to
//                              file issp_defs.h. Modified function
//                              fSecureTargetFlashMain() in issp_routines.c
//                              to use new #define. Modified function
//                              fLoadSecurityData() in issp_driver_routines.c
//                              to accept a bank number.  Modified the secure
//                              data loop in main.c to program multiple banks.
//
//                              2. Created function fAccTargetBankChecksum to
//                              read and add the target bank checksum to the
//                              referenced accumulator.  This allows the
//                              checksum loop in main.c to function at the
//                              same level of abstraction as the other
//                              programming steps.  Accordingly, modified the 
//                              checksum loop in main.c.  Deleted previous
//                              function fVerifyTargetChecksum().
//
//  09/08/06  2.00       mwl    1. Array variable abTargetDataOUT was not
//                              getting intialized anywhere and compiled as a
//                              one-byte array. Modified issp_driver_routines.c
//                              line 44 to initialize with TARGET_DATABUFF_LEN.
//
//                              2. Function void LoadProgramData(unsigned char
//                              bBlockNum) in issp_driver_routines.c had only
//                              one parameter bBlockNum but was being called
//                              from function main() with two parameters,
//                              LoadProgramData(bBankCounter, (unsigned char)
//                              iBlockCounter).  Modified function 
//                              LoadProgramData() to accept both parameters,
//                              and in turn modified InitTargetTestData() to 
//                              accept and use both as well.
//
//                              3. Corrected byte set_bank_number[1]
//                              inissp_vectors.h.  Was 0xF2, correct value is
//                              0xE2.
//
//                              4. Corrected the logic to send the SET_BANK_NUM
//                              vectors per the AN2026B flow chart.The previous
//                              code version was sending once per block, but
//                              should have been once per bank.  Removed the
//                              conditionally-compiled bank setting code blocks
//                              from the top of fProgramTargetBlock() and
//                              fVerifyTargetBlock() int issp_routines.c and
//                              created a conditionally-compiled subroutine in
//                              that same file called SetBankNumber().  Two
//                              conditionally-compiled calls to SetBankNumber()
//                              were added to main.c().
//
//                              5. Corrected CY8C29x66 NUM_BANKS and
//                              BLOCKS_PER_BANK definitions in ISSP_Defs.h.
//                              Was 2 and 256 respectively, correct values are
//                              4 and 128.
//
//                              6. Modified function fVerifyTargetChecksum()
//                              in issp_routines.c to read and accumulate multiple
//                              banks of checksums as required for targets
//                              CY8C24x94 and CY8C29x66.  Would have kept same
//                              level of abstraction as other multi-bank functions
//                              in main.c, but this implementation impacted the
//                              code the least.
//
//                              7. Corrected byte checksum_v[26] of
//                              CHECKSUM_SETUP_24_29 in issp_vectors.h.  Was 0x02,
//                              correct value is  0x04.
//
//  06/30/06  1.10       jvy    Added support for 24x94 and 29x66 devices.
//  06/09/06  1.00       jvy    Changed CPU Clk to 12MHz (from 24MHz) so the 
//                              host can run from 3.3V.
//                              Simplified init of security data.
//  06/05/06  0.06       jvy    Version #ifdef added to each file to make sure
//                              all of the file are from the same revision.
//                              Added flags to prevent multiple includes of H
//                              files.
//                              Changed pre-determined data for demo to be 
//                              unique for each block.
//                              Changed block verify to check all blocks after
//                              block programming has been completed.
//                              Added SetSCLKHiZ to explicitly set the Clk to 
//                              HighZ before power cycle acquire.
//                              Fixed wrong vectors in setting Security.
//                              Fixed wrong vectors in Block program.
//                              Added support for pods
//  06/05/06  0.05       jvy    Comments from code review. First copy checked
//                              into perforce.  Code has been updated enough to
//                              compile, by implementing some comments and
//                              fixing others.
//  06/04/06  0.04       jvy    made code more efficient in bReceiveByte(), and
//                              SendVector() by re-arranging so that local vars
//                              could be eliminated.
//                              added defines for the delays used in the code.
//  06/02/06  0.03       jvy    added number of Flash block adjustment to 
//                              programming. added power cycle programming
//                              mode support. This is the version initially 
//                              sent out for peer review.
//  06/02/06  0.02       jvy    added framework for multiple chip support from 
//                              one source code set using compiler directives.
//                              added timeout to high-low trasition detection.
//                              added multiple error message to allow tracking
//                              of failures.
//  05/30/06  0.01       jvy    initial version,
//                              created from DBD's issp_27xxx_v3 program.
/////////////////////////////////////////////////////////////////////////////*/

/* (((((((((((((((((((((((((((((((((((((())))))))))))))))))))))))))))))))))))))
 PSoC In-System Serial Programming (ISSP) Template
 This PSoC Project is designed to be used as a template for designs that
 require PSoC ISSP Functions.
 
 This project is based on the AN2026 series of Application Notes. That app
 note should be referenced before any modifications to this project are made.
 
 The subroutines and files were created in such a way as to allow easy cut & 
 paste as needed. There are no customer-specific functions in this project. 
 This demo of the code utilizes a PSoC as the Host.
 
 Some of the subroutines could be merged, or otherwise reduced, but they have
 been written as independently as possible so that the specific steps involved
 within each function can easily be seen. By merging things, some code-space 
 savings could be realized. 
 
 As is, and with all features enabled, the project consumes approximately 3500
 bytes of code space, and 19-Bytes of RAM (not including stack usage). The
 Block-Verify requires a 64-Byte buffer for read-back verification. This same
 buffer could be used to hold the (actual) incoming program data.
 
 Please refer to the compiler-directives file "directives.h" to see the various
 features.
 
 The pin used in this project are assigned as shown below. The HOST pins are 
 arbitrary and any 3 pins could be used (the masks used to control the pins 
 must be changed). The TARGET pins cannot be changed, these are fixed function
 pins on the PSoC. 
 The PWR pin is used to provide power to the target device if power cycle
 programming mode is used. The compiler directive RESET_MODE in ISSP_directives.h
 is used to select the programming mode. This pin could control the enable on
 a voltage regulator, or could control the gate of a FET that is used to turn
 the power to the PSoC on.
 The TP pin is a Test Point pin that can be used signal from the host processor
 that the program has completed certain tasks. Predefined test points are
 included that can be used to observe the timing for bulk erasing, block 
 programming and security programming.
 
      SIGNAL  HOST  TARGET
      ---------------------
      SDATA   P1.0   P1.0
      SCLK    P1.1   P1.1
      XRES    P2.0   XRES
      PWR     P2.1   Vdd 
      TP      P0.7   n/a
 
 For test & demonstration, this project generates the program data internally. 
 It does not take-in the data from an external source such as I2C, UART, SPI,
 etc. However, the program was written in such a way to be portable into such
 designs. The spirit of this project was to keep it stripped to the minimum 
 functions required to do the ISSP functions only, thereby making a portable 
 framework for integration with other projects.

 The high-level functions have been written in C in order to be portable to
 other processors. The low-level functions that are processor dependent, such 
 as toggling pins and implementing specific delays, are all found in the file
 ISSP_Drive_Routines.c. These functions must be converted to equivalent
 functions for the HOST processor.  Care must be taken to meet the timing 
 requirements when converting to a new processor. ISSP timing information can
 be found in Application Note AN2026.  All of the sections of this program
 that need to be modified for the host processor have "PROCESSOR_SPECIFIC" in
 the comments. By performing a "Find in files" using "PROCESSOR_SPECIFIC" these
 sections can easily be identified.

 The variables in this project use Hungarian notation. Hungarian prepends a
 lower case letter to each variable that identifies the variable type. The
 prefixes used in this program are defined below:
  b = byte length variable, signed char and unsigned char
  i = 2-byte length variable, signed int and unsigned int
  f = byte length variable used as a flag (TRUE = 0, FALSE != 0)
  ab = an array of byte length variables


 After this program has been ported to the desired host processor the timing
 of the signals must be confirmed.  The maximum SCLK frequency must be checked
 as well as the timing of the bulk erase, block write and security write
 pulses.
 
 The maximum SCLK frequency for the target device can be found in the device 
 datasheet under AC Programming Specifications with a Symbol of "Fsclk".
 An oscilloscope should be used to make sure that no half-cycles (the high 
 time or the low time) are shorter than the half-period of the maximum
 freqency. In other words, if the maximum SCLK frequency is 8MHz, there can be
 no high or low pulses shorter than 1/(2*8MHz), or 62.5 nsec.

 The test point (TP) functions, enabled by the define USE_TP, provide an output
 from the host processor that brackets the timing of the internal bulk erase,
 block write and security write programming pulses. An oscilloscope, along with
 break points in the PSoC ICE Debugger should be used to verify the timing of 
 the programming.  The Application Note, "Host-Sourced Serial Programming"
 explains how to do these measurements and should be consulted for the expected
 timing of the erase and program pulses.

/* ############################################################################
   ############################################################################ 

(((((((((((((((((((((((((((((((((((((()))))))))))))))))))))))))))))))))))))) */



/*----------------------------------------------------------------------------
//                               C main line
//----------------------------------------------------------------------------
*/

#include <m8c.h>        // part specific constants and macros
#include "PSoCAPI.h"    // PSoC API definitions for all User Modules


// ------ Declarations Associated with ISSP Files & Routines -------
//     Add these to your project as needed.
#include "ISSP_extern.h"
#include "ISSP_directives.h"
#include "ISSP_defs.h"
#include "ISSP_errors.h"
/* ------------------------------------------------------------------------- */

unsigned char bBankCounter;
unsigned int  iBlockCounter;
unsigned int  iChecksumData;
unsigned int  iChecksumTarget;


/* ========================================================================= */
// ErrorTrap()
// Return is not valid from main for PSOC, so this ErrorTrap routine is used.
// For some systems returning an error code will work best. For those, the 
// calls to ErrorTrap() should be replaced with a return(bErrorNumber). For
// other systems another method of reporting an error could be added to this
// function -- such as reporting over a communcations port.
/* ========================================================================= */
void ErrorTrap(unsigned char bErrorNumber)
{
#ifndef RESET_MODE
    // Set all pins to highZ to avoid back powering the PSoC through the GPIO
    // protection diodes.
    SetSCLKHiZ();   
    SetSDATAHiZ();
    // If Power Cycle programming, turn off the target
    RemoveTargetVDD();
#endif
     while (1);
     // return(bErrorNumbers);
}

/* ========================================================================= */
/* MAIN LOOP                                                                 */
/* Based on the diagram in the AN2026                                        */
/* ========================================================================= */

void main(void)
{
    // -- This example section of commands show the high-level calls to -------
    // -- perform Target Initialization, SilcionID Test, Bulk-Erase, Target ---
    // -- RAM Load, FLASH-Block Program, and Target Checksum Verification. ----

    #ifdef USE_TP
    InitTP();
    #endif
    
    // >>>> ISSP Programming Starts Here <<<<
    
    // Acquire the device through reset or power cycle
    #ifdef RESET_MODE
    // Initialize the Host & Target for ISSP operations
    if (fIsError = fXRESInitializeTargetForISSP()) {		
        ErrorTrap(fIsError);
    }
    #else
    // Initialize the Host & Target for ISSP operations
    if (fIsError = fPowerCycleInitializeTargetForISSP()) {		
        ErrorTrap(fIsError);
    }
    #endif

    // Run the SiliconID Verification, and proceed according to result.
    if (fIsError = fVerifySiliconID()) { 
        ErrorTrap(fIsError);
    }
	
    // Bulk-Erase the Device.
    #ifdef USE_TP
    SetTPHigh();    // Only used of Test Points are enabled  
    #endif
    if (fIsError = fEraseTarget()) {
        ErrorTrap(fIsError);
    }
    #ifdef USE_TP
    SetTPLow();    // Only used of Test Points are enabled
    #endif
	
    // Program Flash blocks with predetermined data. In the final application
    // this data should come from the HEX output of PSoC Designer.
    iChecksumData = 0;     // Calculte the device checksum as you go
    for (bBankCounter=0; bBankCounter<NUM_BANKS; bBankCounter++)
    {
        #ifdef MULTI_BANK
        // Set the bank number
        SetBankNumber(bBankCounter);
        #endif        
        for (iBlockCounter=0; iBlockCounter<BLOCKS_PER_BANK; iBlockCounter++) {
            LoadProgramData((unsigned char)iBlockCounter, bBankCounter);
            iChecksumData += iLoadTarget();
            #ifdef USE_TP
            SetTPHigh();    // Only used of Test Points are enabled 
            #endif
            if (fIsError = fProgramTargetBlock(bBankCounter,(unsigned char)iBlockCounter)) {
                ErrorTrap(fIsError);				
            }
        #ifdef USE_TP
        SetTPLow();    // Only used of Test Points are enabled  
        #endif
        }
    }
	
    // Verify the data block-by-block after programming all of the blocks and
    // before setting security.
    for (bBankCounter=0; bBankCounter<NUM_BANKS; bBankCounter++)
    {
        #ifdef MULTI_BANK
        // Set the bank number
        SetBankNumber(bBankCounter);
        #endif        
        for (iBlockCounter=0; iBlockCounter<BLOCKS_PER_BANK; iBlockCounter++) {
            LoadProgramData((unsigned char)iBlockCounter, bBankCounter);
            if (fIsError = fVerifyTargetBlock(bBankCounter,(unsigned char)iBlockCounter)) {
                ErrorTrap(fIsError);
            }
        }
    }

    // Program security data into target PSoC. In the final application this 
    // data should come from the HEX output of PSoC Designer.
    for (bBankCounter=0; bBankCounter<NUM_BANKS; bBankCounter++)
    {
        #ifdef MULTI_BANK
        // Set the bank number
        SetBankNumber(bBankCounter);
        #endif        

        // Load one bank of security data from hex file into buffer
        if (fIsError = fLoadSecurityData(bBankCounter)) {
            ErrorTrap(fIsError);
        }
        // Secure one bank of the target flash
        if (fIsError = fSecureTargetFlash()) {
            ErrorTrap(fIsError);
        }
    }
	
    // Run the Target-Checksum Verification, and proceed according to result.
    // Checksum only valid if every Flash block is programed
    #ifdef USE_TP
    SetTPHigh();    // Only used of Test Points are enabled
    #endif
    iChecksumTarget = 0;
    for (bBankCounter=0; bBankCounter<NUM_BANKS; bBankCounter++)
    {
        #ifdef MULTI_BANK
        // Set the bank number
        SetBankNumber(bBankCounter);
        #endif        
        if (fIsError = fAccTargetBankChecksum(&iChecksumTarget)) {
            ErrorTrap(fIsError);
        }
    }    
    if (iChecksumTarget != iChecksumData)
        ErrorTrap(VERIFY_ERROR);
    #ifdef USE_TP
    SetTPLow();    // Only used of Test Points are enabled 
    #endif

    
    // *** SUCCESS *** 
    // At this point, the Target has been successfully Initialize, ID-Checked,
    // Bulk-Erased, Block-Loaded, Block-Programmed, Block-Verified, and Device-
    // Checksum Verified.

    // You may want to restart Your Target PSoC Here.
    ReStartTarget();
 
    while(1) {
        // Continue with other functions or return to the calling routine		
    }
} 
// end of main()

#endif  //(PROJECT_REV_)
// end of file main.c
