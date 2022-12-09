#include <M5Stack.h>

 

const int sensorPin = 36;       // define which pin is the input
int tmpHigh = 0;
int tmpLow = 0;
float timr = 0;
float period = 0;
float heartRate = 0;              //This is the value of the heartrate which can be used in the algorithm code.
float tempheartRate = 0;
float triggervalue1 = 100;      // below this value the signal is considered to be voltage minimum (including error margin)
float triggervalue2 = 4000;     // above this value the signal is considered to be voltage peak (including error margin)
float analogInput = 50;

 

void setup() {
  M5.begin();
}

void loop() {
analogInput = analogRead(sensorPin);          // read the input and store it in variable analogInput

if(analogInput > triggervalue2 && tmpHigh == 0){

  timr = 0;
  tmpHigh = 1;

}

delay(2);                     //these two lines are the timer
timr = timr + 2;

if(analogInput < triggervalue1 && tmpHigh == 1){

  tmpLow = 1;

}

if(analogInput > triggervalue2 && tmpLow == 1){
  period = timr;
  tempheartRate = 60/(period/1000);
  tmpLow = 0;
  tmpHigh = 0;


  if (heartRate > 55 && heartRate < 240){       //remove outliers
    heartRate = tempheartRate;
  }
}

}