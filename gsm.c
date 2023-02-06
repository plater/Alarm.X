/* 
 * File:   gsm.c
 * Author: Dave Plater
 *
 * Created on September 26, 2018, 3:14 PM 
 */
#include "gsm.h"

/*struct 
{
    unsigned ledredflash   : 1;
    unsigned ledgreenflash : 1;
    unsigned ledredon      : 1;
    unsigned ledgreenon    : 1;
    unsigned ledslow       : 1;
    unsigned ledfast       : 1;
    unsigned ledchange     : 1;
    unsigned spare         : 1;
} ledflags;
*/
void fast_ledflash(bool colour)
{
    if(colour) //red = 1 and ledgreen = 0
    {
        
    }
}

void slow_ledflash(bool colour)
{
    if(colour)
    {
        
    }
}

//Wait for buffer empty
void gsm_waitx(void)
{
    U2CON0bits.TXEN = 1;
    while(!PIR3bits.U1TXIF)
    {
    }
}
//Wait for buffer empty
void gsm_waitr(void)
{
    while(!PIR3bits.U1RXIF)
    {
        
    }
}

void gsm_transmit(uint8_t txbyte)
{
    U2CON0bits.TXEN = 1;
    UART2_Write(txbyte);
    while(!U2ERRIRbits.TXMTIF){}
}

void gsm_zerobuff(uint8_t* gsmsgbuf, uint16_t count )
{
    uint16_t x = 0;
    while(x < count)
    {
        gsmsgbuf[x] = 0x00;
        x++;
    }
    
}

void gsm_msg(uint8_t *msgadd)
{
    __uint24 msgbkup = msgadd;
    retrans:
    msgadd = msgbkup;
    gsmflags.retransmit = 0;
    
    for(uint8_t gsmstr = 0; msgadd[gsmstr] != 0x00; gsmstr++)
    {
        gsmbyte = msgadd[gsmstr];
        gsm_transmit(gsmbyte);
    }
    if(gsmflags.retransmit)
    {
        goto retrans;
    }
//     __delay_us(500);
}

