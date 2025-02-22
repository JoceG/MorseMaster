#ifndef MORSE_CODE_H
#define MORSE_CODE_H

#include <Arduino.h>
#include <unordered_map>

// Define Morse code dictionary
extern std::unordered_map<char, String> MORSE_CODE_DICT;

String encodeToMorse(String message);
String decodeFromMorse(String morseCode);

#endif
