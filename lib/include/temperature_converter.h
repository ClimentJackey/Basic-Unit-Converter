#include <string>

enum class TemperatureUnit {
    Celsius,
    Fahrenheit,
    Kelvin
};

constexpr double kelvinOffset = 273.15;
constexpr double fahrenheitOffset = 32.0;
constexpr double fahrenheitFactor = 9.0 / 5.0;
constexpr double celsiusFactor = 5.0 / 9.0;


double convertTemperature(const double value, TemperatureUnit const from, TemperatureUnit to);

double processString(const std::string& fromStr, const double value, const std::string& toStr);
