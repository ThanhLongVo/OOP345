// Name: Thanh Long Vo
// Seneca Student ID: 171587223
// Seneca email: tlvo2@myseneca.ca
// Date of completion: 28 Jul 2024
// 
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SENECA_WORKSTATION_H
#define SENECA_WORKSTATION_H

#include <iostream>
#include <deque>
#include "CustomerOrder.h"
#include "Station.h"

namespace seneca {
    extern std::deque<CustomerOrder> g_pending;
    extern std::deque<CustomerOrder> g_completed;
    extern std::deque<CustomerOrder> g_incomplete;

    class Workstation : public Station {
        std::deque<CustomerOrder> m_orders;      // Double-ended queue with CustomerOrders
        Workstation* m_pNextStation{ nullptr };  // Pointer to the next Workstation on the assembly line

    public:
        Workstation(const std::string& src) : Station(src) {}
        Workstation(const Workstation&) = delete;
        Workstation(Workstation&&) noexcept = delete;
        Workstation& operator=(const Workstation&) = delete;
        Workstation& operator=(Workstation&&) noexcept = delete;

        void fill(std::ostream& os);
        bool attemptToMoveOrder();
        void setNextStation(Workstation* station = nullptr);
        Workstation* getNextStation() const;
        void display(std::ostream& os) const;
        Workstation& operator+=(CustomerOrder&& newOrder);
    };
}

#endif // !SENECA_WORKSTATION_H
