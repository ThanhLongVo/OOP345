/*
///////////////////////////////////////////////////////////////////////////
                    OOP345 Workshop 2 - Part 2
Full Name : Thanh Long Vo
Student ID# : 171587223
Email : tlvo2@myseneca.ca
Section : ZCC
Date: 19 May 2024
File: TimedTask.h
Version: 1.0
I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.
#pragma once
///////////////////////////////////////////////////////////////////////////
*/
#ifndef SENECA_TIMEDTASK_H
#define SENECA_TIMEDTASK_H

#include <chrono>
#include <string>
#include <iostream>

namespace seneca {

    struct Task {
        std::string name;
        std::string units;
        std::chrono::steady_clock::duration duration;
    };

    class TimedTask {
        int numRecords;
        std::chrono::steady_clock::time_point startTime;
        std::chrono::steady_clock::time_point endTime;
        Task tasks[10];

    public:
        TimedTask();
        void startClock();
        void stopClock();
        void addTask(const char* name);
        friend std::ostream& operator<<(std::ostream& os, const TimedTask& tt);
    };

}

#endif // SENECA_TIMEDTASK_H
