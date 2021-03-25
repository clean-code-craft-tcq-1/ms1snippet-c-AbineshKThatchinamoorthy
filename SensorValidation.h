/******************************************************************************
***     \file        SensorValidation.h
***     \author      Abinesh Kanji Kovil Thatchinamoorthy
\nt
***
\par    File_description
***                  Header for validation of battery sensor inputs
*\n*/
/*****************************************************************************/

/*=============================================================================
=======                             INCLUSIONS                          =======
=============================================================================*/
#include <stdio.h>

/*=============================================================================
=======                        MACRO DEFINITIONS                        =======
=============================================================================*/
#define SOC_DIFF_THRESHOLD        0.05
#define CURRENT_DIFF_THRESHOLD    0.1
#define TEMP_DIFF_THRESHOLD       2

/*=============================================================================
=======                     PROTOTYPES OF FUNCTIONS                     =======
=============================================================================*/
int validateSensorIp_i(double* sensorVals_a, double lastButOneIndex_i, double maxDelta);
int validateSensorReadings_i(double* sensorVals_a, int numOfValues, double maxDelta);
int iterateSensorReadings_i(double* sensorVals_a, int lastButOneIndex_i, double maxDelta_d)
  
  /* EOF */