//BAUDCONbits.ABDEN
void gsm_init(bool inittype)
{
    uint16_t x;
    /*
    PIE6bits.U2RXIE = 0;
    gsmflags.meerror = 0;
//    eusart2RxCount = 512;
    gsminit:
    
  //Make sure that 5 seconds have passed.
    while(!PIR7bits.TMR4IF)d
    {
    }
    TMR4_Stop();
    PIR7bits.TMR4IF = 0;*/
    
/** TODO: test for autobaud and
 reconfigure for 57600 baud rate
 */
    uint8_t y;
    led_switch(2); //Off
    gsm_zerobuff(gsmusd, 127); 
    y = gsm_on();
    led_switch(2);//RED
//    x = strstr(gsmusd, "RDY");
    if(y == 0)                                                                                                                                                                                                                                      if(y == 0)
    {
        gsm_txAT();//Transmit AT\r to sync baud rate.
        gsm_transmit(0x0D);
        gsm_receive(1, gsmusm);
        gsm_msg("AT+IPR=57600\r");
//        gsm_msg("AT+IPR=0\r");
        gsm_receive(2, gsmusm);
        gsm_msg("AT&W\r");
        gsm_receive(1, gsmusm);
        asm("reset");
    }
//    gsmbyte = Read_timeout1(gsmusd);
    //gsm_unsolic(); //Populates gsmmsg
    gsm_msg((uint8_t*)noecho);
    if(!inittype)
    {
        gsm_receive(1, gsmusd);
    }
    //
/*    uint8_t msgstr[24] = "AT+COPN\r";
    gsm_msg((uint8_t*)msgstr);
    gsmbyte = Read_timeout(gsmusd);
    gsm_msg((uint8_t*)"AT+CPOL?\r");
    gsmbyte = Read_timeout(gsmusd);
*/
    led_switch(3); //LED toggle GREEN
	gsm_msg((uint8_t*)"AT+CREG=1\r");
	gsm_receive(1, gsmusm);
	gsmwait:
    led_switch(1); // Red = 1
    __delay_ms(1);
    
	gsm_msg((uint8_t*)"AT+CREG?\r");
	gsm_receive(2, gsmusd);
    uint8_t w = gsmusd[9];
	switch(w)
    {
        case '1' : 
            break;
        
        case '5' : 
            break;
            
        default :
            goto gsmwait;
    }
    led_switch(2); //LED off
    gsm_msg((uint8_t*)tsoftid);
    gsm_receive(2, gsmusd);
    gsm_msg("AT+CFUN?\r");
    gsm_receive(2, gsmusd);
    
    /*
     2 = -110db 30 = -54
     15 = -82 */
    
#if 0
    gsm_msg((uint8_t*)"AT+CELLIST=1,30\r");
    Read_timeout1(gsmmsg);
    gsm_msg((uint8_t*)"AT+CELLIST\r");
    Read_timeout1(gsmmsg);
    gsm_msg((uint8_t*)"AT+COPS=4,0,\"VodaCom\"\r");
    Read_timeout1(gsmmsg);
    gsm_msg((uint8_t*)"AT+COPN\r");
    Read_timeout1(gsmmsg);
    gsm_msg((uint8_t*)"AT+CNUM\r");
    Read_timeout1(gsmmsg);
    gsm_msg((uint8_t*)"AT+CPOL?\r");
    Read_timeout1(gsmmsg);
    gsm_msg((uint8_t*)"AT+COPS?\r");
    Read_timeout1(gsmmsg);
    gsm_msg((uint8_t*)"AT+CSPN?\r");
    Read_timeout1(gsmmsg);
    gsm_msg((uint8_t*)"AT+CBAND?\r");
    Read_timeout1(gsmmsg);
    gsm_msg((uint8_t*)"AT+CSDT?\r");//Switch on or off Detecting SIM Card
    Read_timeout1(gsmmsg);
    gsm_msg((uint8_t*)"AT+CGID\r");//Get SIM Card Group Identifier
    Read_timeout1(gsmmsg);
    gsm_msg((uint8_t*)"AT*CELLLOCK?\r");*//*Set the List of ARFCN Which Needs to Be Locked - 

                                           *     Read_timeout1(gsmmsg);
    gsm_msg((uint8_t*)"AT+CSDT=0\r");// Don't detect sim
    Read_timeout1(gsmmsg);
    gsm_msg((uint8_t*)"AT+CSDT=1\r");//Detect sim
    Read_timeout1(gsmmsg);
    gsm_msg((uint8_t*)"AT+CSMINS?\r");//SIM Inserted Status Reporting
    Read_timeout1(gsmmsg);
    gsm_msg((uint8_t*)"AT+CSMINS=0\r");//Disable unsolicited result code
    Read_timeout1(gsmmsg);
    gsm_msg((uint8_t*)"AT+CSMINS=1\r");//Enable unsolicited result code
    Read_timeout1(gsmmsg);//AT+CANT
    gsm_msg((uint8_t*)"AT+CANT?\r");//Antenna Detecting
    Read_timeout1(gsmmsg);
    gsm_msg((uint8_t*)"AT+CNETSCAN\r");//Disable unsolicited result code
    Read_timeout1(gsmmsg);
    gsm_msg((uint8_t*)"AT+CSMINS=1\r");//Enable unsolicited result code
    Read_timeout1(gsmmsg);//AT+CANT*/
 #endif
}

//Read until 3 second timeout for initialisation of network
//return message count
uint8_t Read_timeout1(uint8_t *msgadd)
{
    uint8_t v = 0;
    TMR5_Initialize(); //Currently set at 4 seconds
    TMR5_WriteTimer(0); //Should be 16 seconds wait for rdy
    T5CONbits.TMR5ON = 1;
    U2CON0bits.RXEN = 1;
    U1FIFObits.RXBE = 1;
    while(!PIR8bits.TMR5IF)
    {
        if(PIR6bits.U2RXIF)//U2FIFObits.RXBF
        {
            
            led_switch(1);//RED
            msgadd[v] = U2RXB;
            T5CONbits.TMR5ON = 0;
            TMR5_Initialize();
            T5CONbits.TMR5ON = 1;
            PIR3bits.U1RXIF = 0;
            led_switch(2);//OFF
            U1FIFObits.RXBE = 1;
            if(v < 128)
            {
                v++;
            }
        }
        
    }
    led_switch(1);//RED
    msgadd[v] = 0;
    return v;
}

uint8_t Read_Service(void)
{
    uint8_t x = 0;
    while(!SERVICE_PORT)
    {
        if(x)
        {
            RLED_SetHigh();
            GLED_SetLow();
            x = 0;
        }
        else
        {
            GLED_SetHigh();
            RLED_SetLow();
            x = 1;
        }
        delay_10mS(1);
    }
    return 1;
}

