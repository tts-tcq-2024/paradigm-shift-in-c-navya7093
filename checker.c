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

int checkTemperature(float temperature) {
    if (!isTemperatureOk(temperature)) {
        printErrorMessage("Temperature out of range!");
        return 0;
    }
    return 1;
}

int checkSoc(float soc) {
    if (!isSocOk(soc)) {
        printErrorMessage("State of Charge out of range!");
        return 0;
    }
    return 1;
}

int checkChargeRate(float chargeRate) {
    if (!isChargeRateOk(chargeRate)) {
        printErrorMessage("Charge Rate out of range!");
        return 0;
    }
    return 1;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    return checkTemperature(temperature) &&
           checkSoc(soc) &&
           checkChargeRate(chargeRate);
}

int main() {
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
}
