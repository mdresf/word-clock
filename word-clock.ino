#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include <Wire.h> 
#include <OneButton.h>
#include <RTClib.h>

//############################################################################################################################################################

#define pinLed 0
#define pinUp 5
#define pinSet 4
#define pinDown 1
#define pinPhoto A5

uint16_t mask[11];

#define phraseITS        mask[0] |= 0xE000
#define phraseA          mask[0] |= 0x800
#define phraseFIVE       mask[2] |= 0x1E0
#define phraseTEN        mask[1] |= 0x7000
#define phraseQUARTER    mask[1] |= 0xFE0
#define phraseTWENTY     mask[2] |= 0xFC00
#define phraseHALF       mask[0] |= 0x3C0
#define phrasePAST       mask[3] |= 0x3C0
#define phraseTO         mask[3] |= 0x1800
#define hourONE          mask[9] |= 0xE000
#define hourTWO          mask[9] |= 0x1C00//mask[7]  |= 0xE0
#define hourTHREE        mask[9] |= 0x3E0
#define hourFOUR         mask[10]|= 0xF000
#define hourFIVE         mask[7] |= 0xF000
#define hourSIX          mask[7] |= 0xE0//mask[9]  |= 0x1C00
#define hourSEVEN        mask[4] |= 0x7C00
#define hourEIGHT        mask[8] |= 0x3E0
#define hourNINE         mask[7] |= 0xF00
#define hourTEN          mask[6] |= 0xE0
#define hourELEVEN       mask[8] |= 0xFC00
#define hourNOON         mask[4] |= 0x1E0
#define hourMIDNIGHT     mask[6] |= 0xFF00
#define phraseOCLOCK     mask[10]|= 0x7E0
#define phraseHB         mask[0] |= 0x200, mask[1] |= 0x200, mask[2] |= 0x200, mask[3] |= 0x200, mask[4] |= 0x200, mask[5] |= 0x7DC0, mask[7] |= 0x780
#define phraseTOPCROSS   mask[0] |= 0x1F00, mask[1] |= 0x400, mask[2] |= 0x400, mask[3] |= 0x8420, mask[4] |= 0x8420, mask[5] |= 0xFFE0
#define phraseBOTCROSS   mask[10]|= 0x1F00, mask[9] |= 0x400, mask[8] |= 0x400, mask[7] |= 0x8420, mask[6] |= 0x8420
RTC_DS3231 rtc;//on sda and slc

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(11,11,pinLed,NEO_MATRIX_TOP + NEO_MATRIX_LEFT + NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,NEO_GRB + NEO_KHZ800);
const uint16_t color[] = {matrix.Color(255, 255, 255),matrix.Color(255, 0, 0),matrix.Color(0, 0, 255),matrix.Color(0, 255, 0),matrix.Color(128, 255, 128)};
int colorIndex=0;
int brightness=100;

OneButton buttonUp(pinUp, false); // define the 3 buttons
OneButton buttonSet(pinSet, false);
OneButton buttonDown(pinDown, false);


int mode=0;//{0 WORD ,1 YEAR,2 DATE,3 TIME,4 ANNIV,5 CROSS,10 SETYEAR,11 SETMONTH,12 SETDAY,13 SETHOUR,14 SETMINUTE} ;
int modeMax=3;//cross; set to 3 to hide cross and happy birthday 
boolean settings = false;
//int previousMode=99;
DateTime now;
uint16_t newYear; uint8_t newMonth; uint8_t newDay; uint8_t newHour; uint8_t newMinute;


typedef uint8_t Character[5];
const Character charmap[]  = {
  { 0b01110,0b10001,0b10001,0b10001,0b01110},//0
  { 0b00100,0b01100,0b00100,0b00100,0b00100 },//1
  { 0b01110,0b10001,0b00010,0b00100,0b11111 },//2
  { 0b01110,0b00001,0b00110,0b00001,0b01110 },//3
  { 0b00110,0b01010,0b10010,0b11111,0b00010 },//4
  { 0b01111,0b01000,0b01110,0b00001,0b01110 },//5
  { 0b01110,0b10000,0b11110,0b10001,0b01110 },//6
  { 0b11110,0b00010,0b00100,0b01000,0b01000 },//7
  { 0b01110,0b10001,0b01110,0b10001,0b01110 },//8
  { 0b01111,0b01001,0b01111,0b00001,0b00001,}};//9

//############################################################################################################################################################

void setup() {
   setupMatrix();
   setupButtons();
   setupRTC();  
//rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
   displayMsg(F("Pour Ines de la part de Martin..."));
//Serial.begin(9600); 
//while(!Serial);

}

//############################################################################################################################################################

void loop() {
 now = rtc.now();   
 buttonUp.tick();
 buttonSet.tick();
 buttonDown.tick();
if ((now.dayOfTheWeek()==5)&&(now.hour()==7)&&(now.minute()==0)&&(now.second()<10)){  mode=5; }//CROSS
if (now.month()==4 && now.day()==8&&(now.hour()==0)&&(now.minute()==0)){  mode=4;}//anniv 8 avril
 disp();
 delay(50); 
}

