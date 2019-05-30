#include "SearchTicketsInAuctionUI.h"
#include "SearchTicketsInAuction.h"



SearchTicketsInAuctionUI::SearchTicketsInAuctionUI()
{
}


SearchTicketsInAuctionUI* SearchTicketsInAuctionUI::var = nullptr;
SearchTicketsInAuctionUI & SearchTicketsInAuctionUI::get()
{
	if (!var)
		var = new SearchTicketsInAuctionUI();
	return *var;
}

void SearchTicketsInAuctionUI::search(std::string home)
{
	SearchTicketsInAuction::get().show(home);
}

void SearchTicketsInAuctionUI::bid(const Info & bidder, std::string time, std::string away, std::string position, int price)
{
	SearchTicketsInAuction::get().bid(bidder, time, away, position, price);
}

SearchTicketsInAuctionUI::~SearchTicketsInAuctionUI()
{
}
