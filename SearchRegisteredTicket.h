// Class: SearchRegisterTicket
// Description: 등록한 티켓을 검색하기 위한 control class이다.
// Author: 문준오
#pragma once
#include "Info.h"
class SearchRegisteredTicket
{
	//Description: Singleton 패턴을 위한 private 생성자이다.
	SearchRegisteredTicket();
	static SearchRegisteredTicket* var;
public:
	//Description: Singleton 패턴을 위한 instance caller이다.
	static SearchRegisteredTicket& get();
	//Description: 구매자의 티켓을 검색하는 control method이다.
	void search(const Info& info);
	//Description: 소멸자이다.
	~SearchRegisteredTicket();
};

