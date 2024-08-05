#include "battery_monitor.h"

void printLowWarning(float value, float min, float tolerance, const char* lowWarning) {
    if (value >= min && value <= min + tolerance) {
        printf("%s\n", lowWarning);
    }
}

void checkEarlyWarning(float value, float min, float max, float tolerance, const char* lowWarning, const char* highWarning) {
    printLowWarning(value, min, tolerance, lowWarning);
    printHighWarning(value, max, tolerance, highWarning);
}



void printHighWarning(float value, float max, float tolerance, const char* highWarning) {
    if (value >= max - tolerance && value <= max) {
        printf("%s\n", highWarning);
    }
}


void checkEarlyWarningForChargeRate(float value, float max, float tolerance, const char* highWarning) {
   printHighWarning(value, max, tolerance, highWarning);
}



void printWarningMessage(const char* WarningMessage) {
    printf("%s\n", WarningMessage);
}




int isValueInRange(float value, float min, float max, const char* WarningMessage) {
    if (value < min || value > max) {
        printWarningMessage(WarningMessage);
        return 0;
    }
    return 1;
}

int isChargeRateInRange(float value, float max, const char* WarningMessage) {
    if (value > max) {
        printWarningMessage(WarningMessage);
        return 0;
    }
    return 1;
}


int isSocOk(float soc) {
    checkEarlyWarning(soc, 20, 80, 4, "Warning: Approaching discharge", "Warning: Approaching charge-peak");
    return isValueInRange(soc, 20, 80, "State of Charge out of range!");
}

int isTemperatureOk(float temperature) {
    checkEarlyWarning(temperature, 0, 45, 2.25, "Warning: Approaching lower temperature limit", "Warning: Approaching upper temperature limit");
    return isValueInRange(temperature, 0, 45, "Temperature out of range!");
}



int isChargeRateOk(float chargeRate) {
    checkEarlyWarningForChargeRate(chargeRate, 0.8, 0.04, "Warning: Approaching maximum charge rate");
    return isChargeRateInRange(chargeRate, 0.8, "Charge Rate out of range!");
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    return isTemperatureOk(temperature) && isSocOk(soc) && isChargeRateOk(chargeRate);
}


