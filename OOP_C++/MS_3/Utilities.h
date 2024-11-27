/* Full Name : Edwards Josue Ortega Gonzalez
Student ID# : 118705227
Email : eortega-gonzalez@myseneca.ca
Date: 2023 - 11 - 09
Section : NFF */


#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <iostream>
#include <string>

namespace sdds
{
	class Utilities
	{
		size_t m_widthField{ 1u };
		static char m_delimiter;
	public:
		void setFieldWidth(size_t newWidth);
		size_t getFieldWidth() const;
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);

		static void setDelimiter(char newDelimiter);
		static char getDelimiter();
	};
}
#endif // !SDDS_UTILITIES_H
