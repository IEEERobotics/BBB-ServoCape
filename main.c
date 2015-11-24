/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using MPLAB® Code Configurator

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB® Code Configurator - v2.25.2
        Device            :  PIC24FJ64GB202
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.24
        MPLAB             :  MPLAB X v2.35 or v3.00
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

#include "mcc_generated_files/mcc.h"

/*
                         Main application
 * 
 * 
 * 
 */
//Variables
//=======================================================================
int TimerVariable = 0;    //Increments every .1 second  see tmr1.c callback function 
int S1 = 0;               //Increments with every switch one press~State variable 
int S2 = 0;               //Increments with every switch two press 
int cycles; 

//Functions
//=======================================================================
void debounce(int);      // Debounce function which waits multiples of .1 seconds
void StateMaker(int);    // Blinker of LEDs to show state 
void MakeSelection(int);//Calls functions based on state 
void TestRange();
void TestServo1();       //State 1 function 
void TestServo2();       //State 2 function
void TestServo3();       //State 3 function
void TestServo4();       //State 4 function
void TestServo5();       //State 5 function
void TestServo6();       //State 6 function
void Jog();

int main(void) {
    // initialize the device
    SYSTEM_Initialize();
    
    
    debounce(2);
    PORTAbits.RA3 = 0;
    debounce(1);
    PORTAbits.RA1 = 0; 
    debounce(1);
    PORTBbits.RB5 = 0; 
    debounce(1);
    PORTBbits.RB7 = 0; 
    debounce(1);
    PORTBbits.RB6 = 0; 
    debounce(1);
    
    while (1) {
        
        if(PORTAbits.RA0 == 1){        //S1 pressed
            S1++; 
            
            if(S1==9)
                                     //Overflow Condition~No State 9
                S1 = 1; 
            
            debounce(10);
            
            StateMaker(S1);         //Set the LEDs 
        }
        
        if(PORTAbits.RA2 == 1){
            
            PORTBbits.RB6 = 1;        //Signifies selection with blinking of light
            debounce(5);
            PORTBbits.RB6 = 0;
            debounce(3); 
            PORTBbits.RB6 = 1;
            debounce(2);
            PORTBbits.RB6 = 0;
            debounce(1); 
            PORTBbits.RB6 = 1;
            
            MakeSelection(S1); 
            
            PORTBbits.RB6 = 1;        //Signifies selection with blinking of light
            debounce(5);
            PORTBbits.RB6 = 0;
            debounce(3); 
            PORTBbits.RB6 = 1;
            debounce(2);
            PORTBbits.RB6 = 0;
            debounce(1); 
            PORTBbits.RB6 = 1;
            debounce(1);
            PORTBbits.RB6 = 0; 
            
            
        }
    }

    return -1;
}



void debounce(int cycles){
    
    TimerVariable = 0;
    
    while(TimerVariable <= cycles);
    
}

void StateMaker(S1){
    
    switch(S1){
        case 1:  PORTBbits.RB7 = 0;
                 PORTAbits.RA1 = 1;
                 debounce(1); 
                 PORTAbits.RA3 = 0; 
                 break;
        case 2:  PORTAbits.RA1 = 0;
                 debounce(1);
                 PORTAbits.RA3 = 1; 
                 break;
        case 3:  PORTAbits.RA1 = 1;
                 debounce(1);
                 PORTAbits.RA3 = 1; 
                 break;   
        case 4:  PORTAbits.RA1 = 0;
                 debounce(1);
                 PORTAbits.RA3 = 0;
                 debounce(1);  
                 PORTBbits.RB7 = 1;
                 break;
        case 5:  PORTAbits.RA1 = 1;
                 debounce(1);
                 PORTAbits.RA3 = 0;
                 debounce(1);  
                 PORTBbits.RB7 = 1;
                 break;
        case 6:  PORTAbits.RA1 = 0;
                 debounce(1);
                 PORTAbits.RA3 = 1;
                 debounce(1);  
                 PORTBbits.RB7 = 1;
                 break;
        case 7:  PORTAbits.RA1 = 1; 
                 debounce(1);
                 break;
        case 8:  PORTAbits.RA1 = 0;
                 debounce(1); 
                 PORTAbits.RA3 = 0; 
                 debounce(1);
                 PORTBbits.RB7 = 0; 
                 debounce(1); 
                 PORTBbits.RB5 = 1; 
                 break;
        
    }
}


void MakeSelection(S1){
    
    switch(S1){
        case 1:  TestServo1();
                 debounce(1); 
                 break;
        case 2:  TestServo2();
                 debounce(1);
                 break;
        case 3:  TestServo3();
                 debounce(1);
                  break;   
        case 4:  TestServo4();
                 debounce(1);
                 break;
        case 5:  TestServo5();
                 debounce(1);
                 break;
        case 6:  TestServo6();
                 debounce(1);
                 break;
        case 7:  TestRange();
                 debounce(1);
        case 8:  Jog();
                 debounce(1);
                 
        
    }
}

void Jog(){
    OC1R = 0x150;
    debounce(1);
    OC2R = 0x392;
    debounce(1);
    OC3R = 0x392;
    debounce(1);
    OC4R = 0x392;
    debounce(1);
    OC5R = 0x392;
    debounce(1);
    OC6R = 0x392;
    debounce(100);
    
    OC1R = 0x392;
    debounce(1);
    OC2R = 0x2F6;
    debounce(1);
    OC3R = 0x2F6;
    debounce(1);
    OC4R = 0x2F6;
    debounce(1);
    OC5R = 0x392;
    debounce(1);
    OC6R = 0x392;
}
void TestRange(){
    while(1){
    OC1R = 0xDA;                //0 degree value 
    while(OC1R <= 0x490){          //180 degree value
          OC1R += 0x10; 
          debounce(1);
    }
    
    
    while(OC1R >= 0xE0){        //180 degree value 
        OC1R -= 0x10;
        debounce(1);
    }
    }
}

void TestServo1(){
    OC1R = 0xE7 ;
    while(OC1R <= 0x500){
        OC1R = OC1R + 0x10; 
        debounce(1); 
    }
}

void TestServo2(){
    OC2R = 0xE7 ;
    while(OC2R <= 0x500){
        OC2R += 0x10; 
        debounce(1); 
    }
}


void TestServo3(){
    OC3R = 0xE7;  
    while(OC3R <= 0x500){
        OC3R += 0x10; 
        debounce(1); 
    }
}


void TestServo4(){
    OC4R = 0xE7; 
    while(OC4R <= 0x500){
        OC4R += 0x32; 
        debounce(1); 
    }
}


void TestServo5(){
    OC5R = 0x110;  
    while(OC5R <= 0x465){
        OC5R += 0x10; 
        debounce(1); 
    }
}


void TestServo6(){
    OC5R = 0x150;
    while(OC6R <= 0x465){
        OC6R += 0x10; 
        debounce(1); 
    }
}

/**
 End of File
 */