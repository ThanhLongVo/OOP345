// Name: Thanh Long Vo
// Seneca Student ID: 171587223
// Seneca email: tlvo2@myseneca.ca
// Date of completion: 28 Jul 2024
// 
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <set>
#include "CustomerOrder.h"
#include "Utilities.h"

using namespace std;

namespace seneca
{
    size_t CustomerOrder::m_widthField = 0u;

    CustomerOrder::CustomerOrder(const std::string& src)
    {
        Utilities util;
        bool more = true;
        size_t pos = 0u;
        size_t idx = 0u;

        try {
            m_name = util.extractToken(src, pos, more);
            m_product = util.extractToken(src, pos, more);
            m_cntItem = std::count(src.begin(), src.end(), util.getDelimiter()) - 1;

            if (m_cntItem)
                m_lstItem = new Item * [m_cntItem];

            while (more && m_cntItem) {
                m_lstItem[idx] = new Item(util.extractToken(src, pos, more));
                ++idx;
            }

            CustomerOrder::m_widthField = max(util.getFieldWidth(), CustomerOrder::m_widthField);
        }
        catch (std::string err) {
            cout << err;
        }
    }

    CustomerOrder::CustomerOrder(const CustomerOrder& src) {
        throw false;
    }

    CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept {
        *this = std::move(src);
    }

    CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept {
        if (this != &src) {
            if (m_lstItem) {
                for (auto i = 0u; i < m_cntItem; ++i)
                    delete m_lstItem[i];

                delete[] m_lstItem;
            }

            m_name = src.m_name;
            m_product = src.m_product;
            m_cntItem = src.m_cntItem;
            m_lstItem = src.m_lstItem;

            src.m_name = "";
            src.m_product = "";
            src.m_cntItem = 0u;
            src.m_lstItem = nullptr;
        }

        return *this;
    }

    CustomerOrder::~CustomerOrder() {
        if (m_lstItem) {
            for (auto i = 0u; i < m_cntItem; ++i)
                delete m_lstItem[i];

            delete[] m_lstItem;
            m_lstItem = nullptr;
        }
    }

    bool CustomerOrder::isOrderFilled() const {
        bool result = true;
        for (size_t i = 0; i < m_cntItem; ++i) {
            if (!m_lstItem[i]->m_isFilled) {
                result = false; // Mark that at least one item has not been filled in.
                break; // No need to check further if an unfilled item has been found.
            }
        }
        return result;
    }

   
    /*bool CustomerOrder::isItemFilled(const std::string& itemName) const {
        bool result = false;

        for (auto i = 0u; i < m_cntItem; ++i)
            m_lstItem[i]->m_itemName == itemName ? result = false : result = true;

        return result;
    }*/
   bool CustomerOrder::isItemFilled(const std::string& itemName) const {
    for (size_t i = 0; i < m_cntItem; ++i) {
        if (m_lstItem[i]->m_itemName == itemName && !m_lstItem[i]->m_isFilled) {
            return false;
        }
    }
    return true;
    }


   
    //void CustomerOrder::fillItem(Station& station, std::ostream& os) {
    //    std::set<std::string> processedItems; // Store processed products.

    //    for (auto i = 0u; i < m_cntItem; ++i) {
    //        if (m_lstItem[i]->m_itemName == station.getItemName() && !m_lstItem[i]->m_isFilled) {
    //            // Check if the product has been processed.
    //            if (processedItems.find(m_lstItem[i]->m_itemName) == processedItems.end()) {
    //                if (station.getQuantity() > 0) {
    //                    station.updateQuantity();
    //                    m_lstItem[i]->m_isFilled = true;
    //                    m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
    //                    os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
    //                }
    //                else {
    //                    os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
    //                }
    //                processedItems.insert(m_lstItem[i]->m_itemName); // Mark this product as processed.
    //            }
    //        }
    //    }
    //}
   
   void CustomerOrder::fillItem(Station& station, std::ostream& os) 
   { 
       if (m_cntItem <= 0) { return; }
       std::string currentItem = station.getItemName();
       for (auto i = 0u; i < m_cntItem; i++) 
       { 
           if (m_lstItem[i]->m_itemName == currentItem) 
           { 
               if (station.getQuantity() > 0 && m_lstItem[i]->m_isFilled == false) 
               { 
                   station.updateQuantity();
                   m_lstItem[i]->m_isFilled = true;
                   m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
                   os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
                   break;
               }    
               if (!m_lstItem[i]->m_isFilled && !station.getQuantity())
               { 
                   os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
               } 
           } 
       } 
   }


    void CustomerOrder::display(std::ostream& os) const {
        os << m_name << " - " << m_product << std::endl;
        for (size_t i = 0; i < m_cntItem; ++i) {
            os << "[" << std::right << std::setw(6) << std::setfill('0') << m_lstItem[i]->m_serialNumber << "]";
            os << " " << std::left << std::setw(CustomerOrder::m_widthField) << std::setfill(' ') << m_lstItem[i]->m_itemName;
            os << " - " << (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED") << std::endl;
        }
    }

}