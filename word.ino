void displayWords(int myHour,int myMinute) {
   phraseITS;//Always on
//calculate minutes 
    if(myMinute>=0  && myMinute<5 && myHour!=0 && myHour!=12) { phraseOCLOCK;}
    if(myMinute>=5  && myMinute<10){ phraseFIVE; phrasePAST;}    
    if(myMinute>=10 && myMinute<15){ phraseTEN; phrasePAST;}
    if(myMinute>=15 && myMinute<20){ phraseA; phraseQUARTER; phrasePAST;}
    if(myMinute>=20 && myMinute<25){ phraseTWENTY; phrasePAST;}
    if(myMinute>=25 && myMinute<30){ phraseTWENTY; phraseFIVE; phrasePAST;}
    if(myMinute>=30 && myMinute<35){ phraseHALF; phrasePAST;}
    if(myMinute>=35 && myMinute<40){ phraseTWENTY; phraseFIVE; phraseTO;}
    if(myMinute>=40 && myMinute<45){ phraseTWENTY; phraseTO;}
    if(myMinute>=45 && myMinute<50){ phraseA; phraseQUARTER; phraseTO;}    
    if(myMinute>=50 && myMinute<55){ phraseTEN; phraseTO;}
    if(myMinute>=55 && myMinute<60){ phraseFIVE;phraseTO;}
    
 // Calculate hour 
    if(myHour==0)             { if(myMinute<35){hourMIDNIGHT;}   else { hourONE;}}
    if(myHour==1||myHour==13) { if(myMinute<35){hourONE;}   else { hourTWO;}}
    if(myHour==2||myHour==14) { if(myMinute<35){hourTWO;}   else { hourTHREE;}}
    if(myHour==3||myHour==15) { if(myMinute<35){hourTHREE;} else { hourFOUR;}}
    if(myHour==4||myHour==16) { if(myMinute<35){hourFOUR;}  else { hourFIVE;}}
    if(myHour==5||myHour==17) { if(myMinute<35){hourFIVE;}  else { hourSIX;}}
    if(myHour==6||myHour==18) { if(myMinute<35){hourSIX;}   else { hourSEVEN;}}
    if(myHour==7||myHour==19) { if(myMinute<35){hourSEVEN;} else { hourEIGHT;}}
    if(myHour==8||myHour==20) { if(myMinute<35){hourEIGHT;} else { hourNINE;}}
    if(myHour==9||myHour==21) { if(myMinute<35){hourNINE;}  else { hourTEN;}}
    if(myHour==10||myHour==22){ if(myMinute<35){hourTEN;}   else { hourELEVEN;}}
    if(myHour==11)            { if(myMinute<35){hourELEVEN;}else { hourNOON;}}   
    if(myHour==12)            { if(myMinute<35){hourNOON;}  else { hourONE;}}
    if(myHour==23)            { if(myMinute<35){hourELEVEN;}else { hourMIDNIGHT;}}

  applyMask(); 
}

void applyMask() {
   matrix.fillScreen(0);
   for (byte row = 0; row < 11; row++) 
   {
      for (byte col = 0; col < 11; col++) 
      {
         if ( bitRead(mask[row], 15 - col)){
          matrix.drawPixel(col, row, color[colorIndex]);
         }
      }
   mask[row] = 0;// reset mask for next row
   }
   matrix.show(); // show it!
}
