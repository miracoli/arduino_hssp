// filename: ISSP_Vectors.h
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
#ifndef INC_ISSP_VECTORS
#define INC_ISSP_VECTORS

#include "ISSP_directives.h"

// ------------------------- PSoC CY8CTST1x0 Devices ---------------------------
// Modifying these tables is NOT recommendended. Doing so will all but
// guarantee an ISSP error, unless updated vectors have been recommended or
// provided by Cypress Semiconductor.
// ----------------------------------------------------------------------------
#ifdef CY8CTST110_32LTXI
    unsigned char target_id_v[] = {0x06, 0x38};     //ID for CY8CTST110_32LTXI
#endif
#ifdef CY8CTST110_00PVXI
    unsigned char target_id_v[] = {0x06, 0x39};     //ID for CY8CTST110_00PVXI
#endif
#ifdef CY8CTST120_56LTXI
    unsigned char target_id_v[] = {0x06, 0x1F};     //ID for CY8CTST120_56LTXI
#endif
#ifdef CY8CTST120_00AXI
    unsigned char target_id_v[] = {0x06, 0x1B};     //ID for CY8CTST120_00AXI
#endif

// ------------------------- PSoC CY8CTMG1x0 Devices ---------------------------
// Modifying these tables is NOT recommendended. Doing so will all but
// guarantee an ISSP error, unless updated vectors have been recommended or
// provided by Cypress Semiconductor.
// ----------------------------------------------------------------------------
#ifdef CY8CTMG110_32LTXI
    unsigned char target_id_v[] = {0x07, 0x38};     //ID for CY8CTMG110_32LTXI
#endif
#ifdef CY8CTMG110_00PVXI
    unsigned char target_id_v[] = {0x07, 0x39};     //ID for CY8CTMG110_00PVXI
#endif
#ifdef CY8CTMG120_56LTXI
    unsigned char target_id_v[] = {0x07, 0x1F};     //ID for CY8CTMG120_56LTXI
#endif
#ifdef CY8CTMG120_00AXI
    unsigned char target_id_v[] = {0x07, 0x1B};     //ID for CY8CTMG120_00AXI
#endif

// ------------------------- PSoC CY8CTMA120 Devices ---------------------------
// Modifying these tables is NOT recommendended. Doing so will all but
// guarantee an ISSP error, unless updated vectors have been recommended or
// provided by Cypress Semiconductor.
// ----------------------------------------------------------------------------
#ifdef CY8CTMA120_56LTXI
    unsigned char target_id_v[] = {0x05, 0x1F};     //ID for CY8CTMA120_56LTXI
#endif
#ifdef CY8CTMA120_100BVXI
    unsigned char target_id_v[] = {0x05, 0x59};     //ID for CY8CTMA120_100BVXI
#endif
#ifdef CY8CTMA120_00AXI
    unsigned char target_id_v[] = {0x05, 0x1B};     //ID for CY8CTMA120_00AXI
#endif

// ------------------------- PSoC CY8C21x23 Devices ---------------------------
// Modifying these tables is NOT recommendended. Doing so will all but
// guarantee an ISSP error, unless updated vectors have been recommended or
// provided by Cypress Semiconductor.
// ----------------------------------------------------------------------------
#ifdef CY8C21123
    unsigned char target_id_v[] = {0x00, 0x17};     //ID for CY8C21123
#endif
#ifdef CY8C21223
    unsigned char target_id_v[] = {0x00, 0x18};     //ID for CY8C21223
#endif
#ifdef CY8C21323
    unsigned char target_id_v[] = {0x00, 0x19};     //ID for CY8C2132
#endif
#ifdef CY8C21002
    unsigned char target_id_v[] = {0x00, 0x3F};     //ID for CY8C21x23 ICE pod
#endif

// ------------------------- PSoC CY8C21x34 Devices ---------------------------
// Modifying these tables is NOT recommendended. Doing so will all but
// guarantee an ISSP error, unless updated vectors have been recommended or
// provided by Cypress Semiconductor.
// ----------------------------------------------------------------------------
#ifdef CY8C21234
    unsigned char target_id_v[] = {0x00, 0x36};     //ID for CY8C21234
#endif
#ifdef CY8C21334
    unsigned char target_id_v[] = {0x00, 0x37};     //ID for CY8C21334
#endif
#ifdef CY8C21434
    unsigned char target_id_v[] = {0x00, 0x38};     //ID for CY8C21434
#endif
#ifdef CY8C21534
    unsigned char target_id_v[] = {0x00, 0x40};     //ID for CY8C21534
