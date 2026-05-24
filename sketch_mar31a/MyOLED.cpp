#include "MyOLED.h"
#include <Adafruit_SSD1306.h>//OLED库函数
#include <Wire.h>
#include "MyQueue.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void MyOLED_Init(void)
{
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  oled.clearDisplay();
  oled.display();
}

void MyOLED_ShowFace_EyeBox(void)
{
  oled.clearDisplay();
  oled.fillRect(35, 18, 24, 24, WHITE);
  oled.fillRect(69, 18, 24, 24, WHITE); 
  oled.display();
}

void MyOLED_ShowFace_Squint(void)
{
  oled.clearDisplay();
  oled.drawLine(36, 30, 56, 30, WHITE);
  oled.drawLine(36, 34, 56, 34, WHITE);
  oled.drawLine(72, 30, 92, 30, WHITE);
  oled.drawLine(72, 34, 92, 34, WHITE);
  oled.display();
} 
void MyOLED_ShowFace_Wink(void) 
{
  oled.clearDisplay();
  oled.fillRect(35, 18, 24, 24, WHITE);
  oled.drawLine(72, 30, 92, 30, WHITE);
  oled.drawLine(72, 34, 92, 34, WHITE);
  oled.display();
}
void MyOLED_ShowFace_SmileEye(void)
{
  oled.clearDisplay();
  oled.drawLine(38, 28, 46, 32, WHITE);
  oled.drawLine(46, 32, 54, 28, WHITE);
  oled.drawLine(38, 32, 46, 36, WHITE);
  oled.drawLine(46, 36, 54, 32, WHITE);
  oled.drawLine(74, 28, 82, 32, WHITE);
  oled.drawLine(82, 32, 90, 28, WHITE);
  oled.drawLine(74, 32, 82, 36, WHITE);
  oled.drawLine(82, 36, 90, 32, WHITE);
  oled.display();
}