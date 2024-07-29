#ifndef WARNINGS_H
#define WARNINGS_H

#define TEMP_WARNING_TOLERANCE (TEMP_MAX * 0.05)
#define SOC_WARNING_TOLERANCE (SOC_MAX * 0.05)
#define CHARGE_RATE_WARNING_TOLERANCE (CHARGE_RATE_MAX * 0.05)

void enableWarnings(int enable);
void checkTemperatureWarningLow(float temperature);
void checkTemperatureWarningHigh(float temperature);
void checkTemperatureWarning(float temperature);
void checkSocWarningLow(float soc);
void checkSocWarningHigh(float soc);
void checkSocWarning(float soc);
void checkChargeRateWarning(float chargeRate);

#endif // WARNINGS_H
