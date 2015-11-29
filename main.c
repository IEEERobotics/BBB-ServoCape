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
int Timer2Variable = 0;
int S1 = 1;               //Increments with every switch one press~State variable 
int TransmitComplete = 0;               //Increments with every switch two press 
int cycles; 
uint8_t LocalMemory[5]; 
int i = 0;  

//Functions
//=======================================================================
void debounce(int);      // Debounce function which waits multiples of .1 seconds
void FastDebounce(int); 
void StateMaker(int);    // Blinker of LEDs to show state 
void MakeSelection(int);//Calls functions based on state 
void MoveServo1_Degrees(int);
void MoveServo2_Degrees(int);
void MoveServo3_Degrees(int);
void MoveServo4_Degrees(int);
void MoveServo5_Degrees(int);
void ResetMemory();
void SetTo90();
void SetTo180();
void SetTo0();
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
    PORTAbits.RA1 = 1; 
    debounce(1);
    PORTBbits.RB5 = 0; 
    debounce(1);
    PORTBbits.RB7 = 0; 
    debounce(1);
    PORTBbits.RB6 = 0; 
    debounce(1);
    
    ResetMemory();
    
    while (1) {
        
        if(TransmitComplete){
            TransmitComplete = 0; 
            MoveServo1_Degrees(LocalMemory[0]); 
            debounce(1);
            MoveServo2_Degrees(LocalMemory[0]);
            debounce(1);
            MoveServo3_Degrees(LocalMemory[0]);
            debounce(1);
            MoveServo4_Degrees(LocalMemory[0]);
            debounce(1);
            MoveServo5_Degrees(LocalMemory[0]);
            
            
        }
        
        if(PORTAbits.RA0 == 1){        //S1 pressed
            S1++; 
            
            if(S1==10)
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
                 debounce(1);
                 PORTBbits.RB5 = 0;
                 debounce(1);
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
        case 9:  PORTAbits.RA1 = 1;
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
        case 7:  SetTo90();
                 debounce(1);
                 break;
        case 8:  SetTo0();
                 debounce(1);
                 break;
        case 9:  SetTo180();
                 break;
                 
        
    }
}

void SetTo180(){
    
    OC1R = 0x495;       
    debounce(2);
    OC2R = 0x200;
    debounce(2);
    OC3R = 0x505;
    debounce(2);
    OC4R = 0x300;
    debounce(2);
    OC2R = 0x505;
    debounce(2);
    OC4R = 0x500;
    
    debounce(100);
    
    
     
}
void SetTo90(){
                      ///Actually sets to vertically straight not 90 for each servo 
    OC1R = 0xE0;       
    debounce(2);
    OC4R = 0x2F6;
    debounce(2);
    OC2R = 0x1FF;
    debounce(2);
    OC3R = 0x320;
    debounce(2);
    OC2R = 0x320;
    debounce(5);
     
 
}

void SetTo0(){
    
    OC1R = 0xE0;
    debounce(2);
    OC4R = 0x150;
    debounce(2);
    OC2R = 0xE0;
    debounce(2);
    OC4R = 0xE0; 
    debounce(2);
    OC3R = 0xE0;
    debounce(2);
    OC2R = 0xE0;
    debounce(5);
}


void MoveServo1_Degrees(int degrees){
    double currentposition = OC1R; 
    int desiredposition = 0xE0 + (degrees*5.867);         
  
    
    if(currentposition > desiredposition){           //moving negative angles
        while(currentposition >= desiredposition ){
            OC1R = (int)currentposition;
            FastDebounce(5);
            currentposition -= 5.867;
        }
       
    }
    else if(currentposition < desiredposition){
        while(currentposition <= desiredposition ){
            OC1R = currentposition;
            FastDebounce(5);
            currentposition += 0x06;
        }
        
    }
   
    OC1R = desiredposition; 
}     
                       

void MoveServo2_Degrees(int degrees){
    int currentposition = OC2R; 
    int desiredposition = 0xEF + degrees*0x06;  
    int neededchange = desiredposition - currentposition;  
    int stepsize ;  
    
    if(currentposition > desiredposition){           //moving negative angles
        while(currentposition >= desiredposition ){
            OC2R = currentposition;
            FastDebounce(10);
            currentposition -= 0x06;
        }
       
    }
    else if(currentposition < desiredposition){
        while(currentposition <= desiredposition ){
            OC2R = currentposition;
            FastDebounce(10);
            currentposition += 0x06;
        }
        
    }
    
     
                       
    
    
    
}


