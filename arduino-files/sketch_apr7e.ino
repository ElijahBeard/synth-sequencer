/*
  @Author: Eli
*/

#include <MozziGuts.h>
#include <Oscil.h>
#include <tables/sin2048_int8.h>

#define CONTROL_RATE 128
Oscil <2048, AUDIO_RATE> aSin(SIN2048_DATA);
byte gain = 255;

void setup(){
	aSin.setFreq(9600);
	startMozzi(CONTROL_RATE);
  //Serial.begin(9600);
}

void updateControl(){
}

int updateAudio(){
  if(digitalRead(4) == LOW && digitalRead(2) == LOW && digitalRead(3) == HIGH){
    Serial.println("1");
    aSin.setFreq(261);
  }
  if(digitalRead(4) == LOW && digitalRead(2) == HIGH && digitalRead(3) == LOW){
    Serial.println("2");
    aSin.setFreq(329);
  }
  if(digitalRead(4) == LOW && digitalRead(2) == HIGH && digitalRead(3) == HIGH){
    Serial.println("3");
    aSin.setFreq(392);
  }
  if(digitalRead(4) == HIGH && digitalRead(2) == LOW && digitalRead(3) == LOW){
    Serial.println("4");
    aSin.setFreq(493);
  }
  if(digitalRead(4) == LOW && digitalRead(2) == LOW && digitalRead(3) == LOW){
    Serial.println("0");
    return (aSin.next()* gain)>>8;
  }
  return aSin.next();
}

void loop(){
  // if(digitalRead(4) == LOW && digitalRead(2) == LOW && digitalRead(3) == LOW){
  //   Serial.println("4");
  // }
	audioHook();
}
