// Name: Thanh Long Vo
// Seneca Student ID: 171587223
// Seneca email: tlvo2@myseneca.ca
// Date of completion: 28 Jul 2024
// 
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SENECA_UTILITIES_H
#define SENECA_UTILITIES_H

#include <iostream>

namespace seneca
{
    class Utilities
    {
        size_t m_widthField { 1 }; //  specifies the length of the token extracted

        // Class Variables
        static char m_delimiter;    // separates the tokens in any given std::string object

    public:
        // sets the field width of the current object
        void setFieldWidth(size_t newWidth);

        // returns the field width of the current object
        size_t getFieldWidth() const;

        // extracts a token from string str referred to by the first parameter
        std::string extractToken(const std::string& str, size_t& next_pos, bool& more);

        // Class Functions
        // sets the m_delimiter to the received delimiter
        static void setDelimiter(char newDelimiter);

        // returns the delimiter
        static char getDelimiter();
        void analyzeDataFormat(const std::string& data);
    };
}
#endif // !SENECA_UTILITIES_H