/*
///////////////////////////////////////////////////////////////////////////
                    OOP345 Workshop 4 - Part 2
Full Name : Thanh Long Vo
Student ID# : 171587223
Email : tlvo2@myseneca.ca
Section : ZCC
Date: 05 Jun 2024
File: Reservation.cpp
Version: 1.0
I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

///////////////////////////////////////////////////////////////////////////
*/



#define _CRT_SECURE_NO_WARNINGS
#include "Reservation.h"
#include <sstream>
#include <algorithm>
#include <cstring>

namespace seneca {

    Reservation::Reservation() : reservation_id{ "" }, name(""), email(""), party_size(0), day(0), hour(0) {}

    // Constructor that takes a reservation string and parses it into the data members
    Reservation::Reservation(const std::string& res) {
        std::string clean_res = res;

        std::istringstream iss(clean_res);
        std::string token;

        // Extract reservation ID
        std::getline(iss, token, ':');
        // Remove leading and trailing spaces but keep spaces between words
        token.erase(0, token.find_first_not_of(' '));
        token.erase(token.find_last_not_of(' ') + 1);
        strncpy(reservation_id, token.c_str(), sizeof(reservation_id) - 1);
        reservation_id[sizeof(reservation_id) - 1] = '\0';

        // Extract name
        std::getline(iss, name, ',');
        // Remove leading and trailing spaces from the name
        name.erase(name.find_last_not_of(' ') + 1);
        name.erase(0, name.find_first_not_of(' '));

        // Extract email
        std::getline(iss, email, ',');
        // Remove leading and trailing spaces from the email
        email.erase(email.find_last_not_of(' ') + 1);
        email.erase(0, email.find_first_not_of(' '));

        // Extract party size
        std::getline(iss, token, ',');
        party_size = std::stoi(token);

        // Extract day
        std::getline(iss, token, ',');
        day = std::stoi(token);

        // Extract hour
        std::getline(iss, token, ',');
        hour = std::stoi(token);
    }

    // Function to update the day and hour of the reservation
    void Reservation::update(int new_day, int new_hour) {
        day = new_day;
        hour = new_hour;
    }

    // Overloaded operator<< to output reservation details
    std::ostream& operator<<(std::ostream& os, const Reservation& res) {
        os << "Reservation " << std::setw(10) << std::right << res.reservation_id << ": "
            << std::setw(20) << std::right << res.name << "  <" << std::left << res.email << "> ";

        // Calculate and add spaces after the email to align correctly
        int email_padding = 20 - res.email.length();
        for (int i = 0; i < email_padding; ++i) {
            os << " ";
        }
        os << " ";

        
        if (res.hour >= 6 && res.hour <= 9) {
            os << "Breakfast on day " << res.day << " @ " << res.hour << ":00 for " << res.party_size << (res.party_size == 1 ? " person." : " people.");
        }
        else if (res.hour >= 11 && res.hour <= 15) {
            os << "Lunch on day " << res.day << " @ " << res.hour << ":00 for " << res.party_size << (res.party_size == 1 ? " person." : " people.");
        }
        else if (res.hour >= 17 && res.hour <= 21) {
            os << "Dinner on day " << res.day << " @ " << res.hour << ":00 for " << res.party_size << (res.party_size == 1 ? " person." : " people.");
        }
        else {
            os << "Drinks on day " << res.day << " @ " << res.hour << ":00 for " << res.party_size << (res.party_size == 1 ? " person." : " people.");
        }
        os << std::endl;

        return os;
    }

} // namespace seneca
