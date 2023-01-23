/* 
 * File:   dispense.h
 * Author: Dave Plater
 *
 * Created on 24 March 2018, 12:49 PM
 */

#ifndef DISPENSE_H
#define	DISPENSE_H
#endif
#include "buffers.h"
#include "mcc_generated_files/mcc.h"
//#include "vend.h"
/*bool price_check(void);
//Prices per vend 8 x uint8_t*/
const uint16_t pricestore = 0x00;
volatile uint8_t pricevend[8];

/*void dispense(uint8_t chanel);
*/
//Remember to reset configuration

//__EEPROM_DATA(50,43,40,30,20,10,15,25) ; //0 to 7
/**__EEPROM_DATA(0,0,0,0,0,0,0,5) ; //8 to F
__EEPROM_DATA(10,15,20,25,30,35,40,0) ; //10 to 17
__EEPROM_DATA(0x07,0,0,0,0x02,0,0,0) ; //18 to 1F
__EEPROM_DATA(0x00,0,0,0,0x00,0,0,0) ; //20 to 27
__EEPROM_DATA(0x00,0,0,0,0x00,0,0,0) ; //28 to 2F
__EEPROM_DATA(0,0,0,0,0,0,0,0) ; //30 to 37
__EEPROM_DATA(0,0,0,0,0,0,0,0) ; //38 to 3F
__EEPROM_DATA('+','2','7','8','3','4','6','0') ; //40 to 47
__EEPROM_DATA('4','6','0','9',0,0,0,0) ; //48 to 4F
__EEPROM_DATA(0,0,0,0,0,0,0,0) ; //50 to 57
__EEPROM_DATA(0,0,0,0,0,0,0,0) ; //58 to 5F
 */
void vend_nosense(uint8_t chanel);

/*void vend_dispense(uint8_t chanel);

void set_motortime(uint8_t chanel);
*//*
void find_highprice(void);

void find_lowprice(void);

void create_chanmask(void);

void disable_channel(uint8_t chanel);

void init_pricestore(void);

void update_vends(uint8_t channel);
*/

