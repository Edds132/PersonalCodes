/* Full Name : Edwards Josue Ortega Gonzalez
Student ID# : 118705227
Email : eortega-gonzalez@myseneca.ca
Date: 2023 - 12 - 02
Section : NFF */

#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H

#include <string>
#include <vector>
#include <fstream>
#include "Workstation.h"
#include "CustomerOrder.h"
#include <iostream>
#include <algorithm>

namespace sdds
{
	class LineManager
	{
		std::vector<Workstation*> m_activeLine;
		size_t m_cntCustomerOrder{ 0u };
		Workstation* m_firstStation{ nullptr };

	public:
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);
		void reorderStations();
		bool run(std::ostream& os);
		void display(std::ostream& os) const;
	};
}
#endif // !SDDS_LINEMANAGER_H
