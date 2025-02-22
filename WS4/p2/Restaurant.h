﻿
/*
///////////////////////////////////////////////////////////////////////////
                    OOP345 Workshop 4 - Part 2
Full Name : Thanh Long Vo
Student ID# : 171587223
Email : tlvo2@myseneca.ca
Section : ZCC
Date: 05 Jun 2024
File: Restaurant.h
Version: 1.0
I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.
///////////////////////////////////////////////////////////////////////////
*/
#pragma once
#ifndef SENECA_RESTAURANT_H
#define SENECA_RESTAURANT_H

#include "Reservation.h"
#include <iostream>

namespace seneca {

    class Restaurant {
        const Reservation** reservations; 
        size_t count;

    public:
        Restaurant(const Reservation* reservations[], size_t cnt);
        Restaurant(const Restaurant& other);
        Restaurant(Restaurant&& other) noexcept;
        ~Restaurant();
        Restaurant& operator=(const Restaurant& other);
        Restaurant& operator=(Restaurant&& other) noexcept;

        size_t size() const;

        friend std::ostream& operator<<(std::ostream& os, const Restaurant& res);
    };

} // namespace seneca

#endif // SENECA_RESTAURANT_H
