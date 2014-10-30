#include "ini_parser.h"

#include <fstream>
#include <iostream>
#include <stdexcept>

const std::string ini_parser::BOOL_TRUE = "TRUE";
const std::string ini_parser::BOOL_FALSE = "FALSE";

ini_parser::ini_parser(const std::string& filename)
    : current_section("")
{
    parse(filename);
}

int ini_parser::get_int(const std::string& section, const std::string& name) const
{
    ensure_property_exists(section, name);
    return std::stoi(sections.at(section).at(name));
}

bool ini_parser::get_bool(const std::string& section, const std::string& name) const
{
    ensure_property_exists(section, name);

    std::string value = sections.at(section).at(name);
    if (value == BOOL_TRUE)
    {
        return true;
    }
    else if (value == BOOL_FALSE)
    {
        return false;
    }
    else
    {
        throw std::runtime_error("unable to cast to bool");
    }
}

long ini_parser::get_long(const std::string& section, const std::string& name) const
{
    ensure_property_exists(section, name);
    return std::stol(sections.at(section).at(name));
}

float ini_parser::get_float(const std::string& section, const std::string& name) const
{
    ensure_property_exists(section, name);
    return std::stof(sections.at(section).at(name));
}

double ini_parser::get_double(const std::string& section, const std::string& name) const
{
    ensure_property_exists(section, name);
    return std::stod(sections.at(section).at(name));
}

std::string ini_parser::get_string(const std::string& section, const std::string& name) const
{
    ensure_property_exists(section, name);
    return sections.at(section).at(name);
}

void ini_parser::ensure_property_exists(const std::string& section, const std::string& name) const
{
    if (sections.find(section) == sections.end())
    {
        throw std::runtime_error("section does not exist");
    }

    if (sections.at(section).find(name) == sections.at(section).end())
    {
        throw std::runtime_error("property does not exist");
    }
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
            continue;
        }
        else if (is_section_start_line(line))
        {
            start_section(line);
        }
        else if (is_assignment_line(line))
        {
            handle_assignment(line);
        }
    }
}

void ini_parser::handle_assignment(const std::string& line)
{
    std::string key = extract_key(line);
    std::string value = extract_value(line);

    sections[current_section][key] = value;
}

std::string ini_parser::extract_key(const std::string& line) const
{
    std::string key;

    for (int i = 0; line[i] != '='; ++i)
    {
        key += line[i];
    }

    return key;
}

std::string ini_parser::extract_value(const std::string& line) const
{
    std::string value;

    int equals_pos;
    for (equals_pos = 0; line[equals_pos] != '='; ++equals_pos)
    {
        /* Skip to equals sign. */
    }

    for (int i = equals_pos + 1; i < line.length(); ++i)
    {
        value += line[i];
    }

    return value;
}

void ini_parser::start_section(const std::string& line)
{
    current_section = extract_section_name(line);
}

std::string ini_parser::extract_section_name(const std::string& line) const
{
    std::string name;
    
    for (int i = 1; line[i] != ']'; ++i)
    {
        name += line[i];
    }
    
    return name;
}

bool ini_parser::is_comment_line(const std::string& line) const
{
    return (line.length() > 0) && (line[0] == ';');
}

bool ini_parser::is_section_start_line(const std::string& line) const
{
    return (line.length() > 0) && (line[0] == '[') && (line[line.length() - 1] == ']');
}

bool ini_parser::is_assignment_line(const std::string& line) const
{
    std::size_t equals_pos = line.find("=");
    return (equals_pos != std::string::npos) && (equals_pos != 0) && (equals_pos != line.length() - 1);
}
