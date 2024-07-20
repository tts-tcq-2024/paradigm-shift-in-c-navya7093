#include <stdio.h>
#include <assert.h>
 
#define TEMPERATURE_MIN 0
#define TEMPERATURE_MAX 45
#define SOC_MIN 20
#define SOC_MAX 80
#define CHARGE_RATE_MAX 0.8
 
typedef enum {
    BATTERY_OK,
    TEMPERATURE_ERROR,
    SOC_ERROR,
    CHARGE_RATE_ERROR
} BatteryStatus;
 
void printErrorMessage(const char* message) {
    printf("%s\n", message);
}
 
BatteryStatus checkTemperature(float temperature) {
    if (temperature < TEMPERATURE_MIN || temperature > TEMPERATURE_MAX) {
        printErrorMessage("Temperature out of range!");
        return TEMPERATURE_ERROR;
    }
    return BATTERY_OK;
}
 
BatteryStatus checkSoc(float soc) {
    if (soc < SOC_MIN || soc > SOC_MAX) {
        printErrorMessage("State of Charge out of range!");
        return SOC_ERROR;
    }
    return BATTERY_OK;
}
 
BatteryStatus checkChargeRate(float chargeRate) {
    if (chargeRate > CHARGE_RATE_MAX) {
        printErrorMessage("Charge Rate out of range!");
        return CHARGE_RATE_ERROR;
    }
    return BATTERY_OK;
}
 
BatteryStatus batteryIsOk(float temperature, float soc, float chargeRate) {
    if (checkTemperature(temperature) != BATTERY_OK) {
        return TEMPERATURE_ERROR;
    }
    if (checkSoc(soc) != BATTERY_OK) {
        return SOC_ERROR;
    }
    if (checkChargeRate(chargeRate) != BATTERY_OK) {
        return CHARGE_RATE_ERROR;
    }
    return BATTERY_OK;
}
 
int main() {
    assert(batteryIsOk(25, 70, 0.7) == BATTERY_OK);
    assert(batteryIsOk(50, 85, 0) != BATTERY_OK);
    printf("All tests passed.\n");
    return 0;
}
