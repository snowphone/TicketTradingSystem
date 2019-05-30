#include "SearchReservableTicketUI.h"
#include "SearchReservableTicketManager.h"



SearchReservableTicketUI::SearchReservableTicketUI()
{
}


SearchReservableTicketUI* SearchReservableTicketUI::var = nullptr;
SearchReservableTicketUI& SearchReservableTicketUI::get()
{
	if (!var)
		var = new SearchReservableTicketUI();
	return *var;
}

void SearchReservableTicketUI::search(std::string home)
{
	SearchReservableTicketManager::get().show(home);
}

void SearchReservableTicketUI::reserve(const Info& buyerInfo, std::string time, std::string away, std::string position)
{
	SearchReservableTicketManager::get().reserve(buyerInfo, time, away, position);
}

SearchReservableTicketUI::~SearchReservableTicketUI()
{
}

