/**
  OC6 Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    oc6.h

  @Summary
    This is the generated header file for the OC6 driver using MPLAB® Code Configurator

  @Description
    This header file provides APIs for driver for OC6.
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

#ifndef _OC6_H
#define _OC6_H

/**
  Section: Included Files
 */

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif

    /**
      Section: Data Types
     */

    /** OC6 Fault Number

      @Summary
        Defines the fault number

      @Description
        This type defines the various faults supported.

      Remarks:
        None
     */

    typedef enum {
        /* Fault 0 */
        OC6_FAULT0 /*DOM-IGNORE-BEGIN*/ = 0, /*DOM-IGNORE-END*/
        /* Fault 1 */
        OC6_FAULT1 /*DOM-IGNORE-BEGIN*/ = 1, /*DOM-IGNORE-END*/
        /* Fault 2 */
        OC6_FAULT2 /*DOM-IGNORE-BEGIN*/ = 2/*DOM-IGNORE-END*/
    } OC6_FAULTS;

    /**
    Deprecated Fault enumeration
     */
    typedef enum {
        /* Fault 0 */
        DRV_OC6_FAULT0 /*DOM-IGNORE-BEGIN*/ = 0, /*DOM-IGNORE-END*/
        /* Fault 1 */
        DRV_OC6_FAULT1 /*DOM-IGNORE-BEGIN*/ = 1, /*DOM-IGNORE-END*/
        /* Fault 2 */
        DRV_OC6_FAULT2 /*DOM-IGNORE-BEGIN*/ = 2/*DOM-IGNORE-END*/
    } DRV_OC6_FAULTS;

    /**
      Section: Interface Routines
     */


    /**
      @Summary
        This function initializes OC instance : 6

      @Description
        This routine initializes the OC6 driver instance for : 6
        index, making it ready for clients to open and use it.
        This routine must be called before any other OC6 routine is called.
	
      @Preconditions
        None.

      @Param
        None.

      @Returns
        None.

      @Example
        <code>
        uint16_t priVal,secVal;
        bool completeCycle = false;
        priVal = 0x1000;
        secVal = 0x2000;
        OC6_FAULTS faultNum = OC6_FAULT0;

        OC6_Initialize();
    
        OC6_CentreAlignedPWMConfig( priVal, secVal );
  
        OC6_Start();

        while(1)
        {
            faultStat =  OC6_FaultStatusGet( faultNum );

            if(faultStat)
            {
                OC6_FaultStatusClear( faultNum );
            }

            completeCycle = OC6_IsCompareCycleComplete( void );
            if(completeCycle)
            {
                OC6_Stop();
            }
        }
        </code>

     */

    void OC6_Initialize(void);
    /**
        void DRV_OC6_Initialize(void)
     */
    void DRV_OC6_Initialize(void) __attribute__((deprecated("\nThis will be removed in future MCC releases. \nUse OC6_Initialize instead. ")));

    /**
      @Summary
        Maintains the driver's state machine and implements its ISR

      @Description
        This routine is used to maintain the driver's internal state
        machine and implement its ISR for interrupt-driven implementations.
  
      @Preconditions
        None.

      @Param
        None.

      @Returns
        None.

      @Example
        <code>
        while (true)
        {
            OC6_Tasks();

            // Do other tasks
        }
        </code>
    
     */
    void OC6_Tasks(void);

    /**
        void DRV_OC6_Tasks(void)
     */
    void DRV_OC6_Tasks(void) __attribute__((deprecated("\nThis will be removed in future MCC releases. \nUse OC6_Tasks instead. ")));


    /**
      @Summary
        Enables the OC module with the corresponding operation mode.

      @Description
        This routine enables the OC module with the corresponding operation mode.

      @Preconditions
        OC6_Initialize function should have been called 

      @Param
        None.

      @Returns
        None.

      @Example 
        Refer to OC6_Initialize() for an example	
 
     */
    void OC6_Start(void);

    /**
        void DRV_OC6_Start(void)
     */
    void DRV_OC6_Start(void) __attribute__((deprecated("\nThis will be removed in future MCC releases. \nUse OC6_Start instead. ")));

    /**
      @Summary
        Disables the OC module.

      @Description
        This routine disables the OC module.

      @Preconditions
        OC6_Initialize function should have been called 

      @Param
        None.

      @Returns
        None.

     */
    void OC6_Stop(void);

    /**
        void DRV_OC6_Stop(void)
     */
    void DRV_OC6_Stop(void) __attribute__((deprecated("\nThis will be removed in future MCC releases. \nUse OC6_Stop instead. ")));

    /**
      @Summary
        Sets the primary compare value.

      @Description
        This routine sets the primary compare value.

      @Preconditions
        OC6_Initialize function should have been called 

      @Param
        None.

      @Returns
        None.

      @Example 
        <code>
            uint16_t value = 0x1000;
            OC6_SingleCompareValueSet( value );
        <code>
     */

    void OC6_SingleCompareValueSet(uint16_t value);

    /**
        void DRV_OC6_SingleCompareValueSet(uint16_t value)
     */
    void DRV_OC6_SingleCompareValueSet(uint16_t value) __attribute__((deprecated("\nThis will be removed in future MCC releases. \nUse OC6_SingleCompareValueSet instead. ")));

    /**
      @Summary
        Sets the primary and secondary compare value.

      @Description
        This routine sets the primary and secondary compare value.

      @Preconditions
        OC6_Initialize function should have been called 

      @Param
        priVal - 16 bit primary compare value.
        secVal - 16 bit primary compare value.	

      @Returns
        None.

      @Example 
        <code>
            uint16_t priVal = 0x1000;
            uint16_t secVal = 0x2000;
            OC6_DualCompareValueSet( priVal,secVal );
        <code>
  	
     */

    void OC6_DualCompareValueSet(uint16_t priVal, uint16_t secVal);

    /**
        void DRV_OC6_DualCompareValueSet(uint16_t priVal, uint16_t secVal)
     */
    void DRV_OC6_DualCompareValueSet(uint16_t priVal, uint16_t secVal) __attribute__((deprecated("\nThis will be removed in future MCC releases. \nUse OC6_DualCompareValueSet instead. ")));

    /**
      @Summary
        Sets the primary and secondary compare value for Center Aligned PWM

      @Description
        This routine sets the primary and secondary compare value for Center Aligned PWM.

      @Preconditions
        OC6_Initialize function should have been called 

      @Param
        priVal - 16 bit primary compare value.
        secVal - 16 bit primary compare value.	
	
      @Returns
        None.

      @Example 
        Refer to OC6_Initialize() for an example

     */
    void OC6_CentreAlignedPWMConfig(uint16_t priVal, uint16_t secVal);

    /**
        void DRV_OC6_CentreAlignedPWMConfig(uint16_t priVal, uint16_t secVal)
     */
    void DRV_OC6_CentreAlignedPWMConfig(uint16_t priVal, uint16_t secVal) __attribute__((deprecated("\nThis will be removed in future MCC releases. \nUse OC6_CentreAlignedPWMConfig instead. ")));

    /**
      @Summary
        Sets the primary and secondary compare value for Edge Aligned PWM.

      @Description
        This routine sets the primary and secondary compare value for Edge Aligned PWM.

      @Preconditions
        OC6_Initialize function should have been called 

      @Param
        priVal - 16 bit primary compare value.
        secVal - 16 bit primary compare value.	

      @Returns
        None.

      @Example 
        <code>
            uint16_t priVal = 0x1000;
            uint16_t secVal = 0x2000;
            OC6_EdgeAlignedPWMConfig( priVal,secVal );
        <code> 
 	
     */
    void OC6_EdgeAlignedPWMConfig(uint16_t priVal, uint16_t secVal);

    /**
        void DRV_OC6_EdgeAlignedPWMConfig(uint16_t priVal, uint16_t secVal)
     */
    void DRV_OC6_EdgeAlignedPWMConfig(uint16_t priVal, uint16_t secVal) __attribute__((deprecated("\nThis will be removed in future MCC releases. \nUse OC6_EdgeAlignedPWMConfig instead. ")));

    /**
      @Summary
        Gets the status of the compare cycle completion.

      @Description
        This routine gets the status of the compare cycle completion.

      @Preconditions
        OC6_Initialize function should have been called 

      @Param
        None.

      @Returns
        Boolean value describing the current status of the cycle completion. Returns
        true  : When the compare cycle has completed. 
        false : When the compare cycle has not completed. 

      @Example 
        Refer to OC6_Initialize() for an example
	

     */
    bool OC6_IsCompareCycleComplete(void);

    /**
        bool DRV_OC6_IsCompareCycleComplete(void)
     */
    bool DRV_OC6_IsCompareCycleComplete(void) __attribute__((deprecated("\nThis will be removed in future MCC releases. \nUse OC6_IsCompareCycleComplete instead. ")));

    /**
      @Summary
        Gets the status of the PWM fault condition occurrence.

      @Description
        This routine gets the status of the PWM fault condition occurrence.
  
      @Preconditions
        OC6_Initialize function should have been called 

      @Param
        faultNum - The fault number

      @Returns
        boolean value describing the occurrence of the fault condition.
        true  : When the specified fault has occurred.
        false : When the specified fault has not occurred.
	
      @Example 
        Refer to OC6_Initialize() for an example 
 

     */
    bool OC6_FaultStatusGet(OC6_FAULTS faultNum);

    /**
        bool DRV_OC6_FaultStatusGet(DRV_OC6_FAULTS faultNum)
     */
    bool DRV_OC6_FaultStatusGet(DRV_OC6_FAULTS faultNum) __attribute__((deprecated("\nThis will be removed in future MCC releases. \nUse OC6_FaultStatusGet instead. ")));

    /**
      @Summary
        Clears the status of the PWM fault condition occurrence.

      @Description
        This routine clears the status of the PWM fault condition occurrence.
	
      @Preconditions
        None.	

      @Param
        faultNum - The fault number
  
      @Returns
        None.

      @Example 
        Refer to OC6_Initialize() for an example 
  	
     */
    void OC6_FaultStatusClear(OC6_FAULTS faultNum);

    /**
        void DRV_OC6_FaultStatusClear(DRV_OC6_FAULTS faultNum)
     */
    void DRV_OC6_FaultStatusClear(DRV_OC6_FAULTS faultNum) __attribute__((deprecated("\nThis will be removed in future MCC releases. \nUse OC6_FaultStatusClear instead. ")));

    /**
      @Summary
        Sets the manual trigger

      @Description
        This routine sets the manual trigger
	
      @Preconditions
        OC6_Initialize function should have been called 

      @Param
        None
 
      @Returns
        None.
	
      @Example 
        Refer to OC6_TriggerStatusGet() for an example	
 
     */
    void OC6_ManualTriggerSet(void);

    /**
      @Summary
        Gets the status of the timer trigger.

      @Description
        This routine gets the status of the timer trigger source if it has been triggered.
	
      @Preconditions
        OC6_Initialize function should have been called 
	
      @Param
        None
	
      @Returns
        Boolean value describing the timer trigger status.
        true  : When the timer source has triggered and is running 
        false : When the timer has not triggered and being held clear 

      @Example 
        <\code>	
        if(OC6_TriggerStatusGet())
        {
            OC6_TriggerStatusClear();
        }
        <\code>	
     */
    bool OC6_TriggerStatusGet(void);

    /**
        bool DRV_OC6_TriggerStatusGet(void)
     */
    bool DRV_OC6_TriggerStatusGet(void) __attribute__((deprecated("\nThis will be removed in future MCC releases. \nUse OC6_TriggerStatusGet instead. ")));

    /**
      @Summary
        Clears the status of the timer trigger.

      @Description
        This routine clears the status of the timer trigger.
	
      @Preconditions
        OC6_Initialize function should have been called

      @Param
        None
	
      @Returns
        None.
	
      @Example 
        Refer to OC6_TriggerStatusGet() for an example	

     */
    void OC6_TriggerStatusClear(void);

    /**
        void DRV_OC6_TriggerStatusClear(void)
     */
    void DRV_OC6_TriggerStatusClear(void) __attribute__((deprecated("\nThis will be removed in future MCC releases. \nUse OC6_TriggerStatusClear instead. ")));
#ifdef __cplusplus  // Provide C++ Compatibility

}

#endif

#endif //_OC6_H

/**
 End of File
 */
