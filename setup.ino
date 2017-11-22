
  void setupButtons(){
  buttonUp.attachClick(clickUp);
  buttonSet.attachClick(clickSet);
  buttonUp.attachDuringLongPress(longPressUp);
  buttonDown.attachDuringLongPress(longPressDown);
  buttonSet.attachLongPressStart(longPressStartSet);
  buttonDown.attachClick(clickDown);
  }

  void setupRTC(){
  if (! rtc.begin()) {
      displayMsg("NO RTC...");   
      while (1);  
    }
   if (rtc.lostPower()) {
       rtc.adjust(DateTime(2017, 11, 8, 12, 12, 0));//(YEAR,MONTH,DAY,HOUR,MINUTE,SECONDE)
    }   
}

void setupMatrix(){
    matrix.begin();
    matrix.fillScreen(0);
    matrix.show();
    matrix.setTextWrap(false);
    matrix.setBrightness(brightness);
    matrix.setTextColor(color[colorIndex]);
}
