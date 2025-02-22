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
