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
	//티켓 생성
	std::shared_ptr<Ticket> ticket = std::make_shared<Ticket>(price, time, home, away, position, useLTA);

	std::cout << "3.1. 판매티켓 등록" << std::endl
		<< "> " << ticket->getPrice() << " " << ticket << " " << ticket->isLTA() << std::endl;

	//판매자 찾기
	auto user = UserCollection::get()[*currentUser];
	Seller* seller = std::get<Seller*>(user);

	//판매자 객체가 티켓을 소유
	seller->getRegisteredTickets().push_back(std::move(ticket));
}

RegisterTicketManager::~RegisterTicketManager()
{
}
