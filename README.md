ini_parser
==========
An easy-to-use header-only library for reading and writing INI files.

How to use
==========
As this is a header-only library, simply include this in your project. No additional steps are needed.

Example use
===========
* Create an instance of ini_parser, passing the name of the INI file as an argument to the constructor.
  * `ini_parser parser_instance("ini_file.ini");`
* Read the property `foo` from the section `bar`.
  * `int my_int_value = parser_instance.get_int("foo", "bar");`
* Set the value of the property `foo` in the section `bar` to equal `42`.
  * `parser_instance.set_value("foo", 42, "bar");`
