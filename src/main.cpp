#include <Arduino.h>
#include <AUnit.h>
#include <TFT_eSPI.h>
#include "morse_translator.h"  
#include "morse_player.h"  
#include "../test/test_morse_translator.cpp"

#define GREEN_BUTTON 33
#define RED_BUTTON 32
#define BUZZER 25
#define LED 26

TFT_eSPI tft = TFT_eSPI(); // Create TFT instance
bool first_loop = true;
unsigned long startMillis = millis();
int timeUnit = 100;

void setup() {
  startMillis = millis();
  Serial.begin(115200);
  while (!Serial);  // Wait for Serial Monitor to connect

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
}

void loop() {
  aunit::TestRunner::run(); // Run all tests

  if (millis() - startMillis > 1000) {
    if (first_loop) {
      Serial.println("Enter a message to convert to Morse code:");  
      first_loop = false;
    }

    if (Serial.available() > 0) {  // Check if data is available in Serial buffer
      String message = "";
  
      // Keep reading until we get a newline (Enter key)
      while (true) {
        if (Serial.available() > 0) {
          char receivedChar = Serial.read(); // Read one character
          if (receivedChar == '\n') break; // Stop when Enter is pressed
          message += receivedChar; // Append to message
        }
      }
  
      message.trim(); // Remove accidental spaces/newlines
  
      if (message.length() > 0) { // Ensure valid input
        String morseCode = encodeToMorse(message);
        if (morseCode != "") {
          Serial.println("Morse Code: " + morseCode);
          playMorseCode(morseCode, BUZZER, LED, timeUnit);
        }
      } else {
        Serial.println("Error: Empty input received.");
      }
  
      Serial.println("\nEnter a message to convert to Morse code:");
    }
  } 
}
