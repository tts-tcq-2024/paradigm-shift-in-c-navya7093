#include <assert.h>
#include "battery_monitor.h"
#include "Test_cases.h"


void TemperaturecheckBelowLowerLimit() {
    assert(!batteryIsOk(-1, 75, 0.6));
}

void TemperaturecheckAboveUpperLimit() {
    assert(!batteryIsOk(46, 75, 0.6));
}

void SoccheckBelowLowerLimit() {
    assert(!batteryIsOk(30, 19, 0.6));
}

void SoccheckAboveUpperLimit() {
    assert(!batteryIsOk(30, 81, 0.6));
}

void ChargeRatecheckAboveUpperLimit() {
    assert(!batteryIsOk(30, 75, 0.9));
}

void ApproachingcheckLowerTemperatureLimit() {
    assert(batteryIsOk(2.25, 75, 0.6));
}

void ApproachingcheckHigherTemperatureLimit() {
    assert(batteryIsOk(42.75, 75, 0.6));
}

void ApproachingDischargecheck() {
    assert(batteryIsOk(20, 24, 0.6));
}

void ApproachingChargePeakcheck() {
    assert(batteryIsOk(20, 76, 0.6));
}

void ApproachingMaxChargeRatecheck() {
    assert(batteryIsOk(20, 40, 0.76));
}
