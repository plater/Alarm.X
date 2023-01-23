/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.4
        Device            :  PIC18F25K42
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.20 and above
        MPLAB 	          :  MPLAB X 5.40	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA0 procedures
#define RA0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define RA0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define RA0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define RA0_GetValue()              PORTAbits.RA0
#define RA0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define RA0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define RA0_SetPullup()             do { WPUAbits.WPUA0 = 1; } while(0)
#define RA0_ResetPullup()           do { WPUAbits.WPUA0 = 0; } while(0)
#define RA0_SetAnalogMode()         do { ANSELAbits.ANSELA0 = 1; } while(0)
#define RA0_SetDigitalMode()        do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set BUZZER aliases
#define BUZZER_TRIS                 TRISAbits.TRISA1
#define BUZZER_LAT                  LATAbits.LATA1
#define BUZZER_PORT                 PORTAbits.RA1
#define BUZZER_WPU                  WPUAbits.WPUA1
#define BUZZER_OD                   ODCONAbits.ODCA1
#define BUZZER_ANS                  ANSELAbits.ANSELA1
#define BUZZER_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define BUZZER_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define BUZZER_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define BUZZER_GetValue()           PORTAbits.RA1
#define BUZZER_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define BUZZER_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define BUZZER_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define BUZZER_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define BUZZER_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define BUZZER_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define BUZZER_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define BUZZER_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set LED aliases
#define LED_TRIS                 TRISAbits.TRISA2
#define LED_LAT                  LATAbits.LATA2
#define LED_PORT                 PORTAbits.RA2
#define LED_WPU                  WPUAbits.WPUA2
#define LED_OD                   ODCONAbits.ODCA2
#define LED_ANS                  ANSELAbits.ANSELA2
#define LED_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define LED_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define LED_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define LED_GetValue()           PORTAbits.RA2
#define LED_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define LED_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define LED_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define LED_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define LED_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define LED_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define LED_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set SERVICE aliases
#define SERVICE_TRIS                 TRISAbits.TRISA3
#define SERVICE_LAT                  LATAbits.LATA3
#define SERVICE_PORT                 PORTAbits.RA3
#define SERVICE_WPU                  WPUAbits.WPUA3
#define SERVICE_OD                   ODCONAbits.ODCA3
#define SERVICE_ANS                  ANSELAbits.ANSELA3
#define SERVICE_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define SERVICE_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define SERVICE_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define SERVICE_GetValue()           PORTAbits.RA3
#define SERVICE_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define SERVICE_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define SERVICE_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define SERVICE_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define SERVICE_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define SERVICE_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define SERVICE_SetAnalogMode()      do { ANSELAbits.ANSELA3 = 1; } while(0)
#define SERVICE_SetDigitalMode()     do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set CNEN aliases
#define CNEN_TRIS                 TRISAbits.TRISA4
#define CNEN_LAT                  LATAbits.LATA4
#define CNEN_PORT                 PORTAbits.RA4
#define CNEN_WPU                  WPUAbits.WPUA4
#define CNEN_OD                   ODCONAbits.ODCA4
#define CNEN_ANS                  ANSELAbits.ANSELA4
#define CNEN_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define CNEN_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define CNEN_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define CNEN_GetValue()           PORTAbits.RA4
#define CNEN_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define CNEN_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define CNEN_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define CNEN_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define CNEN_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define CNEN_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define CNEN_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define CNEN_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set COIN aliases
#define COIN_TRIS                 TRISAbits.TRISA5
#define COIN_LAT                  LATAbits.LATA5
#define COIN_PORT                 PORTAbits.RA5
#define COIN_WPU                  WPUAbits.WPUA5
#define COIN_OD                   ODCONAbits.ODCA5
#define COIN_ANS                  ANSELAbits.ANSELA5
#define COIN_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define COIN_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define COIN_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define COIN_GetValue()           PORTAbits.RA5
#define COIN_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define COIN_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define COIN_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define COIN_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define COIN_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define COIN_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define COIN_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define COIN_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set BUTTON1 aliases
#define BUTTON1_TRIS                 TRISAbits.TRISA6
#define BUTTON1_LAT                  LATAbits.LATA6
#define BUTTON1_PORT                 PORTAbits.RA6
#define BUTTON1_WPU                  WPUAbits.WPUA6
#define BUTTON1_OD                   ODCONAbits.ODCA6
#define BUTTON1_ANS                  ANSELAbits.ANSELA6
#define BUTTON1_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define BUTTON1_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define BUTTON1_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define BUTTON1_GetValue()           PORTAbits.RA6
#define BUTTON1_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define BUTTON1_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define BUTTON1_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define BUTTON1_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define BUTTON1_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define BUTTON1_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define BUTTON1_SetAnalogMode()      do { ANSELAbits.ANSELA6 = 1; } while(0)
#define BUTTON1_SetDigitalMode()     do { ANSELAbits.ANSELA6 = 0; } while(0)

