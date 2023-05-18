void checkMotors()
{
  for (int i = 0; i < numDedos; i++)
  {
    dedo[i].forward(vel);
  }
  delay(1000);
  for (int i = 0; i < numDedos; i++)
  {
    dedo[i].reverse(vel);
  }
  delay(1000);
  for (int i = 0; i < numDedos; i++)
  {
    dedo[i].stop();
  }
  delay(1000);
}

void checkEndStop()
{
  for (int i = 0; i < numDedos; i++)
  {
    if(dedo[i].getEndstop1()){
      Serial.println("Endstop 1 - "+String(i));
    }
    if(dedo[i].getEndstop2()){
      Serial.println("Endstop 1 - "+String(i));
    }
  }
}