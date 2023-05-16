#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_I2CDevice.h>

Adafruit_SSD1306 oled(128, 64, &Wire);

void oledInit()
{
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}

void showMenu()
{
  oled.setCursor(0,0);
  oled.clearDisplay(); 
  oled.setTextSize(1);     
  oled.setTextColor(WHITE, BLACK);
  oled.println("MENU");
  if (menuOption == 1) oled.print(">");
  oled.print("Motor 1:");
  oled.println(dedoState[0]?"SI":"NO");
  if (menuOption == 2) oled.print(">");
  oled.print("Motor 2:");
  oled.println(dedoState[1]?"SI":"NO");
  if (menuOption == 3) oled.print(">");
  oled.print("Motor 3:");
  oled.println(dedoState[2]?"SI":"NO");
  if (menuOption == 4) oled.print(">");
  oled.print("Motor 4:");
  oled.println(dedoState[3]?"SI":"NO");
  if (menuOption == 5) oled.print(">");
  oled.print("Motor 5:");
  oled.println(dedoState[4]?"SI":"NO");
  if (menuOption == 6) oled.print(">");
  oled.print("Velocidad:");
  oled.println(velOption[velIndex]);
  if (menuOption == 7) oled.print(">");
  oled.println("Inicio");
  oled.display();

  Serial.println("Menu");
  Serial.println("------------------------");
  if (menuOption == 1) Serial.print(">");
  Serial.print("Motor 1:\t");
  Serial.println(dedoState[0]);
  if (menuOption == 2) Serial.print(">");
  Serial.print("Motor 2:\t");
  Serial.println(dedoState[1]);
  if (menuOption == 3) Serial.print(">");
  Serial.print("Motor 3:\t");
  Serial.println(dedoState[2]);
  if (menuOption == 4) Serial.print(">");
  Serial.print("Motor 4:\t");
  Serial.println(dedoState[3]);
  if (menuOption == 5) Serial.print(">");
  Serial.print("Motor 5:\t");
  Serial.println(dedoState[4]);
  Serial.println("------------------------");
  if (menuOption == 6) Serial.print(">");
  Serial.print("Velocidad:\t");
  Serial.println(velOption[velIndex]);
  Serial.println("------------------------");
  if (menuOption == 7) Serial.print(">");
  Serial.println("Inicio");
  Serial.println("------------------------");
}

void emergencyScreen()
{
  oled.setCursor(5,25);
  oled.clearDisplay();
  oled.setTextSize(2);
  oled.setTextColor(WHITE, BLACK);
  oled.println("DETENIENDO");
  oled.display();
}

void runScreen()
{
  oled.setCursor(5,25);
  oled.clearDisplay();
  oled.setTextSize(2);
  oled.setTextColor(WHITE, BLACK);
  oled.println("EJECUTANDO");
  oled.display();
}