#ifndef BATTERY_MONITOR_H
#define BATTERY_MONITOR_H

int batteryIsOk(float temperature, float soc, float chargeRate);
int isTemperatureOk(float temperature);
int isSocOk(float soc);
int isChargeRateOk(float chargeRate);
void checkEarlyWarning(float value, float min, float max, float tolerance, const char* lowWarning, const char* highWarning);
void checkEarlyWarningForChargeRate(float value, float max, float tolerance, const char* highWarning);
int isValueInRange(float value, float min, float max, const char* warningMessage);
int isChargeRateInRange(float value, float max, const char* warningMessage);

#endif 
