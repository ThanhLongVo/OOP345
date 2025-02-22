/*
///////////////////////////////////////////////////////////////////////////
                    OOP345 Workshop 2 - Part 1
Full Name : Thanh Long Vo
Student ID# : 171587223
Email : tlvo2@myseneca.ca
Section : ZCC
Date: 19 May 2024
File: ProteinDatabase.h
Version: 1.0
I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.
#pragma once
///////////////////////////////////////////////////////////////////////////
*/
#pragma once
#ifndef SENECA_PROTEINDATABASE_H
#define SENECA_PROTEINDATABASE_H

#include <string>
#include <cstddef>

namespace seneca {

    class ProteinDatabase {
        std::string* proteins;
        std::size_t numProteins;

    public:
        ProteinDatabase();
        ProteinDatabase(const std::string& filename);
        ProteinDatabase(const ProteinDatabase& other); // Copy constructor
        ProteinDatabase(ProteinDatabase&& other) noexcept; // Move constructor
        ProteinDatabase& operator=(const ProteinDatabase& other); // Copy assignment
        ProteinDatabase& operator=(ProteinDatabase&& other) noexcept; // Move assignment
        ~ProteinDatabase();

        std::size_t size() const;
        std::string operator[](std::size_t index) const;
    };

}

#endif // SENECA_PROTEINDATABASE_H
