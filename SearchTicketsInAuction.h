#pragma once
#include <string>
#include <map>
#include <algorithm>
#include <vector>

#include "Ticket.h"
#include "Buyer.h"
class SearchTicketsInAuction
{
	SearchTicketsInAuction();
	static SearchTicketsInAuction* var;
	static std::map <Ticket*, std::vector<std::pair<Buyer*, int>>> biddingList;
	static std::vector<Ticket*> currentView;
public:
	static void finishBidding();
	static SearchTicketsInAuction& get();
	void show(std::string home);
	void bid(const Info& bidder, std::string time, std::string away, std::string position, int price);
	~SearchTicketsInAuction();
};

