#include "ini_parser.h"

#include <fstream>
#include <iostream>

ini_parser::ini_parser(const std::string& filename)
{
    parse(filename);
}

void ini_parser::parse(const std::string& filename)
{
    std::fstream file;
    file.open(filename);
    if (!file.is_open())
    {
        std::printf("error: could not open \"%s\". terminated parsing.\n", filename.c_str());
        file.close();
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        if (is_comment_line(line))
        {
        }
        else if (is_section_start_line(line))
        {
        }
        else if (is_assignment_line(line))
        {
        }
    }
}

bool ini_parser::is_comment_line(const std::string& line) const
{
    return (line.length() > 0) && (line[0] == ';');
}

bool ini_parser::is_section_start_line(const std::string& line) const
{
    return (line.length() > 0) && (line[0] == '[');
}

bool ini_parser::is_assignment_line(const std::string& line) const
{
    return line.find("=") != std::string::npos;
}
