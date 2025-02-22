// Name: Thanh Long Vo
// Seneca Student ID: 171587223
// Seneca email: tlvo2@myseneca.ca
// Date of completion: 11 Jul 2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include "Station.h"
#include "Utilities.h"

using namespace std;

namespace seneca {
    size_t Station::m_widthField = 0u;
    size_t Station::id_generator = 0u;

    Station::Station(const std::string& src) {
        Utilities util;
        m_id = ++Station::id_generator;
        bool hasMore = true;
        size_t next = 0u;

        try {
            m_name = util.extractToken(src, next, hasMore);
            m_serial_num = stoi(util.extractToken(src, next, hasMore));
            m_curr_items = stoi(util.extractToken(src, next, hasMore));
            Station::m_widthField = max(util.getFieldWidth(), Station::m_widthField);
            m_desc = util.extractToken(src, next, hasMore);
        }
        catch (std::string err) {
            cout << err;
        }
    }

    const std::string& Station::getItemName() const { return m_name; }
    size_t Station::getNextSerialNumber() { ++m_serial_num; return m_serial_num - 1; }
    size_t Station::getQuantity() const { return m_curr_items; }
    void Station::updateQuantity() { m_curr_items = m_curr_items ? m_curr_items - 1 : 0; }
    // Helper function to trim leading spaces
    std::string trimLeft(const std::string& str) {
        size_t start = str.find_first_not_of(' ');
        return (start == std::string::npos) ? "" : str.substr(start);
    }
    void Station::display(std::ostream& os, bool full) const {
        os << std::right << std::setw(3) << std::setfill('0') << m_id << " | ";
        os << std::left << std::setw(m_widthField) << std::setfill(' ') << m_name << "| ";
        os << std::right << std::setw(6) << std::setfill('0') << m_serial_num << " | ";

        if (full) {
            os << std::right << std::setw(4) << std::setfill(' ') << m_curr_items << " | ";
            os << std::left << trimLeft(m_desc);
        }
        os << std::endl;
    }
}
