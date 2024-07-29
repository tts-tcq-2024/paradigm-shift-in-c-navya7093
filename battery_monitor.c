#include <stdio.h>
#include "battery_monitor.h"
#include "warnings.h"

int isTemperatureOk(float temperature) {
    if (temperature < TEMP_MIN || temperature > TEMP_MAX) {
        printf("Temperature out of range!\n");
        return 0;
    }
    checkTemperatureWarning(temperature);
    return 1;
}

int isSocOk(float soc) {
    if (soc < SOC_MIN || soc > SOC_MAX) {
        printf("State of Charge out of range!\n");
        return 0;
    }
    checkSocWarning(soc);
    return 1;
}

int isChargeRateOk(float chargeRate) {
    if (chargeRate > CHARGE_RATE_MAX) {
        printf("Charge Rate out of range!\n");
        return 0;
    }
    checkChargeRateWarning(chargeRate);
    return 1;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    return isTemperatureOk(temperature) &&
           isSocOk(soc) &&
           isChargeRateOk(chargeRate);
}
