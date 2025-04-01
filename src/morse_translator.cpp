#include "morse_translator.h"

std::unordered_map<char, String> MORSE_CODE_DICT = {
  {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},
  {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."},
  {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
  {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."},
  {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
  {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
  {'Y', "-.--"}, {'Z', "--.."}, {'1', ".----"}, {'2', "..---"},
  {'3', "...--"}, {'4', "....-"}, {'5', "....."}, {'6', "-...."},
  {'7', "--..."}, {'8', "---.."}, {'9', "----."}, {'0', "-----"}
};

// Function to encode message to Morse code
String encodeToMorse(String message) {
  String cipher = "";
  message.trim(); // Remove accidental spaces/newlines

  for (char character : message) {  
    if (character != ' ') {
      // Handle both uppercase and lowercase
      if (MORSE_CODE_DICT.find(toupper(character)) != MORSE_CODE_DICT.end()) {
        cipher += MORSE_CODE_DICT[toupper(character)] + ' '; // Add Morse code and space
      } else {
        // Print error message if character is not found
        Serial.println("Warning: Unsupported character " + String(character) + " ignored.");
      }
    } else {
      // Check if the last two characters are not already spaces
      if (cipher.length() >= 2 && (cipher[cipher.length() - 2] != ' ' || cipher[cipher.length() - 1] != ' ')){
        cipher += "  "; // Double space for word separation
      }
    }
  }

  return cipher;
}

// Function to decode Morse code to message
String decodeFromMorse(String morseCode) {
  return ""; // Placeholder for decoding function
}