void Read_SMS(void)
{
//    Read_Service();
 //   base64_encode("22d3cf4f-db05-4609-9773-2312375b4523:", (idx_t) 37, base64buf, (idx_t) 58);
    __delay_ms(500);
    gsm_msg(smstxt);//AT+CMGF=1 set text sms
    gsm_receive(1, gsmtim);
    gsm_msg(smsdel);//"AT+CMGDA=\"DEL ALL\"\r"
    gsm_receive(1, gsmtim);
//    price_set();
    gsmflags.msgavl = 0;
    INTERRUPT_GlobalInterruptEnable();
    PIE6bits.U2RXIE = 1;
//    INTCON0bits.GIEH = 1;
//    INTCON0bits.GIEL = 1;
    led_switch(2); //off
    while(SERVICE_PORT)
    {
        int_sms_notify();
    }
    PIE6bits.U2RXIE = 0;
}

int int_sms_notify(void)
{
    
    uint8_t* x;
    int y = 0;
    ClrWdt();
    if(UART2_is_rx_ready())
    {
        if(gsmflags.msgavl) //Retrieve the message if set
        {
            gsmflags.msgavl = 0;
            y = gsmint_receive(gsmmsg);
            if(y > 0)//if y > 0 then something has been received
            {
                y = 0;
                PIE6bits.U2RXIE = 0;
                ClrWdt();
                led_switch(0); //Green = price store
                x = strstr(gsmmsg, "Setup,");// check for price set message
                if(!x)//Not a setup message, check for merchant key
                {
                    x = strstr(gsmmsg, "KEY = ");
                    if(!x)// Not a merchant key either, delete and wait.
                    {
                        led_switch(2); //off
                        gsm_msg(smsdel);//"AT+CMGDA=\"DEL ALL\"\r"
                        gsm_receive(1, gsmtim);
                        PIE6bits.U2RXIE = 1;
                    }
                    else// is a merchant key
                    {
                        led_switch(1); //Red =  merchant key stored
//                        store_merchkey();
                        while(SERVICE_PORT)
                        {
                            ClrWdt();
                        }
                        gsm_msg(smsdel);//"AT+CMGDA=\"DEL ALL\"\r"
                        gsm_receive(1, gsmtim);
                        __delay_ms(1000);
                        PIE6bits.U2RXIE = 1;
                    }
                }
                else //Is a price set message
                {
                    
                   // price_set();
                    gsm_msg(smsdel);//"AT+CMGDA=\"DEL ALL\"\r"
                    gsm_receive(1, gsmtim);
                    __delay_ms(1000);
                    PIE6bits.U2RXIE = 1;
                }
            }
        /*
         * +CMGR: "REC UNREAD","+27766520007","Dave Plater","22/06/21,15:58:15+08"
         * Setup, 1=50,2=43,3=40,4=30,5=20,6=10,7=15,8=25..0
         * Setup, 1=0975,2=0975,3=1250,4=1190..
         */
        }
        else //Wait for unsolicited notification
        {
            ClrWdt();
            y = gsmint_receive(gsmusd);
            if(!y)
            {
                y = strstr(gsmusd, "+CMTI"); //Make sure it's an sms notification
            }
        }
        led_switch(2) ;       
    }
    if(y > 0)
    {
        gsm_msg("AT+CMGR=1\r");// 
        gsmflags.msgavl = 1;
    }
}

int gsmint_receive( uint8_t messagebuf[] )
{
    //TMR3 PIR6bits.TMR3IF TMR3_StartTimer();
    TMR3_Initialize();
    TMR3_StartTimer();
    gsmflags.meerror = 0;
    int x = 0;
    gsmbyte = 0;
    while(!PIR6bits.TMR3IF)// If no data for 10mS then message receive complete
    {
        if(UART2_is_rx_ready()) //Receive buffer data present
        {
            gsmbyte = UART2_Read();
            messagebuf[x] = gsmbyte;
            x++;
            TMR3_Initialize();
            TMR3_StartTimer();
        }
    }
    TMR3_StopTimer();
    x++;
    messagebuf[x] = 0;
    return x;
}
/*
 Make call then 3ms 0\r\n then 16.8*/
void Call_Home(void)
{
    uint8_t x;
    uint8_t mynumber[32] = {'A','T','D','+','2','7','7','6','6','5','2','0','0','0','7',';','\r'};
 //   gsm_msg("ATD0766520007\r");
    gsm_msg(mynumber);
    x = Read_timeout1(gsmusd);
    gsmbyte = gsmusd[1];
    x = gsmusd[2];
}

