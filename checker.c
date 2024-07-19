#include <stdio.h>
#include <assert.h>

int isTemperatureOk(float temperature) {
    return (temperature >= 0 && temperature <= 45);
}

int isSocOk(float soc) {
    return (soc >= 20 && soc <= 80);
}

int isChargeRateOk(float chargeRate) {
    return (chargeRate <= 0.8);
}

void printErrorMessage(const char* message) {
    printf("%s\n", message);
}

int checkParameter(int (*isParameterOk)(float), float parameter, const char* errorMessage) {
    if (!isParameterOk(parameter)) {
        printErrorMessage(errorMessage);
        return 0;
    }
    return 1;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    int isTemperatureValid = checkParameter(isTemperatureOk, temperature, "Temperature out of range!");
    int isSocValid = checkParameter(isSocOk, soc, "State of Charge out of range!");
    int isChargeRateValid = checkParameter(isChargeRateOk, chargeRate, "Charge Rate out of range!");

    return isTemperatureValid && isSocValid && isChargeRateValid;
}

int main() {
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
    printf("All tests passed.\n");
    return 0;
}
