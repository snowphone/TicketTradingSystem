// Class: BookedTicketManagerUI
// Description: 예약된 티켓 조회를 위한 Boundary class이다.
// Author: 김소연
#include "BookedTicketManagerUI.h"
#include "BookedTicketManager.h"



BookedTicketManagerUI::BookedTicketManagerUI()
{
}


BookedTicketManagerUI* BookedTicketManagerUI::var = nullptr;
BookedTicketManagerUI & BookedTicketManagerUI::get()
{
	if (!var)
		var = new BookedTicketManagerUI();
	return *var;
}

void BookedTicketManagerUI::search(const Info & buyerInfo)
{
	BookedTicketManager::get().print(buyerInfo);
}

BookedTicketManagerUI::~BookedTicketManagerUI()
{
}
