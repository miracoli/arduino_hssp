// filename: ISSP_Routines.c
#include "issp_revision.h"
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
//--------------------------------------------------------------------------

#include <m8c.h>        // part specific constants and macros
#include "PSoCAPI.h"    // PSoC API definitions for all User Modules
#include "issp_defs.h"
#include "issp_vectors.h"
#include "issp_extern.h"
#include "issp_errors.h"
#include "issp_directives.h"
#include "issp_delays.h"

unsigned char  bTargetDataIN;
unsigned char  abTargetDataOUT[TARGET_DATABUFF_LEN];

unsigned char  bTargetAddress;
unsigned char  bTargetDataPtr = 0;
unsigned char  bTargetID[2];

unsigned char  fIsError;

/* ((((((((((((((((((((( LOW-LEVEL ISSP SUBROUTINE SECTION ))))))))))))))))))))
   (( The subroutines in this section use functions from the C file          ))
   (( ISSP_Drive_Routines.c. The functions in that file interface to the     ))
   (( processor specific hardware. So, these functions should work as is, if ))
   (( the routines in ISSP_Drive_Routines.c are correctly converted.         ))
   (((((((((((((((((((((((((((((((((((())))))))))))))))))))))))))))))))))))))))*/

// ============================================================================
// RunClock()
// Description: 
// Run Clock without sending/receiving bits. Use this when transitioning from 
// write to read and read to write "num_cycles" is number of SCLK cycles, not
// number of counter cycles.
//
// SCLK cannot run faster than the specified maximum frequency of 8MHz. Some 
// processors may need to have delays added after setting SCLK low and setting
// SCLK high in order to not exceed this specification. The maximum frequency 
// of SCLK should be measured as part of validation of the final program
//
// ============================================================================
void RunClock(unsigned int iNumCycles)
{
    int i;

    for(i=0; i < iNumCycles; i++) {
        SCLKLow();
        SCLKHigh();
    }
    // function exits with CLK high.
}

// ============================================================================
// bReceiveBit()
// Clocks the SCLK pin (high-low-high) and reads the status of the SDATA pin
// after the rising edge.
//
// SCLK cannot run faster than the specified maximum frequency of 8MHz. Some 
// processors may need to have delays added after setting SCLK low and setting
// SCLK high in order to not exceed this specification. The maximum frequency 
// of SCLK should be measured as part of validation of the final program
//
// Returns:
//     0 if SDATA was low
//     1 if SDATA was high
// ============================================================================
unsigned char bReceiveBit(void)
{
    SCLKLow();
    SCLKHigh();
    if (fSDATACheck()) {
        return(1);
    }
    else {
        return(0);
    }
}          

// ============================================================================
// bReceiveByte()
// Calls ReceiveBit 8 times to receive one byte.
// Returns:
//     The 8-bit values recieved.
// ============================================================================
unsigned char bReceiveByte(void)
{
    unsigned char b;
    unsigned char bCurrByte = 0x00;

    for (b=0; b<8; b++) {
        bCurrByte = (bCurrByte<<1) + bReceiveBit();
    }
    return(bCurrByte);
}          


// ============================================================================
// SendByte()
// This routine sends up to one byte of a vector, one bit at a time.
//    bCurrByte   the byte that contains the bits to be sent.
//    bSize       the number of bits to be sent. Valid values are 1 to 8.
//
// SCLK cannot run faster than the specified maximum frequency of 8MHz. Some 
// processors may need to have delays added after setting SCLK low and setting
// SCLK high in order to not exceed this specification. The maximum frequency 
// of SCLK should be measured as part of validation of the final program
//
// There is no returned value.
// ============================================================================
void SendByte(unsigned char bCurrByte, unsigned char bSize)
{
    unsigned char b = 0;

    for(b=0; b<bSize; b++) {
        if (bCurrByte & 0x80) {
            // Send a '1'
            SetSDATAHigh();
            SCLKHigh();
            SCLKLow();
        }
        else {
            // Send a '0'
            SetSDATALow();
            SCLKHigh();
            SCLKLow();
        }
        bCurrByte = bCurrByte << 1;
    }
}

// ============================================================================
// SendVector()
// This routine sends the vector specifed. All vectors constant strings found
// in ISSP_Vectors.h.  The data line is returned to HiZ after the vector is
// sent.
//    bVect      a pointer to the vector to be sent.
//    nNumBits   the number of bits to be sent.
//    bCurrByte  scratch var to keep the byte to be sent.
//
// There is no returned value.
// ============================================================================
void SendVector(const unsigned char* bVect, unsigned int iNumBits)
{
    SetSDATAStrong();
    while(iNumBits > 0)
    {
        if (iNumBits >= 8) {
            SendByte(*(bVect), 8);
            iNumBits -= 8;
            bVect++;
        }
        else {
            SendByte(*(bVect), iNumBits);
            iNumBits = 0;
        }
    }
    SetSDATAHiZ();
}


