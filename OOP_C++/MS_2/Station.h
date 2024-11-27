/* Full Name : Edwards Josue Ortega Gonzalez
Student ID# : 118705227
Email : eortega-gonzalez@myseneca.ca
Date: 2023 - 11 - 09
Section : NFF */

#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include <iostream>
#include <iomanip>
namespace sdds
{
	class Station {
		int m_id;
		std::string m_name;
		std::string m_description;
		size_t m_serial;
		size_t m_current_items;

		static size_t m_widthField;
		static size_t id_generator;
	public:
		Station(const std::string& line);

		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};
}
#endif // !SDDS_STATION_H
