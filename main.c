#include<stdio.h>
#include "Test_cases.h"

int main() {
    TemperaturecheckBelowLowerLimit();
    TemperaturecheckAboveUpperLimit();
    SoccheckBelowLowerLimit();
    SoccheckAboveUpperLimit();
    ChargeRatecheckAboveUpperLimit();
    ApproachingcheckLowerTemperatureLimit();
    ApproachingcheckHigherTemperatureLimit();
    ApproachingDischargecheck();
    ApproachingChargePeakcheck();
    ApproachingMaxChargeRatecheck();
return 0;
}

