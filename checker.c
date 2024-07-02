#include <stdio.h>
#include <assert.h>
 
typedef int (*CheckFunc)(float);
 
typedef struct {
    CheckFunc check;
    float value;
    const char *message;
} Check;
 
void printMessage(const char *message) {
    printf("%s", message);
}
 
int isTemperatureInRange(float temperature) {
    return (temperature >= 0 && temperature <= 45);
}
 
int isSocInRange(float soc) {
    return (soc >= 20 && soc <= 80);
}
 
int isChargeRateInRange(float chargeRate) {
    return (chargeRate <= 0.8);
}
 
int checkTemperature(float temperature) {
    if (!isTemperatureInRange(temperature)) {
        printMessage("Temperature out of range!\n");
        return 0;
    }
    return 1;
}
 
int checkSoc(float soc) {
    if (!isSocInRange(soc)) {
        printMessage("State of Charge out of range!\n");
        return 0;
    }
    return 1;
}
 
int checkChargeRate(float chargeRate) {
    if (!isChargeRateInRange(chargeRate)) {
        printMessage("Charge Rate out of range!\n");
        return 0;
    }
    return 1;
}
 
int performChecks(Check *checks, int numChecks) {
    int allPassed = 1; // Assume all checks pass initially
    for (int i = 0; i < numChecks; ++i) {
        if (!checks[i].check(checks[i].value)) {
            allPassed = 0; // Set to 0 if any check fails
        }
    }
    return allPassed;
}
 
int batteryIsOk(float temperature, float soc, float chargeRate) {
    Check checks[] = {
        {checkTemperature, temperature, NULL},
        {checkSoc, soc, NULL},
        {checkChargeRate, chargeRate, NULL}
    };
    return performChecks(checks, sizeof(checks) / sizeof(checks[0]));
}
 
int main() {
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
    assert(!batteryIsOk(30, 85, 0));
    assert(!batteryIsOk(25, 70, 0.9));
    printf("All tests passed!\n");
    return 0;
}
