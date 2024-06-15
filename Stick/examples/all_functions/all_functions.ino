#include <stick.h>

STICK stick(A0, A2, A1); // button pin, X axis pin, Y axis pin

void setup() {
  Serial.begin(9600);

  stick.calibrate(); //place your joystic in the middle position while calibration


}

void loop() {
    Serial.print("if available: ");
    Serial.print(stick.available()); //checks if the stick is in use
    Serial.print(" button:");
    Serial.print(stick.button()); //gets button state
    Serial.print(" direction: ");
    Serial.print(stick.dir()); // 1 - up, 2 - left, 3 - down, 4 - right
    Serial.print(" angle: ");
    Serial.print(stick.getAngleValue()); // returns the angle by which the stick is rotated
    Serial.print(" distance: ");
    Serial.print(stick.getDistance(1024, 0)); // how far the stick is deviated from the initial position
    Serial.print(" X: ");
    Serial.print(stick.x()); //raw x axis value
    Serial.print(" Y: ");
    Serial.println(stick.y()); //raw y axis value
  delay(50);

}
