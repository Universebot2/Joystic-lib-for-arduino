A simple joystic library for use with arduino. It requires nothing but three pins specified - and you have full access to your joystic control

to initialize: STICK your_name(button_pin, x_pin, y_pin)

All functions available are there in "all functions" example, but I'l duplicate them here:

available()) 1/true - stick in use, 0/false - stick in the middle position

button() 1 - button pressed, 0 - button released (in most common sticks button is connected to the ground, so it's data is inverted: 1 - released, 0 - pressed. That requires INPUT_PULLUP instead of INPUT.)

dir() returns direction by whitch stick is pointing: 1 - up, 2 - left, 3 - down, 4 - right

getAngleValue() returns the angle by which the stick is rotated

getDistance(min, max) how far the stick is deviated from the initial position

x() raw x axis value

y() raw y axis value
