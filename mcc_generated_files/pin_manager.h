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
#define LED_TRIS                 TRISAbits.TRISA5
#define LED_LAT                  LATAbits.LATA5
#define LED_PORT                 PORTAbits.RA5
#define LED_WPU                  WPUAbits.WPUA5
#define LED_OD                   ODCONAbits.ODCA5
#define LED_ANS                  ANSELAbits.ANSELA5
#define LED_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define LED_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define LED_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define LED_GetValue()           PORTAbits.RA5
#define LED_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define LED_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define LED_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define LED_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define LED_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define LED_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define LED_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set ALARM aliases
#define ALARM_TRIS                 TRISAbits.TRISA7
#define ALARM_LAT                  LATAbits.LATA7
#define ALARM_PORT                 PORTAbits.RA7
#define ALARM_WPU                  WPUAbits.WPUA7
#define ALARM_OD                   ODCONAbits.ODCA7
#define ALARM_ANS                  ANSELAbits.ANSELA7
#define ALARM_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define ALARM_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define ALARM_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define ALARM_GetValue()           PORTAbits.RA7
#define ALARM_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define ALARM_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define ALARM_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define ALARM_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define ALARM_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define ALARM_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define ALARM_SetAnalogMode()      do { ANSELAbits.ANSELA7 = 1; } while(0)
#define ALARM_SetDigitalMode()     do { ANSELAbits.ANSELA7 = 0; } while(0)

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

// get/set ECHO aliases
#define ECHO_TRIS                 TRISCbits.TRISC6
#define ECHO_LAT                  LATCbits.LATC6
#define ECHO_PORT                 PORTCbits.RC6
#define ECHO_WPU                  WPUCbits.WPUC6
#define ECHO_OD                   ODCONCbits.ODCC6
#define ECHO_ANS                  ANSELCbits.ANSELC6
#define ECHO_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define ECHO_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define ECHO_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define ECHO_GetValue()           PORTCbits.RC6
#define ECHO_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define ECHO_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define ECHO_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define ECHO_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define ECHO_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define ECHO_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define ECHO_SetAnalogMode()      do { ANSELCbits.ANSELC6 = 1; } while(0)
#define ECHO_SetDigitalMode()     do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set TRIG aliases
#define TRIG_TRIS                 TRISCbits.TRISC7
#define TRIG_LAT                  LATCbits.LATC7
#define TRIG_PORT                 PORTCbits.RC7
#define TRIG_WPU                  WPUCbits.WPUC7
#define TRIG_OD                   ODCONCbits.ODCC7
#define TRIG_ANS                  ANSELCbits.ANSELC7
#define TRIG_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define TRIG_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define TRIG_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define TRIG_GetValue()           PORTCbits.RC7
#define TRIG_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define TRIG_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define TRIG_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define TRIG_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define TRIG_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define TRIG_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define TRIG_SetAnalogMode()      do { ANSELCbits.ANSELC7 = 1; } while(0)
#define TRIG_SetDigitalMode()     do { ANSELCbits.ANSELC7 = 0; } while(0)

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


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF6 pin functionality
 * @Example
    IOCCF6_ISR();
 */
void IOCCF6_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF6 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF6 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF6_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF6_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF6 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF6_SetInterruptHandler() method.
    This handler is called every time the IOCCF6 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF6_SetInterruptHandler(IOCCF6_InterruptHandler);

*/
extern void (*IOCCF6_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF6 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF6_SetInterruptHandler() method.
    This handler is called every time the IOCCF6 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF6_SetInterruptHandler(IOCCF6_DefaultInterruptHandler);

*/
void IOCCF6_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/