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
	TicketCollection tickets = UserCollection::get().getReservableTickets(home);
	for (auto& ticket : tickets) {
		//TODO
		std::cout << ticket << std::endl;
	}
}

SearchReservableTicketManager::~SearchReservableTicketManager()
{
}
