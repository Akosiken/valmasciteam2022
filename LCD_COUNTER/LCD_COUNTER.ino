#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define scrwid 128
#define scrhei 64
#define scradr 0x3C
#define DELAY 100

int i; 
int x;

Adafruit_SSD1306 display(scrwid, scrhei, &Wire, -1);

void setup() {
  Serial.begin(115200);
  
  if (!display.begin(SSD1306_SWITCHCAPVCC, scradr)){
    Serial.println(F("SSD12306 allocation failed"));
    for (;;);
  }
}

void loop() {
  lcdsetup();
  
  for(i = 1; i <= 20; i++){

    if (i>8){
      lcdsetup();
        for (x = 7; x > 0; x--) {
        display.println(i-x);
      }
      display.println(i);
      delay(DELAY);
      }

    else {
    display.println(i);
    delay(DELAY);
    }

    display.display();
  }
}

void lcdsetup(){
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
}
