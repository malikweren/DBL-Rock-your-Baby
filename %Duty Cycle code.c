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
  ledcSetup(Amotor, freq, resolution);`   //Setup the output channel for the Amplitude motor
  ledcSetup(Fmotor, freq, resolution);    //setup the output channel for the Frequency motor
  ledcAttachPin(AmotorPin, Amotor);   //connect the Amotor channel to the Amotor pin
  ledcAttachPin(FmotorPin, Fmotor);   //connect the Fmotor channel to the Fmotor pin
}

void setDutyCycle(int dutyCycle, int channel) {   //(dutyCycle percentage, Amotor/Fmotor)
  dutyCycle = 100 - dutyCycle;   //invert the signal, because it gets inverted by the motor circuit
  int analogValue = dutyCycle * 255 / 100;    //convert the dutyCycle to an analog value
  ledcWrite(channel, analogValue);    //set the PWM output on the given pin
}

void loop() {   //test program for the motors
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
