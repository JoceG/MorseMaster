#include <Arduino.h>
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();  // Create TFT instance

void setup() {
  tft.init();                 
  tft.fillScreen(TFT_BLACK);  
  tft.setTextColor(TFT_WHITE, TFT_BLACK);  
  tft.setTextSize(4);        
}

void loop() {
  tft.setCursor(10, 30);      
  tft.println("Hello");
  delay(1000);
}
