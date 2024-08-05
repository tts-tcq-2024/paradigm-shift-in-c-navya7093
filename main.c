#include<stdio.h>
#include "Testcases.h"

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

