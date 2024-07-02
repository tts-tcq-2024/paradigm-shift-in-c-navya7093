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
 
int checkNext(Check *checks, int currentIndex, int numChecks) {
    if (currentIndex >= numChecks) {
        return 1; // All checks passed
    }
 
    if (!checks[currentIndex].check(checks[currentIndex].value)) {
        printMessage(checks[currentIndex].message);
        return 0; // Check failed
    }
 
    return checkNext(checks, currentIndex + 1, numChecks); // Recurse to next check
}
 
int performChecks(Check *checks, int numChecks) {
    return checkNext(checks, 0, numChecks); // Start with the first check
}
 
int batteryIsOk(float temperature, float soc, float chargeRate) {
    Check checks[] = {
        {isTemperatureInRange, temperature, "Temperature out of range!\n"},
        {isSocInRange, soc, "State of Charge out of range!\n"},
        {isChargeRateInRange, chargeRate, "Charge Rate out of range!\n"}
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
