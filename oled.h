#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#include <Adafruit_I2CDevice.h>

/* Uncomment the initialize the I2C address , uncomment only one, If you get a totally blank screen try the other*/
#define i2c_Address 0x3c // initialize with the I2C addr 0x3C Typically eBay OLED's
// #define i2c_Address 0x3d //initialize with the I2C addr 0x3D Typically Adafruit OLED's

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1    //   QT-PY / XIAO
Adafruit_SH1106G oled = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void oledInit()
{
  oled.begin(i2c_Address, true);
}

void showMenu()
{
  oled.setCursor(0, 0);
  oled.clearDisplay();
  oled.setTextSize(1);
  oled.setTextColor(SH110X_WHITE, SH110X_BLACK);
  oled.println("MENU");
  if (menuOption == 1)
    oled.print(">");
  oled.print("Pulgar:");
  oled.println(dedoState[0] ? "SI" : "NO");
  if (menuOption == 2)
    oled.print(">");
  oled.print("Indice:");
  oled.println(dedoState[1] ? "SI" : "NO");
  if (menuOption == 3)
    oled.print(">");
  oled.print("Medio:");
  oled.println(dedoState[2] ? "SI" : "NO");
  if (menuOption == 4)
    oled.print(">");
  oled.print("Anular:");
  oled.println(dedoState[3] ? "SI" : "NO");
  if (menuOption == 5)
    oled.print(">");
  oled.print("Menique:");
  oled.println(dedoState[4] ? "SI" : "NO");
  if (menuOption == 6)
    oled.print(">");
  oled.print("Velocidad:");
  oled.println(velOption[velIndex]);
  if (menuOption == 7)
    oled.print(">");
  oled.println("Inicio");
  oled.display();

  Serial.println("Menu");
  Serial.println("------------------------");
  if (menuOption == 1)
    Serial.print(">");
  Serial.print("Pulgar:\t");
  Serial.println(dedoState[0]);
  if (menuOption == 2)
    Serial.print(">");
  Serial.print("Indice:\t");
  Serial.println(dedoState[1]);
  if (menuOption == 3)
    Serial.print(">");
  Serial.print("Medio:\t");
  Serial.println(dedoState[2]);
  if (menuOption == 4)
    Serial.print(">");
  Serial.print("Anular:\t");
  Serial.println(dedoState[3]);
  if (menuOption == 5)
    Serial.print(">");
  Serial.print("Menique:\t");
  Serial.println(dedoState[4]);
  Serial.println("------------------------");
  if (menuOption == 6)
    Serial.print(">");
  Serial.print("Velocidad:\t");
  Serial.println(velOption[velIndex]);
  Serial.println("------------------------");
  if (menuOption == 7)
    Serial.print(">");
  Serial.println("Inicio");
  Serial.println("------------------------");
}

void emergencyScreen()
{
  oled.setCursor(5, 25);
  oled.clearDisplay();
  oled.setTextSize(2);
  oled.setTextColor(SH110X_WHITE, SH110X_BLACK);
  oled.println("DETENIENDO");
  oled.display();
}

void runScreen()
{
  oled.setCursor(5, 25);
  oled.clearDisplay();
  oled.setTextSize(2);
  oled.setTextColor(SH110X_WHITE, SH110X_BLACK);
  oled.println("EJECUTANDO");
  oled.display();
}