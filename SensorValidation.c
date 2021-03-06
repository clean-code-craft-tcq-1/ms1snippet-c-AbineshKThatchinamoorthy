/******************************************************************************
***     \file        SensorValidation.c
***     \author      Abinesh Kanji Kovil Thatchinamoorthy
\nt
***
\par    File_description
***                  Validation of battery sensor inputs
*\n*/
/*****************************************************************************/

/*=============================================================================
=======                             INCLUSIONS                          =======
=============================================================================*/
#include "SensorValidation.h"

/*=============================================================================
=======                        FUNCTION DEFINITIONS                     =======
=============================================================================*/
/*---------------------------------------------------------------------------*/
/*     FUNCTION:  validateSensorReadings_i
 */
/*!    \brief     Read all the sensor inputs and validate it
 *
 *     \param     double* sensorVals_a - array of sensor values
 *     \param     int numOfVals_i - number sensor values provided for validation
 *     \param     double maxDelta_d - maximum delta for the corr. batt. param
 *     \returns   retVal_i - 1 - if all the inputs are valid
 *                           0 - if 1 or more inputs are invalid
*//*------------------------------------------------------------------------*/
int validateSensorReadings_i(double* sensorVals_a, int numOfVals_i, double maxDelta_d) {
  int retVal_i = 0;
  int lastButOneIndex_i = numOfVals_i - 1;
  
  if(NULL != sensorVals_a)
  {
    retVal_i = iterateSensorReadings_i(sensorVals_a, lastButOneIndex_i, maxDelta_d);
  }
  
  return retVal_i;
}

/*---------------------------------------------------------------------------*/
/*     FUNCTION:  iterateSensorReadings_i
 */
/*!    \brief     Iterate each sensor input and send it for validation
 *
 *     \param     double* sensorVals_a - array of sensor values
 *     \param     int lastButOneIndex_i - (No of sensor values - 1)
 *     \param     double maxDelta_d - maximum delta for the corr. batt. param
 *     \returns   1 - if all the inputs are valid
 *                0 - if 1 or more inputs are invalid
*//*------------------------------------------------------------------------*/
int iterateSensorReadings_i(double* sensorVals_a, int lastButOneIndex_i, double maxDelta_d) {
  for(int cnt_i = 0; cnt_i < lastButOneIndex_i; cnt_i++) {
    if(!validateSensorIp_i(sensorVals_a[cnt_i], sensorVals_a[cnt_i + 1], maxDelta_d)) {
      return 0;
    }
  }
  return 1;
}

/*---------------------------------------------------------------------------*/
/*     FUNCTION:  validateSensorIp_i
 */
/*!    \brief     Validate received sensor input against the previous one
 *
 *     \param     double value - previous sensor value
 *     \param     double value - sensor value to be validated
 *     \param     double maxDelta_d - maximum delta for the corr. batt. param
 *     \returns   changeValidity_i  - 1 - if the input is valid
 *                                    0 - if the input is invalid
*//*------------------------------------------------------------------------*/
int validateSensorIp_i(double value, double nextValue, double maxDelta) {
  int changeValidity_i = 1;
  
  if(nextValue - value > maxDelta) {
    changeValidity_i = 0;
  }
  else if(value - nextValue > maxDelta) {
    changeValidity_i = 0; 
  }
  return changeValidity_i;
}

/* EOF */
