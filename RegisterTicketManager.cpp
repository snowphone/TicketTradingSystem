#include "RegisterTicketManager.h"
#include "UserCollection.h"



RegisterTicketManager::RegisterTicketManager()
{
}


RegisterTicketManager* RegisterTicketManager::var = nullptr;
void RegisterTicketManager::deleteHistory()
{
}
RegisterTicketManager & RegisterTicketManager::get()
{
	if (!var)
		var = new RegisterTicketManager();
	return *var;
}

void RegisterTicketManager::addNewTicket(const Info * currentUser, int price, std::string time, std::string home, std::string away, std::string position, bool useLTA)
{
	Ticket ticket(price, time, home, away, position, useLTA);
	auto user = UserCollection::get().at(*currentUser);
	if (useLTA) {
	}
	std::get<Seller*>(user)->getRegisteredTickets().push_back(ticket);
	std::cout << "3.1. 판매티켓 등록" << std::endl
		<< "> " << ticket << " " << ticket.isLTA() << std::endl;
}

RegisterTicketManager::~RegisterTicketManager()
{
}
