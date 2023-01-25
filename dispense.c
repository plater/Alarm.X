/* 
 * File:   dispense.h
 * Author: Dave Plater
 *
 * Created on 24 March 2018, 12:49 PM
 */

#include "dispense.h"

const uint16_t pricestore = 0x00;

#if 0
bool price_check(void)
{
//    return 0;
    channel = 0x00;
    cash = credit_check();
    if(lowprice > cash)
    {
        return 0;
    }
    if(highprice <= cash && !venflags.hiprice)
    {
        //note_disable();
        venflags.hiprice = 1;
    }
    chanmask = 0;
    char i = 7;
    while(i > 0x00)
    {//If enough cash for channel then set mask bit
        if(pricevend[i] <= cash)
        {
            chanmask = chanmask | 0x01;
        }
        chanmask = chanmask << 1;
        i--;
    }
    if(pricevend[0] <= cash)
    {
        chanmask = chanmask | 0x01;
    }
    chanmask = chanmask & ~errormask;
    venflags.error = 0;
    //Turn on button lights for enabled channels.
    //Channel 1 to 4 = RB0 to RB3
    //Channel 5 to 8 = RD4 to RD7
    LATCbits.LC2 = 1;
    LATB = chanmask & 0x0F;
    LATD = chanmask & 0xF0;
    buttons = butin();
    if((buttons & errormask) != 0x00)
    {
        if(!venflags.pricedisplay)
        {
//            lcd_string(emptymsg, line1);
            venflags.pricedisplay = 1;
        }
        
        return 0;
    }
    buttons = buttons & chanmask;
    if(buttons != 0)
    {
        channel = get_channel(buttons);
        vendprice = pricevend[channel];
        uint8_t savechan = channel;
        uint8_t savebut = buttons;
        //This is a quick fix for coke + pie dispense.
        if(channel > 0x03)
        {
            buttons = 0x80;
            channel = 0x07;
        }
        dispense(channel);
        channel = savechan;
        buttons = savebut;
        uint8_t chanlinkbit = DATAEE_ReadByte(chan1linkbits + channel);
        if(chanlinkbit != 0x00 && !venflags.error)
        {
            channel = get_channel(chanlinkbit);
            dispense(channel);
        }
        credit_subtract(vendprice);
        venflags.hiprice = 0;
        cash = credit_check();
        if(cash > 0 && !venflags.nochange && !venflags.error)
        {
            
//            give_change(cash);
        }
        LATAbits.LA5 = 0;
        LATCbits.LC2 = 1;
        return 1;
    }
    else
    {
        venflags.pricedisplay = 0;
        venflags.credisplay = 1;
    }
    return 0;
}

void dispense(uint8_t chanel)
{
    channel = chanel;
    vend_nosense(chanel);
}
#endif //price_check
const uint8_t fgsmmsg[] = " Setup, 1=50,2=43,3=40,4=30,5=20,6=10,7=15,8=25..0";
/** Tasks:
 * SMS price settings: price_set
 * SMS Merchant URL in base64 */
/** gsmmsg contains:        
 * +CMGR: "REC UNREAD","+27766520007","Dave Plater","22/06/21,15:58:15+08"
 * Setup, 1=50,2=43,3=40,4=30,5=20,6=10,7=15,8=25..0
 *          32   2B   28   1E   14   0A   0F   19
 * pricestore = EEPROM address for 8 x uint8_t price store
 */
void price_set(void)
{
//   uint8_t smsmessage[] = " Setup, 1=0975,2=0975,3=1250,4=1190..";
    uint8_t *messagestore;
    uint16_t x;
    uint16_t y;
    uint16_t i;
    uint16_t vpchar;
//    strcpy(gsmmsg, smsmessage);
    messagestore = strstr(gsmmsg, "1=");
    if(!messagestore)
    {
        RESET();
    }
    i = 0;
    while(i < 8)
    {
        vpchar = messagestore[0];// Store ascii channel number
        if(vpchar > '8' || vpchar < '1')// Channel number is from 1 to 8
        {
            break;
        }
        x = atoi(&vpchar);//Convert ascii channel number into x
        if(x > 0)
        {
            x--;
        }
        //R99.99 = 0x270F
        messagestore = messagestore + 2;
        y = atoi(messagestore);
        vendprice = y;
        uint16_t z = x*2;
        DATAEE_WriteWord(pricestore + z, vendprice);
        vendprice = DATAEE_ReadWord(pricestore + z);
        prices[i] = vendprice;
        i++;
        messagestore = messagestore + 5;
    }
            /**
             * DATAEE_WriteByte(pricestore + channel, vendprice);
             * const uint16_t pricestore = 0x00;
             * volatile uint8_t prices[8];
            */
    while(SERVICE_PORT)
    {
        ClrWdt();
    }
}

void price_init(void)
{
    uint8_t x;
    x = 0;
    while(x < 8)
    {
        uint8_t z = x*2;
        vendprice = DATAEE_ReadWord(pricestore + z);
        prices[x] = vendprice;
        x++;
    }
}

