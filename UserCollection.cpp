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

void UserCollection::erase(const Info & info)
{
	if (info.getUserType() == "seller") {
		auto it = std::find_if(sellers.begin(), sellers.end(), [&info](const Seller& i) { return i == info; });
		sellers.erase(it);
	}
	else {
		auto it = std::find_if(buyers.begin(), buyers.end(), [&info](const Buyer& i) { return i == info; });
		buyers.erase(it);
	}
}

std::vector<Seller>& UserCollection::getSellers()
{
	return sellers;
}

std::vector<Buyer>& UserCollection::getBuyers()
{
	return buyers;
}

std::vector<Ticket*> UserCollection::getReservableTickets(const std::string & home)
{
	std::vector<Ticket*> tmp;
	for (Seller& seller : sellers) {
		std::for_each(seller.getRegisteredTickets().begin(), seller.getRegisteredTickets().end(), 
			[&](auto& i) { tmp.push_back(&i); });
	}
	sort(tmp.begin(), tmp.end(), [](Ticket* lhs, Ticket* rhs) { return lhs->getTime() < rhs->getTime(); });
	return tmp;
}

const Info * UserCollection::find(std::string id, std::string pw)
{
	auto buyerIter = std::find_if(buyers.begin(), buyers.end(), 
		[&id, &pw](const Buyer& i) { return i.getInfo().checkID(id, pw); });
	if (buyerIter != buyers.end())
		return &buyerIter->getInfo();

	auto sellerIter = std::find_if(sellers.begin(), sellers.end(), 
		[&id, &pw](const Seller& i) { return i.getInfo().checkID(id, pw); });
	if (sellerIter != sellers.end())
		return &sellerIter->getInfo();

	return nullptr;

}



std::variant<Seller*, Buyer*> UserCollection::at(const Info & info)
{
	if (info.getUserType() == "seller") {
		return &*find_if(sellers.begin(), sellers.end(), [&info](const Seller& i) {return i == info; });
	}
	else {
		return &*find_if(buyers.begin(), buyers.end(), [&info](const Buyer& i) {return i == info; });
	}
}

size_t UserCollection::size() const
{
	return sellers.size() + buyers.size();
}

UserCollection::~UserCollection()
{
}
