#ifndef SENECA_FOODORDER_H
#define SENECA_FOODORDER_H

#include <iostream>
// declaring global variables
extern double g_taxrate;  // Khai báo biến toàn cục
extern double g_dailydiscount;
namespace seneca {
    
    class FoodOrder {
        char customerName[11];  // 10 characters + null terminator
        char orderDescription[26];  // 25 characters + null terminator
        double price;
        bool special;
    public:
        FoodOrder();
        //~FoodOrder();  // Destructor đã khai báo
        void read(std::istream& istr);
        void display() const;
    };    
}

#endif // SENECA_FOODORDER_H
