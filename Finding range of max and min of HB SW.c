#include <M5Stack.h>

const int sensorPin = 36;

int tmpHigh = 0;
int tmpLow = 0;
int timr = 0;
int period = 0;
int heartRate = 0;
float analogInput = 0;
float minimum = 10000;   //set max for minimum to start from
float maximum = 0;      //set min for maximum to start from


void setup() {
  M5.begin();
}

void loop(){

analogInput = analogRead(sensorPin);

if (analogInput > maximum){         //This loop is to set a new maximum when the new value is higher than previous max value


  maximum = analogInput;

  M5.Lcd.print("NEW MAX = ");

  M5.Lcd.println(analogInput);

}

if (analogInput < minimum && analogInput > 0){      //This loop is to set a new minimum when the new value is lower than previous min value

  minimum = analogInput;

  M5.Lcd.print("NEW MIN = ");

  M5.Lcd.println(analogInput);

}

}