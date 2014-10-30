#include "ini_parser.h"

#include <iostream>

int main()
{
    ini_parser parser("test.ini");
    std::string not_in_section = parser.get_string("not_in_section");
    std::string name = parser.get_string("name", "owner");
    /* std::string SHOULD_THROW_EXCEPTION = parser.get_int("owner", "name"); */
    std::string file = parser.get_string("file", "database");
    int port = parser.get_int("port", "database");
    bool on_vacation = parser.get_bool("on_vacation", "owner");

    std::cout << "port = " << port << std::endl;
    std::cout << "name = " << name << std::endl;
    std::cout << "file = " << file << std::endl;
    std::cout << "on vacation = " << std::boolalpha << on_vacation << std::endl;
    std::cout << "not in section = " << not_in_section << std::endl;

    return 0;
}
