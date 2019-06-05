// Class: RegisterTicketManager
// Description: 티켓 등록을 위한 control class이다.
// Authror: 유새람
#include "RegisterTicketManager.h"
#include "UserCollection.h"


// Function: RegisterTicketManager()
// Description: private 생성자(singleton)
// Author: 유새람
// Revisions:
//		1. When & Who: 2019/06/02 by 유새람
//				What: singleton패턴을 위한 private 생성자
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

// Function: static RegisterTicketManager& get();
// Description: singleton패턴에서 instance를 불러오는 메소드
// Return Value: RegisterTicketManager
// Author: 유새람
// Revisions:
//		1. When & Who: 2019/06/02 by 유새람
//				What: 한번만 constructor 호출하도록 함
RegisterTicketManager & RegisterTicketManager::get()
{
	if (!var)
		var = new RegisterTicketManager();
	return *var;
}

// Function: void addNewTicket(const Info * currentUser, int price, std::string time, std::string home, std::string away, std::string position, bool useLTA);
// Description: 판매자가 등록한 티켓을 새로 추가하는 메소드
// Parameters:	const Info * currentUser- 등록하려는 Seller
//				int price- 희망 판매가격
//				string time, home, away, position- 경기정보(경기 날짜, 홈팀, 어웨이팀, 좌석 위치)
//				bool useLTA- limited-time auction 사용 여부
// Author: 유새람
// Revisions:
//		1. When & Who: 2019/06/02 by 유새람
//				What: Ticket을 생성한 후 Seller가 ticket을 소유하게 함
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

// Function: ~RegisterTicketManager()
// Description: 소멸자
// Author: 유새람
// Revisions:
//		1. When & Who: 2019/06/02 by 유새람
RegisterTicketManager::~RegisterTicketManager()
{
}
