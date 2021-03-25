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

int validateSensorIp_i(double* sensorVals_a, int lastButOneIndex_i, double maxDelta) {
   for(int cnt_i = 0; cnt_i < lastButOneIndex_i; cnt_i++) {
      if(sensorVals_a[cnt_i + 1] - sensorVals_a[cnt_i] > maxDelta) {
        return 0;
      }
      else if(sensorVals_a[cnt_i + 1] - sensorVals_a[cnt_i] > maxDelta) {
        return 0; 
      }
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
 *     \param     double maxDelta_d - maximum delta for the corr. batt. param
 *     \returns   1 - if all the inputs are valid
 *                0 - if 1 or more inputs are invalid
*//*------------------------------------------------------------------------*/
int validateSensorReadings_i(double* sensorVals_a, int numOfVals_i, double maxDelta_d) {
  int retVal_i = 0, validitySum_i = 0;
  int lastButOneIndex_i = numOfVals_i - 1;
  
  if(NULL != sensorVals_a)
  {
    retVal_i = validateSensorIp_i(sensorVals_a, lastButOneIndex_i, maxDelta_d)
  }
  
  return retVal_i;
}
