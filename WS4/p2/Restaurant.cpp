/*
///////////////////////////////////////////////////////////////////////////
                    OOP345 Workshop 4 - Part 2
Full Name : Thanh Long Vo
Student ID# : 171587223
Email : tlvo2@myseneca.ca
Section : ZCC
Date: 05 Jun 2024
File: Restaurant.cpp
Version: 1.0
I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

///////////////////////////////////////////////////////////////////////////
*/


#include "Restaurant.h"
#include <utility>
#include <iomanip>

namespace seneca {

    Restaurant::Restaurant(const Reservation* reservations[], size_t cnt) : count(cnt) {
        this->reservations = new const Reservation * [count];
        for (size_t i = 0; i < count; ++i) {
            this->reservations[i] = new Reservation(*reservations[i]);
        }
    }

    Restaurant::Restaurant(const Restaurant& other) : Restaurant(other.reservations, other.count) {}

    Restaurant::Restaurant(Restaurant&& other) noexcept : reservations(other.reservations), count(other.count) {
        other.reservations = nullptr;
        other.count = 0;
    }

    Restaurant::~Restaurant() {
        for (size_t i = 0; i < count; ++i) {
            delete reservations[i];
        }
        delete[] reservations;
    }

    Restaurant& Restaurant::operator=(const Restaurant& other) {
        if (this != &other) {
            for (size_t i = 0; i < count; ++i) {
                delete reservations[i];
            }
            delete[] reservations;

            count = other.count;
            reservations = new const Reservation * [count];
            for (size_t i = 0; i < count; ++i) {
                reservations[i] = new Reservation(*other.reservations[i]);
            }
        }
        return *this;
    }

    Restaurant& Restaurant::operator=(Restaurant&& other) noexcept {
        if (this != &other) {
            for (size_t i = 0; i < count; ++i) {
                delete reservations[i];
            }
            delete[] reservations;

            reservations = other.reservations;
            count = other.count;

            other.reservations = nullptr;
            other.count = 0;
        }
        return *this;
    }

    size_t Restaurant::size() const {
        return count;
    }

    std::ostream& operator<<(std::ostream& os, const Restaurant& res) {
        static int CALL_CNT = 0;
        ++CALL_CNT;

        os << "--------------------------\n";
        os << "Fancy Restaurant (" << CALL_CNT << ")\n";
        os << "--------------------------\n";
        if (res.count == 0) {
            os << "This restaurant is empty!\n";
        }
        else {
            for (size_t i = 0; i < res.count; ++i) {
                os << *res.reservations[i];
            }
        }
        os << "--------------------------\n";
        return os;
    }

} // namespace seneca

