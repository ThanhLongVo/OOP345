// Name: Thanh Long Vo
// Seneca Student ID: 171587223
// Seneca email: tlvo2@myseneca.ca
// Date of completion: 28 Jul 2024
// 
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#pragma once
#ifndef SENECA_STATION_H
#define SENECA_STATION_H

#include <iostream>

namespace seneca
{
    class Station
    {
        int m_id{ 0 }; // the id of the station
        std::string m_name{ "" }; // the name of the item handled by the station
        std::string m_desc{ "" }; // the description of the station
        size_t m_serial_num{ 0u }; // the next serial number to be assigned to an item at this station
        size_t m_curr_items{ 0u }; // the number of items currently in stock

        // Class Variables
        static size_t m_widthField;
        static size_t id_generator;

    public:
        Station(const std::string& src);

        // returns the name of the current Station object
        const std::string& getItemName() const;

        // returns the next serial number
        size_t getNextSerialNumber();

        // returns the remaining quantity of items
        size_t getQuantity() const;

        // subtracts 1 from the available quantity
        void updateQuantity();

        // display information about the current object
        void display(std::ostream& os, bool full) const;

    };
}
#endif // !SENECA_STATION_H