uint8_t Get_Battery(void)
{
    uint8_t x;
    gsm_msg("AT+CBC\r");
    gsm_receive(2, gsmtim);
    uint8_t *msgbuf = gsmtim + 8;
    x = atoi(msgbuf);
    return(x) ;
}

void Call_Me(void)
{
    gsm_msg("AT+CUSD=1,\"*140*0766520007#\"\r"); //Send Dave's phone a call me
}

uint8_t Get_Signal(void)
{
    uint8_t x;
    uint8_t* y;
	gsm_msg((uint8_t*)"AT+CSQ\r");
	gsm_receive(2, gsmusd);
    y = gsmusd + 7;
    x = atoi(y);
    return(x);
}
/* Decode Receiver signal strength value
x =  dBm 	Condition
2 	-109 	Marginal
3 	-107 	Marginal
4 	-105 	Marginal
5 	-103 	Marginal
6 	-101 	Marginal
7 	-99 	Marginal
8 	-97 	Marginal
9 	-95 	Marginal
10 	-93 	OK
11 	-91 	OK
12 	-89 	OK
13 	-87 	OK
14 	-85 	OK
15 	-83 	Good
16 	-81 	Good
17 	-79 	Good
18 	-77 	Good
19 	-75 	Good
20 	-73 	Excellent
21 	-71 	Excellent
22 	-69 	Excellent
23 	-67 	Excellent
24 	-65 	Excellent
25 	-63 	Excellent
26 	-61 	Excellent
27 	-59 	Excellent
28 	-57 	Excellent
29 	-55 	Excellent
30 	-53 	Excellent
 */
/*
    gsm_msg(smstxt);
    gsm_receive(1, gsmmsg);
    
    gsm_msg(smsdel);
    gsm_receive(1, gsmmsg);
    
    gsm_getbalance();
    
    gsm_msg(smslst);
    gsm_receive(1,gsmmsg);
    
    gsm_msg(smdqry);
    gsm_receive(1, gsmmsg);
    
    gsm_msg(engqry);
    gsm_receive(2, gsmmsg);
    
    gsm_msg(netoff);
    gsm_receive(2, gsmmsg);
   
    gsm_msg(facres);
    gsm_receive(1, gsmmsg);
    goto gsminit;
    asm("nop");
*/
/*+CMGR: "REC UNREAD","+27820098372","","22/07/19,15:29:07+08"
ùòèdc££KEY = 22d3cf4f-db05-4609-9773-2312375b4523:.Sent from 27766520007 from the my Vodacom app.Get 20 free sms per day.
0*/


#if 0
void clock_display(void)
{
    gsmflags.sigtest = 0;
    sig_strength();
    INTCON0bits.PEIE = 0;
    PIE6bits.U2RXIE =0;
    dispclka:
    TMR2_Initialize();
    PIR4bits.TMR2IF = 0;
    T2CONbits.TMR2ON = 1;
    gsm_gettime();
//    disp_clock();
    INTCON0bits.PEIE = 0;
    gsmflags.msgavl = 0;
    if(1 == 1)
    {
        if(PIR3bits.U1RXIF)
        {//This detects and ignores rings 2\r\n or 3\r\n.
            gsm_receive(1, gsmusm);
            if(gsmusm[0] != '+')
            {
                gsmflags.msgavl = 0;
            }
            else
            {
                gsmflags.msgavl = 1;
            }
        }
    }
    if(gsmflags.msgavl)
    {
//        lcd_string(gsmusm, line1);
        parse_sms();
        asm("nop");
    }
    INTCON0bits.PEIE = 0;
//    gsm_msg(smstxt);
//    gsm_receive(1);
//    gsm_msg(smslst);
 //   gsm_receive(71);
    
 //   goto dispclka;
}

void get_radio(void)
{
    uint16_t x = 0;
    uint16_t y = x;
    gsm_zerobuff(gsmmsg, 0x100);
    gsmflags.eomsg = 1;
    gsmflags.msggod = 1;
    gsm_msg(engqry);
    gsm_receive(1, gsmmsg);
    while(gsmflags.eomsg)
    {
        gsmbyte = UARTG_Read();
        gsmmsg[x] = gsmbyte;
        if(gsmbyte == 0x0A)
        {
            y = x - 2;
            if(gsmmsg[y] == 0x30)
            {
                gsmflags.eomsg = 0;
            }
            if(gsmflags.msggod)
            {
                gsm_msg(engoff);
                gsmflags.msggod = 0;
            }
        }
        x++;
        if(x > 0xFF)
        {
            gsmflags.eomsg = 0;
        }
    }
}

