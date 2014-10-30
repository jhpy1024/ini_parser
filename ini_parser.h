#ifndef INI_PARSER_H
#define INI_PARSER_H

#include <map>
#include <string>
#include <vector>
#include <utility>

class ini_parser
{
    public:
        ini_parser(const std::string& filename);

    private:
        void parse(const std::string& filename);

        bool is_comment_line(const std::string& line) const;
        bool is_section_start_line(const std::string& line) const;
        bool is_assignment_line(const std::string& line) const;

    private:
        typedef std::pair<std::string, std::string> property;
        typedef std::vector<property> properties;
        std::map<std::string, properties> sections;

        std::string current_section;
};

#endif
