#include "RegisterTicketManager.h"
#include "UserCollection.h"



RegisterTicketManager::RegisterTicketManager()
{
}


RegisterTicketManager* RegisterTicketManager::var = nullptr;
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
	std::get<Seller*>(user)->addTicket(ticket);
	std::cout << ticket << std::endl;
}

RegisterTicketManager::~RegisterTicketManager()
{
}
