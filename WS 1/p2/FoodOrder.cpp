// Name: Thanh Long Vo
// Seneca Student ID: 171587223
// Seneca email: tlvo2@myseneca.ca
// Date of completion: 15 May 2024
// Workshop: 01
// I declare that this submission is the result of my own work and I only copied the code that my professor provided 
// to complete my workshops and assignments. This submitted piece of work has not been shared with any other student 
// or 3rd party content provider.
#define _CRT_SECURE_NO_WARNINGS
#include "FoodOrder.h"
#include <cstring>
#include <limits>
#include <iomanip>
#include <iostream>  // Include necessary header

// Define global variables
double g_taxrate = 0;
double g_dailydiscount = 0;

namespace seneca {

    /*FoodOrder::FoodOrder() : price(0.0), special(false) {
        customerName[0] = '\0';
        orderDescription[0] = '\0';
    }*/
    FoodOrder::FoodOrder() : price(0.0), special(false) {}

    FoodOrder::~FoodOrder() {}  // Định nghĩa destructor

    void FoodOrder::read(std::istream& istr) {
        if (istr.good()) {
            std::getline(istr, customerName, ',');
            if (istr.fail()) {
                customerName.clear(); // Ensure the string is empty
            }

            std::getline(istr, orderDescription, ',');
            if (istr.fail()) {
                orderDescription.clear(); // Ensure the string is empty
            }

            istr >> price;
            if (istr.fail()) {
                price = 0.0; // Ensure the initial value
            }

            istr.ignore(std::numeric_limits<std::streamsize>::max(), ',');
            char sp;
            istr >> sp;
            if (istr.fail()) {
                sp = 'N'; // Ensure the initial value
            }
            special = (sp == 'Y');
            istr.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            customerName.clear(); // Ensure the string is empty
            orderDescription.clear(); // Ensure the string is empty
            price = 0.0;
            special = false;
        }
    }

    void FoodOrder::display() const {
        static int displayCounter = 0;  // counting variable
        displayCounter++;
        double taxedPrice = price * (1 + g_taxrate);
        double specialPrice = special ? (taxedPrice - g_dailydiscount) : 0;

        if (customerName[0] != '\0') {  // Check if customerName is not empty
            std::cout << std::left << std::setw(2) << displayCounter << ". "
                << std::setw(10) << customerName << "|"
                << std::setw(25) << orderDescription << "|"
                << std::setw(12) << std::fixed << std::setprecision(2) << taxedPrice << "|";
            if (special) {
                std::cout << std::right << std::setw(13) << std::fixed << std::setprecision(2) << specialPrice;
            }
        }
        else {
            std::cout << std::left << std::setw(2) << displayCounter << ". " << "No Order";
        }
        std::cout << std::endl;
    }
}