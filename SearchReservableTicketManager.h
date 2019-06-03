// Class: SearchReservableTicketManager
// Description: 구매자가 구매 가능한 티켓을 조회 및 구매할 수 있는 control class이다.
// Author: 문준오
#pragma once
#include <string>
#include <algorithm>
#include <vector>
#include "Info.h"
#include "Ticket.h"
#include "Seller.h"
#include "Buyer.h"

class SearchReservableTicketManager
{
	//Description: Singleton 패턴을 위한 private 생성자이다.
	SearchReservableTicketManager();
	static SearchReservableTicketManager* var;
	std::vector<Ticket*> watchingTickets;
	void selectSellingTickets();
	// Description: Ticket*가 가리키는 티켓 객체(shared_ptr)를 찾기 위한 보조함수이다.
	const Ticket* findSample(std::string time, std::string away, std::string position);
	// Description: 구매자가 판매자의 티켓을 결제하는 보조함수이다.
	void deal(Seller* seller, Buyer* buyer, std::vector<std::shared_ptr<Ticket>>::iterator it);
public:
	// Description: Singleton 패턴을 위한 instance caller이다.
	static SearchReservableTicketManager& get();
	// Description: 구매 가능한 티켓을 조회하는 함수이다.
	void show(const std::string home);
	// Description: 원하는 티켓을 예약하는 함수이다.
	void reserve(const Info& buyerInfo, std::string time, std::string away, std::string position);
};