// get/set BUTTON2 aliases
#define BUTTON2_TRIS                 TRISAbits.TRISA7
#define BUTTON2_LAT                  LATAbits.LATA7
#define BUTTON2_PORT                 PORTAbits.RA7
#define BUTTON2_WPU                  WPUAbits.WPUA7
#define BUTTON2_OD                   ODCONAbits.ODCA7
#define BUTTON2_ANS                  ANSELAbits.ANSELA7
#define BUTTON2_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define BUTTON2_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define BUTTON2_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define BUTTON2_GetValue()           PORTAbits.RA7
#define BUTTON2_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define BUTTON2_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define BUTTON2_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define BUTTON2_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define BUTTON2_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define BUTTON2_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define BUTTON2_SetAnalogMode()      do { ANSELAbits.ANSELA7 = 1; } while(0)
#define BUTTON2_SetDigitalMode()     do { ANSELAbits.ANSELA7 = 0; } while(0)

// get/set MOTOR1 aliases
#define MOTOR1_TRIS                 TRISBbits.TRISB0
#define MOTOR1_LAT                  LATBbits.LATB0
#define MOTOR1_PORT                 PORTBbits.RB0
#define MOTOR1_WPU                  WPUBbits.WPUB0
#define MOTOR1_OD                   ODCONBbits.ODCB0
#define MOTOR1_ANS                  ANSELBbits.ANSELB0
#define MOTOR1_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define MOTOR1_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define MOTOR1_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define MOTOR1_GetValue()           PORTBbits.RB0
#define MOTOR1_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define MOTOR1_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define MOTOR1_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define MOTOR1_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define MOTOR1_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define MOTOR1_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define MOTOR1_SetAnalogMode()      do { ANSELBbits.ANSELB0 = 1; } while(0)
#define MOTOR1_SetDigitalMode()     do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set MDBTX aliases
#define MDBTX_TRIS                 TRISBbits.TRISB1
#define MDBTX_LAT                  LATBbits.LATB1
#define MDBTX_PORT                 PORTBbits.RB1
#define MDBTX_WPU                  WPUBbits.WPUB1
#define MDBTX_OD                   ODCONBbits.ODCB1
#define MDBTX_ANS                  ANSELBbits.ANSELB1
#define MDBTX_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define MDBTX_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define MDBTX_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define MDBTX_GetValue()           PORTBbits.RB1
#define MDBTX_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define MDBTX_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define MDBTX_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define MDBTX_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define MDBTX_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define MDBTX_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define MDBTX_SetAnalogMode()      do { ANSELBbits.ANSELB1 = 1; } while(0)
#define MDBTX_SetDigitalMode()     do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set MDBRX aliases
#define MDBRX_TRIS                 TRISBbits.TRISB2
#define MDBRX_LAT                  LATBbits.LATB2
#define MDBRX_PORT                 PORTBbits.RB2
#define MDBRX_WPU                  WPUBbits.WPUB2
#define MDBRX_OD                   ODCONBbits.ODCB2
#define MDBRX_ANS                  ANSELBbits.ANSELB2
#define MDBRX_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define MDBRX_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define MDBRX_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define MDBRX_GetValue()           PORTBbits.RB2
#define MDBRX_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define MDBRX_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define MDBRX_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define MDBRX_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define MDBRX_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define MDBRX_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define MDBRX_SetAnalogMode()      do { ANSELBbits.ANSELB2 = 1; } while(0)
#define MDBRX_SetDigitalMode()     do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set IO_RB3 aliases
#define IO_RB3_TRIS                 TRISBbits.TRISB3
#define IO_RB3_LAT                  LATBbits.LATB3
#define IO_RB3_PORT                 PORTBbits.RB3
#define IO_RB3_WPU                  WPUBbits.WPUB3
#define IO_RB3_OD                   ODCONBbits.ODCB3
#define IO_RB3_ANS                  ANSELBbits.ANSELB3
#define IO_RB3_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define IO_RB3_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define IO_RB3_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define IO_RB3_GetValue()           PORTBbits.RB3
#define IO_RB3_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define IO_RB3_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define IO_RB3_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define IO_RB3_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define IO_RB3_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define IO_RB3_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define IO_RB3_SetAnalogMode()      do { ANSELBbits.ANSELB3 = 1; } while(0)
#define IO_RB3_SetDigitalMode()     do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set IO_RB4 aliases
#define IO_RB4_TRIS                 TRISBbits.TRISB4
#define IO_RB4_LAT                  LATBbits.LATB4
#define IO_RB4_PORT                 PORTBbits.RB4
#define IO_RB4_WPU                  WPUBbits.WPUB4
#define IO_RB4_OD                   ODCONBbits.ODCB4
#define IO_RB4_ANS                  ANSELBbits.ANSELB4
#define IO_RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define IO_RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define IO_RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define IO_RB4_GetValue()           PORTBbits.RB4
#define IO_RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define IO_RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define IO_RB4_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define IO_RB4_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define IO_RB4_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define IO_RB4_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define IO_RB4_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define IO_RB4_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set IO_RB5 aliases
#define IO_RB5_TRIS                 TRISBbits.TRISB5
#define IO_RB5_LAT                  LATBbits.LATB5
#define IO_RB5_PORT                 PORTBbits.RB5
#define IO_RB5_WPU                  WPUBbits.WPUB5
#define IO_RB5_OD                   ODCONBbits.ODCB5
#define IO_RB5_ANS                  ANSELBbits.ANSELB5
#define IO_RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define IO_RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define IO_RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define IO_RB5_GetValue()           PORTBbits.RB5
#define IO_RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define IO_RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define IO_RB5_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define IO_RB5_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define IO_RB5_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define IO_RB5_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define IO_RB5_SetAnalogMode()      do { ANSELBbits.ANSELB5 = 1; } while(0)
#define IO_RB5_SetDigitalMode()     do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set RC0 procedures
#define RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RC0_GetValue()              PORTCbits.RC0
#define RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define RC0_SetPullup()             do { WPUCbits.WPUC0 = 1; } while(0)
#define RC0_ResetPullup()           do { WPUCbits.WPUC0 = 0; } while(0)
#define RC0_SetAnalogMode()         do { ANSELCbits.ANSELC0 = 1; } while(0)
#define RC0_SetDigitalMode()        do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set RC1 procedures
#define RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RC1_GetValue()              PORTCbits.RC1
#define RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define RC1_SetPullup()             do { WPUCbits.WPUC1 = 1; } while(0)
#define RC1_ResetPullup()           do { WPUCbits.WPUC1 = 0; } while(0)
#define RC1_SetAnalogMode()         do { ANSELCbits.ANSELC1 = 1; } while(0)
#define RC1_SetDigitalMode()        do { ANSELCbits.ANSELC1 = 0; } while(0)

