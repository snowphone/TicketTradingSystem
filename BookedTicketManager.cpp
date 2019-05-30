#include "BookedTicketManager.h"
#include "UserCollection.h"




BookedTicketManager::BookedTicketManager()
{
}


BookedTicketManager* BookedTicketManager::var = nullptr;
BookedTicketManager & BookedTicketManager::get()
{
	if (!var)
		var = new BookedTicketManager();
	return *var;
}

void BookedTicketManager::print(const Info & buyerInfo)
{
	std::cout << "4.5. 예약 정보 조회" << std::endl;
	auto user = UserCollection::get()[buyerInfo];
	Buyer* buyer = std::get<Buyer*>(user);
	for (std::shared_ptr<Ticket>& ticket : buyer->getTickets()) {
		if(ticket->isUnderAuction())
			std::cout << "> " << ticket->getPrice() << " " << *ticket << std::endl;
		else
			std::cout << "> "  << *ticket << std::endl;
	}
}

BookedTicketManager::~BookedTicketManager()
{
}
