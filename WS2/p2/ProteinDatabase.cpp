/*
///////////////////////////////////////////////////////////////////////////
                    OOP345 Workshop 2 - Part 2
Full Name : Thanh Long Vo
Student ID# : 171587223
Email : tlvo2@myseneca.ca
Section : ZCC
Date: 19 May 2024
File: ProteinDatabase.cpp
Version: 2.0
I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.
#pragma once
///////////////////////////////////////////////////////////////////////////
*/
#include "ProteinDatabase.h"
#include <fstream>
#include <iostream>
#include <vector>

namespace seneca {

    ProteinDatabase::ProteinDatabase() : proteins(nullptr), numProteins(0) {}

    ProteinDatabase::ProteinDatabase(const std::string& filename) : proteins(nullptr), numProteins(0) {
        std::ifstream file(filename);
        if (!file) {
            std::cerr << "Error: File '" << filename << "' could not be opened." << std::endl;
            return;
        }

        std::string line;
        std::vector<std::string> proteinSequences;
        std::string currentProtein;

        while (std::getline(file, line)) {
            if (line.empty()) continue;
            if (line[0] == '>') {
                if (!currentProtein.empty()) {
                    proteinSequences.push_back(currentProtein);
                    currentProtein.clear();
                }
            }
            else {
                currentProtein += line;
            }
        }
        if (!currentProtein.empty()) {
            proteinSequences.push_back(currentProtein);
        }

        numProteins = proteinSequences.size();
        proteins = new std::string[numProteins];
        for (size_t i = 0; i < numProteins; ++i) {
            proteins[i] = proteinSequences[i];
        }
    }

    ProteinDatabase::ProteinDatabase(const ProteinDatabase& other) : proteins(nullptr), numProteins(0) {
        *this = other;
    }

    ProteinDatabase::ProteinDatabase(ProteinDatabase&& other) noexcept : proteins(other.proteins), numProteins(other.numProteins) {
        other.proteins = nullptr;
        other.numProteins = 0;
    }

    ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& other) {
        if (this != &other) {
            delete[] proteins;
            numProteins = other.numProteins;
            proteins = new std::string[numProteins];
            for (size_t i = 0; i < numProteins; ++i) {
                proteins[i] = other.proteins[i];
            }
        }
        return *this;
    }

    ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& other) noexcept {
        if (this != &other) {
            delete[] proteins;
            proteins = other.proteins;
            numProteins = other.numProteins;
            other.proteins = nullptr;
            other.numProteins = 0;
        }
        return *this;
    }

    ProteinDatabase::~ProteinDatabase() {
        delete[] proteins;
    }

    std::size_t ProteinDatabase::size() const {
        return numProteins;
    }

    std::string ProteinDatabase::operator[](std::size_t index) const {
        return index < numProteins ? proteins[index] : "";
    }

}
