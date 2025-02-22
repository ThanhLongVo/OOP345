// Name: Thanh Long Vo
// Seneca Student ID: 171587223
// Seneca email: tlvo2@myseneca.ca
// Date of completion: 28 Jul 2024
// 
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "Workstation.h"

using namespace std;

namespace seneca {
    std::deque<CustomerOrder> g_pending;
    std::deque<CustomerOrder> g_completed;
    std::deque<CustomerOrder> g_incomplete;

    void Workstation::fill(std::ostream& os) {
        if (!m_orders.empty()) {
            m_orders.front().fillItem(*this, os);
        }
    }

    bool Workstation::attemptToMoveOrder() {
        if (m_orders.empty()) return false;

        // Order can be moved if it's filled or cannot be filled (no inventory)
        if (m_orders.front().isItemFilled(getItemName()) || getQuantity() <= 0) {
            if (m_pNextStation) {
                // Move to next station
                *m_pNextStation += move(m_orders.front());
            }
            else {
                // Determine if order is complete or incomplete and move to the appropriate queue
                if (m_orders.front().isOrderFilled()) {
                    g_completed.push_back(move(m_orders.front()));
                }
                else {
                    g_incomplete.push_back(move(m_orders.front()));
                }
            }
            m_orders.pop_front();
            return true;
        }
        return false;
    }
    //bool Workstation::attemptToMoveOrder() {
    //    bool moved = false;
    //    if (!m_orders.empty()) {
    //        // Check if the order at the front needs processing at this station
    //        if (m_orders.front().isItemFilled(getItemName()) || getQuantity() <= 0) {
    //            // Move to the next station or complete/incomplete queue
    //            if (m_pNextStation != nullptr) {
    //                *m_pNextStation += move(m_orders.front());
    //            }
    //            else {
    //                if (m_orders.front().isOrderFilled()) {
    //                    g_completed.push_back(move(m_orders.front()));
    //                }
    //                else {
    //                    g_incomplete.push_back(move(m_orders.front()));
    //                }
    //            }
    //            m_orders.pop_front();
    //            moved = true;
    //        }
    //    }
    //    return moved;
    //}





    void Workstation::setNextStation(Workstation* station) {
        m_pNextStation = station;
    }

    Workstation* Workstation::getNextStation() const {
        return m_pNextStation;
    }

    void Workstation::display(std::ostream& os) const {
        if (m_pNextStation) {
            os << getItemName() << " --> " << m_pNextStation->getItemName() << endl;
        }
        else {
            os << getItemName() << " --> End of Line" << endl;
        }
    }

    Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
        m_orders.push_back(move(newOrder));
        return *this;
    }
}