// ============================================================================
// fDetectHiLoTransition()
// Waits for transition from SDATA = 1 to SDATA = 0.  Has a 100 msec timeout.
// TRANSITION_TIMEOUT is a loop counter for a 100msec timeout when waiting for
// a high-to-low transition. This is used in the polling loop of 
// fDetectHiLoTransition(). The timing of the while(1) loops can be calculated
// and the number of loops is counted, using iTimer, to determine when 100 
// msec has passed.
//
// SCLK cannot run faster than the specified maximum frequency of 8MHz. Some 
// processors may need to have delays added after setting SCLK low and setting
// SCLK high in order to not exceed this specification. The maximum frequency 
// of SCLK should be measured as part of validation of the final program
//
// Returns:
//     0 if successful
//    -1 if timed out.
// ============================================================================
signed char fDetectHiLoTransition(void)
{
    // nTimer breaks out of the while loops if the wait in the two loops totals
    // more than 100 msec.  Making this static makes the loop run a faster.
    // This is really a processor/compiler dependency and it not needed.
    static unsigned int iTimer;
    
    // NOTE:
    // These loops look unconventional, but it is necessary to check SDATA_PIN
    // as shown because the transition can be missed otherwise, due to the
    // length of the SDATA Low-High-Low after certain commands.

    // Generate clocks for the target to pull SDATA High
    iTimer = TRANSITION_TIMEOUT;
    while(1) {
        SCLKLow();
        if (fSDATACheck())       // exit once SDATA goes HI
            break;
        SCLKHigh();
        // If the wait is too long then timeout
        if (iTimer-- == 0) {
			return (ERROR);
        }
    }

	
	// Generate Clocks and wait for Target to pull SDATA Low again
    iTimer = TRANSITION_TIMEOUT;              // reset the timeout counter
    while(1) {
        SCLKLow();
        if (!fSDATACheck()) {   // exit once SDATA returns LOW 
            break;
        }
        SCLKHigh();
        // If the wait is too long then timeout
        if (iTimer-- == 0) {
            return (ERROR);
        }
    }
    return (PASS);
}


/* ((((((((((((((((((((( HIGH-LEVEL ISSP ROUTINE SECTION ))))))))))))))))))))))
   (( These functions are mostly made of calls to the low level routines     ))
   (( above.  This should isolate the processor-specific changes so that     ))
   (( these routines do not need to be modified.                             ))
   (((((((((((((((((((((((((((((((((((())))))))))))))))))))))))))))))))))))))))*/

#ifdef RESET_MODE
// ============================================================================
// fXRESInitializeTargetForISSP()
// Implements the intialization vectors for the device.
// Returns:
//     0 if successful
//     INIT_ERROR if timed out on handshake to the device.
// ============================================================================
signed char fXRESInitializeTargetForISSP(void)
{
    // Configure the pins for initialization
    SetSDATAHiZ();
    SetSCLKStrong();
    SCLKLow();
    SetXRESStrong();
  
    // Cycle reset and put the device in programming mode when it exits reset
    AssertXRES();
    Delay(XRES_CLK_DELAY);
    DeassertXRES();

    // !!! NOTE: 
    //  The timing spec that requires that the first Init-Vector happen within
    //  1 msec after the reset/power up. For this reason, it is not advisable
    //  to separate the above RESET_MODE or POWER_CYCLE_MODE code from the 
    //  Init-Vector instructions below. Doing so could introduce excess delay
    //  and cause the target device to exit ISSP Mode.

    // Send Initialization Vectors and detect Hi-Lo transition on SDATA
    SendVector(init1_v, num_bits_init1); 
    if (fIsError = fDetectHiLoTransition()) {
        return(INIT_ERROR);
    }
    SendVector(wait_and_poll_end, num_bits_wait_and_poll_end);

    // Send Initialize 2 Vector
    SendVector(init2_v, num_bits_init2);
    if (fIsError = fDetectHiLoTransition()) {
        return(INIT_ERROR);
    }
    SendVector(wait_and_poll_end, num_bits_wait_and_poll_end);      
     
    // Send Initialize 3 Vector NOTE: the proper vector based on Vdd of target
#ifdef TARGET_VOLTAGE_IS_5V
    SendVector(init3_5v, num_bits_init3_5v);          // Target Vdd = 5v
#else
    SendVector(init3_3v, num_bits_init3_3v);          // Target Vdd = 3.3v
#endif

    SendVector(wait_and_poll_end, num_bits_wait_and_poll_end);

    // NOTE: DO NOT not wait for HiLo on SDATA after vector Init-3
    //       it does not occur (per spec).
    return(PASS);
}