// get/set SPARE aliases
#define SPARE_TRIS                 TRISCbits.TRISC2
#define SPARE_LAT                  LATCbits.LATC2
#define SPARE_PORT                 PORTCbits.RC2
#define SPARE_WPU                  WPUCbits.WPUC2
#define SPARE_OD                   ODCONCbits.ODCC2
#define SPARE_ANS                  ANSELCbits.ANSELC2
#define SPARE_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define SPARE_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define SPARE_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define SPARE_GetValue()           PORTCbits.RC2
#define SPARE_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define SPARE_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define SPARE_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define SPARE_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define SPARE_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define SPARE_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define SPARE_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define SPARE_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set CNT2 aliases
#define CNT2_TRIS                 TRISCbits.TRISC3
#define CNT2_LAT                  LATCbits.LATC3
#define CNT2_PORT                 PORTCbits.RC3
#define CNT2_WPU                  WPUCbits.WPUC3
#define CNT2_OD                   ODCONCbits.ODCC3
#define CNT2_ANS                  ANSELCbits.ANSELC3
#define CNT2_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define CNT2_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define CNT2_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define CNT2_GetValue()           PORTCbits.RC3
#define CNT2_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define CNT2_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define CNT2_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define CNT2_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define CNT2_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define CNT2_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define CNT2_SetAnalogMode()      do { ANSELCbits.ANSELC3 = 1; } while(0)
#define CNT2_SetDigitalMode()     do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set CNT1 aliases
#define CNT1_TRIS                 TRISCbits.TRISC4
#define CNT1_LAT                  LATCbits.LATC4
#define CNT1_PORT                 PORTCbits.RC4
#define CNT1_WPU                  WPUCbits.WPUC4
#define CNT1_OD                   ODCONCbits.ODCC4
#define CNT1_ANS                  ANSELCbits.ANSELC4
#define CNT1_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define CNT1_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define CNT1_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define CNT1_GetValue()           PORTCbits.RC4
#define CNT1_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define CNT1_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define CNT1_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define CNT1_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define CNT1_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define CNT1_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define CNT1_SetAnalogMode()      do { ANSELCbits.ANSELC4 = 1; } while(0)
#define CNT1_SetDigitalMode()     do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set LIGHT2 aliases
#define LIGHT2_TRIS                 TRISCbits.TRISC5
#define LIGHT2_LAT                  LATCbits.LATC5
#define LIGHT2_PORT                 PORTCbits.RC5
#define LIGHT2_WPU                  WPUCbits.WPUC5
#define LIGHT2_OD                   ODCONCbits.ODCC5
#define LIGHT2_ANS                  ANSELCbits.ANSELC5
#define LIGHT2_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define LIGHT2_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define LIGHT2_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define LIGHT2_GetValue()           PORTCbits.RC5
#define LIGHT2_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define LIGHT2_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define LIGHT2_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define LIGHT2_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define LIGHT2_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define LIGHT2_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define LIGHT2_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define LIGHT2_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set LIGHT1 aliases
#define LIGHT1_TRIS                 TRISCbits.TRISC6
#define LIGHT1_LAT                  LATCbits.LATC6
#define LIGHT1_PORT                 PORTCbits.RC6
#define LIGHT1_WPU                  WPUCbits.WPUC6
#define LIGHT1_OD                   ODCONCbits.ODCC6
#define LIGHT1_ANS                  ANSELCbits.ANSELC6
#define LIGHT1_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define LIGHT1_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define LIGHT1_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define LIGHT1_GetValue()           PORTCbits.RC6
#define LIGHT1_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define LIGHT1_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define LIGHT1_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define LIGHT1_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define LIGHT1_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define LIGHT1_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define LIGHT1_SetAnalogMode()      do { ANSELCbits.ANSELC6 = 1; } while(0)
#define LIGHT1_SetDigitalMode()     do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set MOTOR2 aliases
#define MOTOR2_TRIS                 TRISCbits.TRISC7
#define MOTOR2_LAT                  LATCbits.LATC7
#define MOTOR2_PORT                 PORTCbits.RC7
#define MOTOR2_WPU                  WPUCbits.WPUC7
#define MOTOR2_OD                   ODCONCbits.ODCC7
#define MOTOR2_ANS                  ANSELCbits.ANSELC7
#define MOTOR2_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define MOTOR2_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define MOTOR2_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define MOTOR2_GetValue()           PORTCbits.RC7
#define MOTOR2_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define MOTOR2_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define MOTOR2_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define MOTOR2_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define MOTOR2_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define MOTOR2_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define MOTOR2_SetAnalogMode()      do { ANSELCbits.ANSELC7 = 1; } while(0)
#define MOTOR2_SetDigitalMode()     do { ANSELCbits.ANSELC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/