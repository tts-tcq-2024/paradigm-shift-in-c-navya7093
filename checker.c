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

typedef int (*checkFunction)(float);
typedef struct {
    checkFunction function;
    const char* errorMessage;
} ParameterCheck;

int checkParameter(float parameter, checkFunction function, const char* errorMessage) {
    if (!function(parameter)) {
        printErrorMessage(errorMessage);
        return 0;
    }
    return 1;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    ParameterCheck checks[] = {
        { isTemperatureOk, "Temperature out of range!" },
        { isSocOk, "State of Charge out of range!" },
        { isChargeRateOk, "Charge Rate out of range!" }
    };
    
    float parameters[] = { temperature, soc, chargeRate };
    
    for (int i = 0; i < 3; ++i) {
        if (!checkParameter(parameters[i], checks[i].function, checks[i].errorMessage)) {
            return 0;
        }
    }
    
    return 1;
}

int main() {
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
    printf("All tests passed.\n");
    return 0;
}
