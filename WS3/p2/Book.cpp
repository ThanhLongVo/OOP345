/*
///////////////////////////////////////////////////////////////////////////
                    OOP345 Workshop 3 - Part 2
Full Name : Thanh Long Vo
Student ID# : 171587223
Email : tlvo2@myseneca.ca
Section : ZCC
Date: 31 May 2024
File: Book.cpp
Version: 1.0
I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.
#pragma once
///////////////////////////////////////////////////////////////////////////
*/
#include "Book.h"
#include <iomanip>

namespace seneca {

    Book::Book() : m_title{ "" }, m_numChapters{ 0 }, m_numPages{ 0 } {}

    Book::Book(const std::string& title, unsigned nChapters, unsigned nPages)
        : m_title{ title }, m_numChapters{ nChapters }, m_numPages{ nPages } {}

    bool Book::isValid() const {
        return !m_title.empty() && m_numChapters > 0 && m_numPages > 0;
    }

    std::string Book::title() const {
        return m_title;
    }

    unsigned Book::numChapters() const {
        return m_numChapters;
    }

    unsigned Book::numPages() const {
        return m_numPages;
    }

    double Book::averagePagesPerChapter() const {
        return static_cast<double>(m_numPages) / m_numChapters;
    }

    bool Book::operator<(const Book& other) const {
        return this->averagePagesPerChapter() < other.averagePagesPerChapter();
    }

    bool Book::operator>(const Book& other) const {
        return this->averagePagesPerChapter() > other.averagePagesPerChapter();
    }

    std::ostream& Book::print(std::ostream& os) const {
        if (isValid()) {
            os << std::right << std::setw(56)
                << m_title + "," + std::to_string(m_numChapters) + "," + std::to_string(m_numPages)
                << " | " << std::left << std::setw(15)
                << "(" + std::to_string(averagePagesPerChapter()) + ")";
        }
        else {
            os << "| Invalid book data";
        }
        return os;
    }

    std::ostream& operator<<(std::ostream& os, const Book& bk) {
        return bk.print(os);
    }
}
