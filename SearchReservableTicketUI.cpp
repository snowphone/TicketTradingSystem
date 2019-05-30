#include "SearchReservableTicketUI.h"
#include "SearchReservableTicketManager.h"



SearchReservableTicketUI::SearchReservableTicketUI()
{
}


SearchReservableTicketUI* SearchReservableTicketUI::var = nullptr;
SearchReservableTicketUI & SearchReservableTicketUI::get()
{
	if (!var)
		var = new SearchReservableTicketUI();
	return *var;
}

void SearchReservableTicketUI::search(std::string home)
{
	SearchReservableTicketManager::get().show(home);
}

SearchReservableTicketUI::~SearchReservableTicketUI()
{
}

