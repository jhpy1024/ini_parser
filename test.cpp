#include "ini_parser.h"

#include <iostream>

int main()
{
    ini_parser parser("test.ini");

    /* Set Jake to be the collaborator. */
    parser.set_value("name", std::string("Jake"), "collaborator");
    parser.set_value("age", 17, "collaborator");

    /* Set Ricardo to be the owner. */
    parser.set_value("name", std::string("Ricardo"), "owner");
    parser.set_value("age", 18, "owner");

    return 0;
}
