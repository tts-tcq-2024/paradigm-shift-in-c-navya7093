#include <stdio.h>
#include <assert.h>
 
typedef int (*CheckFunc)(float);
typedef struct {
    CheckFunc check;
    float value;
    const char *message;
} Check;
 
int isTemperatureInRange(float temperature) {
    return (temperature >= 0 && temperature <= 45);
}
 
int isSocInRange(float soc) {
    return (soc >= 20 && soc <= 80);
}
 
int isChargeRateInRange(float chargeRate) {
    return (chargeRate <= 0.8);
}
 
void printMessage(const char *message) {
    printf("%s", message);
}
 
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
 
int batteryIsOk(float temperature, float soc, float chargeRate) {
    Check checks[] = {
        {isTemperatureInRange, temperature, "Temperature out of range!\n"},
        {isSocInRange, soc, "SoC out of range!\n"},
        {isChargeRateInRange, chargeRate, "Charge Rate out of range!\n"}
    };
 
    for (int i = 0; i < ARRAY_SIZE(checks); ++i) {
        if (!checks[i].check(checks[i].value)) {
            printMessage(checks[i].message);
            return 0;
        }
    }
    return 1;
}
 
int main() {
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(25, 70, 0.9));
    assert(!batteryIsOk(50, 70, 0));
    assert(!batteryIsOk(30, 90, 0.1));
    printf("All tests passed!\n");
    return 0;
}
