#include "SearchTicketsInAuction.h"
#include "UserCollection.h"
#include <algorithm>



SearchTicketsInAuction::SearchTicketsInAuction()
{
}

std::map <Ticket*, std::vector<std::pair<Buyer*, int>>> SearchTicketsInAuction::biddingList;

std::vector<Ticket*> SearchTicketsInAuction::currentView;
SearchTicketsInAuction* SearchTicketsInAuction::var = nullptr;
void SearchTicketsInAuction::finishBidding()
{
	using P = std::pair<Buyer*, int>;
	for (auto iter = biddingList.begin(); iter != biddingList.end(); ++iter) {
		auto&[ticketptr, bidders] = *iter;
		if (!ticketptr->getAuctionTimer().isExpired())
			continue;

		if (!bidders.empty())
		{

			//입찰자 선정
			Buyer* winner = std::max_element(bidders.begin(), bidders.end(),
				[](P l, P r) {return l.second < r.second; })->first;
			winner->getTickets().push_back(*ticketptr);

			//판매자 파악
			auto& sellers = UserCollection::get().getSellers();
			auto& seller = *std::find_if(sellers.begin(), sellers.end(), 
				[ticketptr](Seller& s) {
				auto& tickets = s.getRegisteredTickets();
				return count_if(tickets.begin(), tickets.end(), 
					[ticketptr](Ticket& t) {return t == *ticketptr; });
			});
			//판매자의 판매한 록록에 추가
			seller.getSoldTickets().push_back(*ticketptr);
			//판매자의 판매중인 목록에서 제거
			auto it = std::find(seller.getRegisteredTickets().begin(), seller.getRegisteredTickets().end(), *ticketptr);
			seller.getRegisteredTickets().erase(it);
		}
		iter = biddingList.erase(iter);
		--iter;
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
	std::cout << "4.3. 경매 중인 티켓 검색" << std::endl
		<< "> ";
	currentView = UserCollection::get().getReservableTickets(home);
	auto it = std::remove_if(currentView.begin(), currentView.end(), [](Ticket* t) {return !t->isUnderAuction(); });
	currentView.erase(it, currentView.end());
	sort(currentView.begin(), currentView.end(), [](Ticket* l, Ticket* r) {return l->getTime() < r->getTime(); });
	for (Ticket* t : currentView)
		std::cout << *t << std::endl;

	if (currentView.empty())
		std::cout << std::endl;
}

void SearchTicketsInAuction::bid(const Info & bidderInfo, std::string time, std::string away, std::string position, int price)
{
	
	std::cout << "4.4. 경매 참여" << std::endl
		<< "> " << price << std::endl;

	//원하는 티켓을 찾는다.
	std::vector<Ticket*>::iterator it = find_if(currentView.begin(), currentView.end(),
		[&](Ticket* t) {return t->getTime() == time && t->getAway() == away && t->getPosition() == position; });

	if (it == currentView.end()) {
		throw std::runtime_error("제발..");
	}
	Ticket* ticket = *it;

	auto user = UserCollection::get().at(bidderInfo);
	Buyer* bidder = std::get<Buyer*>(user);


	std::vector<std::pair<Buyer*, int>>& list = biddingList[ticket];

}

SearchTicketsInAuction::~SearchTicketsInAuction()
{
}
