//Class: SearchTicketsInAuction
//Description: 경매에서 입찰 가능한 티켓을 조회 및 입찰하는 boundary 클래스이다.
//Author: 문준오
#pragma once
#include <string>
#include "Info.h"
class SearchTicketsInAuctionUI
{
	//Description: Singleton을 위한 private 생성자
	SearchTicketsInAuctionUI();
	static SearchTicketsInAuctionUI* var;
public:
	//Description: Singleton을 위한 instance caller
	static SearchTicketsInAuctionUI& get();
	//Description: 선택한 home팀이 경기하는 모든 경매중인 티켓을 조회하는 boundary method이다.
	void search(std::string home);
	//Description: 원하는 티켓을 입찰하는 boundary method이다.
	void bid(const Info& bidder, std::string time, std::string away, std::string position, int price);
	//Description: 소멸자이다.
	~SearchTicketsInAuctionUI();
};