void sig_strength(void)
{
    while(gsmflags.sigtest)
    {//((uint8_t*) &pnvcash)
        __uint24 *convte;
//        lcd_write(dispclr);
        get_radio();
//        lcd_dispadd(line2 + 4);
        convte = gsmmsg;
//        displ_hex(convte[5] & 0x00FFFF);
    }
}
#endif
void check_num(void)
{//int memcmp(const void *s1, const void *s2, size_t n);
    index = (gsmusm[0x0C] & 0x0F) * 2;
    gsm_msg(smstxt);
    gsm_receive(1, gsmmsg);
    gsm_msg(smslst);//"AT+CMGL=\"ALL\"\r"
    gsm_receive(++index, gsmmsg);
    gsmflags.msggod = 0;
    //Phone number starts gsmmsg[24]
    int diffr = memcmp(gsmmsg + 24, spnum, 0x0B);
    if(diffr == 0x00)
    {
        gsmflags.msggod = 1;
    }
    else
    {
        gsm_msg(smstxt);//"AT+CMGF=1\r"
        gsm_receive(1, gsmusm);
        gsm_msg(smsdel);//"AT+CMGDA=\"DEL ALL\"\r"
        gsm_receive(1, gsmtim); 
    }
}

void parse_sms(void)
{
    int diffr = memcmp(gsmusm, cmti, 0x05);
    while(diffr == 0x00)
    {
        check_num();
        if(!gsmflags.msggod)
        {
            break;
        }
        gsm_msg(setgsm);
        gsm_receive(1, gsdate);
        gsm_msg(smstxt);
        gsm_receive(1, gstime);
        gsm_msg(sendms);
        gsm_msg(pnum);
        gsm_numack();
        //if gsmflags.abrtmsg send call me instead
        gsm_msg(ackmsg);
        //Send ^Z or SUB to terminate sms
        gsm_transmit(0x1A);
        gsm_transmit(0x0D);
        gsm_receive(1, gsdate);
        asm("NOP"); //gsm_receive(1, gsdate); needs to be fixed!
        gsm_msg(smstxt);
        gsm_receive(1, gsmusm);
        gsm_msg(smsdel);
        gsm_receive(1, gsmtim);
        sms_report();
        asm("NOP");
        diffr = 0xFF;
    }
}

void start_sms(void)
{
    gsm_msg(setgsm);
    gsm_receive(1, gsmmsg);
    gsm_msg(smstxt);
    gsm_receive(1, gsmmsg);
    gsm_msg(sendms);
    gsm_msg(pnum);
    gsm_numack();
    //if gsmflags.abrtmsg send call me instead
}