#else  //else = the part is power cycle programmed

// ============================================================================
// fPowerCycleInitializeTargetForISSP()
// Implements the intialization vectors for the device.
// The first time fDetectHiLoTransition is called the Clk pin is highZ because
// the clock is not needed during acquire. 
// Returns:
//     0 if successful
//     INIT_ERROR if timed out on handshake to the device.
// ============================================================================
signed char fPowerCycleInitializeTargetForISSP(void)
{
    unsigned char n;

    // Set all pins to highZ to avoid back powering the PSoC through the GPIO
    // protection diodes.
    SetSCLKHiZ();   
    SetSDATAHiZ();
      
    // Turn on power to the target device before other signals
    SetTargetVDDStrong();
    ApplyTargetVDD();
    // wait 1msec for the power to stabilize

    for (n=0; n<10; n++) {
        Delay(DELAY100us);
    }

    // Set SCLK to high Z so there is no clock and wait for a high to low
    // transition on SDAT. SCLK is not needed this time.
    SetSCLKHiZ();
    if (fIsError = fDetectHiLoTransition()) {
        return(INIT_ERROR);
    }    

    // Configure the pins for initialization
    SetSDATAHiZ();
    SetSCLKStrong();
    SCLKLow();

    // !!! NOTE: 
    //  The timing spec that requires that the first Init-Vector happen within
    //  1 msec after the reset/power up. For this reason, it is not advisable
    //  to separate the above RESET_MODE or POWER_CYCLE_MODE code from the 
    //  Init-Vector instructions below. Doing so could introduce excess delay
    //  and cause the target device to exit ISSP Mode.

    // Send Initialization Vectors and detect Hi-Lo transition on SDATA
    SendVector(init1_v, num_bits_init1); 
    if (fIsError = fDetectHiLoTransition()) {
        return(INIT_ERROR);
    }
    SendVector(wait_and_poll_end, num_bits_wait_and_poll_end);

    // Send Initialize 2 Vector
    SendVector(init2_v, num_bits_init2);
    if (fIsError = fDetectHiLoTransition()) {
        return(INIT_ERROR);
    }
    SendVector(wait_and_poll_end, num_bits_wait_and_poll_end);
     
    // Send Initialize 3 Vector NOTE: the proper vector based on Vdd of target
    #ifdef TARGET_VOLTAGE_IS_5V
    SendVector(init3_5v, num_bits_init3_5v);          // Target Vdd = 5v
    #else
    SendVector(init3_3v, num_bits_init3_3v);          // Target Vdd = 3.3v
    #endif

    SendVector(wait_and_poll_end, num_bits_wait_and_poll_end);

    // NOTE: DO NOT not wait for HiLo on SDATA after vector Init-3
    //       it does not occur (per spec).
    return(PASS);
}
#endif


// ============================================================================
// fVerifySiliconID()
// Returns:
//     0 if successful
//     Si_ID if timed out on handshake to the device.
// ============================================================================
signed char fVerifySiliconID(void)
{
    // Send ID-Setup vector set
    SendVector(id_setup_v, num_bits_id_setup);
    if (fIsError = fDetectHiLoTransition()) {
        return(SiID_ERROR);
    }
    SendVector(wait_and_poll_end, num_bits_wait_and_poll_end);     

    //Send Read ID vector and get Target ID
    SendVector(read_id_v, 11);      // Read-MSB Vector is the first 11-Bits
    RunClock(2);                    // Two SCLK cycles between write & read
    bTargetID[0] = bReceiveByte();
    RunClock(1);
    SendVector(read_id_v+2, 12);    // 12 bits starting from the 3rd character

    RunClock(2);                    // Read-LSB Command
    bTargetID[1] = bReceiveByte();

    RunClock(1);
    SendVector(read_id_v+4, 1);     // 1 bit starting from the 5th character

    if (bTargetID[0] != target_id_v[0] || bTargetID[1] != target_id_v[1]) {
        return(SiID_ERROR);
    }
    else {
        return(PASS);
    }
}


