#include "SearchRegisteredTicketUI.h"
#include "SearchRegisteredTicket.h"



SearchRegisteredTicketUI::SearchRegisteredTicketUI()
{
}


SearchRegisteredTicketUI* SearchRegisteredTicketUI::var = nullptr;
SearchRegisteredTicketUI & SearchRegisteredTicketUI::get()
{
	if (!var)
		var = new SearchRegisteredTicketUI();
	return *var;
}

void SearchRegisteredTicketUI::search(const Info & info)
{

	SearchRegisteredTicket::get().search(info);
}

SearchRegisteredTicketUI::~SearchRegisteredTicketUI()
{
}