void gsm_numack(void)
{
    gsmbyte = 0x00;
    uint8_t x = 4;
    gsmflags.abrtmsg = 0;
    while(x > 0)
    {
        gsmbyte = UARTG_Read();
        if(gsmbyte == '4')
        {
            gsmflags.abrtmsg = 1;
            break;
        }
        if(gsmbyte == '\"')
        {
            gsmflags.abrtmsg = 0;
            break;
        }
        x--;
    }
}
/*
void sms_report(void)
{
    uint8_t i = 0;
    uint8_t z = i;
    gsm_getbalance();
    gsm_gettime();
    
    gsm_zerobuff(gsmmsg, 0x100);
    gsmmsg[i] = 0x20;
    //Read in "Date "
    i = write_sms(i,clockdate);
    //Read in actual date.
    i = write_sms(i,gsdate);
    gsmmsg[i++] = 0x20;
    //Things go wrong!
    i = write_sms(i,clocktime);
    i = write_sms(i,gstime);
    gsmmsg[i++] = 0x20;
    gsmmsg[i++] = ',';
    gsmmsg[i++] = 0x20;
    gsmmsg[i++] = 'R';
    Read_NVstore(cashinv, ((uint8_t*) &pvcash), 0x02);
    Read_NVstore(cashint, ((uint8_t*) &pnvcash), 0x03);
    uint8_t *gsmval = convert_hex((__uint24) pvcash);
    i = write_sms(i,gsmval);
    gsmmsg[i++] = ',';
    gsmmsg[i++] = 0x20;
    gsmmsg[i++] = 'R';
    gsmval = convert_hex(pnvcash);
    i = write_sms(i,gsmval);
    gsmmsg[i++] = ',';
    i = write_sms(i, totalvendsm);
    //Total vends
    uint16_t vendstores = vendstore;
    for(char x = 0; x < 0x08; x++)
    {
        gsmmsg[i++] = (x +1) | 0x30;
        gsmmsg[i++] = '=';
        gsmbyte = DATAEE_ReadByte(vendstores + x);
        gsmval = convert_hex((__uint24) gsmbyte);
        i = write_sms(i,gsmval);
        gsmmsg[i++] = ',';
    }
    gsmmsg[i++] = 0x20;
    //Display change coins given
    i = write_sms(i,coinsout);
    Read_NVstore(cashoutv, ((uint8_t*) &pvcash), 0x02);
    gsmval = convert_hex((__uint24) pvcash);
    i = write_sms(i,gsmval);
    i = write_sms(i,coinvalu);
    gsmbyte = DATAEE_ReadByte(hopcoin);
    gsmmsg[i++] = gsmbyte | 0x30;
    i = write_sms(i, gsmusd);
    //Null string terminator
    gsmmsg[i] = 0x00;
    start_sms();
    //if gsmflags.abrtmsg send call me instead
    if(gsmflags.abrtmsg)
    {
        
    }
    gsm_msg(gsmmsg);
    gsm_transmit(0x1A);
    gsm_transmit(0x0D);
}
*/
uint8_t write_sms(uint8_t i, uint8_t *msgpnt)
{
    uint8_t x = 0x00;
    gsmbyte = 0x20;
    while(gsmbyte != 0x00)
    {
        gsmbyte = msgpnt[x++];
        gsmmsg[i++] = gsmbyte;
    }
    return --i;
}

//Take a 24 bit hex value and convert it.
// Return pointer to eight ASCII digits lsd first.
uint8_t* convert_hex(__uint24 hexnum)
{
    signed char x = 0;
    uint8_t value[8];
    uint8_t xvalue[8];
    __uint24 hexnumsave = hexnum;
    while(hexnum > 0)
    {
        xvalue[x] = hexnum % 10;
        hexnum /= 10;
        xvalue[x] = xvalue[x] | 0x30;
        x++;
    }
    //insert null string terminator
    value[x--] = 0x00;
    uint8_t y = 0;
    while(x >= 0)
    {
        value[x--] = xvalue[y++];
    }
    
        //In case hexnum is zero
    if(hexnumsave == 0)
    {
       value[0] = 0x30;
       value[1] = 0x00;
    }
    return value;

}
void parse_date_time(void)
{
    gsm_zerobuff(gsdate, 0x014);
    gsm_zerobuff(gstime, 0x014);
    uint8_t x = 8;
    uint8_t i = 0x07;
    gsmbyte = gsmmsg[27];
    gsmbyte = gsmbyte & 0x0F;
    gsmbyte = gsmbyte/4;
    uint8_t hour = (gsmmsg[18] & 0x0F) + gsmbyte;
    uint8_t hhour = gsmmsg[17] & 0x0F;
    if(hour > 9)
    {
        gsmmsg[18] = 0x30;
        gsmmsg[17]++;
        if(gsmmsg[17] > 0x32)
        {
            gsmmsg[17] = 0x30;
        }
        while(hour > 0x0A)
        {
            hour--;
            gsmmsg[18]++;
        }
    }
    else
    {
        gsmmsg[18] = hour | 0x30;
    }
    while(x < 0x10)
    {
        gsdate[i - 1] = gsmmsg[x++];
        gsdate[i--] = gsmmsg[x++];
        gsdate[--i] = gsmmsg[x++];
        i--;
    }
    i = 0;
    while(i < 0x08)
    {
        gstime[i++] = gsmmsg[x++];
    }
}

void gsm_gettime(void)
{
    gsm_msg(clockr);
    
    gsm_receive(2,gsmmsg);
    parse_date_time();
}