#endif
#ifdef CY8C21634
    unsigned char target_id_v[] = {0x00, 0x49};     //ID for CY8C21634
#endif
#ifdef CY8C21001
    unsigned char target_id_v[] = {0x00, 0x39};     //ID for CY8C21x34 ICE pod
#endif

// ------------------------- PSoC CY8C21x45 Devices ---------------------------
// Modifying these tables is NOT recommendended. Doing so will all but
// guarantee an ISSP error, unless updated vectors have been recommended or
// provided by Cypress Semiconductor.
// ----------------------------------------------------------------------------
#ifdef CY8C21345
    unsigned char target_id_v[] = {0x00, 0xD3};     //ID for CY8C21345  
#endif

// ------------------------- PSoC CY8C22x45 Devices ---------------------------
// Modifying these tables is NOT recommendended. Doing so will all but
// guarantee an ISSP error, unless updated vectors have been recommended or
// provided by Cypress Semiconductor.
// ----------------------------------------------------------------------------
#ifdef CY8C22045
    unsigned char target_id_v[] = {0x00, 0xD0};     //ID for CY8C22045
#endif
#ifdef CY8C22345
    unsigned char target_id_v[] = {0x00, 0xD1};     //ID for CY8C22345
#endif
#ifdef CY8C22545
    unsigned char target_id_v[] = {0x00, 0xD2};     //ID for CY8C22545
#endif

// ------------------------- PSoC CY8C23x33 Devices ---------------------------
// Modifying these tables is NOT recommendended. Doing so will all but
// guarantee an ISSP error, unless updated vectors have been recommended or
// provided by Cypress Semiconductor.
// ----------------------------------------------------------------------------
#ifdef CY8C23033
    unsigned char target_id_v[] = {0x08, 0xB2};     //ID for CY8C23033
#endif
#ifdef CY8C23433
    unsigned char target_id_v[] = {0x08, 0xB0};     //ID for CY8C23433
#endif
#ifdef CY8C23533
    unsigned char target_id_v[] = {0x08, 0xB1};     //ID for CY8C23533
#endif

// ------------------------- PSoC CY8C24x23A Devices --------------------------
// Modifying these tables is NOT recommendended. Doing so will all but
// guarantee an ISSP error, unless updated vectors have been recommended or
// provided by Cypress Semiconductor.
// ----------------------------------------------------------------------------
#ifdef CY8C24123A
    unsigned char target_id_v[] = {0x00, 0x32};     //ID for CY8C24123A
#endif
#ifdef CY8C24223A
    unsigned char target_id_v[] = {0x00, 0x33};     //ID for CY8C24223A
#endif
#ifdef CY8C24423A
    unsigned char target_id_v[] = {0x00, 0x34};     //ID for CY8C24423A
#endif
#ifdef CY8C24000A
    unsigned char target_id_v[] = {0x00, 0x35};     //ID for CY8C24x23A ICE pod
#endif


// ------------------------- PSoC CY8C24x94 Devices ---------------------------
// Modifying these tables is NOT recommendended. Doing so will all but
// guarantee an ISSP error, unless updated vectors have been recommended or
// provided by Cypress Semiconductor.
// ----------------------------------------------------------------------------
#ifdef CY8C24794
    unsigned char target_id_v[] = {0x00, 0x1D};     //ID for CY8C24794
#endif
#ifdef CY8C24894
    unsigned char target_id_v[] = {0x00, 0x1F};     //ID for CY8C24894
#endif
#ifdef CY8C24994
    unsigned char target_id_v[] = {0x00, 0x59};     //ID for CY8C24994
#endif
#ifdef CY8C24094
    unsigned char target_id_v[] = {0x00, 0x1B};     //ID for CY8C24094
#endif


// ------------------------- PSoC CY8C27x43 Devices ---------------------------
// Modifying these tables is NOT recommendended. Doing so will all but
// guarantee an ISSP error, unless updated vectors have been recommended or
// provided by Cypress Semiconductor.
// ----------------------------------------------------------------------------
#ifdef CY8C27143
    unsigned char target_id_v[] = {0x00, 0x09};     //ID for CY8C27143
#endif
#ifdef CY8C27243
    unsigned char target_id_v[] = {0x00, 0x0A};     //ID for CY8C27243
#endif
#ifdef CY8C27443
    unsigned char target_id_v[] = {0x00, 0x0B};     //ID for CY8C27443
#endif
#ifdef CY8C27543
    unsigned char target_id_v[] = {0x00, 0x0C};     //ID for CY8C27543
#endif
#ifdef CY8C27643
    unsigned char target_id_v[] = {0x00, 0x0D};     //ID for CY8C27643
