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
=======                     PROTOTYPES OF FUNCTIONS                     =======
=============================================================================*/
#define SOC_DIFF_THRESHOLD        0.05
#define CURRENT_DIFF_THRESHOLD    0.1
#define TEMP_DIFF_THRESHOLD       2

/*=============================================================================
=======                     PROTOTYPES OF FUNCTIONS                     =======
=============================================================================*/
int validateSensorIp_i(double value, double nextValue, double maxDelta);
int validateSensorReadings_i(double* values, int numOfValues, double maxDelta);
