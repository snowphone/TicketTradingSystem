// Class: SearchRegisteredTicketUI
// Description: 등록된 티켓 조회를 위한 boundary class이다.
// Author: 김상엽
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

void SearchRegisteredTicketUI::search(const Info& info)
{

	SearchRegisteredTicket::get().search(info);
}

SearchRegisteredTicketUI::~SearchRegisteredTicketUI()
{
}
