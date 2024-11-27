/* Full Name : Edwards Josue Ortega Gonzalez
Student ID# : 118705227
Email : eortega-gonzalez@myseneca.ca
Date: 2023 - 11 - 16
Section : NFF */
#include "CustomerOrder.h"
#include "Utilities.h"

namespace sdds
{
	size_t CustomerOrder::m_widthField = 0u;

	/*CustomerOrder::CustomerOrder() :
		m_name{ "" }, m_product{ "" }, m_cntItem{ 0 }, m_lstItem(nullptr) {}*/

	CustomerOrder::CustomerOrder(const std::string& src)
	{
		Utilities util;
		bool more = true;
		size_t pos = 0u;

		m_name = util.extractToken(src, pos, more);
		m_product = util.extractToken(src, pos, more);
		m_cntItem = std::count(src.begin(), src.end(), util.getDelimiter()) - 1;

		if (m_cntItem)
		{
			m_lstItem = new Item * [m_cntItem];
		}
		for (size_t i = 0; i < m_cntItem && more; ++i)
		{
			m_lstItem[i] = new Item(util.extractToken(src, pos, more));
		}
		
		if (m_widthField < util.getFieldWidth())
		{
			m_widthField = util.getFieldWidth();
		}
	}

	CustomerOrder::CustomerOrder(const CustomerOrder& src)
	{
		throw false;
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept
	{
		*this = std::move(src);
	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept 
	{
		if (this != &src) 
		{
			if (m_lstItem)
			{
				for (auto i = 0u; i < m_cntItem; ++i)
				{
					delete m_lstItem[i];
				}
				delete[] m_lstItem;
			}
			m_name = src.m_name;
			m_product = src.m_product;
			m_cntItem = src.m_cntItem;
			m_lstItem = src.m_lstItem;

			src.m_name = "";
			src.m_product = "";
			src.m_cntItem = 0u;
			src.m_lstItem = nullptr;
		}
		return *this;
	}

	CustomerOrder::~CustomerOrder()
	{
		if (m_lstItem) 
		{
			for (size_t i = 0; i < m_cntItem; ++i) 
			{
				delete m_lstItem[i];
			}
			delete[] m_lstItem;
			m_lstItem = nullptr;
		}
	}

	bool CustomerOrder::isOrderFilled() const
	{
		for (size_t i = 0; i < m_cntItem; ++i) 
		{
			if (!m_lstItem[i]->m_isFilled) 
			{
				return false;
			}
		}
		return true;
	}

	bool CustomerOrder::isItemFilled(const std::string& itemName) const
	{
		for (size_t i = 0; i < m_cntItem; ++i)
		{
			if (m_lstItem[i]->m_itemName == itemName && !m_lstItem[i]->m_isFilled)
			{
				return false; 
			}
		}
		return true;
	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os)
	{
		for (size_t i = 0; i < m_cntItem; ++i) {
			if (m_lstItem[i]->m_itemName == station.getItemName() && !m_lstItem[i]->m_isFilled)
			{
				if (station.getQuantity() > 0 ) 
				{
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					m_lstItem[i]->m_isFilled = true;
					station.updateQuantity();
					os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
					return;
				}
				else
				{
					os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
				}
				//os << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
			}
		}
	}

	void CustomerOrder::display(std::ostream& os) const
	{
		os << m_name << " - " << m_product << std::endl;

		for (size_t i = 0u; i < m_cntItem; ++i) 
		{
			os << "[";
			os << std::right << std::setw(6) << std::setfill('0') << m_lstItem[i]->m_serialNumber;
			os<< "] ";
			os << std::left << std::setw(m_widthField - 2) << std::setfill(' ') << m_lstItem[i]->m_itemName;
			os << " - ";
			os << (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED") << std::endl;
		}
	}

}