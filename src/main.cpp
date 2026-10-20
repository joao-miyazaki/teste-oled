#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "bad_apple_frames.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define I2C_SDA 32
#define I2C_SCL 33

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
    Serial.begin(115200);
    Wire.begin(I2C_SDA, I2C_SCL);

    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println(F("ERROR: OLED not found!"));
        for(;;);
    }

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 25);
    display.print(F("Loading Bad Apple..."));
    display.display();
    delay(2000);
}

void loop() {
    for (int i = 0; i < TOTAL_FRAMES; i++) {
        unsigned long startTime = millis();

        display.clearDisplay();
        
      
        display.drawBitmap(0, 0, bad_apple_frames[i], 128, 64, SSD1306_WHITE);
        
        display.display();

        unsigned long elapsed = millis() - startTime;
        if (elapsed < 33) {
            delay(33 - elapsed);
        }
    }
}