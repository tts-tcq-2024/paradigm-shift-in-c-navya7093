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
 
int isTemperatureOk(float temperature) {
    return (temperature >= TEMPERATURE_MIN && temperature <= TEMPERATURE_MAX);
}
 
int isSocOk(float soc) {
    return (soc >= SOC_MIN && soc <= SOC_MAX);
}
 
int isChargeRateOk(float chargeRate) {
    return (chargeRate <= CHARGE_RATE_MAX);
}
 
int isError(BatteryStatus status) {
    return status != BATTERY_OK;
}
 
BatteryStatus checkBattery(float temperature, float soc, float chargeRate) {
    return isTemperatureOk(temperature) && isSocOk(soc) && isChargeRateOk(chargeRate) ? BATTERY_OK :
           !isTemperatureOk(temperature) ? TEMPERATURE_ERROR :
           !isSocOk(soc) ? SOC_ERROR :
           CHARGE_RATE_ERROR;
}
 
BatteryStatus updateBatteryStatus(BatteryStatus currentStatus, BatteryStatus newStatus) {
    return isError(newStatus) ? newStatus : currentStatus;
}
 
BatteryStatus batteryIsOk(float temperature, float soc, float chargeRate) {
    return updateBatteryStatus(BATTERY_OK, checkBattery(temperature, soc, chargeRate));
}
 
int main() {
    assert(batteryIsOk(25, 70, 0.7) == BATTERY_OK);
    assert(batteryIsOk(50, 85, 0) != BATTERY_OK);
    printf("All tests passed.\n");
    return 0;
}
