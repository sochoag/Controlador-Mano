#include "Motor.h"
#include "pins.h"
#include "variables.h"
#include "oled.h"
#include "encoder.h"
#include "routine.h"

void (*resetFunc)(void) = 0;

void setup()
{
  Serial.begin(115200);
  oledInit();
  initRotary();
  while (!isSet)
  {
    checkRotary();
    checkButton();
  }
  runScreen();
  for (int i = 0; i < numDedos; i++)
  {
    dedo[i].init(motorIn1[i], motorIn2[i], motorPWM[i], motorFC1[i], motorFC2[i]);
  }
  digitalWrite(stby, HIGH);
}

void loop()
{
  while (!stopFlag)
  {
    firstRoutine();
    secondRoutine();
  }
  Serial.println("Out of loop");
  stopFlag = false;
  routineFlag = false;
  emergencyFlag = false;
  emergencyScreen();
  secondRoutine();
  delay(1000);
  resetFunc();
}