void dispense(uint8_t chanel)
{
    uint8_t  x;
    uint16_t p;
    
    x = chanel;
    p = prices[x];
    if(p == price)
    {
        led_switch(0); // Green = 0 started dispense
        vend_nosense(channum);
        led_switch(1); // Red = 1 finished vend
    }
    else
    {
        ledchange = 1;
        ledredon = 1;
        ledgreenon = 0;
        led_opperate();
    }
    ClrWdt();
}
#if 0
void vend_nosense(uint8_t chanel)
{
    ClrWdt();
    switch(chanel)
    {
        case 0 :
            VEND1_SetHigh();
            break;
        case 1 :
            VEND2_SetHigh();
            break;
        case 2 :
            VEND3_SetHigh();
            break;
        case 3 :
            VEND4_SetHigh();
            break;
        case 4 :
            VEND5_SetHigh();
            break;
        case 5 :
            VEND6_SetHigh();
            break;
        case 6 :
            VEND7_SetHigh();
            break;
        case 7 :
            VEND8_SetHigh();
            break;
/*        case 8 :
            VEND9_SetHigh();
            break;
        case 9 :
            VEND10_SetHigh();
            break;*/
    }
    __delay_ms(1000);
    LATD = LATD & 0x0F;
    LATB = LATB & 0xF0;
    VEND9_SetLow();
    VEND10_SetLow();
    ClrWdt();
}
/*
 *  bool ledredflash; RLED_Toggle()
    bool ledgreenflash; GLED_Toggle()
    bool ledredon;RLED_SetHigh()
    bool ledgreenon;GLED_SetHigh()
    bool ledslow;
    bool ledfast;
    bool ledchange;
*/
void led_opperate(void)
{
    ledchange = 0;
    if(ledredon)
    {
        RLED_SetHigh();
        GLED_SetLow();
    }
    if(ledgreenon)
    {
        GLED_SetHigh();
        RLED_SetLow();
    }
}
#endif //#if 0

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


void DATAEE_WriteWord(uint16_t bAdd, uint16_t bData)
{
    uint8_t x = (uint8_t)bData & 0x00FF;
    DATAEE_WriteByte(bAdd, x);
    x = (uint8_t)(bData >> 8);
    DATAEE_WriteByte(bAdd + 1, x);
}

uint16_t DATAEE_ReadWord(uint16_t bAdd)
{
    uint8_t x = DATAEE_ReadByte(bAdd);
    uint16_t y = (uint16_t) x;
    y = y & 0x00FF;
    x = DATAEE_ReadByte(bAdd + 1);//Read most significant byte
    uint16_t z = (uint16_t) x;
    z = z & 0x00FF;
    y = (y | (z << 8));
    return y;
}
#if 0
void vend_dispense(uint8_t chanel)
{//Ensure all channels off
//    mdb_unlock();
    LATB = 0x00;
    LATD = 0x00;
    //Turn on motor common
    LATAbits.LA5 = 1;
    //Turn off button light common
    LATCbits.LC2 = 0;
    //Get channel bit
    chanmask = 0x01;
    chanmask = chanmask << chanel;
    set_motortime(chanel);
    while(!CMOUTbits.MC1OUT && !PIR0bits.TMR0IF)
    {
        LATB = chanmask & 0x0F;
        LATD = chanmask & 0xF0;
    }
    LATB = 0;
    LATD = 0;
    TMR0_StopTimer();
    if(PIR0bits.TMR0IF)
    {//Timeout no package has dropped
        set_motortime(chanel);
        //Wait for drop.
        while(!CMOUTbits.MC1OUT && !PIR0bits.TMR0IF){}
        if(PIR0bits.TMR0IF)
        {//Now we have a no stock situation
            venflags.error = 1;
            disable_channel(chanel);
            //No vend no pay
            vendprice = 0x00;
        }
    }
    
}

void set_motortime(uint8_t chanel)
{//void TMR0_Write16bitTimer(uint16_t timerVal)
    uint8_t i = DATAEE_ReadByte(chan1time + chanel);
    TMR0_StopTimer();
    PIR0bits.TMR0IF = 0;
    //Initialize timer at one second
    uint16_t time = second1;
    time = time - (second_5 * i);
    TMR0_WriteTimer(time);
    TMR0_StartTimer();
}

void find_highprice(void)
{
    char i = 0;
    highprice = pricevend[0];
    while(i < 8)
    {
        if(highprice < pricevend[i])
        {
            highprice = pricevend[i];
        }
        i++;
    }
}

void find_lowprice(void)
{
    char i = 0;
    lowprice = pricevend[0];
    while(i < 8)
    {
        if(lowprice > pricevend[i])
        {
            lowprice = pricevend[i];
        }
        i++;
    }

}

void create_chanmask(void)
{
    
}
void init_pricestore(void)
{
    //Transfer prices to pricevend[]
    char i = 0;
    while(i < 8)
    {
        pricevend[i] = DATAEE_ReadByte(pricestore + i);
        i++;
    }

}

//Read values stored in NVRam and initialize link and time flags.
void Init_vendmem(void)
{
    //Transfer prices to pricevend[]
    uint8_t i = 0;
    while(i < 8)
    {
        pricevend[i] = DATAEE_ReadByte(pricestore + i);
        i++;
    }
}


void disable_channel(uint8_t channel)
{
    uint8_t errormask = 0x01;
    errormask = errormask << channel;
    errormask = errormask | DATAEE_ReadByte(venderrors);
    DATAEE_WriteByte(venderrors, errormask);
}

void update_vends(uint8_t chanel)
{
    uint8_t x = DATAEE_ReadByte(vendstore + chanel);
    x++;
    DATAEE_WriteByte(vendstore + chanel, x);
}
#endif