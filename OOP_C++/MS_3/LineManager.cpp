/* Full Name : Edwards Josue Ortega Gonzalez
Student ID# : 118705227
Email : eortega-gonzalez@myseneca.ca
Date: 2023 - 12 - 02
Section : NFF */

#include "LineManager.h"
#include "Utilities.h"


namespace sdds
{
	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
	{
        std::vector<std::string> curStation;
        std::vector<std::string> nextStation;
        std::ifstream inputFile(file);
        std::string line;
        Utilities temp_util;
		size_t firstPos = 0u;
        size_t nextPos;
        bool more = false;

        if (!inputFile)
        {
            throw std::string("\n***ERROR: Can not open: ") + std::string(file);
        }
        else 
        {
            while (std::getline(inputFile, line)) 
            {
				nextPos = firstPos;
				std::string t_curStation;
				std::string t_nextStation;
				t_curStation = temp_util.extractToken(line, nextPos, more);
				if (nextPos != firstPos)
				{
					t_nextStation = temp_util.extractToken(line, nextPos, more);
					curStation.push_back(t_curStation);
					nextStation.push_back(t_nextStation);
				}
				auto flag_1 = std::find_if(stations.begin(), stations.end(), [&](Workstation* station)
					{
						return station->getItemName() == t_curStation;
					});
				m_activeLine.push_back(*flag_1);

				if (t_nextStation.length() > 0) {
					auto flag_2 = std::find_if(stations.begin(), stations.end(), [&](Workstation* station) 
						{
						return station->getItemName() == t_nextStation;
						});
					(*flag_1)->setNextStation(*flag_2);
				}
            }
            inputFile.close();
			std::string tempStation;
			
			std::for_each(curStation.begin(), curStation.end(), [&](std::string station) {
				bool found = false;
				std::for_each(nextStation.begin(), nextStation.end(), [&](std::string nStation) {
					if (station == nStation) { found = true; }
				});

				if (!found)
				{
					tempStation = station;
				}
			});

			auto firstStation = std::find_if(stations.begin(), stations.end(), [&](Workstation* station) 
				{
				return station->getItemName() == tempStation;
				});

			m_firstStation = *firstStation;
			m_cntCustomerOrder = g_pending.size();
        }

	}
	void LineManager::reorderStations()
	{
		Workstation* currentWS = m_firstStation;
		std::vector<Workstation*> ordered;
		while (currentWS) 
		{
			ordered.push_back(currentWS);
			currentWS = currentWS->getNextStation();
		}
		m_activeLine = ordered;
	}
	bool LineManager::run(std::ostream& os)
	{
		static size_t count = 0;
		os << "Line Manager Iteration: " << ++count << std::endl;
		if (!g_pending.empty()) 
		{
			*m_firstStation += std::move(g_pending.front());
			g_pending.pop_front();
		}
		std::for_each(m_activeLine.begin(), m_activeLine.end(), [&](auto& val) {
			val->fill(os);
			});

		std::for_each(m_activeLine.begin(), m_activeLine.end(), [&](auto& val) {
			val->attemptToMoveOrder();
			});

		bool out = (g_incomplete.size() + g_completed.size()) == m_cntCustomerOrder;
		return out;
	}
	void LineManager::display(std::ostream& os) const
	{
		std::for_each(m_activeLine.begin(), m_activeLine.end(), [&](auto station) {station->display(os); });
	}
}