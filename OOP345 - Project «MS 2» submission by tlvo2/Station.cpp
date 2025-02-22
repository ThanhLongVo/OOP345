// Name: Thanh Long Vo
// Seneca Student ID: 171587223
// Seneca email: tlvo2@myseneca.ca
// Date of completion: 15 Mar 2024
// Project: MS2
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include "Station.h"
#include "Utilities.h"

using namespace std;

namespace seneca
{
    // default constructor to intialize class variables to the 0
    size_t Station::m_widthField = 0u;
    size_t Station::id_generator = 0u;

    Station::Station(const std::string& src) {
        Utilities util;
        m_id = ++Station::id_generator;
        bool more = false;
        size_t pos = 0u;

        if (!src.empty()) {
            m_name = util.extractToken(src, pos, more);

            if (more) m_serial_num = stoi(util.extractToken(src, pos, more));

            if (more) m_curr_items = stoi(util.extractToken(src, pos, more));

            Station::m_widthField = max(util.getFieldWidth(), Station::m_widthField);

            if (more) m_desc = util.extractToken(src, pos, more);
        }
    }

    const std::string& Station::getItemName() const {
        return m_name;
    }

    size_t Station::getNextSerialNumber() {
        ++m_serial_num;
        return m_serial_num - 1;
    }

    size_t Station::getQuantity() const {
        return m_curr_items;
    }

    void Station::updateQuantity() {
        m_curr_items == 0 ? m_curr_items = 0 : --m_curr_items;
    }
    // Helper function to trim leading spaces
    std::string trimLeft(const std::string& str) {
        size_t start = str.find_first_not_of(' ');
        return (start == std::string::npos) ? "" : str.substr(start);
    }
    void Station::display(std::ostream& os, bool full) const {
        os << right << setw(3) << setfill('0') << m_id << " | ";
        os << left << setw(Station::m_widthField + 1) << setfill(' ') << m_name;
        os << "| " << right << setw(6) << setfill('0') << m_serial_num << " | ";

        if (full) {
            os << right << setw(4) << setfill(' ')  << m_curr_items << " | ";
            os << m_desc << endl;
        }
        else
            os << endl;
    }
}