//{0 WORD ,1 YEAR,2 DATE,3 TIME,4 ANNIV,5 CROSS,10 SETYEAR,11 SETMONTH,12 SETDAY,13 SETHOUR,14 SETMINUTE} ;
void disp(){
  brightness=map(round(analogRead(pinPhoto)/-10),-100,0,5,100);
  matrix.setBrightness(constrain(brightness,5,100));
 // Serial.println(brightness);
  switch (mode) {
        case 0: //WORD
         displayWords(now.hour(),now.minute());
          break;
        case 1: //YEAR
         displayFourDigits(round(now.year()/100),now.year()%100);
          break;
        case 2: //DATE
         displayFourDigits(now.day(),now.month());
          break;
        case 3: //TIME
         displayFourDigits(now.hour(),now.minute());
          break;
        case 4: //ANNIV
         phraseHB;
         applyMask();
          break; 
        case 5: //CROSS
         phraseTOPCROSS; phraseBOTCROSS;
         applyMask();
          break; 
        case 10: //SETYEAR no max
        displayFourDigits(round(newYear/100),newYear%100);
          break;
        case 11: //SETMONTH max 12
        displayTwoDigits(newMonth);
          break;
        case 12: //SETDAY max 31
        displayTwoDigits(newDay);
          break;
        case 13: //SETHOUR max 23
        displayTwoDigits(newHour);
          break;
        case 14: //SETMINUTE 59
         displayTwoDigits(newMinute);
          break; 
       }
}


void displayFourDigits(int myTop, int myBot){
      int topRight=round(myTop/10);
      int botRight=round(myBot/10);
      int topLeft=myTop%10;
      int botLeft=myBot%10;
      matrix.fillScreen(0);
      displayNumber(0,0,charmap[topRight],color[colorIndex]);
      displayNumber(6,0,charmap[topLeft], color[colorIndex]);
      displayNumber(0,6,charmap[botRight],color[colorIndex]);
      displayNumber(6,6,charmap[botLeft], color[colorIndex]);
      matrix.show();
}
void displayTwoDigits(int myNumber){
      matrix.setTextColor(color[colorIndex]);
      int right=round(myNumber/10);
      int left=myNumber%10;
      matrix.fillScreen(0);
      matrix.setCursor(6, 2);
      matrix.print(left);
      matrix.setCursor(0, 2);
      matrix.print(right);
      matrix.show();
}
void displayMsg(String myMsg){
  matrix.setTextColor(color[colorIndex]);
  int len= myMsg.length()*-6-11;
  //Serial.println(myMsg);
  for (int i=11; i>len;i--){
  matrix.fillScreen(0);
  matrix.setCursor(i, 2);
  matrix.print(myMsg);
  matrix.show();
  delay(150);
  }
}

void displayNumber(uint8_t x, uint8_t y, const Character &c, uint16_t color) {
  for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) {
    if (bitRead(c[i], j)) matrix.drawPixel(x+4-j, y+i, color);
  }
}

