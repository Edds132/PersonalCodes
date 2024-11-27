/* Full Name : Edwards Josue Ortega Gonzalez
Student ID# : 118705227
Email : eortega-gonzalez@myseneca.ca
Date: 2023 - 11 - 09
Section : NFF */
#include "Station.h"
#include "Utilities.h"


namespace sdds
{
	size_t Station::m_widthField = 0u;
	size_t Station::id_generator = 0u;

	Station::Station(const std::string& line) : 
		m_id{}, m_name{}, m_description{}, m_serial{}, m_current_items{}
	{
		Utilities utilObj;
		m_id = (int)(++Station::id_generator);
		bool more = true;
		size_t pos = 0u;

		m_name = utilObj.extractToken(line, pos, more);
		m_serial = std::stoi(utilObj.extractToken(line, pos, more));
		m_current_items = std::stoi(utilObj.extractToken(line, pos, more));
		Station::m_widthField = std::max(utilObj.getFieldWidth(), Station::m_widthField);
		m_description = utilObj.extractToken(line, pos, more);
	}
	const std::string& Station::getItemName() const
	{
		return m_name;
	}
	size_t Station::getNextSerialNumber()
	{
		m_serial++;
		return m_serial - 1;
	}
	size_t Station::getQuantity() const
	{
		return m_current_items;
	}
	void Station::updateQuantity()
	{
		if (m_current_items > 0)
		{
			m_current_items = m_current_items - 1;
		}

	}
	void Station::display(std::ostream& os, bool full) const
	{
		os  << std::right << std::setw(3) << std::setfill('0') << m_id << " | ";
		os << std::left << std::setw(Station::m_widthField) << std::setfill(' ') << m_name;
		os << "| " << std::right << std::setw(6) << std::setfill('0') << m_serial << " | ";

		if (full) {
			os << std::right << std::setw(4) << std::setfill(' ') << m_current_items << " | ";
			os << m_description << std::endl;
		}
		else
			os << std::endl;
	}
}