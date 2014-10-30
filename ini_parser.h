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

        int get_int(const std::string& section, const std::string& name) const;
        bool get_bool(const std::string& section, const std::string& name) const;
        long get_long(const std::string& section, const std::string& name) const;
        float get_float(const std::string& section, const std::string& name) const;
        double get_double(const std::string& section, const std::string& name) const;
        std::string get_string(const std::string& section, const std::string& name) const;

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

        void ensure_property_exists(const std::string& section, const std::string& name) const;

    private:
        typedef std::map<std::string, std::string> properties;
        std::map<std::string, properties> sections;

        std::string current_section;

        static const std::string BOOL_TRUE;
        static const std::string BOOL_FALSE;
};

#endif
