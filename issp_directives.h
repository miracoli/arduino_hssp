// filename: ISSP_Directives.h
#include "ISSP_Revision.h"
#ifdef PROJECT_REV_230
// Copyright 2006-2010, Cypress Semiconductor Corporation.
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
//-----------------------------------------------------------------------------

// --------------------- Compiler Directives ----------------------------------
#ifndef INC_ISSP_DIRECTIVES
#define INC_ISSP_DIRECTIVES

// This directive will enable a Genral Purpose test-point on P1.7
// It can be toggled as needed to measure timing, execution, etc...
// A "Test Point" sets a GPIO pin of the host processor high or low. This GPIO
// pin can be observed with an oscilloscope to verify the timing of key
// programming steps. TPs have been added in main() that set Port 0, pin 1
// high during bulk erase, during each block write and during security write.
// The timing of these programming steps should be verified as correct as part
// of the validation process of the final program.
#define USE_TP


// ****************************************************************************
// ************* USER ATTENTION REQUIRED: TARGET SUPPLY VOLTAGE ***************
// ****************************************************************************
// This directive causes the proper Initialization vector #3 to be sent
// to the Target, based on what the Target Vdd programming voltage will
// be. Either 5V (if #define enabled) or 3.3V (if #define disabled).
#define TARGET_VOLTAGE_IS_5V


// ****************************************************************************
// **************** USER ATTENTION REQUIRED: PROGRAMMING MODE *****************
// ****************************************************************************
// This directive selects whether code that uses reset programming mode or code
// that uses power cycle programming is use. Reset programming mode uses the
// external reset pin (XRES) to enter programming mode. Power cycle programming
// mode uses the power-on reset to enter programming mode.
// Applying signals to various pins on the target device must be done in a 
// deliberate order when using power cycle mode. Otherwise, high signals to GPIO
// pins on the target will power the PSoC through the protection diodes.
#define RESET_MODE

// ****************************************************************************
// ****************** USER ATTENTION REQUIRED: TARGET PSOC ********************
// ****************************************************************************
// The directives below enable support for various PSoC devices. The root part
// number to be programmed should be un-commented so that its value becomes
// defined.
//By default, CY8C29466 device is selected in below list. 
//Comment this, and uncomment required Part number that needs to be programmed in your application.
//All other devices should be commented out.
// Select one device to be supported below:

// **** CY8CTST1x0 devices ****
//#define CY8CTST110_32LTXI
//#define CY8CTST110_00PVXI       //OCD part
//#define CY8CTST120_56LTXI
//#define CY8CTST120_00AXI        //OCD part

// **** CY8CTMG1x0 devices ****
//#define CY8CTMG110_32LTXI
//#define CY8CTMG110_00PVXI       //OCD part
//#define CY8CTMG120_56LTXI
//#define CY8CTMG120_00AXI        //OCD part

// **** CY8CTMA120 devices ****
//#define CY8CTMA120_56LTXI
//#define CY8CTMA120_100BVXI
//#define CY8CTMA120_00AXI        //OCD part

// **** CY8C21x23 devices ****
//#define CY8C21123
//#define CY8C21223
//#define CY8C21323
//#define CY8C21002

// **** CY8C21x34 devices ****
//#define CY8C21234
//#define CY8C21334
//#define CY8C21434
//#define CY8C21534
//#define CY8C21634
//#define CY8C21001

// **** CY8C21x45 devices ****
//#define CY8C21345

// **** CY8C22x45 devices ****
//#define CY8C22045         //OCD part
//#define CY8C22345
//#define CY8C22545

// **** CY8C23x33 devices ****
//#define CY8C23033         
//#define CY8C23433 
//#define CY8C23533 

// **** CY8C24x23A devices ****
//#define CY8C24123A
//#define CY8C24223A
//#define CY8C24423A
//#define CY8C24000A

// **** CY8C24x94 devices ****
//#define CY8C24794
//#define CY8C24894
//#define CY8C24994
//#define CY8C24094

// **** CY8C27x34 devices ****
//#define CY8C27143
//#define CY8C27243
//#define CY8C27443
//#define CY8C27543
//#define CY8C27643
//#define CY8C27002

// **** CY8C28xxx devices ****
//#define CY8C28000
//#define CY8C28445
//#define CY8C28545
//#define CY8C28645
//#define CY8C28x43
//#define CY8C28452
//#define CY8C28x13
//#define CY8C28x33
//#define CY8C28403
//#define CY8C28623

// **** CY8C29x66 devices ****
#define CY8C29466  /*Default device selected. Comment this, and uncomment required Part number that needs to be programmed in your application */
//#define CY8C29566
//#define CY8C29666
//#define CY8C29866
//#define CY8C29002

//-----------------------------------------------------------------------------
// This section sets the Family that has been selected. These are used to 
// simplify other conditional compilation blocks.
//-----------------------------------------------------------------------------

