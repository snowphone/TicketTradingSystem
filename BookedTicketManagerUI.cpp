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
