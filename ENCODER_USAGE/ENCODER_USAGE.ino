#include <Adafruit_NeoPixel.h>

#define CLK 19
#define DT 18
#define SW 6
#define LED_PIN 10
#define LED_COUNT 1
#define DELAY 500

int counter = 0;
int currentStateCLK;
int lastStateCLK;
int mod;
String currentDir ="";

Adafruit_NeoPixel pixels(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  
  // Set encoder pins as inputs
  pinMode(CLK,INPUT);
  pinMode(DT,INPUT);
  pinMode(SW, INPUT_PULLUP);
  
  pixels.begin();
  pixels.clear();

  Serial.begin(9600);
  lastStateCLK = digitalRead(CLK);
}

void loop() {
  
  currentStateCLK = digitalRead(CLK);

  if (currentStateCLK != lastStateCLK  && currentStateCLK == 0){
    if (digitalRead(DT) != currentStateCLK) {
      currentDir = "CW";
      CW_LED();    
    } 
    else { 
      currentDir = "CCW";
      CCW_LED();
    }
  }
  
  else if (currentStateCLK == lastStateCLK  && currentStateCLK == 0){
    if (currentDir == "CW") {
      CW_LED();    
    } 
    else { 
      CCW_LED();
    }
  }
  
  lastStateCLK = currentStateCLK;
  delay(1);
}

void CW_LED(){
  LED(255, 0, 0);
  LED(0, 255, 0);
  LED(0, 0, 255);
  LED(255, 255, 255);
}

void CCW_LED(){
  LED(255, 0, 0);
  LED(255, 255, 255);
  LED(0, 0, 255);
  LED(0, 255, 0);
}

void LED(int RED, int BLUE, int GREEN){
  pixels.clear();
  pixels.setPixelColor(0, pixels.Color(RED, BLUE, GREEN));
  pixels.show();
  delay(DELAY);
}
