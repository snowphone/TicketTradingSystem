// Class: SearchReservableTicketManager
// Description: 구매자가 구매 가능한 티켓을 조회 및 구매할 수 있는 control class이다.
// Author: 유새람
#include "SearchReservableTicketManager.h"
#include "UserCollection.h"
#include <algorithm>


// Function: SearchReservableTicketManager()
// Description: private 생성자 (singleton)
// Author: 유새람
// Revisions:
//		1. When & Who: 2019/06/03 by 유새람
//				What: singleton패턴을 위한 private 생성자
SearchReservableTicketManager::SearchReservableTicketManager()
{
}


SearchReservableTicketManager* SearchReservableTicketManager::var = nullptr;

// Function: void selectSellingTickets();
// Description: 경매중인 티켓을 배제하기 위한 함수
// Author: 유새람
// Revisions:
//		1. When & Who: 2019/06/04 by 유새람
//				What: Auction 진행중인 Ticket(=경매중인 Ticket)은 지움
void SearchReservableTicketManager::selectSellingTickets()
{
	// 경매중인 티켓을 배제한다. 
	auto it = std::remove_if(watchingTickets.begin(), watchingTickets.end(), [](Ticket* i) { return i->isUnderAuction(); });
	watchingTickets.erase(it, watchingTickets.end());

	// 팔리지 못한 티켓도 배제한다. 
	// 이는 경매에 유찰된 경우나 미판매 상태로 경기가 시작한 경우를 의미한다. 
	it = std::remove_if(watchingTickets.begin(), watchingTickets.end(), [](Ticket* i) { return i->getSellableTimer().isExpired(); });
	watchingTickets.erase(it, watchingTickets.end());
}

// Function: const Ticket* findSample(std::string time, std::string away, std::string position)
// Description: Ticket*가 가리키는 ticket을 찾기위한 보조함수
// Parameters:	string time, away, position- 찾기원하는 ticket의 경기 시간, 어웨이팀, 좌석 위치
// Return Value:
// Author: 유새람
// Revisions:
//		1. When & Who: 2019/06/03 by 유새람
//				What: Ticket* 에서 입력된 경기정보를 사용해 가리키는 티켓 객체를 찾음 
const Ticket * SearchReservableTicketManager::findSample(std::string time, std::string away, std::string position)
{
	auto it = find_if(watchingTickets.begin(), watchingTickets.end(), [&](Ticket* t) {
		return t->getTime() == time && t->getAway() == away && t->getPosition() == position;
	});

	return it != watchingTickets.end() ? *it : nullptr;
}

// Function: void deal(Seller* seller, Buyer* buyer, std::vector<std::shared_ptr<Ticket>>::iterator it)
// Description: Buyer가 원하는 Ticket을 결제하는 함수
// Parameters:	Seller* seller - 결제를 진행할 Ticket의 판매자
//				Buyer* buyer - Ticket을 구매할 구매자
//				vector<std::shared_ptr<Ticket>>::iterator it - 결제를 진행할 Ticket
// Author: 유새람
// Revisions:
//		1. When & Who: 2019/06/04 by 유새람
//				What: 해당 Ticket을 Seller의 판매한 Ticket목록에 추가
//						해당 Ticket을 구매자가 소유한 Ticket에 추가
//						Seller의 등록한 Ticket 목록에서 삭제
void SearchReservableTicketManager::deal(Seller* seller, Buyer* buyer, std::vector<std::shared_ptr<Ticket>>::iterator it)
{
	//판매자의 판매 목록에 티켓 추가
	seller->getSoldTickets().push_back(*it);

	//판매자 -> 구매자로 소유권 양도
	buyer->getTickets().push_back(std::move(*it));
	seller->getRegisteredTickets().erase(it);
}

// Function: static SearchReservableTicketManager& get()
// Description: singleton패턴에서 instance를 불러오는 메소드
// Author: 유새람
// Revisions:
//		1. When & Who: 2019/06/04 by 유새람
//				What: 한번만 constructor 호출하도록 함
SearchReservableTicketManager & SearchReservableTicketManager::get()
{
	if (!var)
		var = new SearchReservableTicketManager();
	return *var;
}

// Function: void show(const std::string home);
// Description: 구매가능한 티켓을 조회하는 함수 (LTA 제외)
// Parameters:	string home- Buyer가 검색하기 원하는 홈팀
// Author: 유새람
// Revisions:
//		1. When & Who: 2019/06/04 by 유새람
//				What: 판매중인 모든 티켓 홈팀이 Buyer가 선택한것과 동일한 것을 get
//						그중 경매중인 티켓을 제외하고, 경기 시간이 빠른 순서로 출력
void SearchReservableTicketManager::show(std::string home)
{
	std::cout << "4.1. 티켓 검색" << std::endl;
	// 판매중인 모든 티켓 추출
	watchingTickets = UserCollection::get().getReservableTickets(home);
	// 경매중인 티켓 배제
	selectSellingTickets();

	// 출력
	for (auto& ticketPtr : watchingTickets) {
		std::cout << "> " << *ticketPtr << std::endl;
	}
}

// Function: void reserve(const Info& buyerInfo, std::string time, std::string away, std::string position)
// Description: Buyer가 선택한 Ticket을 예약하는 함수
// Parameters:	const Info & buyerInfo
//				string time, away, position - 선택한 티켓의 경기 시간, 어웨이팀, 좌석 위치
// Author: 유새람
// Revisions:
//		1. When & Who: 2019/06/04 by 유새람
//				What: Buyer 정보를 가져온 뒤, Buyer가 선택한 Ticket을 가져옴
//						해당 Ticket을 등록한 Seller를 찾아 함수 deal을 호출
//						이후 예약 내역을 출력 시킴
void SearchReservableTicketManager::reserve(const Info & buyerInfo, std::string time, std::string away, std::string position)
{
	//구매자 검색
	auto user = UserCollection::get()[buyerInfo];
	Buyer* buyer = std::get<Buyer*>(user);

	//원하는 티켓 검색
	const Ticket* ticketSample = findSample(time, away, position);

	//판매자 검색
	std::vector<Seller>& sellers = UserCollection::get().getSellers();
	for (Seller& seller : sellers) {
		std::vector<std::shared_ptr<Ticket>>& tickets = seller.getRegisteredTickets();
		for(auto ticketIter = tickets.begin(); ticketIter != tickets.end(); ++ticketIter) {
			if (ticketIter->get() == ticketSample) {

				deal(&seller, buyer, ticketIter);

				goto print;
			}
		}
	}

print:
	std::cout << "4.2. 티켓 예약" << std::endl
		<< "> " << *ticketSample << std::endl;
}

