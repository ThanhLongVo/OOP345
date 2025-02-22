#pragma once
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

        std::ostream& print(std::ostream& os) const;
    };

    std::ostream& operator<<(std::ostream& os, const Book& bk);
}

#endif // SENECA_BOOK_H
