#include <Arduino.h>
#include <BleMouse.h>

#define BUTTON_PIN 9  // BOOT button on ESP32-C3
#define DOUBLE_CLICK_TIME 500

BleMouse bleMouse("Dell Wireless Mouse WM126", "Dell", 100);

enum JiggleMode { NONE, SLOW, FAST, ZIGZAG };
JiggleMode jiggleMode = NONE;

unsigned long lastJiggleTime = 0;
unsigned long lastButtonPressTime = 0;
int buttonPressCount = 0;
bool buttonLastState = HIGH;

int zigzagStep = 0;
const int zigzagSteps = 20;
bool zigzagDirection = true; // true = ↘️, false = ↙️

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  bleMouse.begin();
  Serial.println("🔌 BLE Mouse started. Waiting for connection...");
}

void handleButtonPress() {
  bool buttonState = digitalRead(BUTTON_PIN);
  if (buttonLastState == HIGH && buttonState == LOW) {
    unsigned long now = millis();
    if (now - lastButtonPressTime < DOUBLE_CLICK_TIME) {
      buttonPressCount++;
    } else {
      buttonPressCount = 1;
    }
    lastButtonPressTime = now;
  }
  buttonLastState = buttonState;

  if (millis() - lastButtonPressTime > DOUBLE_CLICK_TIME) {
    if (buttonPressCount == 1) {
      jiggleMode = (jiggleMode == SLOW) ? NONE : SLOW;
      Serial.println(jiggleMode == SLOW ? "🟢 Jiggle mode: SLOW (every minute, wide range)" : "🔴 Jiggle mode: OFF");
    } else if (buttonPressCount == 2) {
      jiggleMode = FAST;
      Serial.println("⚡ Jiggle mode: FAST (every second, short range)");
    } else if (buttonPressCount == 3) {
      jiggleMode = ZIGZAG;
      zigzagStep = 0;
      Serial.println("🌀 Jiggle mode: ZIGZAG (diagonal movement)");
    }
    buttonPressCount = 0;
  }
}

void loop() {
  handleButtonPress();

  if (bleMouse.isConnected() && jiggleMode != NONE) {
    unsigned long now = millis();
    unsigned long interval = 0;

    switch (jiggleMode) {
      case SLOW:
        interval = 60000;
        break;
      case FAST:
        interval = 1000;
        break;
      case ZIGZAG:
        interval = 100;  // faster for zigzag pattern
        break;
      default:
        return;
    }

    if (now - lastJiggleTime >= interval) {
      int dx = 0, dy = 0;

      if (jiggleMode == SLOW) {
        dx = random(-50, 51);
        dy = random(-50, 51);
      } else if (jiggleMode == FAST) {
        dx = random(-3, 4);
        dy = random(-3, 4);
      } else if (jiggleMode == ZIGZAG) {
        // Simulate scribble with aggressive random diagonal movement
        int pattern = zigzagStep % 4;

        switch (pattern) {
            case 0:
            dx = random(15, 25);
            dy = random(15, 25);    // ↘️
            break;
            case 1:
            dx = random(-25, -15);
            dy = random(-25, -15);  // ↖️
            break;
            case 2:
            dx = random(15, 25);
            dy = random(-25, -15);  // ↗️
            break;
            case 3:
            dx = random(-25, -15);
            dy = random(15, 25);    // ↙️
            break;
        }

        zigzagStep++;
        if (zigzagStep >= 20) zigzagStep = 0;
        }


      bleMouse.move(dx, dy);
      Serial.printf("🖱️ Mouse moved: x=%d y=%d\n", dx, dy);
      lastJiggleTime = now;
    }
  }

  delay(10);
}
