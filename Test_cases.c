#include <assert.h>
#include "Battery_Monitor.h"
#include "Testcases.h"

void testTemperatureBelowLowerLimit() {
    assert(!batteryIsOk(-1, 75, 0.6));
}

void testTemperatureAboveUpperLimit() {
    assert(!batteryIsOk(46, 75, 0.6));
}

void testSocBelowLowerLimit() {
    assert(!batteryIsOk(30, 19, 0.6));
}

void testSocAboveUpperLimit() {
    assert(!batteryIsOk(30, 81, 0.6));
}

void testChargeRateAboveUpperLimit() {
    assert(!batteryIsOk(30, 75, 0.9));
}

void testApproachingLowerTemperatureLimit() {
    assert(batteryIsOk(2.25, 75, 0.6));
}

void testApproachingHigherTemperatureLimit() {
    assert(batteryIsOk(42.75, 75, 0.6));
}

void testApproachingDischarge() {
    assert(batteryIsOk(20, 24, 0.6));
}

void testApproachingChargePeak() {
    assert(batteryIsOk(20, 76, 0.6));
}

void testApproachingMaxChargeRate() {
    assert(batteryIsOk(20, 40, 0.76));
}
