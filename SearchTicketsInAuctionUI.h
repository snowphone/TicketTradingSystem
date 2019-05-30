#pragma once
#include <string>
#include "Info.h"
class SearchTicketsInAuctionUI
{
	SearchTicketsInAuctionUI();
	static SearchTicketsInAuctionUI* var;
public:
	static SearchTicketsInAuctionUI& get();
	void search(std::string home);
	void bid(const Info& bidder, std::string time, std::string away, std::string position, int price);
	~SearchTicketsInAuctionUI();
};

