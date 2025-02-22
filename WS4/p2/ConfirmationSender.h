/*
///////////////////////////////////////////////////////////////////////////
                    OOP345 Workshop 4 - Part 2
Full Name : Thanh Long Vo
Student ID# : 171587223
Email : tlvo2@myseneca.ca
Section : ZCC
Date: 05 Jun 2024
File: ConfirmationSender.h
Version: 1.0
I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

///////////////////////////////////////////////////////////////////////////
*/

#pragma once
#pragma once
#ifndef SENECA_CONFIRMATIONSENDER_H
#define SENECA_CONFIRMATIONSENDER_H

#include "Reservation.h"
#include <iostream>

namespace seneca {

    class ConfirmationSender {
        const Reservation** reservations;
        size_t count;

    public:
        ConfirmationSender();
        ConfirmationSender(const ConfirmationSender& other);
        ConfirmationSender(ConfirmationSender&& other) noexcept;
        ~ConfirmationSender();
        ConfirmationSender& operator=(const ConfirmationSender& other);
        ConfirmationSender& operator=(ConfirmationSender&& other) noexcept;

        ConfirmationSender& operator+=(const Reservation& res);
        ConfirmationSender& operator-=(const Reservation& res);

        friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& cs);
    };

} // namespace seneca

#endif // SENECA_CONFIRMATIONSENDER_H
