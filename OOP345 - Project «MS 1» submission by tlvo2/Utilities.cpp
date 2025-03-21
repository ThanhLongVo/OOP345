// Name: Thanh Long Vo
// Seneca Student ID: 171587223
// Seneca email: tlvo2@myseneca.ca
// Date of completion: 11 Jul 2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <string>
#include <algorithm>
#include "Utilities.h"

using namespace std;

namespace seneca {
    char Utilities::m_delimiter = ' ';

    void Utilities::setFieldWidth(size_t newWidth) { m_widthField = newWidth; }
    size_t Utilities::getFieldWidth() const { return m_widthField; }
    std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
        string token = "";
        size_t start = next_pos;
        next_pos = str.find(m_delimiter, start);

        if (start == next_pos) {
            more = false;
            throw "ERROR: No token found.";
        }
        else if (next_pos == string::npos) {
            token = str.substr(start);
            m_widthField = max(token.length(), m_widthField);
            more = false;
        }
        else {
            token = str.substr(start, next_pos - start);
            m_widthField = max(token.length(), m_widthField);
            more = true;
        }
        next_pos++;
        return token;
    }
    void Utilities::setDelimiter(char newDelimiter) { m_delimiter = newDelimiter; }
    char Utilities::getDelimiter() { return m_delimiter; }
}
