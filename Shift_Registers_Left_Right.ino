int latchPin=11;
int clockPin=9;
int dataPin=12;
int dt=500;

byte LEDs=0xFF;
byte LEDsb=0x00;


//byte LED1s=0b10101010;
//byte LED2s=0b01010101;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(latchPin,OUTPUT);
pinMode(dataPin,OUTPUT);
pinMode(clockPin,OUTPUT);
digitalWrite(latchPin,LOW);
shiftOut(dataPin,clockPin,LSBFIRST,LEDs); //This is used to turn all the lights on at begining
digitalWrite(latchPin,HIGH);
delay(dt +dt +dt +dt);                    //This is used to pause the full lights on
digitalWrite(latchPin,LOW);
shiftOut(dataPin,clockPin,LSBFIRST,LEDsb);
digitalWrite(latchPin,HIGH);
delay(dt +dt);
  LEDsb=0x99;                             //This is a seed number to begin a light sequence

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(latchPin,LOW);
shiftOut(dataPin,clockPin,LSBFIRST,LEDsb);
digitalWrite(latchPin,HIGH);
delay(dt);

  LEDsb = LEDsb/128 + LEDsb*2;    //This shifts all teh lights to the left
//LEDsb = LEDsb*128 + LEDsb/2;    //This shifts all the lights to the right
//LEDsb=LEDsb +1;                 //is is a binary counter
//LED1s = LED1s >> 1;

Serial.print(LEDsb);
Serial.print(", ");
Serial.print(LEDsb, BIN);
Serial.print(", ");
Serial.println(LEDsb, HEX);
}
