#include "Seller.h"
#include <vector>



const Info & Seller::getInfo() const
{
	return this->info;
}

bool Seller::empty() const
{
	return tickets.empty();
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