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

void SearchTicketsInAuction::finishBidding()
{
	// 모든 경매 순회
	for (auto iter = biddingList.begin(); iter != biddingList.end(); ++iter) {
		auto[ticketSample, bidders] = *iter;

		//경매가 종료된 티켓 -> 경매중인 리스트에서 제외
		iter = biddingList.erase(iter);
		if(iter != biddingList.begin())
			--iter;

		//유찰 
		if (bidders.empty())
			continue;

		/*    입찰자 선정   */

		//최대 입찰 금액을 선정한 입찰자를 선정
		auto[winner, price] = *std::max_element(bidders.begin(), bidders.end(),
			[](std::pair<Buyer*, int>& l, std::pair<Buyer*, int>& r) {return l.second < r.second; });

		/*    판매자 파악하기    */
		auto& sellers = UserCollection::get().getSellers();
		for (Seller& seller : sellers) {
			std::vector<std::shared_ptr<Ticket>>& ticketList = seller.getRegisteredTickets();
			for (auto ticketIter = ticketList.begin(); ticketIter != ticketList.end(); ++ticketIter) {
				/*   판매자 및 판매할 티켓 확보   */
				if (ticketSample == ticketIter->get()) {

					// 복사본 생성하여 판매자의 판매 완료된 목록에 추가
					Ticket copiedTicket = **ticketIter;
					seller.getSoldTickets().push_back(std::make_shared<Ticket>(copiedTicket));

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
SearchTicketsInAuction & SearchTicketsInAuction::get()
{
	if (!var)
		var = new SearchTicketsInAuction();
	return *var;
}

void SearchTicketsInAuction::show(std::string home)
{
	std::cout << "4.3. 경매 중인 티켓 검색" << std::endl;
	//경매중인 티켓 추출
	currentView = UserCollection::get().getReservableTickets(home);
	auto it = std::remove_if(currentView.begin(), currentView.end(), [](Ticket* t) {return !t->isUnderAuction(); });
	currentView.erase(it, currentView.end());

	//시간순 정렬
	sort(currentView.begin(), currentView.end(), [](Ticket* l, Ticket* r) {return l->getTime() < r->getTime(); });

	//출력
	for (Ticket* t : currentView) {
		time_t remaining = Timer::parseTime(t->getAuctionTimer().getDeadline()) - Timer::parseTime(Timer::getCurrentTime());
		const time_t hour = 3600;
		char timeInStr[32];
		sprintf(timeInStr, "%02d:%02d", remaining / hour, (remaining % hour) / 60);
		std::cout << "> " << *t << " " << timeInStr << std::endl;
	}
}

void SearchTicketsInAuction::bid(const Info & bidderInfo, std::string time, std::string away, std::string position, int price)
{
	
	std::cout << "4.4. 경매 참여" << std::endl
		<< "> " << price << std::endl;

	//경매에 참가할 티켓을 찾는다
	std::vector<Ticket*>::iterator it = find_if(currentView.begin(), currentView.end(),
		[&](Ticket* t) {return t->getTime() == time && t->getAway() == away && t->getPosition() == position; });

	Ticket* ticket = *it;

	//입찰자 탐색
	auto user = UserCollection::get()[bidderInfo];
	Buyer* bidder = std::get<Buyer*>(user);


	//입찰
	std::vector<std::pair<Buyer*, int>>& list = biddingList[ticket];
	list.push_back({ bidder, price });
}

SearchTicketsInAuction::~SearchTicketsInAuction()
{
}
