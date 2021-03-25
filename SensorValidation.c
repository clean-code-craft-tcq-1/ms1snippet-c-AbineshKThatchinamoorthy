/******************************************************************************
***     \file        SensorValidation.c
***     \author      Abinesh Kanji Kovil Thatchinamoorthy
\nt
***
\par    File_description
***                  Validation of battery sensor inputs
*\n*/
/*****************************************************************************/

#include "SensorValidation.h"

int validateSensorIp_i(double value, double nextValue, double maxDelta) {
  if(nextValue - value > maxDelta) {
    return 0;
  }
  return 1;
}

/*---------------------------------------------------------------------------*/
/*     FUNCTION:  validateSensorReadings_i
 */
/*!    \brief     Read all the sensor inputs and validate it
 *
 *     \param     double* sensorVals_a - array of sensor values
 *     \param     int numOfVals_i - number sensor values provided for validation
 *     \returns   1 - if all the inputs are valid
 *                0 - if 1 or more inputs are invalid
*//*------------------------------------------------------------------------*/
int validateSensorReadings_i(double* sensorVals_a, int numOfVals_i) {
  int lastButOneIndex_i = numOfVals_i - 1;
  for(int cnt_i = 0; cnt_i < lastButOneIndex_i; cnt_i++) {
    if(!validateSensorIp_i(sensorVals_a[cnt_i], sensorVals_a[cnt_i + 1], 0.05)) {
      return 0;
    }
  }
  return 1;
}