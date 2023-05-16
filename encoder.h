void emergencyStop()
{
  Serial.println("Emergencia");
  stopFlag = true;
}

void initRotary()
{
  pinMode(SW, INPUT_PULLUP);
  pinMode(DT, INPUT);
  pinMode(CLK, INPUT);
  dtLastState = digitalRead(DT);
  showMenu();
}

void initEmergencyStop()
{
  attachInterrupt(digitalPinToInterrupt(DT), emergencyStop, FALLING);
}

void checkRotary()
{
    bool dtState = digitalRead(DT);
    bool clkState = digitalRead(CLK);
    if(dtState != dtLastState){
      delay(250);
      if(clkState == dtState){
        menuOption = menuOption > 6 ? 1 : menuOption + 1;
      }
      else{
        menuOption = menuOption <= 1 ? 7 : menuOption - 1;
      }
      showMenu();
    }
    // dtLastState = dtState;
}

void checkButton()
{
  if(!digitalRead(SW))
  {
    delay(250);
    if(menuOption < 6){
      dedoState[menuOption-1] = !dedoState[menuOption-1];  
    }
    if(menuOption == 6){
      velIndex = velIndex >= 2 ? 0 : velIndex + 1;
      vel = velValue[velIndex];
    }
    if(menuOption == 7){
      isSet = true;
    }
    showMenu();
  }
}