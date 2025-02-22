/*
///////////////////////////////////////////////////////////////////////////
                    OOP345 Workshop 4 - Part 2
Full Name : Thanh Long Vo
Student ID# : 171587223
Email : tlvo2@myseneca.ca
Section : ZCC
Date: 05 Jun 2024
File: Reservation.h
Version: 1.0
I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

///////////////////////////////////////////////////////////////////////////
*/

#pragma once
#ifndef SENECA_RESERVATION_H
#define SENECA_RESERVATION_H

#include <string>
#include <iostream>
#include <iomanip>

namespace seneca {

    class Reservation {
        char reservation_id[11];
        std::string name;
        std::string email;
        int party_size;
        int day;
        int hour;

    public:
        Reservation();
        Reservation(const std::string& res);
        void update(int new_day, int new_hour);

        friend std::ostream& operator<<(std::ostream& os, const Reservation& res);
    };

} // namespace seneca

#endif // SENECA_RESERVATION_H
