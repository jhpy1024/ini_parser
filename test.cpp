#include "ini_parser.hpp"

#include <iostream>

int main()
{
    ini_parser parser("test.ini");
    parser.create_property("project_name", "Galactic Empires");
    parser.create_section("fancy_new_section");

    return 0;
}
