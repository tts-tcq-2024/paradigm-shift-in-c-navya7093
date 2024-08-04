#include <stdio.h>
#include "battery_monitor.h"

int batteryIsOk(float temperature, float soc, float chargeRate) {
    return isTemperatureOk(temperature) && isSocOk(soc) && isChargeRateOk(chargeRate);
}

int isTemperatureOk(float temperature) {
    checkTemperatureWarnings(temperature);
    return isValueInRange(temperature, 0, 45, "Temperature out of range!");
}

int isSocOk(float soc) {
    checkSocWarnings(soc);
    return isValueInRange(soc, 20, 80, "State of Charge out of range!");
}

int isChargeRateOk(float chargeRate) {
    checkChargeRateWarnings(chargeRate);
    return isChargeRateInRange(chargeRate, 0.8, "Charge Rate out of range!");
}

void checkTemperatureWarnings(float temperature) {
    checkLowWarning(temperature, 0, 2.25, "Warning: Approaching lower temperature limit");
    checkHighWarning(temperature, 45, 2.25, "Warning: Approaching upper temperature limit");
}

void checkSocWarnings(float soc) {
    checkLowWarning(soc, 20, 4, "Warning: Approaching discharge");
    checkHighWarning(soc, 80, 4, "Warning: Approaching charge-peak");
}

void checkChargeRateWarnings(float chargeRate) {
    checkHighWarning(chargeRate, 0.8, 0.04, "Warning: Approaching maximum charge rate");
}

void checkLowWarning(float value, float min, float tolerance, const char* lowWarning) {
    if (value >= min && value <= min + tolerance) {
        printf("%s\n", lowWarning);
    }
}

void checkHighWarning(float value, float max, float tolerance, const char* highWarning) {
    if (value >= max - tolerance && value <= max) {
        printf("%s\n", highWarning);
    }
}

int isValueInRange(float value, float min, float max, const char* warningMessage) {
    if (value < min || value > max) {
        printf("%s\n", warningMessage);
        return 0;
    }
    return 1;
}

int isChargeRateInRange(float value, float max, const char* warningMessage) {
    if (value > max) {
        printf("%s\n", warningMessage);
        return 0;
    }
    return 1;
}
