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
#ifndef INC_ISSP_EXTERN
#define INC_ISSP_EXTERN

#include "Arduino.h"

extern signed char fXRESInitializeTargetForISSP(void);
extern signed char fPowerCycleInitializeTargetForISSP(void);
extern signed char fEraseTarget(void);
extern unsigned int iLoadTarget(void);
extern void ReStartTarget(void);
extern signed char fVerifySiliconID(void);
extern signed char fAccTargetBankChecksum(unsigned int*);
extern void SetBankNumber(unsigned char);
extern signed char fProgramTargetBlock(unsigned char, unsigned char);
extern signed char fVerifyTargetBlock(unsigned char, unsigned char);
extern signed char fSecureTargetFlash(void);

extern void InitTargetTestData(void);
extern void LoadArrayWithSecurityData(unsigned char, unsigned char, unsigned char);

extern void LoadProgramData(unsigned char, unsigned char);
extern signed char fLoadSecurityData(unsigned char);
extern unsigned char fSDATACheck(void);
extern void SCLKHigh(void);
extern void SCLKLow(void);
extern void SetSCLKHiZ(void);
extern void SetSCLKStrong(void);
extern void SetSDATAHigh(void);
extern void SetSDATALow(void);
extern void SetSDATAHiZ(void);
extern void SetSDATAStrong(void);
extern void AssertXRES(void);
extern void DeassertXRES(void);
extern void SetXRESStrong(void);
extern void ApplyTargetVDD(void);
extern void RemoveTargetVDD(void);
extern void SetTargetVDDStrong(void);

extern unsigned char   fIsError;

// This enumeration causes the proper Initialization vector #3 to be sent
// to the Target, based on what the Target Vdd programming voltage will
// be. Either 5V or 3.3V.
enum target_voltage {
  TARGET_VOLTAGE_5V,
  TARGET_VOLTAGE_3_3V,
} extern targ_voltage;

// This enumeration selects whether code that uses reset programming mode or code
// that uses power cycle programming is use. Reset programming mode uses the
// external reset pin (XRES) to enter programming mode. Power cycle programming
// mode uses the power-on reset to enter programming mode.
// Applying signals to various pins on the target device must be done in a 
// deliberate order when using power cycle mode. Otherwise, high signals to GPIO
// pins on the target will power the PSoC through the protection diodes.
enum programming_mode {
    RESET_MODE,
    POWER_CYCLE_MODE,
} extern prog_mode;

// The boolean below is used to control switching banks if the device
// has multiple banks of Flash.
extern bool multi_bank;

// The enumerations below are used to define various sets of vectors that differ
// for more than one set of PSoC parts.
enum checksum_setup {
  CHECKSUM_SETUP_21_23_27_TST110_TMG110, // CY8C21x23, CY8C21x34, CY8C23x33, CY8C27x43, TST110 & TMG110 Checksum Setup Vectors
  CHECKSUM_SETUP_22_24_28_29_TST120_TMG120_TMA120, // CY8C21x45,CY8C22x45,CY8C24x94, CY8C28xxx, CY8C29x66, TST120, TMG120, & TMA120 Checksum Setup Vectors
  CHECKSUM_SETUP_24_24A // CY8C24x23 & CY8C24x23A Checksum Setup Vectors
} extern chksm_setup;

enum program_block {
  PROGRAM_BLOCK_21_22_23_24_28_29_TST_TMG_TMA, // CY8C21xxx, CY8C21x45, CY8C22x45, CY8C23x33, CY8C24x23A, CY8C24x94, CY8C28xxx, CY8C29x66, TST1x0, TMG1x0, & TMA120 Program Block Vectors 
  PROGRAM_BLOCK_27 //  CY8C27x43 Program Block Vectors
} extern prgm_block;

#endif  //(INC_ISSP_EXTERN)

