#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "SensorValidation.h"

TEST_CASE("reports error when soc jumps abruptly") {
  double socReadings[] = {0.0, 0.01, 0.5, 0.51};
  int numOfSocReadings = sizeof(socReadings) / sizeof(socReadings[0]);
  REQUIRE(validateSensorReadings_i(socReadings, numOfSocReadings) == 0);
}

TEST_CASE("reports error when current jumps abruptly") {
  double currentReadings[] = {0.0, 0.02, 0.03, 0.33};
  int numOfCurReadings = sizeof(currentReadings) / sizeof(currentReadings[0]);
  REQUIRE(validateSensorReadings_i(currentReadings, numOfCurReadings) == 0);
}

