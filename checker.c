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
 
int performTemperatureCheck(float temperature) {
    return checkTemperature(temperature);
}
 
int performSocCheck(float soc) {
    return checkSoc(soc);
}
 
int performChargeRateCheck(float chargeRate) {
    return checkChargeRate(chargeRate);
}
 
int performChecks(Check *checks, int numChecks) {
    int allPassed = 1; // Assume all checks pass initially
    // Call each check function directly
    if (numChecks > 0 && !checks[0].check(checks[0].value)) {
        allPassed = 0;
    }
    if (numChecks > 1 && !checks[1].check(checks[1].value)) {
        allPassed = 0;
    }
    if (numChecks > 2 && !checks[2].check(checks[2].value)) {
        allPassed = 0;
    }
    return allPassed;
}
 
int batteryIsOk(float temperature, float soc, float chargeRate) {
    Check checks[] = {
        {performTemperatureCheck, temperature, NULL},
        {performSocCheck, soc, NULL},
        {performChargeRateCheck, chargeRate, NULL}
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
