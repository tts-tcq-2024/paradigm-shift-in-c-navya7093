#include <assert.h>
#include "battery_monitor.h"
#include "warnings.h"

int main() {
    // Run tests with warnings enabled
    enableWarnings(1);

    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));

    printf("All tests passed.\n");
    return 0;
}
