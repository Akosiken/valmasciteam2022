#include <Adafruit_NeoPixel.h>
#define LED_PIN 10
#define LED_COUNT 1
#define DELAY 500

Adafruit_NeoPixel pixels(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);


void setup() {
  pixels.begin();
  pixels.clear();
}

void loop() {
  LED(255, 0, 0);
  LED(0, 255, 0);
  LED(0, 0, 255);
  LED(255, 255, 255);  
}

void LED(int RED, int BLUE, int GREEN){
  pixels.setPixelColor(0, pixels.Color(RED, BLUE, GREEN));
  pixels.show();
  delay(DELAY);
}
