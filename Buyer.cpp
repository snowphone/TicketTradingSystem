#include "Buyer.h"


const Info & Buyer::getInfo() const
{
	return this->info;
}

bool Buyer::empty() const
{
	return tickets.empty();
}

bool Buyer::operator==(const Info & i) const
{
	return this->info == i;
}

Buyer::Buyer(const Info & info) : info(info)
{
}

Buyer::~Buyer()
{
}