// ============================================================================
// fEraseTarget()
// Perform a bulk erase of the target device.
// Returns:
//     0 if successful
//     ERASE_ERROR if timed out on handshake to the device.
// ============================================================================
signed char fEraseTarget(void)
{
    SendVector(erase_all_v, num_bits_erase_all);
    if (fIsError = fDetectHiLoTransition()) {
        return(ERASE_ERROR);
    }
    SendVector(wait_and_poll_end, num_bits_wait_and_poll_end);
    return(PASS);
}


// ============================================================================
// LoadTarget()
// Transfers data from array in Host to RAM buffer in the target.
// Returns the checksum of the data.
// ============================================================================
unsigned int iLoadTarget(void)
{
unsigned char bTemp;
unsigned int  iChecksumData = 0;

    // Set SDATA to Strong Drive here because SendByte() does not
    SetSDATAStrong();

    // Transfer the temporary RAM array into the target.
    // In this section, a 64-Byte array was specified by #define, so the entire
    // 64-Bytes are written in this loop.
    bTargetAddress = 0x00;
    bTargetDataPtr = 0x00;
          
    while(bTargetDataPtr < TARGET_DATABUFF_LEN) {     
        bTemp = abTargetDataOUT[bTargetDataPtr];
        iChecksumData += bTemp;

        SendByte(write_byte_start,5);     
        SendByte(bTargetAddress, 6);
        SendByte(bTemp, 8);
        SendByte(write_byte_end, 3);
               
        // !!!NOTE:
        // SendByte() uses MSbits, so inc by '4' to put the 0..63 address into
        // the six MSBit locations.
        //
        // This can be confusing, but check the logic:
        //   The address is only 6-Bits long. The SendByte() subroutine will
        // send however-many bits, BUT...always reads them bits from left-to-
        // right. So in order to pass a value of 0..63 as the address using
        // SendByte(), we have to left justify the address by 2-Bits.
        //   This can be done easily by incrementing the address each time by
        // '4' rather than by '1'.

        bTargetAddress += 4;
        bTargetDataPtr++;
    }
    return(iChecksumData);
}


#ifdef MULTI_BANK
// ============================================================================
// SetBankNumber()
// Set the bank number in the target device.
// Returns:
//     none
// ============================================================================
void SetBankNumber(unsigned char bBankNumber)
{
    // Send the bank-select vector.
    SendVector(set_bank_number, 33);

    // Set the drive here because SendByte() does not.
    SetSDATAStrong();
    SendByte(bBankNumber,8);
    SendVector(set_bank_number_end, 25);
}
#endif


// ============================================================================
// fProgramTargetBlock()
// Program one block with data that has been loaded into a RAM buffer in the 
// target device.
// Returns:
//     0 if successful
//     BLOCK_ERROR if timed out on handshake to the device.
// ============================================================================
signed char fProgramTargetBlock(unsigned char bBankNumber, unsigned char bBlockNumber)
{
    // Send the block-select vector.
    SendVector(set_block_number, 11);

    // Set the drive here because SendByte() does not.
    SetSDATAStrong();
    SendByte(bBlockNumber,8);
    SendByte(set_block_number_end, 3);

    // Send the program-block vector.
    SendVector(program_block, num_bits_program_block);
    // wait for acknowledge from target.
    if (fIsError = fDetectHiLoTransition()) {
        return(BLOCK_ERROR);
    }
    // Send the Wait-For-Poll-End vector
    SendVector(wait_and_poll_end, num_bits_wait_and_poll_end);
    return(PASS);
}


// ============================================================================
// fAddTargetBankChecksum()
// Reads and adds the target bank checksum to the referenced accumulator.
// Returns:
//     0 if successful
//     VERIFY_ERROR if timed out on handshake to the device.
// ============================================================================
signed char fAccTargetBankChecksum(unsigned int* pAcc)
{
    SendVector(checksum_v, num_bits_checksum); 
    if (fIsError = fDetectHiLoTransition()) {
        return(VERIFY_ERROR);
    }

    SendVector(wait_and_poll_end, num_bits_wait_and_poll_end);     

    //Send Read Checksum vector and get Target Checksum
    SendVector(read_checksum_v, 11);     // first 11-bits is ReadCKSum-MSB
    RunClock(2);                         // Two SCLKs between write & read
    *pAcc += (int)bReceiveByte() << 8;
    RunClock(1);                         // See Fig. 6
    SendVector(read_checksum_v + 2, 12); // 12 bits starting from 3rd character
    RunClock(2);                         // Read-LSB Command
    *pAcc += bReceiveByte();
    RunClock(1);
    SendVector(read_checksum_v + 3, 1);  // Send the final bit of the command
    return(PASS);    
}    


