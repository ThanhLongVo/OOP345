/*
///////////////////////////////////////////////////////////////////////////
                    OOP345 Workshop 2 - Part 2
Full Name : Thanh Long Vo
Student ID# : 171587223
Email : tlvo2@myseneca.ca
Section : ZCC
Date: 19 May 2024
File: TimedTask.cpp
Version: 1.0
I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.
#pragma once
///////////////////////////////////////////////////////////////////////////
*/
#include "TimedTask.h"
#include <iomanip>

namespace seneca {

    TimedTask::TimedTask() : numRecords(0) {}

    void TimedTask::startClock() {
        startTime = std::chrono::steady_clock::now();
    }

    void TimedTask::stopClock() {
        endTime = std::chrono::steady_clock::now();
    }

    void TimedTask::addTask(const char* name) {
        if (numRecords < 10) {
            tasks[numRecords].name = name;
            tasks[numRecords].units = "nanoseconds";
            tasks[numRecords].duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
            numRecords++;
        }
    }

    std::ostream& operator<<(std::ostream& os, const TimedTask& tt) {
        os << "--------------------------\n";
        os << "Execution Times:\n--------------------------\n";
        for (int i = 0; i < tt.numRecords; ++i) {
            os << std::setw(21) << std::left << tt.tasks[i].name
                << std::setw(13) << std::right << tt.tasks[i].duration.count() << " "
                << tt.tasks[i].units << "\n";
        }
        os << "--------------------------\n";
        return os;
    }

}
