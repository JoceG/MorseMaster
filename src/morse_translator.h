#ifndef MORSE_TRANSLATOR_H
#define MORSE_TRANSLATOR_H

#include <Arduino.h>
#include <unordered_map>

// Define Morse code dictionary
extern std::unordered_map<char, String> MORSE_CODE_DICT;

String encodeToMorse(String message);
String decodeFromMorse(String morseCode);

#endif
