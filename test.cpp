#include "ini_parser.h"

#include <iostream>

int main()
{
    ini_parser parser("test.ini");
    std::string name = parser.get_string("owner", "name");
    std::string file = parser.get_string("database", "file");
    int port = parser.get_int("database", "port");
    /* int SHOULD_THROW_EXCEPTION = parser.get_int("owner", "name"); */
    bool on_vacation = parser.get_bool("owner", "on_vacation");

    std::cout << "port = " << port << std::endl;
    std::cout << "name = " << name << std::endl;
    std::cout << "file = " << file << std::endl;
    std::cout << "on vacation = " << std::boolalpha << on_vacation << std::endl;

    return 0;
}
