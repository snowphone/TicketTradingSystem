#include "SearchRegisteredTicket.h"
#include "UserCollection.h"



SearchRegisteredTicket::SearchRegisteredTicket()
{
}


SearchRegisteredTicket* SearchRegisteredTicket::var = nullptr;
SearchRegisteredTicket & SearchRegisteredTicket::get()
{
	if (!var)
		var = new SearchRegisteredTicket();
	return *var;
}

void SearchRegisteredTicket::search(const Info & info)
{
	auto user = UserCollection::get().at(info);
	std::cout << "3.2. 등록티켓 조회 " << std::endl
		<< "> ";
	std::get<Seller*>(user)->printTickets();
}

SearchRegisteredTicket::~SearchRegisteredTicket()
{
}
