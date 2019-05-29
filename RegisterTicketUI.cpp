#include "RegisterTicketUI.h"
#include "RegisterTicketManager.h"



RegisterTicketUI::RegisterTicketUI()
{
}


RegisterTicketUI* RegisterTicketUI::var = nullptr;
RegisterTicketUI & RegisterTicketUI::get()
{
	if (!var)
		var = new RegisterTicketUI();
	return *var;
}

void RegisterTicketUI::createNewTicket(const Info * user, int price, std::string time, 
	std::string home, std::string away, std::string position, bool useLTA)
{
	RegisterTicketManager::get().addNewTicket(user, price, time, home, away, position, useLTA);
}

RegisterTicketUI::~RegisterTicketUI()
{
}