#include <M5Stack.h>

const int ledPin = 26;
const int sensorPin = 35;
int tmpHigh = 0;
int tmpLow = 0;
int timr = 0;
int period = 0;
int heartRate = 0;

void setup() {
  M5.begin();
  pinMode (ledPin, OUTPUT);

}

 

void loop() {

int analogInput = analogRead(sensorPin);

if(analogInput > 800 && tmpHigh == 0){          
  timr = millis();
  tmpHigh = 1;
}

if(analogInput < 800 && tmpHigh == 1){
  tmpLow = 1;
}

 

if(analogInput > 800 && tmpLow == 1){
  int temp2 = millis();
  period = temp2 - timr;
  heartRate = 60/(period/1000);
  tmpLow = 0;
  tmpHigh = 0;
  M5.Lcd.print(heartRate);

}

}