// Name: Thanh Long Vo
// Seneca Student ID: 171587223
// Seneca email: tlvo2@myseneca.ca
// Date of completion: 15 May 2024
// Workshop: 01
// I declare that this submission is the result of my own work and I only copied the code that my professor provided 
// to complete my workshops and assignments. This submitted piece of work has not been shared with any other student 
// or 3rd party content provider.

#ifndef SENECA_FOODORDER_H
#define SENECA_FOODORDER_H

#include <iostream>
#include <string>
// declaring global variables
extern double g_taxrate;  // Khai báo biến toàn cục
extern double g_dailydiscount;
namespace seneca {
    
    class FoodOrder {
        std::string customerName;  // 10 characters + null terminator
        std::string orderDescription;  // 25 characters + null terminator
        double price;
        bool special;
    public:
        FoodOrder();
        ~FoodOrder();  // Destructor đã khai báo
        void read(std::istream& istr);
        void display() const;
    };    
}

#endif // SENECA_FOODORDER_H
