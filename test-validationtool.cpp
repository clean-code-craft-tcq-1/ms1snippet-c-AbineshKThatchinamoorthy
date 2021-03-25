#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "SensorValidation.h"

TEST_CASE("reports error when soc increases abruptly") {
  double socReadings[] = {0.0, 0.01, 0.5, 0.51};
  int numOfSocReadings = sizeof(socReadings) / sizeof(socReadings[0]);
  REQUIRE(validateSensorReadings_i(socReadings, numOfSocReadings, SOC_DIFF_THRESHOLD) == 0);
}

TEST_CASE("reports error when soc decreases abruptly") {
  double socReadings[] = {0.02, 0.06, 0.0, 0.02};
  int numOfSocReadings = sizeof(socReadings) / sizeof(socReadings[0]);
  REQUIRE(validateSensorReadings_i(socReadings, numOfSocReadings, SOC_DIFF_THRESHOLD) == 0);
}

TEST_CASE("Test for no error when soc varies normally") {
  double socReadings[] = {0.02, 0.06, 0.04, 0.051};
  int numOfSocReadings = sizeof(socReadings) / sizeof(socReadings[0]);
  REQUIRE(validateSensorReadings_i(socReadings, numOfSocReadings, SOC_DIFF_THRESHOLD) == 1);
}

TEST_CASE("reports error when current increases abruptly") {
  double currentReadings[] = {0.0, 0.02, 0.03, 0.33};
  int numOfCurReadings = sizeof(currentReadings) / sizeof(currentReadings[0]);
  REQUIRE(validateSensorReadings_i(currentReadings, numOfCurReadings, CURRENT_DIFF_THRESHOLD) == 0);
}

TEST_CASE("reports error when current decreases abruptly") {
  double currentReadings[] = {0.0, 0.1, 0.2, 0.0};
  int numOfCurReadings = sizeof(currentReadings) / sizeof(currentReadings[0]);
  REQUIRE(validateSensorReadings_i(currentReadings, numOfCurReadings, CURRENT_DIFF_THRESHOLD) == 0);
}

TEST_CASE("Test for no error when current increases abruptly") {
  double currentReadings[] = {0.0, 0.02, 0.03, 0.12};
  int numOfCurReadings = sizeof(currentReadings) / sizeof(currentReadings[0]);
  REQUIRE(validateSensorReadings_i(currentReadings, numOfCurReadings, CURRENT_DIFF_THRESHOLD) == 0);
}
