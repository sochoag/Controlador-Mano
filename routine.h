#ifndef ROUTINE_H
#define ROUTINE_H
void firstRoutine()
{
  Serial.println("FirstRoutine");
  // Acciono y espero que el primer dedo se cierre completamente
  if (!emergencyFlag)
  {
    if (dedoState[0])
    {
      while (!dedo[0].getEndstop1() && !emergencyFlag)
      {
        checkButton();
        dedo[0].forward(vel);
      }
      dedo[0].stop();
      while (!dedo[0].getEndstop2() && !emergencyFlag)
      {
        checkButton();
        dedo[0].reverse(vel);
      }
      dedo[0].stop();
    }
    // Acciono los demas dedos
    for (int i = 1; i < numDedos; i++)
    {
      if (dedoState[i])
      {
        dedo[i].forward(vel);
      }
    }
    while (!routineFlag)
    {
      checkButton();
      byte movingCount = 0;
      for (int i = 0; i < numDedos; i++)
      {
        if (dedo[i].getEndstop1())
        {
          dedo[i].stop();
        }
        if (dedo[i].moving())
        {
          movingCount++;
        }
      }
      if (movingCount == 0)
      {
        routineFlag = true;
      }
    }
    routineFlag = false;
  }
}

void secondRoutine()
{
  Serial.println("SecondRoutine");
  // Acciono los demas dedos
  if (!emergencyFlag)
  {

    for (int i = 1; i < numDedos; i++)
    {
      if (dedoState[i])
      {
        dedo[i].reverse(vel);
      }
    }
    while (!routineFlag)
    {
      checkButton();
      byte movingCount = 0;
      for (int i = 0; i < numDedos; i++)
      {
        if (dedo[i].getEndstop2())
        {
          dedo[i].stop();
        }
        if (dedo[i].moving())
        {
          movingCount++;
        }
      }
      if (movingCount == 0)
      {
        routineFlag = true;
      }
    }
    routineFlag = false;
    // Acciono y espero que el primer dedo se cierre completamente
    // if (dedoState[0])
    // {
    //   while (!dedo[0].getEndstop2() && !emergencyFlag)
    //   {
    //     checkButton();
    //     dedo[0].reverse(vel);
    //   }
    //   dedo[0].stop();
    // }
  }
}
#endif