#define LED_PIN_0 10
#define LED_PIN_1 11
#define LED_PIN_2 12
#define LED_PIN_3 13

#define BUTTON_PIN_0 7
#define BUTTON_PIN_1 6
#define BUTTON_PIN_2 5
#define BUTTON_PIN_3 4

#define SOUND_OUT 2
// #define CHANGE_0 2

int tempo = 32000;
int pattern = 0;
int counter = 0;

byte lastButtonState = LOW;
byte lastButtonState1 = LOW;
byte lastButtonState2 = LOW;
byte lastButtonState3 = LOW;

byte ledState = LOW;
byte ledState1 = LOW;
byte ledState2 = LOW;
byte ledState3 = LOW;

// second one lol
byte lastButtonState4 = LOW;
byte lastButtonState5 = LOW;
byte lastButtonState6 = LOW;
byte lastButtonState7 = LOW;

byte lastButtonState8 = LOW;

byte ledState4 = LOW;
byte ledState5 = LOW;
byte ledState6 = LOW;
byte ledState7 = LOW;

void setup() {
  pinMode(BUTTON_PIN_0, INPUT);
  pinMode(LED_PIN_0, OUTPUT);

  pinMode(BUTTON_PIN_1, INPUT);
  pinMode(LED_PIN_1, OUTPUT);

  pinMode(BUTTON_PIN_2, INPUT);
  pinMode(LED_PIN_2, OUTPUT);

  pinMode(BUTTON_PIN_3, INPUT);
  pinMode(LED_PIN_3, OUTPUT);

  pinMode(SOUND_OUT, OUTPUT);
  // pinMode(CHANGE_0, INPUT);

  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(1,OUTPUT);
}

void light_up()
{
  byte buttonState = digitalRead(BUTTON_PIN_0);
  byte buttonState1 = digitalRead(BUTTON_PIN_1);
  byte buttonState2 = digitalRead(BUTTON_PIN_2);
  byte buttonState3 = digitalRead(BUTTON_PIN_3);

  if (buttonState != lastButtonState) {
    lastButtonState = buttonState;
    if (buttonState == LOW) {
      ledState = (ledState == HIGH) ? LOW: HIGH;
      digitalWrite(LED_PIN_0, ledState);
    }
  }

  if (buttonState1 != lastButtonState1) {
    lastButtonState1 = buttonState1;
    if (buttonState1 == LOW) {
      ledState1 = (ledState1 == HIGH) ? LOW: HIGH;
      digitalWrite(LED_PIN_1, ledState1);
    }
  }

  if (buttonState2 != lastButtonState2) {
    lastButtonState2 = buttonState2;
    if (buttonState2 == LOW) {
      ledState2 = (ledState2 == HIGH) ? LOW: HIGH;
      digitalWrite(LED_PIN_2, ledState2);
    }
  }

  if (buttonState3 != lastButtonState3) {
    lastButtonState3 = buttonState3;
    if (buttonState3 == LOW) {
      ledState3 = (ledState3 == HIGH) ? LOW: HIGH;
      digitalWrite(LED_PIN_3, ledState3);
    }
  }

  delay(50);
}

void light_up2()
{
  byte buttonState4 = digitalRead(BUTTON_PIN_0);
  byte buttonState5 = digitalRead(BUTTON_PIN_1);
  byte buttonState6 = digitalRead(BUTTON_PIN_2);
  byte buttonState7 = digitalRead(BUTTON_PIN_3);

  if (buttonState4 != lastButtonState4) {
    lastButtonState4 = buttonState4;
    if (buttonState4 == LOW) {
      ledState4 = (ledState4 == HIGH) ? LOW: HIGH;
      digitalWrite(LED_PIN_0, ledState4);
    }
  }

  if (buttonState5 != lastButtonState5) {
    lastButtonState5 = buttonState5;
    if (buttonState5 == LOW) {
      ledState5 = (ledState5 == HIGH) ? LOW: HIGH;
      digitalWrite(LED_PIN_1, ledState5);
    }
  }

  if (buttonState6 != lastButtonState6) {
    lastButtonState6 = buttonState6;
    if (buttonState6 == LOW) {
      ledState6 = (ledState6 == HIGH) ? LOW: HIGH;
      digitalWrite(LED_PIN_2, ledState6);
    }
  }

  if (buttonState7 != lastButtonState7) {
    lastButtonState7 = buttonState7;
    if (buttonState7 == LOW) {
      ledState7 = (ledState7 == HIGH) ? LOW: HIGH;
      digitalWrite(LED_PIN_3, ledState7);
    }
  }

  delay(50);
}

void loop() {

  counter++; 

  if(counter > tempo){
    counter=0;
    pattern++;

    if(pattern >= 4){
      pattern = 0;
    }

    if(pattern == 0)
    {
      if(digitalRead(LED_PIN_0) == HIGH)
      {
        tone(SOUND_OUT, 110, 100);
        digitalWrite(8,HIGH);digitalWrite(9,LOW);digitalWrite(1,LOW);digitalWrite(3,LOW);
      } else {digitalWrite(8,LOW);digitalWrite(9,LOW);digitalWrite(1,LOW);digitalWrite(3,LOW);}
    }
    if(pattern == 1)
    {
      if(digitalRead(LED_PIN_1) == HIGH)
      {
        tone(SOUND_OUT, 210, 100);
        digitalWrite(8,LOW);digitalWrite(9,HIGH);digitalWrite(1,LOW);digitalWrite(3,LOW);
      } else {digitalWrite(8,LOW);digitalWrite(9,LOW);digitalWrite(1,LOW);digitalWrite(3,LOW);}
    }
    if(pattern == 2)
    {
      if(digitalRead(LED_PIN_2) == HIGH)
      {
        tone(SOUND_OUT, 310, 100);
        digitalWrite(8,LOW);digitalWrite(9,LOW);digitalWrite(1,HIGH);digitalWrite(3,LOW);
      } else {digitalWrite(8,LOW);digitalWrite(9,LOW);digitalWrite(1,LOW);digitalWrite(3,LOW);}
    }
    if(pattern == 3)
    {
      if(digitalRead(LED_PIN_3) == HIGH)
      {
        tone(SOUND_OUT, 410, 100);
        digitalWrite(8,LOW);digitalWrite(9,LOW);digitalWrite(1,LOW);digitalWrite(3,HIGH);
      } else {digitalWrite(8,LOW);digitalWrite(9,LOW);digitalWrite(1,LOW);digitalWrite(3,LOW);}
    }

  //   byte ButtonState8 = digitalRead(CHANGE_0);

  //   if(ButtonState8 != lastButtonState8)
  //   {
  //     lastButtonState8 = ButtonState8;
  //     if(buttonState8 == LOW)
  //     {
        
  //     }
  //   }

  //   if (buttonState3 != lastButtonState3) {
  //   lastButtonState3 = buttonState3;
  //   if (buttonState3 == LOW) {
  //     ledState3 = (ledState3 == HIGH) ? LOW: HIGH;
  //     digitalWrite(LED_PIN_3, ledState3);
  //   }
  // }

    light_up();
  }

}
