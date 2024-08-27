#include <SoftwareSerial.h>

SoftwareSerial HC12(2, 3); // HC-12 TX Pin, HC-12 RX Pin

// Morse code mapping: you can extend this for more characters
const char* morseAlphabet[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",
};

void setup() {
  Serial.begin(9600);
  HC12.begin(9600);
}

void loop() {
  // Receiver Arduino can both send and receive
  while (HC12.available()) {
    String morseCode = HC12.readStringUntil('\n');
    if (morseCode.length() > 0) {
      String receivedMessage = decodeMorse(morseCode);
      Serial.println("Received Morse Code: " + morseCode);
      Serial.println("Decoded Message: " + receivedMessage);
    }
  }

  while (Serial.available()) {
    String message = Serial.readStringUntil('\n');
    if (message.length() > 0) {
      if (message == "receive") {
        // Switch to receive mode when "receive" is sent
        while (HC12.available()) {
          String morseCode = HC12.readStringUntil('\n');
          String receivedMessage = decodeMorse(morseCode);
          Serial.println("Received Morse Code: " + morseCode);
          Serial.println("Decoded Message: " + receivedMessage);
        }
      } else {
        String morseCode = convertToMorse(message);
        HC12.println(morseCode);
      }
    }
  }
}

String convertToMorse(String text) {
  String morseCode = "";
  text.toUpperCase();

  for (size_t i = 0; i < text.length(); i++) {
    char c = text.charAt(i);
    if (isAlpha(c)) {
      int index = c - 'A';
      if (index >= 0 && index < 26) {
        morseCode += morseAlphabet[index];
        morseCode += " ";
      }
    } else if (c == ' ') {
      morseCode += "  ";
    }
  }

  return morseCode;
}

String decodeMorse(String morseCode) {
  String decodedMessage = "";
  int morseLen = morseCode.length();
  String morseCharacter = "";

  for (int i = 0; i < morseLen; i++) {
    char c = morseCode.charAt(i);

    if (c == ' ') {
      if (morseCharacter == "") {
        decodedMessage += " ";
      } else {
        for (int j = 0; j < 26; j++) {
          if (String(morseAlphabet[j]) == morseCharacter) {
            decodedMessage += (char)('A' + j);
            break;
          }
        }
        morseCharacter = "";
      }
    } else {
      morseCharacter += c;
    }
  }

  for (int j = 0; j < 26; j++) {
    if (String(morseAlphabet[j]) == morseCharacter) {
      decodedMessage += (char)('A' + j);
      break;
    }
  }

  return decodedMessage;
}
