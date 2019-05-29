#include <algorithm>
#include "UserCollection.h"



UserCollection::UserCollection()
{
}

UserCollection* UserCollection::var = nullptr;

UserCollection & UserCollection::get()
{
	if (!var)
		var = new UserCollection();
	return *var;
}

void UserCollection::insert(const Seller & seller)
{
	sellers.push_back(seller);
}

void UserCollection::insert(const Buyer & buyer)
{
	buyers.push_back(buyer);
}



size_t UserCollection::size() const
{
	return sellers.size() + buyers.size();
}

UserCollection::~UserCollection()
{
}
