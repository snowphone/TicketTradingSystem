//Class: Seller
//Description: 판매자 정보를 표현하는 클래스이다.
//Author: 김상엽
#include "Seller.h"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>





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

std::vector<Ticket*> Seller::getTickets()
{	
	std::vector<Ticket*> ticketList;

	auto& registeredTickets = getRegisteredTickets();
	for (auto it = registeredTickets.begin(); it != registeredTickets.end(); ++it)
		ticketList.push_back(it->get());

	auto& soldTickets = getSoldTickets();
	for (auto it = soldTickets.begin(); it != soldTickets.end(); ++it)
		ticketList.push_back(it->get());

	return ticketList;
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
