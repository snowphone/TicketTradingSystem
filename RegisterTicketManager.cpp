// Class: RegisterTicketManager
// Description: 티켓 등록을 위한 control class이다.
// Authror: 유새람
#include "Timer.h"
#include "RegisterTicketManager.h"
#include "UserCollection.h"



RegisterTicketManager::RegisterTicketManager()
{
}


RegisterTicketManager* RegisterTicketManager::var = nullptr;

// Function: deleteHistory()
// Parameters: void
// Return value: void
//
// Created: 2019/05/30/17:27 by 문준오
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
	const time_t day = 86400;
	//티켓 등록은 경기 시작 이틀 전에 이루어져야한다
	time_t deadline = Timer::parseTime(time),
		current = Timer::parseTime(Timer::getCurrentTime());
	if (current + 2 * day >= deadline)
	{
		return;
	}
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

// Function: switchToLTA()
// Parameters: void
// Return value: void
//
// Created: 2019/05/30/18:27 by 문준오
void RegisterTicketManager::switchToLTA()
{
	// 아무것도 하지 않는다. 
	// LTA 티켓 여부는 Ticket.isUnderAuction() 함수가 현 시각에 맞추어 반환하기 때문이다.
}
