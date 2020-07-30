//
// Example how to read the Zumo32U4 line sensors 
//
#include <Zumo32U4.h>

namespace {
  // Delay between loop()s in milliseconds
  constexpr unsigned long DELAY_MS = 250;

  // Line sensors interface
  Zumo32U4LineSensors lineSensors = Zumo32U4LineSensors{};

  // Enable the LCD Screen
  Zumo32U4LCD lcd = Zumo32U4LCD{};

  // Sensor values will go in this array
  // array indicies Left = 0, Center = 1, Right = 2
  unsigned int lineSensorValues[3] = {};
  // Constants for the accessing sensor values array indicies
  enum Position { LEFT = 0, CENTER = 1, RIGHT = 2 };
} 

void setup()
{
  // Initialize the sensors
  lineSensors.initThreeSensors();
}

void loop()
{
  // Read in the values
  lineSensors.read(lineSensorValues);

  // Display the values divided by 10 (to fit on LCD)
  //    L     R
  //       C
  lcd.clear();

  // Left sensor
  lcd.gotoXY(0, 0);
  lcd.print(lineSensorValues[Position::LEFT] / 10);

  // Right sensor
  lcd.gotoXY(5, 0);
  lcd.print(lineSensorValues[Position::RIGHT] / 10);

  // Center sensor
  lcd.gotoXY(3, 1);
  lcd.print(lineSensorValues[Position::CENTER] / 10);

  delay(DELAY_MS);
}