// Class: RegisterTicketUI
// Description: 티켓 등록을 위한 boundary 클래스이다.
// Author: 문준오
#pragma once
#include <string>
#include "Info.h"
class RegisterTicketUI
{
	//Description: Singleton 패턴을 위한 private 생성자이다.
	RegisterTicketUI();
	static RegisterTicketUI* var;
public:
	//Description: Singleton 패턴을 위한 instance caller이다.
	static RegisterTicketUI& get();
	//Description: 새 티켓을 등록하기 위한 boundary method이다.
	void createNewTicket(const Info* user, int price, std::string time, std::string home, std::string away, std::string position, bool useLTA);
	//Description: 소멸자이다.
	~RegisterTicketUI();
};

