// Class: SearchRegisteredTicketUI
// Description: 등록된 티켓 조회를 위한 boundary class이다.
// Author: 문준오
#pragma once
#include "Info.h"
class SearchRegisteredTicketUI
{
	//Description: Singleton을 위한 private 생성자이다.
	SearchRegisteredTicketUI();
	static SearchRegisteredTicketUI* var;
public:
	//Description: Singleton을 위한 instance caller이다.
	static SearchRegisteredTicketUI& get();
	//Description: 등록된 티켓을 조회하기 위한 boundary method이다.
	void search(const Info& info);
	//Description: 소멸자이다.
	~SearchRegisteredTicketUI();
};

