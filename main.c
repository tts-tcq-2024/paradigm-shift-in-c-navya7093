#include <stdio.h>
#include "Test_cases.h"

int main() {
    testTemperatureBelowLowerLimit();
    testTemperatureAboveUpperLimit();
    testSocBelowLowerLimit();
    testSocAboveUpperLimit();
    testChargeRateAboveUpperLimit();
    testApproachingLowerTemperatureLimit();
    testApproachingHigherTemperatureLimit();
    testApproachingDischarge();
    testApproachingChargePeak();
    testApproachingMaxChargeRate();
    return 0;
}
