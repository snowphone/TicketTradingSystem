// Class: SearchReservableTicketUI
// Description: 예약 가능한 티켓을 조회 및 예약하는 boundary class이다.
// Author: 문준오
#pragma once
#include <string>
#include "Info.h"
class SearchReservableTicketUI
{
	//Description: Singleton 패턴을 위한 private 생성자이다.
	SearchReservableTicketUI();
	static SearchReservableTicketUI* var;
public:
	//Description: Singleton 패턴을 위한 instance caller이다.
	static SearchReservableTicketUI& get();
	//Description: 선택한 홈팀에 해당하는 예약 가능한 티켓을 조회하는 함수이다.
	void search(std::string home);
	//Description: 선택한 티켓을 예약하는 함수이다.
	void reserve(const Info& buyerInfo, std::string time, std::string away, std::string position);
	//Description: 소멸자이다.
	~SearchReservableTicketUI();
};

