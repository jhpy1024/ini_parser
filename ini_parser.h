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

        void start_section(const std::string& line);
        std::string extract_section_name(const std::string& line) const;

        void handle_assignment(const std::string& line);
        std::string extract_key(const std::string& line) const;
        std::string extract_value(const std::string& value) const;

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