#endif
#ifdef CY8C27002
    unsigned char target_id_v[] = {0x00, 0x0E};     //ID for CY8C27x43 ICE pod
#endif

// ------------------------- PSoC CY8C28xxx Devices ---------------------------
// Modifying these tables is NOT recommendended. Doing so will all but
// guarantee an ISSP error, unless updated vectors have been recommended or
// provided by Cypress Semiconductor.
// ----------------------------------------------------------------------------
#ifdef CY8C28000
    unsigned char target_id_v[] = {0x00, 0xE0};     //ID for CY8C28000 ICE pod
#endif
#ifdef CY8C28445
    unsigned char target_id_v[] = {0x00, 0xE1};     //ID for CY8C28445
#endif
#ifdef CY8C28545
    unsigned char target_id_v[] = {0x00, 0xE2};     //ID for CY8C28545
#endif
#ifdef CY8C28645
    unsigned char target_id_v[] = {0x00, 0xE3};     //ID for CY8C28645
#endif
#ifdef CY8C28x43
    unsigned char target_id_v[] = {0x00, 0xE4};     //ID for CY8C28x43
#endif
#ifdef CY8C28452
    unsigned char target_id_v[] = {0x00, 0xE5};     //ID for CY8C28452
#endif
#ifdef CY8C28x13
    unsigned char target_id_v[] = {0x00, 0xE6};     //ID for CY8C28x13
#endif
#ifdef CY8C28x33
    unsigned char target_id_v[] = {0x00, 0xE7};     //ID for CY8C28x33
#endif
#ifdef CY8C28403
    unsigned char target_id_v[] = {0x00, 0xE8};     //ID for CY8C28403
#endif
#ifdef CY8C28623
    unsigned char target_id_v[] = {0x00, 0xE9};     //ID for CY8C28623
#endif

// ------------------------- PSoC CY8C29x66 Devices ---------------------------
// Modifying these tables is NOT recommendended. Doing so will all but
// guarantee an ISSP error, unless updated vectors have been recommended or
// provided by Cypress Semiconductor.
// ----------------------------------------------------------------------------
#ifdef CY8C29466
    unsigned char target_id_v[] = {0x00, 0x2A};     //ID for CY8C29466
#endif
#ifdef CY8C29566
    unsigned char target_id_v[] = {0x00, 0x2B};     //ID for CY8C29566
#endif
#ifdef CY8C29666
    unsigned char target_id_v[] = {0x00, 0x2C};     //ID for CY8C29666
#endif
#ifdef CY8C29866
    unsigned char target_id_v[] = {0x00, 0x2D};     //ID for CY8C29866
#endif
#ifdef CY8C29002
    unsigned char target_id_v[] = {0x00, 0x2E};     //ID for CY8C29002
#endif


// ---- CY8C21x23, CY8C21x34, CY8C23x33, CY8C27x43, TST110 & TMG110 Checksum Setup Vectors ----
// Modifying these tables is NOT recommendended. Doing so will all but
// guarantee an ISSP error, unless updated vectors have been recommended or
// provided by Cypress Semiconductor.
// ---------------------------------------------------------------------------------
#ifdef CHECKSUM_SETUP_21_23_27_TST110_TMG110
    const unsigned int num_bits_checksum = 286;
    const unsigned char checksum_v[] =
    {
        0xDE, 0xE0, 0x1F, 0x7B, 0x00, 0x79, 0xF0, 0x75,
        0xE7, 0xC8, 0x1F, 0xDE, 0xA0, 0x1F, 0x7A, 0x01,
        0xF9, 0xF7, 0x01, 0xF7, 0xC9, 0x87, 0xDF, 0x48,
        0x1E, 0x7D, 0x00, 0x7D, 0xE0, 0x0F, 0xF7, 0xC0,
        0x07, 0xDF, 0xE2, 0x5C
                     
//          0b11011110,0b11100000,0b00011111,0b01111011,0b00000000,0b01111001,0b11110000,0b01110101,
//          0b11100111,0b11001000,0b00011111,0b11011110,0b10100000,0b00011111,0b01111010,0b00000001,
//          0b11111001,0b11110111,0b00000001,0b11110111,0b11001001,0b10000111,0b11011111,0b01001000,
//          0b00011110,0b01111101,0b00000000,0b01111101,0b11100000,0b00001111,0b11110111,0b11000000,
//          0b00000111,0b11011111,0b11100010,0b01011100
    };
#endif


