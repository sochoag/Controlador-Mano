#ifndef VARIABLES_H
#define VARIABLES_H

byte dedoState[] = {true, true, true, true, true};
byte numDedos = sizeof(motorIn1) / sizeof(motorIn1[0]);
Motor dedo[5];
bool routineFlag = false;
bool stopFlag = false;
bool isSet = false;
bool emergencyFlag = false;

byte velIndex = 0;
String velOption[] = {"Lento", "Medio", "Rapido"};
byte velValue[] = {64, 127, 255};
byte vel = velValue[0];

bool dtLastState = false;
int menuOption = 1;

#endif