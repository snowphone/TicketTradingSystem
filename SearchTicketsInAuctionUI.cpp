// Class: SearchTicketsInAuction
// Description: 경매에서 입찰 가능한 티켓을 조회 및 입찰하는 boundary 클래스이다.
// Created: 2019/05/29
// Author: 김동하
// mail: kdongha1995@gmail.com
// 

#include "SearchTicketsInAuctionUI.h"
#include "SearchTicketsInAuction.h"



// Function: SearchTicketsInAuctionUI::SearchTicketsInAuctionUI()
// Description: Singleton을 위한 private 생성자
// Created: 2019/5/30
// Author: 김동하
SearchTicketsInAuctionUI::SearchTicketsInAuctionUI()
{
}


SearchTicketsInAuctionUI* SearchTicketsInAuctionUI::var = nullptr;
// Function: SearchTicketsInAuctionUI & SearchTicketsInAuctionUI::get()
// Description: Singleton을 위한 instance caller
// Created: 2019/5/30
// Author: 김동하
SearchTicketsInAuctionUI & SearchTicketsInAuctionUI::get()
{
	if (!var)
		var = new SearchTicketsInAuctionUI();
	return *var;
}


// Function: SearchTicketsInAuctionUI::search(std::string home)
// Description: 선택한 home팀이 경기하는 모든 경매중인 티켓을 조회하는 boundary method이다.
// Parameters : std::string home – home team
// Return Value : void
// Created: 2019/5/30
// Author: 김동하
void SearchTicketsInAuctionUI::search(std::string home)
{
	SearchTicketsInAuction::get().show(home);
}

// Function: bid(const Info & bidder, std::string time, std::string away, std::string position, int price)
// Description: 원하는 티켓을 입찰하는 boundary method이다.
// Parameters : const Info & bidder - bidder
// 		std::string time - game time
// 		std::string away - away team
//		std::string position - seating location
// 		int price - bid amount
// Return Value : void
// Created: 2019/5/30
// Author: 김동하
void SearchTicketsInAuctionUI::bid(const Info & bidder, std::string time, std::string away, std::string position, int price)
{
	SearchTicketsInAuction::get().bid(bidder, time, away, position, price);
}

// Function: ~SearchTicketsInAuctionUI()
// Description: 소멸자
// Created: 2019/5/30
// Author: 김동하
SearchTicketsInAuctionUI::~SearchTicketsInAuctionUI()
{
}
