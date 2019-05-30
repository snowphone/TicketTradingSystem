#include "SearchRegisteredTicket.h"
#include "UserCollection.h"



SearchRegisteredTicket::SearchRegisteredTicket()
{
}


SearchRegisteredTicket* SearchRegisteredTicket::var = nullptr;
SearchRegisteredTicket & SearchRegisteredTicket::get()
{
	if (!var)
		var = new SearchRegisteredTicket();
	return *var;
}

void SearchRegisteredTicket::search(const Info & info)
{
	auto user = UserCollection::get()[info];
	std::cout << "3.2. 등록티켓 조회 " << std::endl;
	Seller* seller = std::get<Seller*>(user);

	std::vector<Ticket*> ticketList;
	auto& registeredTickets = seller->getRegisteredTickets();
	auto& soldTickets = seller->getSoldTickets();
	for (auto it = registeredTickets.begin(); it != registeredTickets.end(); ++it)
		ticketList.push_back(it->get());
	for (auto it = soldTickets.begin(); it != soldTickets.end(); ++it)
		ticketList.push_back(it->get());

	sort(ticketList.begin(), ticketList.end(), [](Ticket* lhs, Ticket* rhs) { return lhs->getTime() < rhs->getTime(); });


	for (Ticket* t : ticketList) {
		if (t->isUnderAuction())
			std::cout << "> " << t->getPrice() << " " << t << " " << t->isLTA() << " "
			<< (bool)std::count(soldTickets.begin(), soldTickets.end(), t) << std::endl;
		else
			std::cout << "> " << t << " " << t->isLTA() << " "
			<< (bool)std::count(soldTickets.begin(), soldTickets.end(), t) << std::endl;
	}

}

SearchRegisteredTicket::~SearchRegisteredTicket()
{
}