// -------------- CY8C24x23 & CY8C24x23A Checksum Setup Vectors ---------------
// Modifying these tables is NOT recommendended. Doing so will all but
// guarantee an ISSP error, unless updated vectors have been recommended or
// provided by Cypress Semiconductor.
// ----------------------------------------------------------------------------
#ifdef CHECKSUM_SETUP_24_24A
    const unsigned int num_bits_checksum = 286;
    const unsigned char checksum_v[] =
    {
        0xDE, 0xE0, 0x1F, 0x7B, 0x00, 0x79, 0xF0, 0x75,
        0xE7, 0xC8, 0x1F, 0xDE, 0xA0, 0x1F, 0x7A, 0x01,
        0xF9, 0xF7, 0x01, 0xF7, 0xC9, 0x87, 0xDF, 0x48,
        0x1E, 0x7D, 0x20, 0x7D, 0xE0, 0x0F, 0xF7, 0xC0,
        0x07, 0xDF, 0xE2, 0x5C
                     
//          0b11011110,0b11100000,0b00011111,0b01111011,0b00000000,0b01111001,0b11110000,0b01110101,
//          0b11100111,0b11001000,0b00011111,0b11011110,0b10100000,0b00011111,0b01111010,0b00000001,
//          0b11111001,0b11110111,0b00000001,0b11110111,0b11001001,0b10000111,0b11011111,0b01001000,
//          0b00011110,0b01111101,0b00100000,0b01111101,0b11100000,0b00001111,0b11110111,0b11000000,
//          0b00000111,0b11011111,0b11100010,0b01011100
    };
#endif


// ---- CY8C21x45,CY8C22x45,CY8C24x94, CY8C28xxx, CY8C29x66, TST120, TMG120, & TMA120 Checksum Setup Vectors ----
// Modifying these tables is NOT recommendended. Doing so will all but
// guarantee an ISSP error, unless updated vectors have been recommended or
// provided by Cypress Semiconductor.
// ------------------------------------------------------------------------------------------
#ifdef CHECKSUM_SETUP_22_24_28_29_TST120_TMG120_TMA120
    const unsigned int num_bits_checksum = 286;
    const unsigned char checksum_v[] =
    {
        0xDE, 0xE0, 0x1F, 0x7B, 0x00, 0x79, 0xF0, 0x75,
        0xE7, 0xC8, 0x1F, 0xDE, 0xA0, 0x1F, 0x7A, 0x01,
        0xF9, 0xF6, 0x01, 0xF7, 0xC9, 0x87, 0xDF, 0x48,
        0x1E, 0x7D, 0x40, 0x7D, 0xE0, 0x0F, 0xF7, 0xC0,
        0x07, 0xDF, 0xE2, 0x5C
                    
//          0b11011110,0b11100000,0b00011111,0b01111011,0b00000000,0b01111001,0b11110000,0b01110101,
//          0b11100111,0b11001000,0b00011111,0b11011110,0b10100000,0b00011111,0b01111010,0b00000001,
//          0b11111001,0b11110110,0b00000001,0b11110111,0b11001001,0b10000111,0b11011111,0b01001000,
//          0b00011110,0b01111101,0b00100000,0b01111101,0b11100000,0b00001111,0b11110111,0b11000000,
//          0b00000111,0b11011111,0b11100010,0b01011100
    };
#endif


// ---- CY8C21xxx, CY8C21x45, CY8C22x45, CY8C23x33, CY8C24x23A, CY8C24x94, CY8C28xxx, CY8C29x66, TST1x0, TMG1x0, & TMA120 Program Block Vectors ----
// Modifying these tables is NOT recommendended. Doing so will all but
// guarantee an ISSP error, unless updated vectors have been recommended or
// provided by Cypress Semiconductor.
// ----------------------------------------------------------------------------------------------------------------
#ifdef PROGRAM_BLOCK_21_22_23_24_28_29_TST_TMG_TMA
    const unsigned int num_bits_program_block = 308;
    const unsigned char program_block[] =
    {
        0x9F, 0x8A, 0x9E, 0x7F, 0x2B, 0x7D, 0xEE, 0x01,
        0xF7, 0xB0, 0x07, 0x9F, 0x07, 0x5E, 0x7C, 0x81,
        0xFD, 0xEA, 0x01, 0xF7, 0xA0, 0x1F, 0x9F, 0x70,
        0x1F, 0x7C, 0x98, 0x7D, 0xF4, 0x81, 0xF7, 0x80,
        0x17, 0xDF, 0x00, 0x1F, 0x7F, 0x89, 0x70
                     
//          0b10011111,0b10001010,0b10011110,0b01111111,0b00101011,0b01111101,0b11101110,0b00000001,
//          0b11110111,0b10110000,0b00000111,0b10011111,0b00000111,0b01011110,0b01111100,0b10000001,
//          0b11111101,0b11101010,0b00000001,0b11110111,0b10100000,0b00011111,0b10011111,0b01110000,
//          0b00011111,0b01111100,0b10011000,0b01111101,0b11110100,0b10000001,0b11110111,0b10000000,
//          0b00010111,0b11011111,0b00000000,0b00011111,0b01111111,0b10001001,0b01110000

    };