#ifdef CY8CTST110_32LTXI
    #define CY8CTST110
#endif
#ifdef CY8CTST110_00PVXI
    #define CY8CTST110
#endif
#ifdef CY8CTST120_56LTXI
    #define CY8CTST120
#endif
#ifdef CY8CTST120_00AXI
    #define CY8CTST120
#endif

#ifdef CY8CTMG110_32LTXI
    #define CY8CTMG110
#endif
#ifdef CY8CTMG110_00PVXI
    #define CY8CTMG110
#endif
#ifdef CY8CTMG120_56LTXI
    #define CY8CTMG120
#endif
#ifdef CY8CTMG120_00AXI
    #define CY8CTMG120
#endif

#ifdef CY8CTMA120_56LTXI
    #define CY8CTMA120
#endif
#ifdef CY8CTMA120_100BVXI
    #define CY8CTMA120
#endif
#ifdef CY8CTMA120_00AXI
    #define CY8CTMA120
#endif

#ifdef CY8C21123
    #define CY8C21x23
#endif
#ifdef CY8C21223
    #define CY8C21x23
#endif
#ifdef CY8C21323
    #define CY8C21x23
#endif
#ifdef CY8C21002
    #define CY8C21x23
#endif
#ifdef CY8C21234
    #define CY8C21x34
#endif
#ifdef CY8C21334
    #define CY8C21x34
#endif
#ifdef CY8C21434
    #define CY8C21x34
#endif
#ifdef CY8C21534
    #define CY8C21x34
#endif
#ifdef CY8C21634
    #define CY8C21x34
#endif
#ifdef CY8C21001
    #define CY8C21x34
#endif
#ifdef CY8C21345
    #define CY8C21x45
#endif
#ifdef CY8C22045
    #define CY8C22x45
#endif
#ifdef CY8C22345
    #define CY8C22x45
#endif
#ifdef CY8C22545
    #define CY8C22x45
#endif
#ifdef CY8C23033
    #define CY8C23x33
#endif
#ifdef CY8C23433
    #define CY8C23x33
#endif
#ifdef CY8C23533
    #define CY8C23x33
#endif
#ifdef CY8C24123A
    #define CY8C24x23A
#endif
#ifdef CY8C24223A
    #define CY8C24x23A
#endif
#ifdef CY8C24423A
    #define CY8C24x23A
#endif
#ifdef CY8C24000A
    #define CY8C24x23A
#endif
#ifdef CY8C24794
    #define CY8C24x94
#endif
#ifdef CY8C24894
    #define CY8C24x94
#endif
#ifdef CY8C24994
    #define CY8C24x94
#endif
#ifdef CY8C24094
    #define CY8C24x94
#endif
#ifdef CY8C27143
    #define CY8C27x43
#endif
#ifdef CY8C27243
    #define CY8C27x43
#endif
#ifdef CY8C27443
    #define CY8C27x43
#endif
#ifdef CY8C27543
    #define CY8C27x43
#endif
#ifdef CY8C27643
    #define CY8C27x43
#endif
#ifdef CY8C27002
    #define CY8C27x43
#endif
#ifdef CY8C28000
	#define CY8C28xxx
#endif
#ifdef CY8C28445
	#define CY8C28xxx
#endif
#ifdef CY8C28545
	#define CY8C28xxx
#endif
#ifdef CY8C28645
	#define CY8C28xxx
#endif
#ifdef CY8C28x43
	#define CY8C28xxx
#endif
#ifdef CY8C28452
	#define CY8C28xxx
#endif
#ifdef CY8C28x13
	#define CY8C28xxx
#endif
#ifdef CY8C28x33
	#define CY8C28xxx
#endif
#ifdef CY8C28403
	#define CY8C28xxx
#endif
#ifdef CY8C28623
	#define CY8C28xxx
#endif
#ifdef CY8C29466
    #define CY8C29x66
#endif
#ifdef CY8C29566
    #define CY8C29x66
#endif
#ifdef CY8C29666
    #define CY8C29x66
#endif
#ifdef CY8C29866
    #define CY8C29x66
#endif
#ifdef CY8C29002
    #define CY8C29x66
#endif
//-----------------------------------------------------------------------------
// The directives below are used to define various sets of vectors that differ
// for more than one set of PSoC parts.
//-----------------------------------------------------------------------------
// **** Select a Checksum Setup Vector ****

//CY8CTST110, 
#ifdef CY8CTST110
    #define CHECKSUM_SETUP_21_23_27_TST110_TMG110
#endif

//CY8CTST120, 
#ifdef CY8CTST120
    #define CHECKSUM_SETUP_22_24_28_29_TST120_TMG120_TMA120
#endif

//CY8CTMG110, 
#ifdef CY8CTMG110
    #define CHECKSUM_SETUP_21_23_27_TST110_TMG110
#endif

