#include <stdio.h>
#include "warnings.h"
#include "battery_monitor.h"

static int warningsEnabled = 0;

void enableWarnings(int enable) {
    warningsEnabled = enable;
}

void checkTemperatureWarningLow(float temperature) {
    if (temperature <= TEMP_MIN + TEMP_WARNING_TOLERANCE) {
        printf("Warning: Approaching discharge temperature\n");
    }
}

void checkTemperatureWarningHigh(float temperature) {
    if (temperature >= TEMP_MAX - TEMP_WARNING_TOLERANCE) {
        printf("Warning: Approaching peak temperature\n");
    }
}

void checkTemperatureWarning(float temperature) {
    if (!warningsEnabled) return;
    checkTemperatureWarningLow(temperature);
    checkTemperatureWarningHigh(temperature);
}

void checkSocWarningLow(float soc) {
    if (soc <= SOC_MIN + SOC_WARNING_TOLERANCE) {
        printf("Warning: Approaching discharge SoC\n");
    }
}

void checkSocWarningHigh(float soc) {
    if (soc >= SOC_MAX - SOC_WARNING_TOLERANCE) {
        printf("Warning: Approaching peak SoC\n");
    }
}

void checkSocWarning(float soc) {
    if (!warningsEnabled) return;
    checkSocWarningLow(soc);
    checkSocWarningHigh(soc);
}

void checkChargeRateWarning(float chargeRate) {
    if (!warningsEnabled) return;
    if (chargeRate >= CHARGE_RATE_MAX - CHARGE_RATE_WARNING_TOLERANCE) {
        printf("Warning: Approaching peak charge rate\n");
    }
}
