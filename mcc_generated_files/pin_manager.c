/**
  Generated Pin Manager File

  Company:
    Microchip Technology Inc.

  File Name:
    pin_manager.c

  Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.4
        Device            :  PIC18F25K42
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.20 and above
        MPLAB             :  MPLAB X 5.40

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "pin_manager.h"




void (*IOCCF6_InterruptHandler)(void);


void PIN_MANAGER_Initialize(void)
{
    /**
    LATx registers
    */
    LATA = 0x00;
    LATB = 0x01;
    LATC = 0x00;

    /**
    TRISx registers
    */
    TRISA = 0x5F;
    TRISB = 0xE4;
    TRISC = 0x7E;

    /**
    ANSELx registers
    */
    ANSELC = 0xB8;
    ANSELB = 0xC3;
    ANSELA = 0xFE;

    /**
    WPUx registers
    */
    WPUE = 0x00;
    WPUB = 0x00;
    WPUA = 0x89;
    WPUC = 0x44;

    /**
    RxyI2C registers
    */
    RB1I2C = 0x00;
    RB2I2C = 0x00;
    RC3I2C = 0x00;
    RC4I2C = 0x00;

    /**
    ODx registers
    */
    ODCONA = 0x40;
    ODCONB = 0x13;
    ODCONC = 0x81;

    /**
    SLRCONx registers
    */
    SLRCONA = 0xFF;
    SLRCONB = 0xFF;
    SLRCONC = 0xFF;

    /**
    INLVLx registers
    */
    INLVLA = 0xFF;
    INLVLB = 0xFF;
    INLVLC = 0xFF;
    INLVLE = 0x08;


    /**
    IOCx registers 
    */
    //interrupt on change for group IOCCF - flag
    IOCCFbits.IOCCF6 = 0;
    //interrupt on change for group IOCCN - negative
    IOCCNbits.IOCCN6 = 1;
    //interrupt on change for group IOCCP - positive
    IOCCPbits.IOCCP6 = 1;



    // register default IOC callback functions at runtime; use these methods to register a custom function
    IOCCF6_SetInterruptHandler(IOCCF6_DefaultInterruptHandler);
   
    // Enable IOCI interrupt 
    PIE0bits.IOCIE = 1; 
    
	
    U2RXPPS = 0x0A;   //RB2->UART2:RX2;    
    RB1PPS = 0x16;   //RB1->UART2:TX2;    
}
  
void PIN_MANAGER_IOC(void)
{   
	// interrupt on change for pin IOCCF6
    if(IOCCFbits.IOCCF6 == 1)
    {
        IOCCF6_ISR();  
    }	
}

/**
   IOCCF6 Interrupt Service Routine
*/
void IOCCF6_ISR(void) {

    // Add custom IOCCF6 code

    // Call the interrupt handler for the callback registered at runtime
    if(IOCCF6_InterruptHandler)
    {
        IOCCF6_InterruptHandler();
    }
    IOCCFbits.IOCCF6 = 0;
}

/**
  Allows selecting an interrupt handler for IOCCF6 at application runtime
*/
void IOCCF6_SetInterruptHandler(void (* InterruptHandler)(void)){
    IOCCF6_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for IOCCF6
*/
void IOCCF6_DefaultInterruptHandler(void){
    // add your IOCCF6 interrupt custom code
    // or set custom function using IOCCF6_SetInterruptHandler()
}

/**
 End of File
*/