//past first 0A to 0X0C spaces 
void gsm_getbalance(void)
{
    gsm_msg(setgsm);
    gsm_receive(1,gsmmsg);
    uint8_t x = 0x0C;
    uint8_t y = 0x00;
    gsmusd[y++] = ' ';
    gsmflags.eomsg = 1;
// For mtn each line remove 0x0A
// Parse until 0A  0A
    if(gsmflags.mtn)
    {
        gsm_msg(ussdwm);
        gsm_receive(11,gsmmsg);
        gsmusd[y++] = gsmmsg[x++];
        while(gsmflags.eomsg)
        {
            gsmbyte = gsmmsg[x++];
            if(gsmbyte == 0x0A)
            {//Add 0x20 inplace of 0A
                gsmusd[y++] = ',';
                gsmusd[y++] = ' ';
                gsmbyte = gsmmsg[x++];
                if(gsmbyte == 0x0A)
                {
                    gsmflags.eomsg = 0;
                    gsmusd[y++] = 0x22;
                    gsmbyte = 0x00;
                }
            }
            gsmusd[y++] = gsmbyte;
        }
    }
//For vodacom parse to first 0x0A
    else
    {
        gsm_msg(ussdwv);
        gsm_receive(3,gsmmsg);
        gsmusd[y++] = gsmmsg[x++];
        while(gsmflags.eomsg)
        {
            gsmbyte = gsmmsg[x++];
            if(gsmbyte == 0x0A)
            {
                gsmflags.eomsg = 0;
                gsmusd[y++] = 0x22;
                gsmbyte = 0x00;
            }
            gsmusd[y++] = gsmbyte;
        }
    }
    gsm_msg(ussdwc);
    gsm_receive(1,gsmmsg);
}

void gsm_setime(void)
{
    gsm_zerobuff(gsmmsg, 0x100);
    gsm_msg(nettst);
//    gsm_receive(5,gsmmsg);
    retry:
    gsmbyte = 0;
    uint8_t x = 0;
    //Search for *
    while(gsmbyte != '*')
    {
        gsmbyte = UARTG_Read();
        if(gsmflags.meerror)
        {
            goto offnet;
        }
    }
    gsmbyte = UARTG_Read(); //P
    gsmbyte = UARTG_Read(); //S
    gsmbyte = UARTG_Read(); //U
    if(gsmbyte != 'U')
    {
        goto retry;
    }
    while(gsmbyte != ':')
    {
        gsmbyte = UARTG_Read();
    }
    while(gsmbyte != '\n')
    {
        gsmbyte = UARTG_Read();
        gsmmsg[x++] = gsmbyte;
    }
    //In case of DST message.
    __delay_ms(5);


    x = 0x03;
    gsmtim[0] = '"';
    uint8_t i = 0x01;
    while(i < 0x09)
    {
        gsmtim[i] = gsmmsg[x];
        gsmtim[i+1] = gsmmsg[x+1];
        if(gsmmsg[x+1] == ',')
        {
            gsmtim[i+1] = gsmmsg[x];
            gsmtim[i] = '0';
            x--;
        }
        gsmtim[i+2] = '/';
        i = i + 3;
        x = x + 3;
    }
    gsmtim[i-1] = ',';
    
    
    while(i < 0x11)
    {
        gsmtim[i] = gsmmsg[x];
        gsmtim[i+1] = gsmmsg[x+1];
        if(gsmmsg[x+1] == ',')
        {
            gsmtim[i+1] = gsmmsg[x];
            gsmtim[i] = '0';
            x--;
        }
        gsmtim[i+2] = ':';
        i = i + 3;
        x = x + 3;
    }
    //This should take us to time zone dec i
    i--;
    x++;
    gsmtim[i] = gsmmsg[x];
    gsmtim[i+1] = '0';
    gsmtim[i+2] = gsmmsg[x+1];
    gsmtim[i+3] = '"';
    gsmtim[i+4] = '\r';
    gsmtim[i+5] = 0x00;
    offnet:
    gsm_msg(netoff);
    gsm_receive(1, gsmmsg);
    gsm_msg(clockw);
    gsm_msg(gsmtim);
    gsm_receive(1, gsmmsg);
    if(gsmmsg[0] != '0')
    {
        LATCbits.LC3 = 0;
        __delay_ms(2000);
        asm("RESET");
    }
}
//Receive unsolicited messages for 16 seconds
//and return the number of newlines.
uint8_t gsm_unsolic(void)
{
    gsm_zerobuff(gsmmsg, 0x100);
    uint8_t i = 1;
    uint16_t x = 0;
    uint8_t y = 0;
    resttim:
    TMR4_Initialize();
    T4CONbits.TMR4ON = 1;
    while(!PIR7bits.TMR4IF && x < 0x200)
    {
        gsmmsg[x] = UARTG_Read();
        if(gsmmsg[x] == '\n')
        {
            y++;
        }
        x++;
    }
    if(i > 0)
    {
        i--;
        goto resttim;
    }
    return y;
}

