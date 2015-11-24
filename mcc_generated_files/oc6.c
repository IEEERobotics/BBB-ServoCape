
/**
  OC6 Generated Driver API Source File

  @Company
    Microchip Technology Inc.

  @File Name
    oc6.c

  @Summary
    This is the generated source file for the OC6 driver using MPLAB® Code Configurator

  @Description
    This source file provides APIs for driver for OC6.
    Generation Information :
        Product Revision  :  MPLAB® Code Configurator - v2.25.2
        Device            :  PIC24FJ64GB202
        Driver Version    :  0.5
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.24
        MPLAB 	          :  MPLAB X v2.35 or v3.00
 */

/*
Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 */

/**
  Section: Included Files
 */
#include <xc.h>
#include "oc6.h"

/** OC Mode.

  @Summary
    Defines the OC Mode.

  @Description
    This data type defines the OC Mode of operation.

 */

static uint16_t gOC6Mode;

/**
  Section: Driver Interface
 */


void OC6_Initialize(void) {
    // OCFLT0 disabled; OCTSEL TMR1; OCFLT1 disabled; OCM Edge-Aligned PWM mode; OCSIDL disabled; ENFLT2 disabled; ENFLT1 disabled; TRIGMODE Only Software; OCFLT2 disabled; ENFLT0 disabled; 
    OC6CON1 = 0x1006;
    // OCTRIS disabled; OCINV disabled; FLTMD Cycle; SYNCSEL None; FLTOUT disabled; TRIGSTAT disabled; DCB Start of instruction cycle; FLTTRIEN disabled; OC32 disabled; OCTRIG disabled; 
    OC6CON2 = 0x0000;
    // OC6RS 10000; 
    OC6RS = 0x2710;
    // OC6R 592; 
    OC6R = 0x0250;
    // OC6TMR 0; 
    OC6TMR = 0x0000;

    gOC6Mode = OC6CON1bits.OCM;
}

/**
    void DRV_OC6_Initialize (void)
 */
void DRV_OC6_Initialize(void) {
    OC6_Initialize();
}

void OC6_Tasks(void) {
    if (IFS2bits.OC6IF) {
        IFS2bits.OC6IF = 0;
    }
}

/**
    void DRV_OC6_Tasks (void)
 */
void DRV_OC6_Tasks(void) {
    OC6_Tasks();
}

void OC6_Start(void) {
    OC6CON1bits.OCM = gOC6Mode;
}

/**
    void DRV_OC6_Start (void)
 */
void DRV_OC6_Start(void) {
    OC6_Start();
}

void OC6_Stop(void) {
    OC6CON1bits.OCM = 0;
}

/**
    void DRV_OC6_Stop (void)
 */
void DRV_OC6_Stop(void) {
    OC6_Stop();
}

void OC6_SingleCompareValueSet(uint16_t value) {
    OC6R = value;
}

/**
    void DRV_OC6_SingleCompareValueSet (uint16_t value)
 */
void DRV_OC6_SingleCompareValueSet(uint16_t value) {
    OC6_SingleCompareValueSet(value);
}

void OC6_DualCompareValueSet(uint16_t priVal, uint16_t secVal) {
    OC6R = priVal;

    OC6RS = secVal;
}

/**
    void DRV_OC6_DualCompareValueSet (uint16_t priVal, uint16_t secVal)
 */
void DRV_OC6_DualCompareValueSet(uint16_t priVal, uint16_t secVal) {
    OC6_DualCompareValueSet(priVal, secVal);
}

void OC6_CentreAlignedPWMConfig(uint16_t priVal, uint16_t secVal) {
    OC6R = priVal;

    OC6RS = secVal;
}

/**
    void DRV_OC6_CentreAlignedPWMConfig (uint16_t priVal, uint16_t secVal)
 */
void DRV_OC6_CentreAlignedPWMConfig(uint16_t priVal, uint16_t secVal) {
    OC6_CentreAlignedPWMConfig(priVal, secVal);
}

void OC6_EdgeAlignedPWMConfig(uint16_t priVal, uint16_t secVal) {
    OC6R = priVal;

    OC6RS = secVal;
}

/**
    void DRV_OC6_EdgeAlignedPWMConfig (uint16_t priVal, uint16_t secVal)
 */
void DRV_OC6_EdgeAlignedPWMConfig(uint16_t priVal, uint16_t secVal) {
    OC6_EdgeAlignedPWMConfig(priVal, secVal);
}

bool OC6_IsCompareCycleComplete(void) {
    return (IFS2bits.OC6IF);
}

/**
    bool DRV_OC6_IsCompareCycleComplete (void)
 */
bool DRV_OC6_IsCompareCycleComplete(void) {
    return (OC6_IsCompareCycleComplete());
}

bool OC6_FaultStatusGet(OC6_FAULTS faultNum) {
    bool status;
    /* Return the status of the fault condition */

    switch (faultNum) {
        case OC6_FAULT0:status = OC6CON1bits.OCFLT0;
            break;
        case OC6_FAULT1:status = OC6CON1bits.OCFLT1;
            break;

        case OC6_FAULT2:status = OC6CON1bits.OCFLT2;
            break;
        default:
            break;

    }
    return (status);
}

/**
    bool DRV_OC6_FaultStatusGet (DRV_OC6_FAULTS faultNum)
 */
bool DRV_OC6_FaultStatusGet(DRV_OC6_FAULTS faultNum) {
    return (OC6_FaultStatusGet(faultNum));
}

void OC6_FaultStatusClear(OC6_FAULTS faultNum) {

    switch (faultNum) {
        case OC6_FAULT0:OC6CON1bits.OCFLT0 = 0;
            break;
        case OC6_FAULT1:OC6CON1bits.OCFLT1 = 0;
            break;

        case OC6_FAULT2:OC6CON1bits.OCFLT2 = 0;
            break;
        default:
            break;
    }
}

/**
    void DRV_OC6_FaultStatusClear (DRV_OC6_FAULTS faultNum)
 */
void DRV_OC6_FaultStatusClear(DRV_OC6_FAULTS faultNum) {
    OC6_FaultStatusClear(faultNum);
}

void OC6_ManualTriggerSet(void) {
    OC6CON2bits.TRIGSTAT = true;
}

bool OC6_TriggerStatusGet(void) {
    return ( OC6CON2bits.TRIGSTAT);
}

/**
    bool DRV_OC6_TriggerStatusGet (void)
 */
bool DRV_OC6_TriggerStatusGet(void) {
    return (OC6_TriggerStatusGet());
}

void OC6_TriggerStatusClear(void) {
    /* Clears the trigger status */
    OC6CON2bits.TRIGSTAT = 0;
}

/**
    void DRV_OC6_TriggerStatusClear (void)
 */
void DRV_OC6_TriggerStatusClear(void) {
    OC6_TriggerStatusClear();
}
/**
 End of File
 */
