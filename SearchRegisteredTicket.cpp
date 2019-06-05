// Class: SearchRegisterTicket
// Description: 등록한 티켓을 검색하기 위한 control class이다.
// Author: 김상엽
// Created: 2019/05/31
// Mail: natsuko0012@gmail.com

// Revisions:
// 		1.	When & Who: 2019/05/31 by 김상엽
// 				What: create file
//
// 		2.	When & Who: 2019/05/31 by 김상엽
// 				What: complete basic logic
//
// 		3.	When & Who: 2019/06/01 by 김상엽
// 				What: add Korean comment

#include "SearchRegisteredTicket.h"
#include "UserCollection.h"

// Function: SearchRegisteredTicket::SearchRegisteredTicket()
// Description: SearchRegisterTicket 클래스의 생성자이다.
// Author: 김상엽
// Created: 2019/05/31
// Parameters:
// Return Value: SearchRegisterTicket 클래스의 인스턴스

// Revisions:
// 		1.	When & Who: 2019/05/31 by 김상엽
// 				What: create function

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

// Function: void SearchRegisteredTicket::search(const Info & info)
// Description: 등록된 티켓을 조회하여 출력하는 함수이다.
// Author: 김상엽
// Created: 2019/05/31
// Parameters: const Info & info(검색할 티켓에 대한 정보)
// Return Value:

// Revisions:
// 		1.	When & Who: 2019/05/31 by 김상엽
// 				What: create function
// 		2.	When & Who: 2019/05/31 by 김상엽
// 				What: modify print format
// 		3.	When & Who: 2019/05/31 by 김상엽
// 				What: complete function

void SearchRegisteredTicket::search(const Info & info)
{
	std::cout << "3.2. 등록티켓 조회 " << std::endl;
	//판매자 탐색
	auto user = UserCollection::get()[info];
	Seller* seller = std::get<Seller*>(user);

	// 판매중인 티켓 및 판매 완료된 티켓 추출
	std::vector<Ticket*> ticketList = seller->getTickets();


	//시간순 추출
	sort(ticketList.begin(), ticketList.end(), [](Ticket* lhs, Ticket* rhs) { return lhs->getTime() < rhs->getTime(); });


	//출력
	auto& soldTickets = seller->getSoldTickets();
	for (Ticket* t : ticketList) {
		if (t->isUnderAuction())
			std::cout << "> " << t->getPrice() << " " << t << " " << t->isLTA() << " "
			<< (bool)std::count(soldTickets.begin(), soldTickets.end(), t) << std::endl;
		else
			std::cout << "> " << t << " " << t->isLTA() << " "
			<< (bool)std::count(soldTickets.begin(), soldTickets.end(), t) << std::endl;
	}

}

// Function: SearchRegisteredTicket::~SearchRegisteredTicket()
// Description: SearchRegisterTicket 클래스의 소멸자이다.
// Author: 김상엽
// Created: 2019/05/31
// Parameters:
// Return Value:

// Revisions:
// 		1.	When & Who: 2019/05/31 by 김상엽
// 				What: create function

SearchRegisteredTicket::~SearchRegisteredTicket()
{
}
