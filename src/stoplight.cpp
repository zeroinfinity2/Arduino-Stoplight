#include <Arduino.h>

int lightPins[] = {8,10,12};
int button = 6;
int count = 0;
int buttonState;
int lastButtonState = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(lightPins[0], OUTPUT);
  pinMode(lightPins[1], OUTPUT);
  pinMode(lightPins[2], OUTPUT);
  pinMode(button, INPUT_PULLUP);
  digitalWrite(lightPins[0],HIGH);

  Serial.begin(9600);
}

void loop() {
buttonState = digitalRead(button);
  
  if (buttonState != lastButtonState) {
    if (buttonState == LOW) {
      count = (count + 1) % 3;
    
      for (int i = 0; i < 3; i++) {
        digitalWrite(lightPins[i],LOW);
      }

      digitalWrite(lightPins[count],HIGH);
      delay(500);
    }
    lastButtonState = buttonState;
  }

}
