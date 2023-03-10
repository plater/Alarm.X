/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <stdbool.h>
#include <string.h>
#include <errno.h>
/* Get ptrdiff_t.  */
#include <stddef.h>/* Use the signed type 'ptrdiff_t'.  */
/* Note: ISO C does not mandate that 'size_t' and 'ptrdiff_t' have the same
   size, but it is so on all platforms we have seen since 1990.  */
typedef ptrdiff_t idx_t;

#include <xc.h> // include processor files - each processor file is guarded.  
#include "sonar.h"

#endif	//XC_HEADER_TEMPLATE_H

    bool ledredflash;
    bool ledgreenflash;
    bool ledredon;
    bool ledgreenon;
    bool ledslow;
    bool ledfast;
    bool ledchange;

volatile uint8_t pricevend[8];
//Gsm related memory
uint8_t gsmbyte;
//moble network code 01 = Vodacom, 10 or 12 = Mtn
uint8_t mncbyte;
uint8_t credit;
//gsm scratch pad
//Gsm related memory
//uint8_t gsmbyte =error: 0;
//moble network code 01 = Vodacom, 10 or 12 = Mtn
//uint8_t mncbyte = 0;
//gsm scratch pad
uint8_t gsmmsg[256];

uint16_t distant[512];
//sms storage
//uint8_t gsmums[512];
//ussd storage
uint8_t gsmusd[128];
//Store unsolicited notifications
uint8_t gsmusm[128];
uint8_t gsmtim[23];
//Store date
uint8_t gsdate[10];
//Store time
uint8_t gstime[10];
//Phone number scratch pad
uint8_t phnumb[11];
uint8_t noofline;
uint16_t index;


uint8_t  gsmtim[23];
//uint8_t  qrbuffer[256];
//char     base64buf[64];
//char     snap64buf[256];
//uint8_t  merchkey[40];
uint16_t distantcount;
#if 0
uint16_t  prices[8];

uint8_t qchan[2];
//uint8_t qprice[4];

signed int translngth;
uint8_t transid[10];//195
unsigned long long cntlength;
unsigned long long countstore;
uint8_t urlbuf[200];

uint8_t * searchbufa;

int price;
uint8_t channum;
#endif
/**dispense related
 */
volatile uint8_t cash;
volatile uint8_t buttons;
volatile uint16_t vendprice;
volatile uint8_t sensorval;
volatile uint8_t vcash[2];
volatile uint8_t nvcash[3];
volatile uint8_t tvends[8];
volatile uint8_t vcashout[2];
volatile uint16_t pvcash;
volatile __uint24 pnvcash;
volatile uint8_t senspos;
volatile uint8_t highprice;
volatile uint8_t lowprice;
volatile uint8_t chanmask;
volatile uint8_t errormask;
volatile uint8_t channel;


/*static const uint8_t clockdate[] = "  Date:";
static const uint8_t clocktime[] = "  Time:";
*/

void gsm_zerobuff(uint8_t* gsmsgbuf, uint16_t count );

void build_record_url(char * restrict basebuf, const char * restrict snapurl );

void snap_buildurl(void);

void build_url(void);

void led_opperate(void);

void led_switch(uint8_t color);

void price_init(void);

void price_set(void);

void One_Second(void);

/** Prototypes from tcpip.h */
void tcp_httpget(uint8_t httpurl[128], bool sslflag);

void http_receive(uint8_t noofline, uint8_t *messagebuf);

uint32_t ascnumtohex(uint8_t *numberbuf);

int tls_get_payment(void);

void tls_getseed(void);

int OpenConnection(void);

void gsm_init(bool inittype);

uint8_t UARTG_Read(void);

void dispense(uint8_t chanel);

uint8_t Read_timeout(uint8_t *msgadd);

uint8_t Read_timeout1(uint8_t *msgadd);

//void base64_encode (const uint8_t *in, idx_t inlen, uint8_t *out, idx_t outlen);

//void store_merchkey(void);

void mkey_init(void);

bool delay_10mS(uint16_t count);

uint8_t Read_Service(void);

void Read_SMS(void);

void Call_Me(void);

void Call_Home(void);

uint8_t Get_Battery(void);

uint8_t Get_Signal(void);

void Orange_light(void);

void Store_Count(void);

void Retrieve_Count(void);

void DATAEE_WriteWord(uint16_t bAdd, uint16_t bData);

uint16_t DATAEE_ReadWord(uint16_t bAdd);


#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */


