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
int validateSensorIp_i(double value, double nextValue, double maxDelta);
int validateSOCreadings(double* values, int numOfValues);