void MoveServo3_Degrees(int degrees){
    int currentposition = OC3R; 
    int desiredposition = 0xEF + degrees*0x06;  
    int neededchange = desiredposition - currentposition;  
    int stepsize ;  
    
    if(currentposition > desiredposition){           //moving negative angles
        while(currentposition >= desiredposition ){
            OC3R = currentposition;
            FastDebounce(10);
            currentposition -= 0x06;
        }
       
    }
    else if(currentposition < desiredposition){
        while(currentposition <= desiredposition ){
            OC3R = currentposition;
            FastDebounce(10);
            currentposition += 0x06;
        }
        
    }
   
    
     
                       
    
    
    
}


void MoveServo4_Degrees(int degrees){
    int currentposition = OC4R; 
    int desiredposition = 0xEF + degrees*0x06;  
    int neededchange = desiredposition - currentposition;  
    int stepsize ;  
    
    if(currentposition > desiredposition){           //moving negative angles
        while(currentposition >= desiredposition ){
            OC4R = currentposition;
            FastDebounce(10);
            currentposition -= 0x06;
        }
       
    }
    else if(currentposition < desiredposition){
        while(currentposition <= desiredposition ){
            OC4R = currentposition;
            FastDebounce(10);
            currentposition += 0x06;
        }
        
    }
   
    
    
}


void MoveServo5_Degrees(int degrees){
    int currentposition = OC5R; 
    int desiredposition = 0x110 + degrees*0x04;  
    int neededchange = desiredposition - currentposition;  
    int stepsize = neededchange/10;  
    
    if(currentposition > desiredposition){           //moving negative angles
        while(currentposition >= desiredposition ){
            currentposition += stepsize;
            OC5R = currentposition;
            debounce(1);
        }
    }
    else if(currentposition < desiredposition){
        while(currentposition <= desiredposition ){
            currentposition += stepsize;
            OC5R = currentposition;
            debounce(1);
        }
    }
   
    
     
                       
    
    
    
}


    
    

    
    
void Jog(){
    
    MoveServo1_Degrees(0); 
    MoveServo2_Degrees(0);
    MoveServo3_Degrees(0);
    
    debounce(5);
 
    
  

    debounce(100);
    

    /*
    while(1){
        while(OC6R<0x450){
            OC6R++;
            FastDebounce(1);
            
        }
        
        while(OC6R>0x200){
            OC6R--; 
            FastDebounce(1);
            
        }
        OC1R--;
        
        if(OC1R )*/
    
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
    MoveServo1_Degrees(0);
    debounce(100);
    MoveServo1_Degrees(180);
    debounce(100);
    MoveServo1_Degrees(90);
    
}

void TestServo2(){
    MoveServo2_Degrees(0);
    debounce(100);
    MoveServo2_Degrees(180);
    debounce(100);
    MoveServo2_Degrees(90);
    
}


void TestServo3(){
    MoveServo3_Degrees(0);
    debounce(100);
    MoveServo3_Degrees(180);
    debounce(100);
    MoveServo3_Degrees(90);
    
}


void TestServo4(){
    MoveServo4_Degrees(0);
    debounce(100);
    MoveServo4_Degrees(180);
    debounce(100);
    MoveServo4_Degrees(90);
    
}


void TestServo5(){
    OC5R = 0x110;  
    while(OC5R <= 0x465){
        OC5R += 0x10; 
        debounce(1); 
    }
}


void TestServo6(){
    
    OC6R = 0x400;
    while(OC6R >= 0x275){
        OC6R -= 0x10; 
        debounce(1); 
    }
}

void ResetMemory(){
    
    int ResetIndex = 0; 
    
    while(ResetIndex<6)
        LocalMemory[ResetIndex++] = 0x01; 
    
    ResetIndex = 0;
}

void FastDebounce(int cycles){
    
    Timer2Variable = 0;
    while(Timer2Variable <= cycles); 
    
}
/*
 End of File
 */