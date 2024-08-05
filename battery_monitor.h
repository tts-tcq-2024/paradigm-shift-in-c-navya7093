#ifndef BATTERY_MONITOR_H
#define BATTERY_MONITOR_H

int batteryIsOk(float temperature, float soc, float chargeRate);
int isTemperatureOk(float temperature);
int isChargeRateOk(float chargeRate);
void checkEarlyWarning(float value, float min, float max, float tolerance, const char* lowWarning, const char* highWarning);
void checkEarlyWarningForChargeRate(float value, float max, float tolerance, const char* highWarning);
int isSocOk(float soc);
int isTemperatureOk(float temperature);
int isValueInRange(float value, float min, float max, const char* WarningMessage);
int isChargeRateInRange(float value, float max, const char* WarningMessage);
void printWarningMessage(const char* WarningMessage);
void printLowWarning(float value, float min, float tolerance, const char* lowWarning);
void printHighWarning(float value, float max, float tolerance, const char* highWarning);

#endif 
