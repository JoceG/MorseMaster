#ifndef MORSE_PLAYER_H
#define MORSE_PLAYER_H

#include <Arduino.h>

void playSignal(int BUZZER, int LED, int duration, int timeUnit, int i, int morseCodeLength);
void waitTime(int duration);
void playMorseCode(String morseCode, int LED, int BUZZER, int timeUnit);

#endif
