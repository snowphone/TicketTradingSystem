#include <algorithm>
#include "UserCollection.h"


UserCollection::UserCollection()
{
}

UserCollection* UserCollection::var = nullptr;

UserCollection& UserCollection::get()
{
	if (!var)
		var = new UserCollection();
	return *var;
}

#if 0
void UserCollection::insert(const Seller & seller)
{
	sellers.push_back(seller);
}

void UserCollection::insert(const Buyer & buyer)
{
	buyers.push_back(buyer);
}
#endif
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

std::vector<Ticket*> UserCollection::getReservableTickets(const std::string& home)
{
	std::vector<Ticket*> reservableTickets;
	//모든 판매자로부터
	for (Seller& seller : sellers) {
		//판매중인 티켓 선택
		std::vector<std::shared_ptr<Ticket>>& tickets = seller.getRegisteredTickets();
#if 0
		std::for_each(tickets.begin(), tickets.end(), 
			[&](const std::shared_ptr<Ticket>& i) { reservableTickets.push_back(i.get()); });
#else
		for (auto it = tickets.begin(); it != tickets.end(); ++it)
		{
			reservableTickets.push_back(it->get());
		}
#endif
	}
	//시간순 정렬
	sort(reservableTickets.begin(), reservableTickets.end(), [](Ticket* lhs, Ticket* rhs) { return lhs->getTime() < rhs->getTime(); });

	return reservableTickets;
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

const Info * UserCollection::find(std::string id)
{
	/* Requirements에는 없지만, 6.1. session변경을 위하여 추가로 구현하였다. */
	auto buyerIter = std::find_if(buyers.begin(), buyers.end(), 
		[&id](const Buyer& i) { return i.getInfo().getID() == id; });
	if (buyerIter != buyers.end())
		return &buyerIter->getInfo();

	auto sellerIter = std::find_if(sellers.begin(), sellers.end(), 
		[&id](const Seller& i) { return i.getInfo().getID() == id; });
	if (sellerIter != sellers.end())
		return &sellerIter->getInfo();

	return nullptr;
}


std::variant<Seller*, Buyer*> UserCollection::operator[](const Info & info)
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
