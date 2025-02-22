/*
///////////////////////////////////////////////////////////////////////////
                    OOP345 Workshop 3 - Part 2
Full Name : Thanh Long Vo
Student ID# : 171587223
Email : tlvo2@myseneca.ca
Section : ZCC
Date: 31 May 2024
File: OrderedCollection.h
Version: 1.0
I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.
#pragma once
///////////////////////////////////////////////////////////////////////////
*/

#ifndef SENECA_ORDEREDCOLLECTION_H
#define SENECA_ORDEREDCOLLECTION_H

#include "Collection.h"

namespace seneca {

    template <typename T>
    class OrderedCollection : public Collection<T, 72> {
    public:
        bool operator+=(const T& item) override;
    };

    template <typename T>
    bool OrderedCollection<T>::operator+=(const T& item) {
        if (this->size() >= this->capacity()) {
            return false;
        }
        unsigned i;
        for (i = this->size(); i > 0 && this->operator[](i - 1) > item; --i) {
            this->operator[](i) = this->operator[](i - 1);
        }
        this->operator[](i) = item;
        this->incrSize();
        this->setSmallestItem(item);
        this->setLargestItem(item);
        return true;
    }
}

#endif // SENECA_ORDEREDCOLLECTION_H
