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
