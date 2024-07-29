#include <stdio.h>
#include "warnings.h"

static int warningsEnabled = 0;

void enableWarnings(int enable) {
    warningsEnabled = enable;
}

void checkTemperatureWarning(float temperature) {
    if (!warningsEnabled) return;
    if (temperature <= TEMP_MIN + TEMP_WARNING_TOLERANCE) {
        printf("Warning: Approaching discharge temperature\n");
    } else if (temperature >= TEMP_MAX - TEMP_WARNING_TOLERANCE) {
        printf("Warning: Approaching peak temperature\n");
    }
}

void checkSocWarning(float soc) {
    if (!warningsEnabled) return;
    if (soc <= SOC_MIN + SOC_WARNING_TOLERANCE) {
        printf("Warning: Approaching discharge SoC\n");
    } else if (soc >= SOC_MAX - SOC_WARNING_TOLERANCE) {
        printf("Warning: Approaching peak SoC\n");
    }
}

void checkChargeRateWarning(float chargeRate) {
    if (!warningsEnabled) return;
    if (chargeRate >= CHARGE_RATE_MAX - CHARGE_RATE_WARNING_TOLERANCE) {
        printf("Warning: Approaching peak charge rate\n");
    }
}
