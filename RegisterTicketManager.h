// Class: RegisterTicketManager
// Description: 티켓 등록을 위한 control class이다.
// Authror: 문준오
#pragma once
#include "Info.h"
class RegisterTicketManager
{
	//Description: Singleton패턴을 위한 private 생성자이다.
	RegisterTicketManager();
	static RegisterTicketManager* var;

public:
	//Description: Timer가 만료되었을 때 1년 이상 등록된 티켓을 지우기 위해 호출할 함수이다.
	static void deleteHistory();
	//Description: Singleton 패턴에서 instance를 불러오는 method이다.
	static RegisterTicketManager& get();
	//Description: 판매자가 등록한 티켓을 새로 추가하는 메소드이다.
	void addNewTicket(const Info * currentUser, int price, std::string time, std::string home, std::string away, std::string position, bool useLTA);
	//Description: 소멸자이다.
	~RegisterTicketManager();
};

