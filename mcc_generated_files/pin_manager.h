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

// get/set SERVICE aliases
#define SERVICE_TRIS                 TRISAbits.TRISA0
#define SERVICE_LAT                  LATAbits.LATA0
#define SERVICE_PORT                 PORTAbits.RA0
#define SERVICE_WPU                  WPUAbits.WPUA0
#define SERVICE_OD                   ODCONAbits.ODCA0
#define SERVICE_ANS                  ANSELAbits.ANSELA0
#define SERVICE_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define SERVICE_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define SERVICE_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define SERVICE_GetValue()           PORTAbits.RA0
#define SERVICE_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define SERVICE_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define SERVICE_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define SERVICE_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define SERVICE_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define SERVICE_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define SERVICE_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define SERVICE_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

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

// get/set PWRKEY aliases
#define PWRKEY_TRIS                 TRISBbits.TRISB0
#define PWRKEY_LAT                  LATBbits.LATB0
#define PWRKEY_PORT                 PORTBbits.RB0
#define PWRKEY_WPU                  WPUBbits.WPUB0
#define PWRKEY_OD                   ODCONBbits.ODCB0
#define PWRKEY_ANS                  ANSELBbits.ANSELB0
#define PWRKEY_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define PWRKEY_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define PWRKEY_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define PWRKEY_GetValue()           PORTBbits.RB0
#define PWRKEY_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define PWRKEY_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define PWRKEY_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define PWRKEY_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define PWRKEY_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define PWRKEY_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define PWRKEY_SetAnalogMode()      do { ANSELBbits.ANSELB0 = 1; } while(0)
#define PWRKEY_SetDigitalMode()     do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set RB1 procedures
#define RB1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define RB1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define RB1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define RB1_GetValue()              PORTBbits.RB1
#define RB1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define RB1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define RB1_SetPullup()             do { WPUBbits.WPUB1 = 1; } while(0)
#define RB1_ResetPullup()           do { WPUBbits.WPUB1 = 0; } while(0)
#define RB1_SetAnalogMode()         do { ANSELBbits.ANSELB1 = 1; } while(0)
#define RB1_SetDigitalMode()        do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set RB2 procedures
#define RB2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define RB2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define RB2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define RB2_GetValue()              PORTBbits.RB2
#define RB2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define RB2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define RB2_SetPullup()             do { WPUBbits.WPUB2 = 1; } while(0)
#define RB2_ResetPullup()           do { WPUBbits.WPUB2 = 0; } while(0)
#define RB2_SetAnalogMode()         do { ANSELBbits.ANSELB2 = 1; } while(0)
#define RB2_SetDigitalMode()        do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set GLED aliases
#define GLED_TRIS                 TRISCbits.TRISC6
#define GLED_LAT                  LATCbits.LATC6
#define GLED_PORT                 PORTCbits.RC6
#define GLED_WPU                  WPUCbits.WPUC6
#define GLED_OD                   ODCONCbits.ODCC6
#define GLED_ANS                  ANSELCbits.ANSELC6
#define GLED_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define GLED_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define GLED_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define GLED_GetValue()           PORTCbits.RC6
#define GLED_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define GLED_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define GLED_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define GLED_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define GLED_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define GLED_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define GLED_SetAnalogMode()      do { ANSELCbits.ANSELC6 = 1; } while(0)
#define GLED_SetDigitalMode()     do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set RLED aliases
#define RLED_TRIS                 TRISCbits.TRISC7
#define RLED_LAT                  LATCbits.LATC7
#define RLED_PORT                 PORTCbits.RC7
#define RLED_WPU                  WPUCbits.WPUC7
#define RLED_OD                   ODCONCbits.ODCC7
#define RLED_ANS                  ANSELCbits.ANSELC7
#define RLED_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RLED_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RLED_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RLED_GetValue()           PORTCbits.RC7
#define RLED_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RLED_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define RLED_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define RLED_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define RLED_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define RLED_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define RLED_SetAnalogMode()      do { ANSELCbits.ANSELC7 = 1; } while(0)
#define RLED_SetDigitalMode()     do { ANSELCbits.ANSELC7 = 0; } while(0)

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