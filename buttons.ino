

//{0 WORD ,1 YEAR,2 DATE,3 TIME,4 ANNIV,5 CROSS,10 SETYEAR,11 SETMONTH,12 SETDAY,13 SETHOUR,14 SETMINUTE} ;
  
// CALLBACK FUNCTION FOR BUTTON Up
void clickUp() {
//Serial.println(F("clickUp"));
    if (settings){
          switchUp();
     //serialPrintNewDate();
    }else{
      if (mode <modeMax ){mode = mode+1;}else{ mode=0;}
     //rtc.adjust( now + TimeSpan(300));
     // Serial.println(mode);
    }
} // end clickUp

void longPressUp() {
//Serial.println(F("longPressUp"));
    if (settings){
          switchUp();
          delay(200);
          //serialPrintNewDate();
    }
} // end longPressUp

void switchUp(){
    switch (mode) {
        case 10: //SETYEAR no max
        newYear+=1;
          break;
        case 11: //SETMONTH max 12
         if (newMonth >=12){ newMonth=1;}else{newMonth+=1;}
          break;
        case 12: //SETDAY max 31
          if (newDay >=31){ newDay=1;}else{newDay+=1;}
          break;
        case 13: //SETHOUR max 23
          if (newHour >=23){ newHour=0;}else{newHour+=1;}
          break;
        case 14: //SETMINUTE 59
          if (newMinute>=59){ newMinute=0;}else{newMinute+=1;}
          break; 
       }
}
// CALLBACK FUNCTION FOR BUTTON Down
void clickDown() {
//Serial.println(F("clickDown"));
   if (settings){
           switchDown();
           //serialPrintNewDate();
   }else{
          if (mode >modeMax) {mode=modeMax;} 
          else{
          if (mode >0 ){ mode = mode-1;}else{mode=modeMax;}
          }
          
         //rtc.adjust( now + TimeSpan(3600));
         // Serial.println(mode);
   }
} //end clickDown
void longPressDown() {
//Serial.println(("longPressDown"));
   if (settings){
           switchDown();
           delay(200);
          // serialPrintNewDate();
           
   }
} //end longPressDown

void switchDown(){
   switch (mode) {
      case 10: //SETYEAR min 2015
      newYear-=1;
      if (newYear <=2015) {newYear-=1;}
        break;
      case 11: //SETMONTH min 1
       if (newMonth <=1) {newMonth=12;}else{newMonth-=1;}
        break;
      case 12: //SETDAY min 1
        if (newDay <=1) {newDay=31;}else{newDay-=1;}
        break;
      case 13: //SETHOUR min 0
        if (newHour <=0) {newHour=23;}else{newHour-=1;}
        break;
      case 14: //SETMINUTE min 0
        if (newMinute<=0) {newMinute=59;}else{newMinute-=1;}
        break; 
     }
}

// CALLBACK FUNCTION FOR BUTTON Set
void clickSet() {
//Serial.println(F("clickSet"));
    if (settings){
              switch (mode) {           
                case 10: //SETYEAR
                    mode = mode+1;
                  break;
                case 11: //SETMONTH   
                   mode = mode+1;
                  break;
                case 12: //SETDAY
                   mode = mode+1;
                  break;
                case 13: //SETHOUR
                   mode = mode+1;
                  break;
                case 14: //SETMINUTE
                  //serialPrintNewDate();
                  rtc.adjust(DateTime(newYear, newMonth, newDay, newHour, newMinute, 0));
                  settings=false;
                  mode = 0;
                  colorIndex=0;
                  break; }
      } else{
        if (colorIndex<=3){
          colorIndex+=1;
        }else{
          colorIndex=0;
        }
      }
 }//end clickSet



void longPressStartSet() {
  
  if (!settings){
        Serial.println("enter setting mode");
        settings=true;
        mode=10;//setyear
        newYear=now.year();
        newMonth=now.month();
        newDay=now.day();
        newHour=now.hour();
        newMinute=now.minute();
        colorIndex=4;
  }
} //end longPressStartSet

/*
void serialPrintDate(){
    Serial.print("now: ");
    Serial.print(now.year(), DEC);    Serial.print('/');
    Serial.print(now.month(), DEC);    Serial.print('/');
    Serial.print(now.day(), DEC);    Serial.print(" (");
    Serial.print(now.hour(), DEC);    Serial.print(':');
    Serial.print(now.minute(), DEC);    Serial.print(':');
    Serial.println(now.second(), DEC);
}
void serialPrintNewDate(){
    Serial.print("new date: ");
    Serial.print(newYear, DEC);    Serial.print('/');
    Serial.print(newMonth, DEC);    Serial.print('/');
    Serial.print(newDay, DEC);    Serial.print(" (");
    Serial.print(newHour, DEC);    Serial.print(':');
    Serial.println(newMinute, DEC);
}
*/

