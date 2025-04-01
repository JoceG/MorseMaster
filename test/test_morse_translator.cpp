#include <Arduino.h>
#include <AUnit.h>
#include "../src/morse_translator.h"

test(encodeEmptyStringTest) {
    String input = "";
    String expected = "";  // An empty string should result in an empty Morse code string
    String result = encodeToMorse(input);

    assertEqual(result, expected);
}

test(encodeLowerCaseTest) {
    String input = "hello";
    String expected = ".... . .-.. .-.. --- ";  // Expecting it to be the same as "HELLO"
    String result = encodeToMorse(input);

    assertEqual(result, expected);
}
    
test(encodeNumbersTest) {
    String input = "12345";
    String expected = ".---- ..--- ...-- ....- ..... ";  // Morse code for 1-5
    String result = encodeToMorse(input);
  
    assertEqual(result, expected);
}

test(encodeInvalidCharactersTest) {
    String input = "HELLO@WORLD";
    String expected = ".... . .-.. .-.. --- .-- --- .-. .-.. -.. ";  // Just ignore the unsupported '@'
    String result = encodeToMorse(input);
  
    assertEqual(result, expected);
}
  

test(encodeMultipleSpacesTest) {
    String input = "HELLO    WORLD";
    String expected = ".... . .-.. .-.. ---   .-- --- .-. .-.. -.. ";  // Multiple spaces should still result in a single space
    String result = encodeToMorse(input);
  
    assertEqual(result, expected);
}
  
test(encodeMixedInputTest) {
    String input = "HELLO 123";
    String expected = ".... . .-.. .-.. ---   .---- ..--- ...-- ";  // Expected Morse code with both letters and numbers
    String result = encodeToMorse(input);
  
    assertEqual(result, expected);
}

test(encodeTrailingSpacesTest) {
    String input = "HELLO ";
    String expected = ".... . .-.. .-.. --- ";  // No trailing space should appear in the result
    String result = encodeToMorse(input);
  
    assertEqual(result, expected);
}

test(encodeAllTrailingSpacesTest) {
    String input = "  ";
    String expected = "";  // An empty string should result in an empty Morse code string
    String result = encodeToMorse(input);

    assertEqual(result, expected);
}
  
test(encodeLongInputTest) {
    // Create the input string by repeating "HELLO " 100 times
    String input = "";
    for (int i = 0; i < 100; i++) {
        input += "HELLO ";
    }

    // Create the expected Morse code by repeating ".... . .-.. .-.. ---   " 99 times
    String expected = "";
    for (int i = 0; i < 99; i++) {
        expected += ".... . .-.. .-.. ---   ";
    }

    // Complete the expected Morse code by adding ".... . .-.. .-.. --- " 
    expected += ".... . .-.. .-.. --- ";

    // Run the Morse encoding
    String result = encodeToMorse(input);
  
    // Compare the result with the expected value
    assertEqual(result, expected);
}
