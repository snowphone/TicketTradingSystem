// Class: SearchTicketsInAuction
// Description: 경매에서 입찰 가능한 티켓을 조회 및 입찰하는 control 클래스이다.
// Created: 2019/05/29
// Author: 김동하
// mail: kdongha1995@gmail.com
//
// Revisions:
//	1. When & Who : 2019/06/01 19:07 by 김동하
//	    What : added comments
#include "SearchTicketsInAuction.h"
#include "UserCollection.h"
#include <ctime>
#include <algorithm>



SearchTicketsInAuction::SearchTicketsInAuction()
{
}

std::map <Ticket*, std::vector<std::pair<Buyer*, int>>> SearchTicketsInAuction::biddingList;

std::vector<Ticket*> SearchTicketsInAuction::currentView;

SearchTicketsInAuction* SearchTicketsInAuction::var = nullptr;

// Function: void finishBidding()
// Description: auctionTimer가 만료되었을 때, list를 순회하면서 경매가 끝난 티켓들에 대해 입찰자를 선정한다.
// Parameters: void
// Return value: void
// Created: 2019/05/30 22:57 by 문준오
void SearchTicketsInAuction::finishBidding()
{
	// 모든 경매 순회
	for (auto iter = biddingList.begin(); iter != biddingList.end(); ++iter) {
		auto[ticketSample, bidders] = *iter;

		//경매가 종료된 티켓 -> 경매중인 리스트에서 제외
		iter = biddingList.erase(iter);
		if (iter != biddingList.begin())
			--iter;

		//유찰 
		if (bidders.empty())
			continue;

		//    입찰자 선정   

		//최대 입찰 금액을 선정한 입찰자를 선정
		auto[winner, price] = *std::max_element(bidders.begin(), bidders.end(),
			[](std::pair<Buyer*, int>& l, std::pair<Buyer*, int>& r) {return l.second < r.second; });

		//    판매자 파악하기    
		auto& sellers = UserCollection::get().getSellers();
		for (Seller& seller : sellers) {
			std::vector<std::shared_ptr<Ticket>>& ticketList = seller.getRegisteredTickets();
			for (auto ticketIter = ticketList.begin(); ticketIter != ticketList.end(); ++ticketIter) {
				//   판매자 및 판매할 티켓 확보   
				if (ticketSample == ticketIter->get()) {

					// 복사본 생성하여 판매자의 판매 완료된 목록에 추가
					Ticket copiedTicket = **ticketIter;
					auto ticketPtr = std::make_shared<Ticket>(copiedTicket);
					seller.getSoldTickets().push_back(ticketPtr);

					//입찰가로 가격 갱신
					(*ticketIter)->setPrice(price);

					// 판매자 -> 구매자로 티켓 소유권 양도
					winner->getTickets().push_back(*ticketIter);

					// 판매자의 판매중 목록에서 삭제
					seller.getRegisteredTickets().erase(ticketIter);

					return;
				}
			}
		}
	}
}
// Function: SearchTicketsInAuction & SearchTicketsInAuction::get()
// Description: Singleton을 위한 instance caller 함수
// Created: 2019/05/29
// Author: 김동하
SearchTicketsInAuction & SearchTicketsInAuction::get()
{
	if (!var)
		var = new SearchTicketsInAuction();
	return *var;
}

// Function: SearchTicketsInAuction::show(std::string home)
// Description: 선택한 home팀이 경기하는 모든 경매중인 티켓을 조회하는 control method이다.
// Parameters: std::string home - selected home team
// Return Value: void
// Created: 2019/05/29
// Author: 김동하
void SearchTicketsInAuction::show(std::string home)
{
	std::cout << "4.3. 경매 중인 티켓 검색" << std::endl;
	//경매중인 티켓 추출
	currentView = UserCollection::get().getReservableTickets(home);

	selectBiddableAndSort();

	//출력
	for (Ticket* t : currentView) {
		time_t remaining = Timer::parseTime(t->getSellableTimer().getDeadline()) - Timer::parseTime(Timer::getCurrentTime());
		const time_t hour = 3600;
		char timeInStr[32];
		sprintf(timeInStr, "%02d:%02d", remaining / hour, (remaining % hour) / 60);
		std::cout << "> " << *t << " " << timeInStr << std::endl;
	}
}

// Function: SearchTicketsInAuction::bid(const Info & bidderInfo, std::string time, std::string away, std::string position, int price)
// Description: 원하는 티켓을 입찰하는 control method이다.
// Parameters:	const Info & bidderInfo - bidder
// 		std::string time - game time
// 		std::string away - away team
//		std::string position - seating location
// 		int price - bid amount
// Return Value: void
// Created: 2019/05/29
// Author: 김동하
void SearchTicketsInAuction::bid(const Info & bidderInfo, std::string time, std::string away, std::string position, int price)
{

	std::cout << "4.4. 경매 참여" << std::endl
		<< "> " << price << std::endl;



	Ticket* ticket = *findTicket(time, away, position);

	//입찰자 탐색
	auto user = UserCollection::get()[bidderInfo];
	Buyer* bidder = std::get<Buyer*>(user);


	bid(bidder, ticket, price);
}

// Function: SearchTicketsInAuction::selectBiddableAndSort()
// Description: currentView로 부터 LTA중인 티켓만을 선별하여 시간순으로 정렬하는 함수
// Parameters: void
// Return Value: void
// Created: 2019/05/29
// Author: 김동하
void SearchTicketsInAuction::selectBiddableAndSort()
{
	//경매중 티켓 선정
	auto it = std::partition(currentView.begin(), currentView.end(), [](Ticket* t) {return t->isUnderAuction(); });
	currentView.erase(it, currentView.end());
	//시간순 정렬
	sort(currentView.begin(), currentView.end(), [](Ticket* l, Ticket* r) {return l->getTime() < r->getTime(); });
}

// Function: SearchTicketsInAuction::findTicket(std::string time, std::string away, std::string position)
// Description: 경매에 참가할 티켓을 찾는 함수
// Parameters:	std::string time - game time
// 		std::string away - away team
//		std::string position - seating location
// Return Value: std::vector<Ticket*>::iterator
// Created: 2019/05/29
// Author: 김동하
std::vector<Ticket*>::iterator SearchTicketsInAuction::findTicket(std::string time, std::string away, std::string position)
{
	//경매에 참가할 티켓을 찾는다
	std::vector<Ticket*>::iterator it = find_if(currentView.begin(), currentView.end(),
		[&](Ticket* t) {return t->getTime() == time && t->getAway() == away && t->getPosition() == position; });
	return it;
}

// Function: SearchTicketsInAuction::bid(Buyer * bidder, Ticket* ticket, int price)
// Description: 원하는 티켓을 입찰하는 보조함수
// Parameters:	Buyer * bidder - bidder
// 		Ticket* ticket - bid ticket
//		int price - bid amount
// Return Value: void
// Created: 2019/05/29
// Author: 김동하
void SearchTicketsInAuction::bid(Buyer * bidder, Ticket* ticket, int price)
{
	//입찰시 최소 금액은 판매 희망가격의 절반이다.
	if (ticket->getPrice() / 2 <= price) {
		std::vector<std::pair<Buyer*, int>>& list = biddingList[ticket];
		list.push_back({ bidder, price });
	}
}


// Function: ~SearchTicketsInAuction()
// Description: 소멸자
// Parameters: void
// Return Value: void
// Created: 2019/05/29
// Author: 김동하
SearchTicketsInAuction::~SearchTicketsInAuction()
{
}
