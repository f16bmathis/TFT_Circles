/* This will draw four colored circles that increase in size. Notes on almost all lines so you can figure out what the code does.
The TFT is a ELEGOO UNO R3 2.8 Inches TFT Touch Screen with SD Card Socket w/All Technical Data in CD for Arduino UNO R3 from AMAZON, run on a UNO. 
*/

#include <Arduino.h>
#define USE_ADAFRUIT_SHIELD_PINOUT 1
#include <Adafruit_GFX.h>                                      //added Adafruit GFX with BIO Whatever also
#include <MCUFRIEND_kbv.h>                                     //added mcufriend.kbv
MCUFRIEND_kbv tft;
 

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

float B;
int delta = 50;                  // 50 was middle of screen, 0 is top of screen, 100 at bottom of screen
int clockCenterX=120;            // 120 is center, 60 shifts left, 230 shifts right
int clockCenterY=110+delta;      // 110 is center, 0 is up, 220 is down   (not all the way to the center in both up & down)

#include <Wire.h>
#include <Adafruit_Sensor.h>                                                        
                                        
void setup() {

   Serial.begin(9600);
  uint16_t identifier = tft.readID();
    tft.begin(identifier);
    tft.fillScreen(BLACK);                                     // Unsure, seemed to have no effect
    tft.setRotation(0);                                                               // Flips Rotation 180 from 0 to 2
    return;
  }
void drawDisplay(float B)
{
    tft.fillScreen(BLACK);
// Draw Clockface
  // first clear clock
  tft.fillCircle(clockCenterX, clockCenterY, 100, RED);             // color of inside circle fill
  for (int i=0; i<10; i++)                                         // size of outter BLUE circle
  {
    tft.drawCircle(clockCenterX, clockCenterY, 100-i, BLUE);        // Color of outter circle
    delay (100);
  }
  for (int i=0; i<60; i++)                                            // Size of green center dot
  {
    tft.drawCircle(clockCenterX, clockCenterY, i, GREEN);           // Color of very center first dot
    delay (100);
  }
for (int i=0; i<40; i++)                                            // size of center fill, 99 makes a large center dot! Almost fills circle
  {
    tft.drawCircle(clockCenterX, clockCenterY, i, WHITE);          // Color of inner circle center fill dot
    delay (100);                                                          // Speed of c
  }
}
void loop(void)

{
drawDisplay(B);
delay (1000);
    }
