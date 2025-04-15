// examples/helloworld.cpp
#include <iostream>
#include <string>
#include <temperature_converter.h> // Include the library's header

int main() {
    std::cout << "Hello from a program using libunitconverter-lib!" << std::endl;

    std::string from = "Celsius";
    double value = 25.0;
    std::string to = "Fahrenheit";
    double convertedValue = processString(from, value, to);
    std::cout << from << " " << value << " to " << to << ": " << convertedValue << std::endl;
    std::cout << "Converted value: " << convertedValue << std::endl;
    return 0;
}