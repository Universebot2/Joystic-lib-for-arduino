#include <Arduino.h>

class STICK {
public:

  STICK(byte btn, byte x, byte y) {
    _x = x;
    _y = y;
    _btn = btn;
    pinMode(_btn, INPUT_PULLUP);
  };
  int getDistance(uint8_t min, uint8_t max) {
    return (map(hypot(x(), y()), 0, 625, min, max));
  }

  int getAngleValue(void) {
    if (available()) {
      return (atan2(x(), y()) * radian + 180);
    } else {
      return (400);
    }
  }


  int x(void) {
    stickX = map(analogRead(_x), 0, 1024, -512 - x_neutral, 512 - x_neutral);
    return (stickX);
  }


  int y(void) {
    stickY = map(analogRead(_y), 0, 1024, 512 - y_neutral, -512 - y_neutral);
    return (stickY);
  }

  void calibrate() {
    x_neutral = map(analogRead(_x), 0, 1024, 512, -512);
    y_neutral = map(analogRead(_y), 0, 1024, 512, -512);
  };

  int dir(void) {
    switch (getAngleValue()) {
      case 135 ... 225:
        return (3);
        break;
      case 0 ... 45:
        return (1);
        break;
      case 315 ... 360:
        return (1);
        break;

      case 46 ... 134:
        return (2);
        break;
      case 226 ... 314:
        return (4);
        break;
    }
  }

  bool available() {
    if (x() >= 0 + x_noise || x() <= 0 - x_noise || y() >= 0 + y_noise || y() <= 0 - y_noise) {
      return (true);
    } else {
      return (false);
    }
  }

  bool button() {
    if (digitalRead(_btn) == 0) {
      return (true);
    } else {
      return (false);
    }
  }


private:
  byte _x;
  byte _y;
  byte _btn;
  int x_neutral = 25;
  int y_neutral = -29;
  int radian = 180 / 3.14;
  int stickX, stickY;
  uint8_t x_noise = 35;
  uint8_t y_noise = 35;
};