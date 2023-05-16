#include "Motor.h"
#include "pins.h"
#include "variables.h"
#include "routine.h"
#include "oled.h"
#include "encoder.h"

void(* resetFunc) (void) = 0;

void setup()
{
  Serial.begin(9600);
  oledInit();
  initRotary();
  while(!isSet){
    checkRotary();
    checkButton();
  }
  runScreen();
  for (int i = 0; i < numDedos; i++)
  {
    dedo[i].init(motorIn1[i], motorIn2[i], motorPWM[i], motorFC1[i], motorFC2[i]);
  }
  digitalWrite(stby, HIGH);
  initEmergencyStop();
}

void loop()
{
  while (!stopFlag)
  {
    firstRoutine();
    secondRoutine();
  }
  emergencyScreen();
  secondRoutine();
  resetFunc();
}