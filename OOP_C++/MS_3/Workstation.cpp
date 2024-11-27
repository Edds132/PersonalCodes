/* Full Name : Edwards Josue Ortega Gonzalez
Student ID# : 118705227
Email : eortega-gonzalez@myseneca.ca
Date: 2023 - 12 - 02
Section : NFF */

#include "Workstation.h"
#include "Utilities.h"

namespace sdds
{
	std::deque<CustomerOrder> g_pending;
	std::deque<CustomerOrder> g_completed;
	std::deque<CustomerOrder> g_incomplete;

	void Workstation::fill(std::ostream& os)
	{
		if (!m_orders.empty())
		{
			m_orders.front().fillItem(*this, os);
		}
	}
	bool Workstation::attemptToMoveOrder()
	{
		bool move_result = false;

		if (!m_orders.empty()) 
		{
			if (m_orders.front().isItemFilled(getItemName()) || this->getQuantity() == 0)
			{
				if (m_pNextStation) 
				{
					*m_pNextStation += std::move(m_orders.front());
				}
				else if (!m_orders.front().isOrderFilled())
				{	
					g_incomplete.push_back(std::move(m_orders.front()));
				}
				else
				{
					g_completed.push_back(std::move(m_orders.front()));
				}
				move_result = true;
				m_orders.pop_front();
			}
		}

		return move_result;


	}
	void Workstation::setNextStation(Workstation* station)
	{
		m_pNextStation = station;
	}
	Workstation* Workstation::getNextStation() const
	{
		return m_pNextStation;
	}
	void Workstation::display(std::ostream& os) const
	{
		if (m_pNextStation)
		{
			os << getItemName() << " --> " << m_pNextStation->getItemName() << std::endl;
		}
		else
		{
			os << getItemName() << " --> " << "End of Line" << std::endl;
		}
	}
	Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
	{
		m_orders.push_back(std::move(newOrder));
		return *this;
	}
}