void gsm_receive(uint8_t noofline, uint8_t messagebuf[])
{
    gsmflags.meerror = 0;
    uint8_t x = 0;
    gsmbyte = 0;
    while(noofline > 0x00)
    {
        gsmbyte = UARTG_Read();
        if(gsmflags.meerror)
        {
            break;
        }
        messagebuf[x] = gsmbyte;
        x++;
        if(gsmbyte == 0x0A || gsmbyte == 0x00)
        {
            noofline--;
        }
    }
    x++;
    messagebuf[x] = 0;
}

void gsm_txAT(void)
{
    gsm_transmit('A');
    gsm_transmit('T');
}

//Turn on or off the gsm unit and initialize the 3 second startup timer.
/*#define PWR_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define PWR_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
*/
uint8_t gsm_on(void)
{
    gsm_msg("AT+CPOWD=0\n");
    __delay_ms(1000);
    led_switch(1);//RED
    PWRKEY_SetLow();
    One_Second();//Hold PWR low for 1 second
    PWRKEY_SetHigh();
    led_switch(2);//OFF
//    uint8_t x = 4;
//    gsm_receive(x, gsmusd);
    uint8_t x = Read_timeout1(gsmusd);
//    gsm_receive(10, gsmusd);
    return x;
}


uint8_t UARTG_Read(void)
{
    while(!PIR6bits.U2RXIF)
    {
    }

    return U2RXB;
}

void UARTG_Write(uint8_t txData)
{
    while(0 == PIR6bits.U2TXIF)
    {
    }

    U2TXB = txData;    // Write the data byte to the USART.
}



void One_Second(void)
{
    T1CONbits.TMR1ON = 0;
    TMR1_Initialize();
    TMR1_WriteTimer(0xF0DD);//TMR1 1 sec = 0x86E8 = 34536; 19036 = 0x4A5C
    T1CONbits.TMR1ON = 1;
    while(!PIR4bits.TMR1IF){}
    T1CONbits.TMR1ON = 0;
    PIR4bits.TMR1IF = 0;
}
/*
uint8_t gsm_Read(void)
{
    while(!PIR3bits.U1RXIF)
    {
        if(PIR7bits.TMR4IF)
        {
            break;
        }
    }

    
    if(1 == RC1STAbits.OERR)
    {
        // UART2 error - restart

        RC1STAbits.CREN = 0; 
        RC1STAbits.CREN = 1; 
    }

    return U2RXB;
}
*/
void gsm_off(void)
{
    gsm_msg("AT+CPOWD=0\n");
    __delay_ms(500);
}

void gsm_netwait(void)
{
    gsmbyte = 0;
    uint8_t x = 0;
    while(gsmbyte != 'S')
    {
        gsmbyte = UARTG_Read();
        gsmmsg[x++] = gsmbyte;
    }
    while(gsmbyte != '\n')
    {
        gsmbyte = UARTG_Read();
        gsmmsg[x++] = gsmbyte;
    }
}

bool delay_10mS(uint16_t count)
{
    TMR3_Initialize();
    TMR3_StartTimer();
    PIR6bits.TMR3IF = 0;
    while(count > 0)
    {
        if(PIR6bits.TMR3IF)
        {
            count--;
            TMR3_StopTimer();
            TMR3_Initialize();
            TMR3_StartTimer();
            PIR6bits.TMR3IF = 0;
        }
    }
    return 1;
}

//PIR3bits.U1TXIF -  UART2 Transmit Interrupt Flag bit
//1 = The UART2 transmit buffer, TX1REG, is empty (cleared by writing TX1REG)
//0 = The UART2 transmit buffer is full

//&& U2CON0bits.TXEN -  Transmit Enable bit SREN/CREN bits of RCxSTA (Register 27-2) override TXEN in Sync mode.
// 1 = Transmit enabled
// 0 = Transmit disabled

//U2ERRIRbits.TXMTIF -  Transmit Shift Register Status bit
// 1 = TSR empty TSR = Tx shift reg
// 0 = TSR full

//PIR3bits.U1RXIF -  UART2 Receive Interrupt Flag bit
//1 = The UART2 receive buffer, U2RXB, is full (cleared by reading U2RXB)
//0 = The UART2 receive buffer is empty


