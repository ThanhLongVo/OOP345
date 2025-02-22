// Name: Thanh Long Vo
// Seneca Student ID: 171587223
// Seneca email: tlvo2@myseneca.ca
// Date of completion: 28 Jul 2024
// 
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "LineManager.h"
#include "Utilities.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

namespace seneca {
    LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {
        ifstream inFile(file);
        if (!inFile) {
            throw string("\n***Failed to open file ") + file + " ***\n";
        }

        string line;
        Utilities util;
        while (getline(inFile, line) && !line.empty()) {
            size_t next_pos = 0;
            bool more = true;
            string station = util.extractToken(line, next_pos, more);
            string nextStation = more ? util.extractToken(line, next_pos, more) : "";
            Workstation* currStationPtr = *find_if(stations.begin(), stations.end(), [&](Workstation* ws) {
                return ws->getItemName() == station;
                });

            if (!nextStation.empty()) {
                Workstation* nextStationPtr = *find_if(stations.begin(), stations.end(), [&](Workstation* ws) {
                    return ws->getItemName() == nextStation;
                    });
                currStationPtr->setNextStation(nextStationPtr);
            }
            m_activeLine.push_back(currStationPtr);
        }

        // Identify the first station
        for (auto& station : m_activeLine) {
            bool isStartingStation = true;
            for (auto& potentialPrevStation : m_activeLine) {
                if (station == potentialPrevStation->getNextStation()) {
                    isStartingStation = false;
                    break;
                }
            }
            if (isStartingStation) {
                m_firstStation = station;
                break;
            }
        }
        // Initialize m_cntCustomerOrder with the size of g_pending queue
        m_cntCustomerOrder = g_pending.size();
        inFile.close();
    }

    void LineManager::reorderStations() {
        vector<Workstation*> reorderedStations;
        Workstation* currentStation = m_firstStation;
        while (currentStation != nullptr) {
            reorderedStations.push_back(currentStation);
            currentStation = currentStation->getNextStation();
        }
        m_activeLine = move(reorderedStations);
    }

    bool LineManager::run(std::ostream& os) {
        static size_t iteration = 0u;
        os << "Line Manager Iteration: " << ++iteration << endl;

        if (!g_pending.empty()) {
            *m_firstStation += move(g_pending.front());
            g_pending.pop_front();
        }

        for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* ws) {
            ws->fill(os);
            });

        for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* ws) {
            ws->attemptToMoveOrder();
            });

        return g_completed.size() + g_incomplete.size() == m_cntCustomerOrder;
    }

    void LineManager::display(std::ostream& os) const {
        for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* ws) {
            ws->display(os);
            });
    }
}
