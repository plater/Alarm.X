/* 
 * File:   operate.h
 * Author: Dave Plater
 * Comments:
 * Date:   Tue 23 Feb 15:25:46 SAST 2021
 */

#include "mcc_generated_files/mcc.h"

struct
{
    unsigned firstalarm : 1;
    unsigned nextalarm :  1;
    unsigned compareok : 1;
    unsigned venddly : 1;
    unsigned dischk : 1;
    unsigned motexit : 1;
} oppflags;

struct
{
    unsigned sonerr1 : 1;
    unsigned sonerr2 :  1;
    unsigned compareok : 1;
    unsigned venddly : 1;
    unsigned dischk : 1;
    unsigned motexit : 1;
} errflag;



//Data eeprom addresses
const uint8_t mtime = 0x00;
const uint8_t distmaxl = 0x01;
const uint8_t distmaxh = 0x02;
const uint8_t beeps = 0x03;

uint8_t alarms;
uint8_t seconds;
uint8_t mottime;
uint16_t compare0;
uint16_t compare1;
uint16_t compared;
uint16_t compare2;
uint16_t maxdist2;
uint16_t maxdist;
uint8_t maxdistl;
uint8_t maxdisth;

void SoundAlarm(uint16_t);
void Dispense(void);
void Service(void);
bool ReadServ(void);
void SetMotor(void);
bool ReadSonar();
void ReadDispense(void);
uint16_t GetMaxDist(void);
uint16_t GetMaxDist2(void);