#endif

// --------------------- CY8C27x43 Program Block Vectors-----------------------
// Modifying these tables is NOT recommendended. Doing so will all but
// guarantee an ISSP error, unless updated vectors have been recommended or
// provided by Cypress Semiconductor.
// ----------------------------------------------------------------------------
#ifdef PROGRAM_BLOCK_27
    const unsigned int num_bits_program_block = 308;
    
    const unsigned char program_block[] =
    {
        0x9F, 0x82, 0xBE, 0x7F, 0x2B, 0x7D, 0xEE, 0x01,
        0xF7, 0xB0, 0x07, 0x9F, 0x07, 0x5E, 0x7C, 0x81,
        0xFD, 0xEA, 0x01, 0xF7, 0xA0, 0x1F, 0x9F, 0x70,
        0x1F, 0x7C, 0x98, 0x7D, 0xF4, 0x81, 0xF7, 0x80,
        0x17, 0xDF, 0x00, 0x1F, 0x7F, 0x89, 0x70
                     
//          0b10011111,0b10000010,0b10111110,0b01111111,0b00101011,0b01111101,0b11101110,0b00000001,
//          0b11110111,0b10110000,0b00000111,0b10011111,0b00000111,0b01011110,0b01111100,0b10000001,
//          0b11111101,0b11101010,0b00000001,0b11110111,0b10100000,0b00011111,0b10011111,0b01110000,
//          0b00011111,0b01111100,0b10011000,0b01111101,0b11110100,0b10000001,0b11110111,0b10000000,
//          0b00010111,0b11011111,0b00000000,0b00011111,0b01111111,0b10001001,0b01110000
    };
#endif

