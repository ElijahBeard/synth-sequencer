/*
  @Author: Eli
*/

#include <MozziGuts.h>
#include <Oscil.h>
#include <tables/sin2048_int8.h>

Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> aSin(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> bSin(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> cSin(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> dSin(SIN2048_DATA);

int gain1 = 1;
int gain2 = 1;
int gain3 = 1;
int gain4 = 1;

void setup() {
  startMozzi(256);
  aSin.setFreq(261);
  bSin.setFreq(329);
  cSin.setFreq(392);
  dSin.setFreq(493);
  pinMode(2, INPUT); // Set pin 2 as input for digital signal
  pinMode(3, INPUT); // Set pin 3 as input for digital signal
  pinMode(4, INPUT); // Set pin 4 as input for digital signal
  pinMode(5, INPUT); // Set pin 5 as input for digital signal
}

void updateControl(){
  //Digital in pins
  byte n1 = digitalRead(2);
  byte n2 = digitalRead(3);
  byte n3 = digitalRead(4);
  byte n4 = digitalRead(5);

  //The following are digital reads from the other arduino
  //This follows a "binary counter" to note which notes are active
  gain1 = map(n1, LOW, HIGH, 0, 255);
  gain2 = map(n2, LOW, HIGH, 0, 255);
  gain3 = map(n3, LOW, HIGH, 0, 255);
  gain4 = map(n4, LOW, HIGH, 0, 255);
}

int updateAudio() {
  int fin = (aSin.next() * gain1/2) + (bSin.next() * gain2/2) + (cSin.next() * gain3/2) + (dSin.next() * gain4/2);
  return fin >> 3;
}

void loop() {
  audioHook();
}
