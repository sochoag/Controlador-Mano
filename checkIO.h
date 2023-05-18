void checkMotors()
{
  Serial.println("Forward");
  dedo[2].forward(255);
  delay(1000);
  Serial.println("Reverse");
  dedo[2].reverse(255);
  delay(1000);
  Serial.println("Stop");
  dedo[2].stop();
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
      Serial.println("Endstop 2 - "+String(i));
    }
  }
  delay(500);
}