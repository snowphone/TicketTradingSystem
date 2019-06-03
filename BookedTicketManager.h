// Class: BookedTicketManager
// Description: 예약된 티켓 정보 출력을 위한 control 클래스이다.
// Author: 문준오
#pragma once
#include "Info.h"

class BookedTicketManager
{
	//Description: Singleton 패턴을 적용한 private 생성자이다.
	BookedTicketManager();
	//Description: Singleton 패턴을 적용한 private instance 변수이다.
	static BookedTicketManager* var;
public:
	//Description: Singleton 패턴을 적용한 instance caller 이다.
	static BookedTicketManager& get();
	//Description: 예약된 티켓의 출력을 담당한다.
	void print(const Info& buyerInfo);
	//Description: 소멸자이다.
	~BookedTicketManager();
};

