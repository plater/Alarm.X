/* 
 * File:   Sonar.h
 * Author: Dave Plater
 * Comments:
 * Date:   Sun 21 Feb 11:19:14 SAST 2021
 */

#include "sonar.h"
//The maximum distance to trigger alarm
//uint16_t maxdist;


/** Timer1 times the echo pin's return to low - 150uSec to 25mSec = 2.59 cm to 4.31 m
 * Formula Time in uSec/58 = cm
 * Set trigger high and wait for echo high then time time to echo low
 * Timer 1: clock source 31.25kHz Overflow at 36.992 ms Count = 0xFB7C
 * Formula - (x = initial timer value) ((distance - x) x  32)/58 = cm 32 = 0x20, 58 = 0x3A
 */
int16_t ReadDistance(void)
{
     uint16_t x, y;
    if(ECHO_GetValue())
    {
        return(1) ; //Device disconnected
    }
    TMR1_Initialize(); //period to overflow = 0x10000 - (TMR1H + TMR1L) 
    T1CONbits.TMR1ON = 0;
    TMR1_WriteTimer(0);
    distance = 0;
    TRIG_SetHigh();
    __delay_us(25);
    TRIG_SetLow();
    LED_SetHigh();
    PIR4bits.TMR1IF = 0;
    T1CONbits.TMR1ON = 1;
    while(!SonarInt())
    {
        if(PIR4bits.TMR1IF)
        {
            T1CONbits.TMR1ON = 0;
            LED_SetLow();
            asm("NOP");
            y = ECHO_GetValue();
            return(0xFFFF) ; //Sonar error = ECHO timeout
        }
    }
    T1CONbits.TMR1ON = 0; 
    LED_SetLow();;
    TMR1_Initialize();
    
    x = TMR1_ReadTimer();
    //Start to time
    T1CONbits.TMR1ON = 1;
    while(SonarInt()) //Wait for echo low
    {
        if(PIR4bits.TMR1IF)
        {
            T1CONbits.TMR1ON = 0;
        //No obstacle = 0xFFFF
            return 0;//Return max distance 4.00 meters
        }
    }
    T1CONbits.TMR1ON = 0;
// Formula - (x = initial timer value) ((distance - x) x  32)/58 = cm : 32 = 0x20, 58 = 0x3A
    distance = TMR1_ReadTimer();
    distance = distance - x;
    distance = (distance * 0x20)/0x3A;
    return distance;
    if(distance <= maxdist)
    {
        return distance;
    }
    return maxdist;//Maximum distance = 2.00 meters
}

bool SonarInt(void)
{
    if(ECHO_GetValue())
    {
        return(1);
    }
    return(0);
}
