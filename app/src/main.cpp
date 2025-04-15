#include <iostream>
#include <temperature_converter.h>

int excute(int argc, char* argv[])
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <from> <value> <to>" << std::endl;
        return 1;
    }
    std::string fromStr = argv[1];
    double value = std::stod(argv[2]);
    std::string toStr = argv[3];
    double converted_value = processString(fromStr, value, toStr);
    std::cout << "Converted value: " << converted_value << std::endl;

    return 0;
}

int main(int argc, char* argv[])
{
    excute(argc, argv);
    return 0;
}