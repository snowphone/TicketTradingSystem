// Class: SearchReservableTicketManager
// Description: 구매자가 구매 가능한 티켓을 조회 및 구매할 수 있는 control class이다.
// Author: 유새람
#include "SearchReservableTicketManager.h"
#include "UserCollection.h"
#include <algorithm>



SearchReservableTicketManager::SearchReservableTicketManager()
{
}


SearchReservableTicketManager* SearchReservableTicketManager::var = nullptr;
void SearchReservableTicketManager::selectSellingTickets()
{
	auto it = std::remove_if(watchingTickets.begin(), watchingTickets.end(), [](Ticket* i) {return i->isUnderAuction(); });
	watchingTickets.erase(it, watchingTickets.end());
}
const Ticket * SearchReservableTicketManager::findSample(std::string time, std::string away, std::string position)
{
	const Ticket* ticketSample = *find_if(watchingTickets.begin(), watchingTickets.end(), [&](Ticket* t) {
		return t->getTime() == time && t->getAway() == away && t->getPosition() == position;
	});
	return ticketSample;
}
void SearchReservableTicketManager::deal(Seller* seller, Buyer* buyer, std::vector<std::shared_ptr<Ticket>>::iterator it)
{
	//판매자의 판매 목록에 티켓 추가
	seller->getSoldTickets().push_back(*it);

	//판매자 -> 구매자로 소유권 양도
	buyer->getTickets().push_back(std::move(*it));
	seller->getRegisteredTickets().erase(it);
}
SearchReservableTicketManager & SearchReservableTicketManager::get()
{
	if (!var)
		var = new SearchReservableTicketManager();
	return *var;
}

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

