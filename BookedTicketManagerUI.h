// Class: BookedTicketManagerUI
// Description: 예약된 티켓 조회를 위한 Boundary class이다.
// Author: 문준오
#pragma once
#include "Info.h"

class BookedTicketManagerUI
{
	//Description: Singleton 패턴을 위한 private 생성자이다.
	BookedTicketManagerUI();
	//Description: Singleton 패턴을 위한 private instance 변수이다.
	static BookedTicketManagerUI* var;
public:
	//Description: Singleton 패턴을 위한 instance caller이다.
	static BookedTicketManagerUI& get();
	//Description: 예약 티켓 조회를 위한 boundary method이다.
	void search(const Info& buyerInfo);
	//Description: 소멸자이다.
	~BookedTicketManagerUI();
};

