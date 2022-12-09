#include <M5Stack.h>

const int AmotorPin = 1;
const int FmotorPin = 2;
const int freq = 1000;
const int Amotor = 1;
const int Fmotor = 2;
const int resolution = 8;
int dutyCycle = 0;

void setup(){
  M5.begin(); //Init M5Core. Initialize M5Core
  ledcSetup(Amotor, freq, resolution);
  ledcSetup(Fmotor, freq, resolution);
  ledcAttachPin(AmotorPin, Amotor);
  ledcAttachPin(FmotorPin, Fmotor);
}

void setDutyCycle(int dutyCycle, int channel) {
  int analogValue = dutyCycle * 255 / 100;
  ledcWrite(channel, analogValue);
}

void loop() {
  for(dutyCycle = 10; dutyCycle <= 90; dutyCycle += 20) {
    setDutyCycle(dutyCycle, Amotor);
    setDutyCycle(100-dutyCycle, Fmotor);
    delay(5000);
  }
  for(dutyCycle = 90; dutyCycle >= 10; dutyCycle -= 20) {
    setDutyCycle(dutyCycle, Amotor);
    setDutyCycle(100-dutyCycle, Fmotor);
    delay(5000);
  }
}