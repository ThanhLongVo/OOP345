/*
///////////////////////////////////////////////////////////////////////////
                    OOP345 Workshop 3 - Part 2
Full Name : Thanh Long Vo
Student ID# : 171587223
Email : tlvo2@myseneca.ca
Section : ZCC
Date: 31 May 2024
File: Book.h
Version: 1.0
I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.
#pragma once
///////////////////////////////////////////////////////////////////////////
*/
#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H

#include <iostream>
#include <string>

namespace seneca {
    class Book {
        std::string m_title;
        unsigned m_numChapters;
        unsigned m_numPages;
    public:
        Book();
        Book(const std::string& title, unsigned nChapters, unsigned nPages);

        // Member prototypes
        bool isValid() const;
        std::string title() const;
        unsigned numChapters() const;
        unsigned numPages() const;
        double averagePagesPerChapter() const;

        bool operator<(const Book& other) const;
        bool operator>(const Book& other) const;

        std::ostream& print(std::ostream& os) const;
    };

    std::ostream& operator<<(std::ostream& os, const Book& bk);
}

#endif // SENECA_BOOK_H
