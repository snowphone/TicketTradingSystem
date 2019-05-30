#include "Seller.h"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>



void Seller::printTickets() const
{
	TicketCollection tmp;
	copy(registeredTickets.begin(), registeredTickets.end(), std::back_inserter(tmp));
	copy(soldTickets.begin(), soldTickets.end(), std::back_inserter(tmp));
	sort(tmp.begin(), tmp.end(), [](Ticket& lhs, Ticket& rhs) { return lhs.getTime() < rhs.getTime(); });


	for (Ticket& t : tmp) {
		std::cout << t << " " << t.isLTA() << " " 
			<< (bool)std::count(soldTickets.begin(), soldTickets.end(), t) << std::endl;
	}
}

const Info & Seller::getInfo() const
{
	return this->info;
}

bool Seller::empty() const
{
	return registeredTickets.empty();
}

TicketCollection & Seller::getRegisteredTickets() 
{
	return registeredTickets;
}

TicketCollection & Seller::getSoldTickets()
{
	return soldTickets;
}

bool Seller::operator==(const Info & info) const
{
	return this->info == info;
}

Seller::Seller(const Info & info) :info(info)
{

}


Seller::~Seller()
{
}