// ============================================================================
// ReStartTarget()
// After programming, the target PSoC must be reset to take it out of 
// programming mode. This routine performs a reset.
// ============================================================================
void ReStartTarget(void)
{
#ifdef RESET_MODE
    // Assert XRES, then release, then disable XRES-Enable
    AssertXRES();
    Delay(XRES_CLK_DELAY);
    DeassertXRES();
#else
    // Set all pins to highZ to avoid back powering the PSoC through the GPIO
    // protection diodes.
    SetSCLKHiZ();   
    SetSDATAHiZ();
    // Cycle power on the target to cause a reset
    RemoveTargetVDD();
    Delay(POWER_CYCLE_DELAY);
    ApplyTargetVDD();
#endif
}


// ============================================================================
// fVerifyTargetBlock()
// Verify the block just written to. This can be done byte-by-byte before the
// protection bits are set.
// Returns:
//     0 if successful
//     BLOCK_ERROR if timed out on handshake to the device.
// ============================================================================
signed char fVerifyTargetBlock(unsigned char bBankNumber, unsigned char bBlockNumber)
{
    SendVector(set_block_number, 11);

    // Set the drive here because SendByte() does not
    SetSDATAStrong();
    SendByte(bBlockNumber,8);
    SendByte(set_block_number_end, 3);
     
    SendVector(verify_setup_v, num_bits_verify_setup);
    if (fIsError = fDetectHiLoTransition()) {
        return(BLOCK_ERROR);
    }
    SendVector(wait_and_poll_end, num_bits_wait_and_poll_end);     

    bTargetAddress = 0;
    bTargetDataPtr = 0;
     
    while(bTargetDataPtr < TARGET_DATABUFF_LEN) {
        //Send Read Byte vector and then get a byte from Target
        SendVector(read_byte_v, 5);
        // Set the drive here because SendByte() does not
        SetSDATAStrong();
        SendByte(bTargetAddress,6);

        RunClock(2);       // Run two SCLK cycles between writing and reading
        SetSDATAHiZ();     // Set to HiZ so Target can drive SDATA
        bTargetDataIN = bReceiveByte();

        RunClock(1);
        SendVector(read_byte_v + 1, 1);     // Send the ReadByte Vector End

        // Test the Byte that was read from the Target against the original
        // value (already in the 64-Byte array "abTargetDataOUT[]"). If it
        // matches, then bump the address & pointer,loop-back and continue.
        // If it does NOT match abort the loop and return and error.	
        if (bTargetDataIN != abTargetDataOUT[bTargetDataPtr])
            return(BLOCK_ERROR);

        bTargetDataPtr++;
        // Increment the address by four to accomodate 6-Bit addressing
        // (puts the 6-bit address into MSBit locations for "SendByte()").
        bTargetAddress += 4;
    }
    return(PASS);
}


// ============================================================================
// fSecureTargetFlash()
// Before calling, load the array, abTargetDataOUT, with the desired security
// settings using LoadArrayWithSecurityData(StartAddress,Length,SecurityType).
// The can be called multiple times with different SecurityTypes as needed for
// particular Flash Blocks. Or set them all the same using the call below:
// LoadArrayWithSecurityData(0,SECURITY_BYTES_PER_BANK, 0); 
// Returns:
//     0 if successful
//     SECURITY_ERROR if timed out on handshake to the device.
// ============================================================================
signed char fSecureTargetFlash(void)
{
unsigned char bTemp;

    // Transfer the temporary RAM array into the target
    bTargetAddress = 0x00;
    bTargetDataPtr = 0x00;
    SetSDATAStrong();
    while(bTargetDataPtr < SECURITY_BYTES_PER_BANK) {     
        bTemp = abTargetDataOUT[bTargetDataPtr];
        SendByte(write_byte_start,5);     
        SendByte(bTargetAddress, 6);
        SendByte(bTemp, 8);
        SendByte(write_byte_end, 3);
           
        // SendBytes() uses MSBits, so increment the address by '4' to put
        // the 0..n address into the six MSBit locations
        bTargetAddress += 4;
        bTargetDataPtr++;
    }

    SendVector(security_v, num_bits_security);
    if (fIsError = fDetectHiLoTransition()) {
        return(SECURITY_ERROR);
    }
    SendVector(wait_and_poll_end, num_bits_wait_and_poll_end);
    return(PASS);
}

#endif  //(PROJECT_REV_)
// end of file ISSP_Routines.c

