#include "morse_player.h"

// Function to play the dot or dash on the board using the LED and buzzer
void playSignal(int BUZZER, int LED, int duration, int timeUnit, int i, int morseCodeLength) {
    digitalWrite(LED, HIGH); // Turn on LED
    tone(BUZZER, 1500); // Start buzzer

    waitTime(duration); // Light up and buzz for 'duration' milliseconds

    digitalWrite(LED, LOW); // Turn off LED
    noTone(BUZZER); // Stop buzzer

    // Only add extra delay if this is not the last character
    if (i < morseCodeLength - 1) {
        waitTime(timeUnit); // Add 1 time unit after every dot/dash 
    }
}

// Function to wait for 'duration' milliseconds
void waitTime(int duration) {
    int startTime = millis();
    while (millis() - startTime < duration) {
        // Wait for 'duration' milliseconds
    }
}

// Function to play the encrypted message on the board using the LED and buzzer
void playMorseCode(String morseCode, int BUZZER, int LED, int timeUnit){
    // Morse Code Spacing Rules:
    // - A single space (' ') represents a gap between letters (3 time units total)
    //   -> We already add a 1-unit gap after each dot/dash, so we add 2 extra units.
    // - Three consecutive spaces ('   ') represent a gap between words (7 time units total)
    //   -> Since each space is processed individually, this naturally results in 6 extra units.
    //
    // Examples:
    // - "hello"  -> ".... . .-.. .-.. ---"
    // - "hi there" -> ".... ..   - .... . .-. ."

    morseCode.trim(); 
    int morseCodeLength = morseCode.length();
  
    for (int i = 0; i < morseCode.length(); i++) {
        char character = morseCode[i];

        if (character == '.') {
            playSignal(BUZZER, LED, timeUnit, timeUnit, i, morseCodeLength); // Dot = 1 time unit
        } else if (character == '-') {
            playSignal(BUZZER, LED, timeUnit * 3, timeUnit, i, morseCodeLength); // Dash = 3 time units
        } else if (character == ' ') {
            // Each space adds 2 extra time units, so three spaces naturally result in 6 units
            waitTime(timeUnit * 2); 
        } else {
            Serial.println("Invalid character " + String(character) + " found in encrypted message"); // ignore unsupported characters
        }
    }
}