// ----------------------------- General PSoC Vectors--------------------------
// Modifying these tables is NOT recommendended. Doing so will all but
// guarantee an ISSP error, unless updated vectors have been recommended or
// provided by Cypress Semiconductor.
// ----------------------------------------------------------------------------
    const unsigned int num_bits_init1 = 396;
    const unsigned char init1_v[] =
    {
        0xCA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x0D, 0xEE, 0x01, 0xF7, 0xB0, 0x07, 0x9F, 0x07,
        0x5E, 0x7C, 0x81, 0xFD, 0xEA, 0x01, 0xF7, 0xA0,
        0x1F, 0x9F, 0x70, 0x1F, 0x7C, 0x98, 0x7D, 0xF4,
        0x81, 0xF7, 0x80, 0x4F, 0xDF, 0x00, 0x1F, 0x7F,
        0x89, 0x70

//          0b11001010,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,
//          0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,
//          0b00001101,0b11101110,0b00000001,0b11110111,0b10110000,0b00000111,0b10011111,0b00000111,
//          0b01011110,0b01111100,0b10000001,0b11111101,0b11101010,0b00000001,0b11110111,0b10100000,
//          0b00011111,0b10011111,0b01110000,0b00011111,0b01111100,0b10011000,0b01111101,0b11110100,
//          0b10000001,0b11110111,0b10000000,0b01001111,0b11011111,0b00000000,0b00011111,0b01111111,
//          0b10001001,0b01110000
    };

    const unsigned int num_bits_init2 = 286;
    const unsigned char init2_v[] =
        {
            0xDE, 0xE0, 0x1F, 0x7B, 0x00, 0x79, 0xF0, 0x75,
            0xE7, 0xC8, 0x1F, 0xDE, 0xA0, 0x1F, 0x7A, 0x01,
            0xF9, 0xF7, 0x01, 0xF7, 0xC9, 0x87, 0xDF, 0x48,
            0x1E, 0x7D, 0x00, 0xFD, 0xE0, 0x0D, 0xF7, 0xC0,
            0x07, 0xDF, 0xE2, 0x5C 
                     
//              0b11011110,0b11100000,0b00011111,0b01111011,0b00000000,0b01111001,0b11110000,0b01110101,
//              0b11100111,0b11001000,0b00011111,0b11011110,0b10100000,0b00011111,0b01111010,0b00000001,
//              0b11111001,0b11110111,0b00000001,0b11110111,0b11001001,0b10000111,0b11011111,0b01001000,
//              0b00011110,0b01111101,0b00000000,0b11111101,0b11100000,0b00001101,0b11110111,0b11000000,
//              0b00000111,0b11011111,0b11100010,0b01011100
        };

    const unsigned int num_bits_init3_5v = 836;
    const unsigned char init3_5v[] =
        {
            0xDE, 0xE0, 0x1F, 0x7A, 0x01, 0xFD, 0xEA, 0x01,
            0xF7, 0xB0, 0x47, 0xDF, 0x0A, 0x3F, 0x7C, 0xFE,
            0x7D, 0xF4, 0x61, 0xF7, 0xF8, 0x97, 0x00, 0x00,
            0x03, 0x7B, 0x80, 0x7D, 0xE8, 0x07, 0xF7, 0xA8,
            0x07, 0xDE, 0xC1, 0x1F, 0x7C, 0x30, 0x7D, 0xF3,
            0xD5, 0xF7, 0xD1, 0x87, 0xDE, 0xE2, 0x1F, 0x7F,
            0x89, 0x70, 0x00, 0x00, 0x37, 0xB8, 0x07, 0xDE,
            0x80, 0x7F, 0x7A, 0x80, 0x7D, 0xEC, 0x11, 0xF7,
            0xC2, 0x8F, 0xDF, 0x3F, 0xBF, 0x7D, 0x18, 0x7D,
            0xFE, 0x25, 0xC0, 0x00, 0x00, 0xDE, 0xE0, 0x1F,
            0x7A, 0x01, 0xFD, 0xEA, 0x01, 0xF7, 0xB0, 0x47,
            0xDF, 0x0C, 0x1F, 0x7C, 0xF4, 0x7D, 0xF4, 0x61,
            0xF7, 0xB8, 0x87, 0xDF, 0xE2, 0x5C, 0x00, 0x00,
            0x00
                     
//              0b11011110,0b11100000,0b00011111,0b01111010,0b00000001,0b11111101,0b11101010,0b00000001,
//              0b11110111,0b10110000,0b01000111,0b11011111,0b00001010,0b00111111,0b01111100,0b11111110,
//              0b01111101,0b11110100,0b01100001,0b11110111,0b11111000,0b10010111,0b00000000,0b00000000,
//              0b00000011,0b01111011,0b10000000,0b01111101,0b11101000,0b00000111,0b11110111,0b10101000,
//              0b00000111,0b11011110,0b11000001,0b00011111,0b01111100,0b00110000,0b01111101,0b11110011,
//              0b11010101,0b11110111,0b11010001,0b10000111,0b11011110,0b11100010,0b00011111,0b01111111,
//              0b10001001,0b01110000,0b00000000,0b00000000,0b00110111,0b10111000,0b00000111,0b11011110,
//              0b10000000,0b01111111,0b01111010,0b10000000,0b01111101,0b11101100,0b00010001,0b11110111,
//              0b11000010,0b10001111,0b11011111,0b00111111,0b10111111,0b01111101,0b00011000,0b01111101,
//              0b11111110,0b00100101,0b11000000,0b00000000,0b00000000,0b11011110,0b11100000,0b00011111,
//              0b01111010,0b00000001,0b11111101,0b11101010,0b00000001,0b11110111,0b10110000,0b01000111,
//              0b11011111,0b00001100,0b00011111,0b01111100,0b11110100,0b01111101,0b11110100,0b01100001,
//              0b11110111,0b10111000,0b10000111,0b11011111,0b11100010,0b01011100,0b00000000,0b00000000,
//              0b00000000
        };

    const unsigned int num_bits_init3_3v = 836;
    const unsigned char init3_3v[] =
        {
            0xDE, 0xE0, 0x1F, 0x7A, 0x01, 0xFD, 0xEA, 0x01,
            0xF7, 0xB0, 0x47, 0xDF, 0x0A, 0x3F, 0x7C, 0xFC,
            0x7D, 0xF4, 0x61, 0xF7, 0xF8, 0x97, 0x00, 0x00,
            0x03, 0x7B, 0x80, 0x7D, 0xE8, 0x07, 0xF7, 0xA8,
            0x07, 0xDE, 0xC1, 0x1F, 0x7C, 0x30, 0x7D, 0xF3,
            0xD5, 0xF7, 0xD1, 0x87, 0xDE, 0xE2, 0x1F, 0x7F,
            0x89, 0x70, 0x00, 0x00, 0x37, 0xB8, 0x07, 0xDE,
            0x80, 0x7F, 0x7A, 0x80, 0x7D, 0xEC, 0x11, 0xF7,
            0xC2, 0x8F, 0xDF, 0x3F, 0x3F, 0x7D, 0x18, 0x7D,
            0xFE, 0x25, 0xC0, 0x00, 0x00, 0xDE, 0xE0, 0x1F,
            0x7A, 0x01, 0xFD, 0xEA, 0x01, 0xF7, 0xB0, 0x47,
            0xDF, 0x0C, 0x1F, 0x7C, 0xF4, 0x7D, 0xF4, 0x61,
            0xF7, 0xB8, 0x87, 0xDF, 0xE2, 0x5C, 0x00, 0x00,
            0x00
                     
//              0b11011110,0b11100000,0b00011111,0b01111010,0b00000001,0b11111101,0b11101010,0b00000001,
//              0b11110111,0b10110000,0b01000111,0b11011111,0b00001010,0b00111111,0b01111100,0b11111100,
//              0b01111101,0b11110100,0b01100001,0b11110111,0b11111000,0b10010111,0b00000000,0b00000000,
//              0b00000011,0b01111011,0b10000000,0b01111101,0b11101000,0b00000111,0b11110111,0b10101000,
//              0b00000111,0b11011110,0b11000001,0b00011111,0b01111100,0b00110000,0b01111101,0b11110011,
//              0b11010101,0b11110111,0b11010001,0b10000111,0b11011110,0b11100010,0b00011111,0b01111111,
//              0b10001001,0b01110000,0b00000000,0b00000000,0b00110111,0b10111000,0b00000111,0b11011110,
//              0b10000000,0b01111111,0b01111010,0b10000000,0b01111101,0b11101100,0b00010001,0b11110111,
//              0b11000010,0b10001111,0b11011111,0b00111111,0b00111111,0b01111101,0b00011000,0b01111101,
//              0b11111110,0b00100101,0b11000000,0b00000000,0b00000000,0b11011110,0b11100000,0b00011111,
//              0b01111010,0b00000001,0b11111101,0b11101010,0b00000001,0b11110111,0b10110000,0b01000111,
//              0b11011111,0b00001100,0b00011111,0b01111100,0b11110100,0b01111101,0b11110100,0b01100001,
//              0b11110111,0b10111000,0b10000111,0b11011111,0b11100010,0b01011100,0b00000000,0b00000000,
//              0b00000000
        };

    const unsigned int num_bits_id_setup = 330;
    const unsigned char id_setup_v[] =
    {
        0xDE, 0xE2, 0x1F, 0x70, 0x01, 0x7D, 0xEE, 0x01,
        0xF7, 0xB0, 0x07, 0x9F, 0x07, 0x5E, 0x7C, 0x81,
        0xFD, 0xEA, 0x01, 0xF7, 0xA0, 0x1F, 0x9F, 0x70,
        0x1F, 0x7C, 0x98, 0x7D, 0xF4, 0x81, 0xE7, 0xD0,
        0x07, 0xDE, 0x00, 0xDF, 0x7C, 0x00, 0x7D, 0xFE,
        0x25, 0xC0
                 
//          0b11011110,0b11100010,0b00011111,0b01110000,0b00000001,0b01111101,0b11101110,0b00000001,
//          0b11110111,0b10110000,0b00000111,0b10011111,0b00000111,0b01011110,0b01111100,0b10000001,
//          0b11111101,0b11101010,0b00000001,0b11110111,0b10100000,0b00011111,0b10011111,0b01110000,
//          0b00011111,0b01111100,0b10011000,0b01111101,0b11110100,0b10000001,0b11100111,0b11010000,
//          0b00000111,0b11011110,0b00000000,0b11011111,0b01111100,0b00000000,0b01111101,0b11111110,
//          0b00100101,0b11000000
    };

    const unsigned int num_bits_erase_all = 308;
    const unsigned char erase_all_v[] =
    {
        0x9F, 0x82, 0xBE, 0x7F, 0x2B, 0x7D, 0xEE, 0x01,
        0xF7, 0xB0, 0x07, 0x9F, 0x07, 0x5E, 0x7C, 0x81,
        0xFD, 0xEA, 0x01, 0xF7, 0xA0, 0x1F, 0x9F, 0x70,
        0x1F, 0x7C, 0x98, 0x7D, 0xF4, 0x81, 0xF7, 0x80,
        0x2F, 0xDF, 0x00, 0x1F, 0x7F, 0x89, 0x70
                     
//          0b10011111,0b10000010,0b10111110,0b01111111,0b00101011,0b01111101,0b11101110,0b00000001,
//          0b11110111,0b10110000,0b00000111,0b10011111,0b00000111,0b01011110,0b01111100,0b10000001,
//          0b11111101,0b11101010,0b00000001,0b11110111,0b10100000,0b00011111,0b10011111,0b01110000,
//          0b00011111,0b01111100,0b10011000,0b01111101,0b11110100,0b10000001,0b11110111,0b10000000,
//          0b00101111,0b11011111,0b00000000,0b00011111,0b01111111,0b10001001,0b01110000
    };


    const unsigned char read_id_v[] =
    {
        0xBF, 0x00, 0xDF, 0x90, 0x00
                     
//          0b10111111,0b00000000,0b11011111,0b10010000,0b00000000
    };

    const unsigned char    write_byte_start = 0x90;
    const unsigned char    write_byte_end = 0xE0;

    const unsigned char    set_block_number[] = {0x9F, 0x40, 0xE0};
    const unsigned char    set_block_number_end = 0xE0;
