/* 
 * File:   operate.h
 * Author: Dave Plater
 * Comments:
 * Date:   Tue 23 Feb 15:25:46 SAST 2021
 */

#include "operate.h"

/** This deals with general operations like
 alarms and sprays
 */
/* Timer 2: clock source 31.25kHz clock period = 1/31250
 * timer period = clock period x prescale postscale
 * With the present post and pre scale this equals 0,012288
*/

void Service(void)
{
    LED_SetHigh();
    //If ReadServ() returns true then button held for > 3sec
    if(ReadServ())
    {
        SetMotor();
    }
    maxdist = GetMaxDist();
    maxdistl = (uint8_t)maxdist & 0xFF;
    maxdisth = (uint8_t)(maxdist >> 8);// & 0xFF;
    DATAEE_WriteByte(distmaxl, maxdistl);
    DATAEE_WriteByte(distmaxh, maxdisth);
    __delay_ms(50);
    LED_SetLow();
    RESET();
}
#if 0
void SetMotor(void)
{
    LED_SetLow();
    __delay_ms(500);
    LED_SetHigh();
    __delay_ms(500);
    LED_SetLow();
    TMR0H = 0xF4;
    oppflags.motexit = 1;
    
    while(oppflags.motexit) //LIDAR_GetValue()
    {
        if(PIR3bits.TMR0IF)
        {
            T0CON0bits.T0EN = 0;
            PIR3bits.TMR0IF = 0;
        }
        while(SERVICE_GetValue())
        {
            
        }
        mottime = mottime;
        while(!SERVICE_GetValue())
        {
            if(!MOTOR_LAT)
            {
                //if the motors off switch it on and start the timer
                TMR0_Initialize();
                TMR0H = 0xE0;
                MOTOR_SetHigh();
                LED_SetHigh();
                
                T0CON0bits.T0EN = 1;
            }
            if(PIR3bits.TMR0IF)
            {
                //2 second timeout
                MOTOR_SetLow();
                T0CON0bits.T0EN = 0;
                LED_SetLow();
                PIR3bits.TMR0IF = 0;
            }
            
            mottime = TMR0L;
        }
        DATAEE_WriteByte(mtime, mottime);
        if(MOTOR_LAT)
        {
            oppflags.motexit = 0;
            T0CON0bits.T0EN = 0;
            
            MOTOR_SetLow();
            LED_SetLow();
            PIR3bits.TMR0IF = 0;
        }
    }
    RESET();
}
#endif
uint16_t GetMaxDist(void)
{
    maxdist = 400;
    compare0 = ReadDistance();
    __delay_ms(500);
    compare1 = ReadDistance();
    __delay_ms(500);
    compare2 = ReadDistance();
    __delay_ms(500);
    compared = ReadDistance();
    if(compared > compare0)
    {
        compared = compare0;
    }
    if(compared > compare1)
    {
        compared = compare1;
    }
    if(compared > compare2)
    {
        compared = compare2;
    }
    compared = compared - 10;
    return compared;
}

uint16_t GetMaxDist2(void)
{
    compare0 = ReadDistance2();
    __delay_ms(500);
    compare1 = ReadDistance2();
    __delay_ms(500);
    compare2 = ReadDistance2();
    __delay_ms(500);
    compared = ReadDistance2();
    if(compared > compare0)
    {
        compared = compare0;
    }
    if(compared > compare1)
    {
        compared = compare1;
    }
    if(compared > compare2)
    {
        compared = compare2;
    }
    compared--;
    return --compared;
}

bool ReadSonar()
{
    
}

bool ReadServ(void)
{
    //Load timer2 with 0xF4 for 1 second delay
    T0CON0bits.OUTPS = 2;
    TMR0H = 0x50;
    PIR3bits.TMR0IF = 0;
    T0CON0bits.T0EN = 1;
    while(!PIR3bits.TMR0IF)
    {
        if(SERVICE_GetValue())
        {
            T0CON0bits.T0EN = 0;
            TMR0_Initialize();
            return 0;
        }
    }
    while(!SERVICE_GetValue())
    {
        
    }
    T0CON0bits.T0EN = 0;
    TMR0_Initialize();
    return 1;
}
#if 0
void Dispense(void)
{
    PIR3bits.TMR0IF = 0;
    T0CON0bits.T0EN = 0;
    TMR0L = 0x00;
    TMR0H = mottime;
    T0CON0bits.T0EN = 1;
    MOTOR_SetHigh();
    LED_SetHigh();
    while(!PIR3bits.TMR0IF)
    {
        
    }
    MOTOR_SetLow();
    LED_SetLow();
    T0CON0bits.T0EN = 0;
    PIR3bits.TMR0IF = 0;
}
#endif
void SoundAlarm(uint16_t distance)
{
    uint8_t x = 1;
    while(x != 0)
    {
        ALARM_SetLow();
        __delay_ms(100);
        ALARM_SetHigh();
        __delay_ms(400);
        x--;
    }
}

void ReadDispense(void)
{
    compare2 = ReadDistance2();
    __delay_ms(100);
    compared = ReadDistance2();
    int x = compare2 - compared;
    if(x > 3 || x < -3)
    {
        Dispense();
    }

}

void led_switch(uint8_t color)
{
    if(color < 2)
    {
        LED_SetHigh();
    }
    else
    {
        LED_SetLow();
    }
}

