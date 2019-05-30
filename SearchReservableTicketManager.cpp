#include "SearchReservableTicketManager.h"
#include "UserCollection.h"



SearchReservableTicketManager::SearchReservableTicketManager()
{
}


SearchReservableTicketManager* SearchReservableTicketManager::var = nullptr;
SearchReservableTicketManager & SearchReservableTicketManager::get()
{
	if (!var)
		var = new SearchReservableTicketManager();
	return *var;
}

void SearchReservableTicketManager::show(std::string home)
{
	std::cout << "4.1. 티켓 검색" << std::endl
		<< "> ";
	this->watchingTickets = UserCollection::get().getReservableTickets(home);
	for (auto& ticketPtr : watchingTickets) {
		std::cout << *ticketPtr << std::endl;
	}
}

void SearchReservableTicketManager::reserve(const Info & buyerInfo, std::string time, std::string away, std::string position)
{
	//원하는 티켓 검색
	const Ticket& ticket = **find_if(watchingTickets.begin(), watchingTickets.end(), [&](Ticket* t) {
		return t->getTime() == time && t->getAway() == away && t->getPosition() == position;
	});
	//구매자 검색
	auto user = UserCollection::get().at(buyerInfo);
	std::get<Buyer*>(user)->getTickets().push_back(ticket);
	std::vector<Seller>& sellers = UserCollection::get().getSellers();

	//판매자 검색
	Seller& seller = *find_if(sellers.begin(), sellers.end(), [&](Seller& sel) {
		return std::count_if(sel.getRegisteredTickets().begin(), sel.getRegisteredTickets().end(),
			[&](const Ticket& tic) {
			return tic.getTime() == time && tic.getAway() == away && tic.getPosition() == position;
		});
	});
	auto it = find(seller.getRegisteredTickets().begin(), seller.getRegisteredTickets().end(), ticket);
	seller.getRegisteredTickets().erase(it);
	seller.getSoldTickets().push_back(ticket);
	std::cout << "4.2. 티켓 예약" << std::endl
		<< "> " << ticket << std::endl;
}

SearchReservableTicketManager::~SearchReservableTicketManager()
{
}
