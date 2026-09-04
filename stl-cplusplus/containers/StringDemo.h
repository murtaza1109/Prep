#ifndef STRINGDEMO_H
#define STRINGDEMO_H

// std::string — dynamic character sequence (typedef for basic_string<char>)
// Specialized container for text with rich string-specific operations.
// Has its own heap allocation + Short String Optimization (SSO).
// Header: <string>

class StringDemo
{
public:
    StringDemo();
    static void demo();
};

#endif // STRINGDEMO_H
