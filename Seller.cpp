//Class: Seller
//Description: 판매자 정보를 표현하는 클래스이다.
//Author: 김상엽

// Revisions:
// 		1.	When & Who: 2019/06/03 by 김상엽
// 				What: create file
//
// 		2.	When & Who: 2019/06/03 by 김상엽
// 				What: add some include
//
// 		3.	When & Who: 2019/06/03 by 김상엽
// 				What: remove redundant include
//
// 		4.	When & Who: 2019/06/03 by 김상엽
// 				What: add debugging code
//
// 		5.	When & Who: 2019/06/03 by 김상엽
// 				What: complete Seller.cpp

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
