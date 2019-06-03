// Class: Buyer
// Descripton: 구매자 객체를 표현하는 클래스이다. 
// Author: 유새람
#include "Buyer.h"


const Info & Buyer::getInfo() const
{
	return this->info;
}

std::vector<std::shared_ptr<Ticket>>& Buyer::getTickets()
{
	return tickets;
}


bool Buyer::empty() const
{
	return tickets.empty();
}

bool Buyer::operator==(const Info& i) const
{
	return this->info == i;
}

Buyer::Buyer(const Info & info) : info(info)
{
}

Buyer::~Buyer()
{
}
