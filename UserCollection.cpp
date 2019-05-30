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

TicketCollection UserCollection::getReservableTickets(const std::string & home)
{
	TicketCollection tmp;
	for (Seller& seller : sellers) {
		std::copy(seller.getRegisteredTickets().begin(), seller.getRegisteredTickets().end(), std::back_inserter(tmp));
	}
	sort(tmp.begin(), tmp.end(), [](Ticket& lhs, Ticket& rhs) { return lhs.getTime() < rhs.getTime(); });
	return tmp;
}

const Info * UserCollection::find(std::string id, std::string pw)
{
	auto buyerIter = std::find_if(buyers.begin(), buyers.end(), [&id, &pw](const Buyer& i) { return i.getInfo().checkID(id, pw); });
	if (buyerIter != buyers.end())
		return &buyerIter->getInfo();

	auto sellerIter = std::find_if(sellers.begin(), sellers.end(), [&id, &pw](const Seller& i) { return i.getInfo().checkID(id, pw); });
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
