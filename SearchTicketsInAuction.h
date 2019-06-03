//Class: SearchTicketsInAuction
//Description: 경매에서 입찰 가능한 티켓을 조회 및 입찰하는 control 클래스이다.
//Author: 문준오
#pragma once
#include <string>
#include <map>
#include <algorithm>
#include <vector>

#include "Ticket.h"
#include "Buyer.h"
class SearchTicketsInAuction
{
	//Description: Singleton 패턴을 위한 private 생성자
	SearchTicketsInAuction();
	static SearchTicketsInAuction* var;
	static std::map <Ticket*, std::vector<std::pair<Buyer*, int>>> biddingList;
	static std::vector<Ticket*> currentView;
	//Description: currentView로 부터 LTA중인 티켓만을 선별하여 시간순으로 정렬하는 함수
	void selectBiddableAndSort();
	std::vector<Ticket*>::iterator findTicket(std::string time, std::string away, std::string position);
	//Description: 원하는 티켓을 입찰하는 보조함수
	void bid(Buyer* bidder, Ticket* ticket, int price);
public:
	//Description: Timer가 만료되었을 때 경매 결과를 처리하여 입찰자를 선정하는 함수
	static void finishBidding();
	//Description: Singleton을 위한 instance caller 함수
	static SearchTicketsInAuction& get();
	//Description: 선택한 home팀이 경기하는 모든 경매중인 티켓을 조회하는 control method이다.
	void show(std::string home);
	//Description: 원하는 티켓을 입찰하는 control method이다.
	void bid(const Info& bidder, std::string time, std::string away, std::string position, int price);
	//Description: 소멸자이다.
	~SearchTicketsInAuction();
};

