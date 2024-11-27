/* Full Name : Edwards Josue Ortega Gonzalez
Student ID# : 118705227
Email : eortega-gonzalez@myseneca.ca
Date: 2023 - 11 - 09
Section : NFF */

#include "Utilities.h"

namespace sdds
{
	char Utilities::m_delimiter = ' ';
	void Utilities::setFieldWidth(size_t newWidth)
	{
		m_widthField = newWidth;
	}

	size_t Utilities::getFieldWidth() const
	{
		return m_widthField;
	}

	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		std::string out = "";
		size_t f_pos = next_pos;
		next_pos = str.find(m_delimiter, f_pos);

		if (next_pos == std::string::npos)
		{
			out = str.substr(f_pos);
			if (out.length() > m_widthField)
			{
				m_widthField = out.length();
			}
			more = false;
		}
		else if (f_pos == next_pos)
		{
			more = false;
			throw "ERROR: No token. \n";
		}
	
		else
		{
			out = str.substr(f_pos, next_pos - f_pos);
			if (out.length() > m_widthField)
			{
				m_widthField = out.length();
			}
			more = true;
		}
		next_pos++;
		// Remove leading/trailing spaces
		out.erase(0, out.find_first_not_of(" \t\n\r\f\v"));
		out.erase(out.find_last_not_of(" \t\n\r\f\v") + 1);
		return out;
	}

	void Utilities::setDelimiter(char newDelimiter)
	{
		m_delimiter = newDelimiter;
	}

	char Utilities::getDelimiter()
	{
		return m_delimiter;
	}
}