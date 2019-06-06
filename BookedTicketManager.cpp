// Class: BookedTicketManager
// Description: 예약된 티켓 정보 출력을 위한 control 클래스이다.
// Author: 김소연
// Created: 2019/06/01
// Mail: 96syk@naver.com

// Revisions:
// 		1.	When & Who: 2019/06/01 by 김소연
// 				What: create file


#include "BookedTicketManager.h"
#include "UserCollection.h"

// Function: BookedTicketManager()
// Description: private 생성자(singleton)
// Author: 김소연
// Revisions:
//		1. When & Who: 2019/06/01 by 김소연
//				What: Singletone 패턴을 적용한 private 생성자
BookedTicketManager::BookedTicketManager()
{
}


// Function: static BookedTicketManager* var;
// Description: private instance 변수 (singleton)
// Author: 김소연
// Revisions:
//		1. When & Who: 2019/06/01 by 김소연
//				What: Singleton 패턴을 적용한 private instance 변수
BookedTicketManager* BookedTicketManager::var = nullptr;

// Function: static BookedTicketManager& get();
// Description: instance caller
// Author: 김소연
// Revisions:
//		1. When & Who: 2019/06/01 by 김소연
//				What: Singleton 패턴을 적용한 instance caller
BookedTicketManager & BookedTicketManager::get()
{
	if (!var)
		var = new BookedTicketManager();
	return *var;
}


// Function: void print(const Info& buyerInfo)
// Description: 예약된 티켓 출력담당
// Author: 김소연
// Parameters: const Info & buyerInfo - 구매자의정보
// Revisions:
//		1. When & Who: 2019/06/01 by 김소연
//				What: 예약된 티켓의 출력을 담당
void BookedTicketManager::print(const Info & buyerInfo)
{
	std::cout << "4.5. 예약 정보 조회" << std::endl;
	// 구매자 파악
	auto user = UserCollection::get()[buyerInfo];
	Buyer* buyer = std::get<Buyer*>(user);

	//구매한 티켓을 시간순으로 정렬
	auto& tickets = buyer->getTickets();
	using Ptr = std::shared_ptr<Ticket>;
	std::sort(tickets.begin(), tickets.end(), [](Ptr l, Ptr r) { return l->getTime() < r->getTime(); });

	// 각 티켓 출력
	for (std::shared_ptr<Ticket>& ticket : buyer->getTickets()) {
		if(ticket->isUnderAuction())
			std::cout << "> " << ticket->getPrice() << " " << *ticket << std::endl;
		else
			std::cout << "> "  << *ticket << std::endl;
	}
}


// Function: ~BookedTicketManager();
// Description: 소멸자
// Author: 김소연
// Revisions:
//		1. When & Who: 2019/06/01 by 김소연
//				What: 소멸자이다
BookedTicketManager::~BookedTicketManager()
{
}