//CY8CTMG120, 
#ifdef CY8CTMG120
    #define CHECKSUM_SETUP_22_24_28_29_TST120_TMG120_TMA120
#endif

//CY8CTMA120, 
#ifdef CY8CTMA120
    #define CHECKSUM_SETUP_22_24_28_29_TST120_TMG120_TMA120
#endif

#ifdef CY8C21x23
    #define CHECKSUM_SETUP_21_23_27_TST110_TMG110
#endif
#ifdef CY8C21x34
    #define CHECKSUM_SETUP_21_23_27_TST110_TMG110
#endif
#ifdef CY8C21x45
    #define CHECKSUM_SETUP_22_24_28_29_TST120_TMG120_TMA120
#endif
#ifdef CY8C22x45
    #define CHECKSUM_SETUP_22_24_28_29_TST120_TMG120_TMA120
#endif
#ifdef CY8C23x33
    #define CHECKSUM_SETUP_21_23_27_TST110_TMG110
#endif
#ifdef CY8C24x23A
    #define CHECKSUM_SETUP_24_24A
#endif
#ifdef CY8C24x94
    #define CHECKSUM_SETUP_22_24_28_29_TST120_TMG120_TMA120
#endif
#ifdef CY8C27x43
    #define CHECKSUM_SETUP_21_23_27_TST110_TMG110
#endif
#ifdef CY8C28xxx
    #define CHECKSUM_SETUP_22_24_28_29_TST120_TMG120_TMA120
#endif
#ifdef CY8C29x66
    #define CHECKSUM_SETUP_22_24_28_29_TST120_TMG120_TMA120
#endif

// **** Select a Program Block Vector ****
//CY8CTST110, 
#ifdef CY8CTST110
    #define PROGRAM_BLOCK_21_22_23_24_28_29_TST_TMG_TMA
#endif

//CY8CTST120, 
#ifdef CY8CTST120
    #define PROGRAM_BLOCK_21_22_23_24_28_29_TST_TMG_TMA
#endif

//CY8CTMG110, 
#ifdef CY8CTMG110
    #define PROGRAM_BLOCK_21_22_23_24_28_29_TST_TMG_TMA
#endif

//CY8CTMG120, 
#ifdef CY8CTMG120
    #define PROGRAM_BLOCK_21_22_23_24_28_29_TST_TMG_TMA
#endif

//CY8CTMA120, 
#ifdef CY8CTMA120
    #define PROGRAM_BLOCK_21_22_23_24_28_29_TST_TMG_TMA
#endif

#ifdef CY8C21x23
    #define PROGRAM_BLOCK_21_22_23_24_28_29_TST_TMG_TMA
#endif
#ifdef CY8C21x34
    #define PROGRAM_BLOCK_21_22_23_24_28_29_TST_TMG_TMA
#endif
#ifdef CY8C21x45
    #define PROGRAM_BLOCK_21_22_23_24_28_29_TST_TMG_TMA
#endif
#ifdef CY8C22x45
    #define PROGRAM_BLOCK_21_22_23_24_28_29_TST_TMG_TMA
#endif
#ifdef CY8C23x33
    #define PROGRAM_BLOCK_21_22_23_24_28_29_TST_TMG_TMA
#endif
#ifdef CY8C24x23A
    #define PROGRAM_BLOCK_21_22_23_24_28_29_TST_TMG_TMA
#endif
#ifdef CY8C24x94
    #define PROGRAM_BLOCK_21_22_23_24_28_29_TST_TMG_TMA
#endif
#ifdef CY8C27x43
    #define PROGRAM_BLOCK_27
#endif
#ifdef CY8C28xxx
    #define PROGRAM_BLOCK_21_22_23_24_28_29_TST_TMG_TMA
#endif
#ifdef CY8C29x66
    #define PROGRAM_BLOCK_21_22_23_24_28_29_TST_TMG_TMA
#endif

//-----------------------------------------------------------------------------
// The directives below are used to control switching banks if the device is
// has multiple banks of Flash.
//-----------------------------------------------------------------------------
// **** Select multi bank if applicable ****
//CY8CTST120, 
#ifdef CY8CTST120
    #define MULTI_BANK
#endif

//CY8CTMG120, 
#ifdef CY8CTMG120
    #define MULTI_BANK
#endif

//CY8CTMA120, 
#ifdef CY8CTMA120
    #define MULTI_BANK
#endif
#ifdef CY8C22x45
    #define MULTI_BANK
#endif
#ifdef CY8C24x94
    #define MULTI_BANK
#endif
#ifdef CY8C28xxx
    #define MULTI_BANK
#endif
#ifdef CY8C29x66
    #define MULTI_BANK
#endif

// ----------------------------------------------------------------------------
#endif  //(INC_ISSP_DIRECTIVES)
#endif  //(PROJECT_REV_)
//end of file ISSP_Directives.h
