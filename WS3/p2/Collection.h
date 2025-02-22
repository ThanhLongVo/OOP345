/*
///////////////////////////////////////////////////////////////////////////
                    OOP345 Workshop 3 - Part 2
Full Name : Thanh Long Vo
Student ID# : 171587223
Email : tlvo2@myseneca.ca
Section : ZCC
Date: 31 May 2024
File: Collection.h
Version: 2.0
I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.
#pragma once
///////////////////////////////////////////////////////////////////////////
*/

#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H

#include <iostream>
#include <array>
#include "Book.h"

namespace seneca {

    template <typename T, unsigned C>
    class Collection {
        std::array<T, C> m_items{};
        unsigned m_size{ 0 };

        static T m_smallestItem;
        static T m_largestItem;

    protected:
        void setSmallestItem(const T& item);
        void setLargestItem(const T& item);
        T& operator[](unsigned index);
        void incrSize();

    public:
        Collection() = default;
        virtual bool operator+=(const T& item);
        unsigned size() const;
        unsigned capacity() const;
        T getSmallestItem() const;
        T getLargestItem() const;
        virtual void print(std::ostream& os) const;
    };

    // Define and initialize static members
    template <typename T, unsigned C>
    T Collection<T, C>::m_smallestItem = 9999;

    template <typename T, unsigned C>
    T Collection<T, C>::m_largestItem = -9999;

    // Template specializations for Book and capacity 10
    template <>
    Book Collection<Book, 10>::m_smallestItem = Book("", 1, 10000);

    template <>
    Book Collection<Book, 10>::m_largestItem = Book("", 10000, 1);

    // Template specializations for Book and capacity 72
    template <>
    Book Collection<Book, 72>::m_smallestItem = Book("", 1, 10000);

    template <>
    Book Collection<Book, 72>::m_largestItem = Book("", 10000, 1);

    template <typename T, unsigned C>
    void Collection<T, C>::setSmallestItem(const T& item) {
        if (item < m_smallestItem) {
            m_smallestItem = item;
        }
    }

    template <typename T, unsigned C>
    void Collection<T, C>::setLargestItem(const T& item) {
        if (item > m_largestItem) {
            m_largestItem = item;
        }
    }

    template <typename T, unsigned C>
    bool Collection<T, C>::operator+=(const T& item) {
        if (m_size >= C) {
            return false;
        }
        setSmallestItem(item);
        setLargestItem(item);
        m_items[m_size++] = item;
        return true;
    }

    template <typename T, unsigned C>
    unsigned Collection<T, C>::size() const {
        return m_size;
    }

    template <typename T, unsigned C>
    unsigned Collection<T, C>::capacity() const {
        return C;
    }

    template <typename T, unsigned C>
    T Collection<T, C>::getSmallestItem() const {
        return m_smallestItem;
    }

    template <typename T, unsigned C>
    T Collection<T, C>::getLargestItem() const {
        return m_largestItem;
    }

    template <typename T, unsigned C>
    T& Collection<T, C>::operator[](unsigned index) {
        return m_items[index];
    }

    template <typename T, unsigned C>
    void Collection<T, C>::incrSize() {
        if (m_size < C) {
            ++m_size;
        }
    }

    // Specialized print functions for Book and capacity 10 and 72    
    template <>
    void Collection<Book, 10>::print(std::ostream& os) const {
        os << "| ---------------------------------------------------------------------------|\n";
        for (unsigned i = 0; i < m_size; ++i) {
            os << "| " << std::setw(80) << std::left;
            m_items[i].print(os) << " |\n";
        }
        os << "| ---------------------------------------------------------------------------|\n";
    }

    template <>
    void Collection<Book, 72>::print(std::ostream& os) const {
        os << "| ---------------------------------------------------------------------------|\n";
        for (unsigned i = 0; i < m_size; ++i) {
            os << "| " << std::setw(80) << std::left;
            m_items[i].print(os) << " |\n";
        }
        os << "| ---------------------------------------------------------------------------|\n";
    }

    // General print function for other types
    template <typename T, unsigned C>
    void Collection<T, C>::print(std::ostream& os) const {
        os << "[";
        for (unsigned i = 0; i < m_size; ++i) {
            os << m_items[i];
            if (i < m_size - 1) {
                os << ",";
            }
        }
        os << "]" << std::endl;
    }

}

#endif // SENECA_COLLECTION_H
