/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.4
        Device            :  PIC18F25K42
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"
#include "buffers.h"
/*
 * Values from sanispray
    Timer0 = 1 s
    Timer1 = 38.016 ms = 0xFB5C 1:1 divide
    8 bit, MF_INT_31.25KHz, Enable Gate, Gate signal T1G_pin Polarity= low
    Timer2 = 1 s, roll over pulse, Software control,
             LF_INT, Rising edge, pre 1:128, post 1:3
    Timer3 = 10ms
    Timer4 = 5 s
    Timer5 = 16 s
    Timer6 = 1 s
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    PWRKEY_SetHigh();
    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    INTERRUPT_GlobalInterruptDisable();
    IOCCF6_SetInterruptHandler(SonarInt);
//    UART2_SetRxInterruptHandler()
    PIE6bits.U2RXIE = 0;
    PIE4bits.TMR2IE = 0;
    PIE0bits.IOCIE = 0;
    gsm_init(0);
    gsmbyte = Get_Signal();
    gsmbyte = Get_Battery();
    vendprice = ReadDistance();//Returns distance from 2 up to 400cm, 65535 = timeout and 1 = no device
    TMR6_Initialize();
    T6CONbits.TMR6ON = 1;
    distantcount = 0;
    memset(distant, 0, sizeof(distant));
    while (1)
    {
        if(TMR6_HasOverflowOccured())
        {
            T6CONbits.TMR6ON = 0;
            vendprice = ReadDistance();
            distant[distantcount] = vendprice;
            distantcount++;
            if(distantcount >= 512)
            {

                distantcount = 0;
                memset(distant, 0, sizeof(distant));
                gsmbyte = Get_Battery();
            }
            TMR6_Initialize();
            T6CONbits.TMR6ON = 1;
        }
    }
    asm("RESET");
    Call_Home();
    Call_Me();
    Read_SMS();
}
/**
 End of File
*/