#ifdef MULTI_BANK
    const unsigned char    set_bank_number[] = {0xDE, 0xE2, 0x1F, 0x7D, 0x00};
    const unsigned char    set_bank_number_end[] = {0xFB, 0xDC, 0x03, 0x80};
#endif

    const unsigned char    num_bits_wait_and_poll_end = 40;
    const unsigned char    wait_and_poll_end[] = 
    {  
        0x00, 0x00, 0x00, 0x00, 0x00 

//          0b00000000,0b00000000,0b00000000,0b00000000,0b00000000 
    };    // forty '0's per the spec
                
                

    const unsigned char read_checksum_v[] = 
    {  
        0xBF, 0x20, 0xDF, 0x80, 0x80
                
//          0b10111111, 0b00100000,0b11011111,0b10000000,0b10000000 
    };

    
    const unsigned char read_byte_v[] = 
    {  
        0xB0, 0x80 
                
//          0b10110000, 0b10000000 
    };
    

    const unsigned int num_bits_verify_setup = 264;
    const unsigned char verify_setup_v[] =
    {
        0xDE, 0xE0, 0x1F, 0x7B, 0x00, 0x79, 0xF0, 0x75,
        0xE7, 0xC8, 0x1F, 0xDE, 0xA0, 0x1F, 0x7A, 0x01,
        0xF9, 0xF7, 0x01, 0xF7, 0xC9, 0x87, 0xDF, 0x48,
        0x1F, 0x78, 0x00, 0xFD, 0xF0, 0x01, 0xF7, 0xF8,
        0x97
                     
//          0b11011110,0b11100000,0b00011111,0b01111011,0b00000000,0b01111001,0b11110000,0b01110101,
//          0b11100111,0b11001000,0b00011111,0b11011110,0b10100000,0b00011111,0b01111010,0b00000001,
//          0b11111001,0b11110111,0b00000001,0b11110111,0b11001001,0b10000111,0b11011111,0b01001000,
//          0b00011111,0b01111000,0b00000000,0b11111101,0b11110000,0b00000001,0b11110111,0b11111000,
//          0b10010111
    };


    const unsigned int num_bits_security = 308;
    const unsigned char security_v[] =
    {
        0x9F, 0x8A, 0x9E, 0x7F, 0x2B, 0x7D, 0xEE, 0x01,
        0xF7, 0xB0, 0x07, 0x9F, 0x07, 0x5E, 0x7C, 0x81,
        0xFD, 0xEA, 0x01, 0xF7, 0xA0, 0x1F, 0x9F, 0x70,
        0x1F, 0x7C, 0x98, 0x7D, 0xF4, 0x81, 0xF7, 0x80,
        0x27, 0xDF, 0x00, 0x1F, 0x7F, 0x89, 0x70
                     
//          0b10011111,0b10001010,0b10011110,0b01111111,0b00101011,0b01111101,0b11101110,0b00000001,
//          0b11110111,0b10110000,0b00000111,0b10011111,0b00000111,0b01011110,0b01111100,0b10000001,
//          0b11111101,0b11101010,0b00000001,0b11110111,0b10100000,0b00011111,0b10011111,0b01110000,
//          0b00011111,0b01111100,0b10011000,0b01111101,0b11110100,0b10000001,0b11110111,0b10000000,
//          0b00100111,0b11011111,0b00000000,0b00011111,0b01111111,0b10001001,0b01110000
    };

#endif  //(INC_ISSP_VECTORS)
#endif  //(PROJECT_REV_)
//end of file ISSP_Vectors.h
