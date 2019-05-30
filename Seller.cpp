#include "Seller.h"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>




void Seller::printTickets() const
{
	std::vector<Ticket*> ticketList;
	for (auto it = registeredTickets.begin(); it != registeredTickets.end(); ++it)
		ticketList.push_back(it->get());
	for (auto it = soldTickets.begin(); it != soldTickets.end(); ++it)
		ticketList.push_back(it->get());

	sort(ticketList.begin(), ticketList.end(), [](Ticket* lhs, Ticket* rhs) { return lhs->getTime() < rhs->getTime(); });


	for (Ticket* t : ticketList) {
		std::cout << t << " " << t->isLTA() << " " 
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

std::vector<std::shared_ptr<Ticket>> & Seller::getRegisteredTickets() 
{
	return registeredTickets;
}

std::vector<std::shared_ptr<Ticket>> & Seller::getSoldTickets()
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
