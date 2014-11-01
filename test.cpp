#include "ini_parser.hpp"

#include <iostream>

int main()
{
    ini_parser parser("test.ini");
    parser.set_value("hi", false);
    parser.set_value("age", 69);
    parser.set_value("sex", std::string("dog"));

    return 0;
}
