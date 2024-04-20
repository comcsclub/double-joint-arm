
#include <stdlib.h>
#define DIR_PIN 2
#define STEP_PIN 3
class StepperS { // The class
  public: // Access specifier
    int currSteps; // Attribute (int variable)
    StepperS() {
      currSteps = 0;
      pinMode(DIR_PIN, OUTPUT);
      pinMode(STEP_PIN, OUTPUT);
    }
    void moveSteps(int steps) {
      int _step = 1;
      int absSteps = abs(steps);
      if (steps > 0) {
        digitalWrite(DIR_PIN, HIGH);
      } else {
        _step  = -1;
        digitalWrite(DIR_PIN, LOW);
      }

     for (int i = 0; i < absSteps; i++) {

        this->currSteps += _step;
        digitalWrite(STEP_PIN, HIGH);
        delayMicroseconds(199);
        digitalWrite(STEP_PIN, LOW);
        delayMicroseconds(199);
      }
    };
};

StepperS mystepper;
// the setup routine runs once when you press reset:
const int POT_MAX = 1024/16;
const int ONE_REV = 1600;
const int POT_TO_STEP = POT_MAX / ONE_REV;
char buffer[200];

int prevSensorVal = 0;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  mystepper.moveSteps(400);
  prevSensorVal = analogRead(A0);

}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorVal =  analogRead(A0);
  int sensorValDiff = sensorVal - prevSensorVal;
  if (sensorValDiff > 0 || sensorValDiff < 0 ) {
    mystepper.moveSteps(sensorValDiff);
    prevSensorVal = sensorVal;
  }
  
  sprintf(buffer,"sensor val %d sensor val diff %d \n", sensorVal, sensorValDiff);
  Serial.println(buffer);
  //  mystepper.moveSteps(200);
  //  delay(1000); // delay in between reads for stability
  //  mystepper.moveSteps(-200);

}
