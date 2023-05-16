#ifndef PINS_H
#define PINS_H

// Motores
const byte motorIn1[] = {40, 36, 30, 28, 22};
const byte motorIn2[] = {42, 34, 32, 26, 24};
const byte motorPWM[] = {9, 10, 11, 12, 13};
const byte motorFC1[] = {41, 37, 33, 29, 25};
const byte motorFC2[] = {39, 35, 31, 27, 23};

const byte stby = 38;

// Encoder
const byte SW = 17;
const byte DT = 19;
const byte CLK = 18;

// Oled
const byte SCLPin = 21;
const byte SDAPin = 20;

#endif