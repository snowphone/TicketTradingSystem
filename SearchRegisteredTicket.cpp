#include "SearchRegisteredTicket.h"
#include "UserCollection.h"



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

void SearchRegisteredTicket::search(const Info & info)
{
	std::cout << "3.2. 등록티켓 조회 " << std::endl;
	//판매자 탐색
	auto user = UserCollection::get()[info];
	Seller* seller = std::get<Seller*>(user);

	// 판매중인 티켓 및 판매 완료된 티켓 추출
	std::vector<Ticket*> ticketList;

	auto& registeredTickets = seller->getRegisteredTickets();
	for (auto it = registeredTickets.begin(); it != registeredTickets.end(); ++it)
		ticketList.push_back(it->get());

	auto& soldTickets = seller->getSoldTickets();
	for (auto it = soldTickets.begin(); it != soldTickets.end(); ++it)
		ticketList.push_back(it->get());

	//시간순 추출
	sort(ticketList.begin(), ticketList.end(), [](Ticket* lhs, Ticket* rhs) { return lhs->getTime() < rhs->getTime(); });


	//출력
	for (Ticket* t : ticketList) {
		if (t->isUnderAuction())
			std::cout << "> " << t->getPrice() << " " << t << " " << t->isLTA() << " "
			<< (bool)std::count(soldTickets.begin(), soldTickets.end(), t) << std::endl;
		else
			std::cout << "> " << t << " " << t->isLTA() << " "
			<< (bool)std::count(soldTickets.begin(), soldTickets.end(), t) << std::endl;
	}

}

SearchRegisteredTicket::~SearchRegisteredTicket()
{
}
