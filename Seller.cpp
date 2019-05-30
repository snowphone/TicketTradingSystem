#include "Seller.h"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>




void Seller::printTickets() const
{
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
