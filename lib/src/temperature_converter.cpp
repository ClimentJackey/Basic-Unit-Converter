#include "temperature_converter.h"
#include <string>
#include <stdexcept>

double convertTemperature(const double value, TemperatureUnit const from, TemperatureUnit to)
{
    if (from == to)
    {
        return value;
    }

    if (from == TemperatureUnit::Celsius)
    {
        if (to == TemperatureUnit::Fahrenheit)
        {
            return (value * fahrenheitFactor) + fahrenheitOffset;
        }
        else
        { // to Kelvin
            return value + kelvinOffset;
        }
    }
    else if (from == TemperatureUnit::Fahrenheit)
    {
        if (to == TemperatureUnit::Celsius)
        {
            return (value - fahrenheitOffset) * celsiusFactor;
        }
        else { // to Kelvin
            return (value - fahrenheitOffset) * celsiusFactor + kelvinOffset;
        }
    }
    else
    { // from Kelvin
        if (to == TemperatureUnit::Celsius)
        {
            return value - kelvinOffset;
        }
        else
        { // to Fahrenheit
            return (value - kelvinOffset) * fahrenheitFactor + fahrenheitOffset;
        }
    }
}

double processString(const std::string &fromStr, const double value, const std::string &toStr)
{
    TemperatureUnit from;
    TemperatureUnit to;

    if (fromStr == "Celsius")
    {
        from = TemperatureUnit::Celsius;
    }
    else if (fromStr == "Fahrenheit")
    {
        from = TemperatureUnit::Fahrenheit;
    }
    else if (fromStr == "Kelvin")
    {
        from = TemperatureUnit::Kelvin;
    }
    else
    {
        throw std::invalid_argument("Invalid temperature unit: " + fromStr);
    }

    if (toStr == "Celsius")
    {
        to = TemperatureUnit::Celsius;
    }
    else if (toStr == "Fahrenheit")
    {
        to = TemperatureUnit::Fahrenheit;
    }
    else if (toStr == "Kelvin")
    {
        to = TemperatureUnit::Kelvin;
    }
    else
    {
        throw std::invalid_argument("Invalid temperature unit: " + toStr);
    }

    return convertTemperature(value, from, to);
}

