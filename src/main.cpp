#include <Arduino.h>
#include <TFT_eSPI.h>

#define GREEN_BUTTON 33
#define RED_BUTTON 32
#define BUZZER 25
#define LED 26

TFT_eSPI tft = TFT_eSPI(); // Create TFT instance

unsigned long previousMillis = 0;
const long interval = 1000; // Time interval to check every 1000ms

void setup() {  
  tft.init();                 
  tft.fillScreen(TFT_BLACK);  
  tft.setTextColor(TFT_WHITE, TFT_BLACK);  
  tft.setTextSize(4);   
  tft.setCursor(10, 30);      
  tft.println("Hello");
  
  pinMode(GREEN_BUTTON, INPUT_PULLUP);
  pinMode(RED_BUTTON, INPUT_PULLUP);
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);

  Serial.begin(115200);
}

void loop() {
  unsigned long currentMillis = millis();

  // Check if 1000ms have passed
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis; // Reset the previous time to now

    int greenButtonState = digitalRead(GREEN_BUTTON); // Pressed = LOW, Released = HIGH
    int redButtonState = digitalRead(RED_BUTTON); // Pressed = LOW, Released = HIGH

    if (greenButtonState == LOW) {
      digitalWrite(LED, HIGH);
      tone(BUZZER, 2000);
    } else {
      digitalWrite(LED, LOW);
      noTone(BUZZER);
    }

    if (redButtonState == LOW) {
      Serial.println("Red button is pressed");
    }
  }
}
