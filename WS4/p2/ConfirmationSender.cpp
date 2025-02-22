/*
///////////////////////////////////////////////////////////////////////////
                    OOP345 Workshop 4 - Part 2
Full Name : Thanh Long Vo
Student ID# : 171587223
Email : tlvo2@myseneca.ca
Section : ZCC
Date: 05 Jun 2024
File: ConfirmationSender.cpp
Version: 1.0
I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

///////////////////////////////////////////////////////////////////////////
*/

#include "ConfirmationSender.h"
#include <algorithm>

namespace seneca {

    ConfirmationSender::ConfirmationSender() : reservations(nullptr), count(0) {}

    ConfirmationSender::ConfirmationSender(const ConfirmationSender& other) : reservations(new const Reservation* [other.count]), count(other.count) {
        std::copy(other.reservations, other.reservations + other.count, reservations);
    }

    ConfirmationSender::ConfirmationSender(ConfirmationSender&& other) noexcept : reservations(other.reservations), count(other.count) {
        other.reservations = nullptr;
        other.count = 0;
    }

    ConfirmationSender::~ConfirmationSender() {
        delete[] reservations;
    }

    ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& other) {
        if (this != &other) {
            delete[] reservations;

            count = other.count;
            reservations = new const Reservation * [count];
            std::copy(other.reservations, other.reservations + count, reservations);
        }
        return *this;
    }

    ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& other) noexcept {
        if (this != &other) {
            delete[] reservations;

            reservations = other.reservations;
            count = other.count;

            other.reservations = nullptr;
            other.count = 0;
        }
        return *this;
    }

    ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
        bool found = std::find(reservations, reservations + count, &res) != reservations + count;
        if (!found) {
            const Reservation** temp = new const Reservation * [count + 1];
            std::copy(reservations, reservations + count, temp);
            temp[count] = &res;
            delete[] reservations;
            reservations = temp;
            ++count;
        }
        return *this;
    }

    ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
        auto it = std::find(reservations, reservations + count, &res);
        if (it != reservations + count) {
            size_t index = it - reservations;
            const Reservation** temp = new const Reservation * [count - 1];
            std::copy(reservations, reservations + index, temp);
            std::copy(reservations + index + 1, reservations + count, temp + index);
            delete[] reservations;
            reservations = temp;
            --count;
        }
        return *this;
    }

    std::ostream& operator<<(std::ostream& os, const ConfirmationSender& cs) {
        os << "--------------------------\n";
        os << "Confirmations to Send\n";
        os << "--------------------------\n";
        if (cs.count == 0) {
            os << "There are no confirmations to send!\n";
        }
        else {
            for (size_t i = 0; i < cs.count; ++i) {
                os << *cs.reservations[i];
            }
        }
        os << "--------------------------\n";
        return os;
    }

} // namespace seneca
