// Class: RegisterTicketManager
// Description: 티켓 등록을 위한 control class이다.
// Authror: 유새람
#include "RegisterTicketManager.h"
#include "UserCollection.h"



RegisterTicketManager::RegisterTicketManager()
{
}


RegisterTicketManager* RegisterTicketManager::var = nullptr;
void RegisterTicketManager::deleteHistory()
{
	std::vector<Seller>& sellers = UserCollection::get().getSellers();
	for (Seller& seller : sellers) {
		// 판매가 완료된 1년이 지난 티켓 삭제
		auto& soldTickets = seller.getSoldTickets();
		auto it = std::remove_if(soldTickets.begin(), soldTickets.end(), [](std::shared_ptr<Ticket>& i) {return i->getHistoryTimer().isExpired(); });
		soldTickets.erase(it, soldTickets.end());	

		// 판매중인 1년이 지난 티켓 삭제
		auto& registeredTickets = seller.getRegisteredTickets();
		it = std::remove_if(registeredTickets.begin(), registeredTickets.end(), [](std::shared_ptr<Ticket>& i) {return i->getHistoryTimer().isExpired(); });
		registeredTickets.erase(it, registeredTickets.end());

	}
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
	seller->getRegisteredTickets().push_back(ticket);
}

RegisterTicketManager::~RegisterTicketManager()
{
}
