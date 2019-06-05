// Class: RegisterTicketUI
// Description: 티켓 등록을 위한 boundary 클래스이다.
// Author: 유새람
#include "RegisterTicketUI.h"
#include "RegisterTicketManager.h"


// Function: RegisterTicketUI()
// Description: private 생성자(singleton)
// Author: 유새람
// Revisions:
//		1. When & Who: 2019/06/02 by 유새람
RegisterTicketUI::RegisterTicketUI()
{
}


RegisterTicketUI* RegisterTicketUI::var = nullptr;

// Function: static RegisterTicketUI& get();
// Description: singleton패턴에서의 instance를 불러오는 caller
// Return Value: RegisterTicketUI
// Author: 유새람
// Revisions:
//		1. When & Who: 2019/06/02 by 유새람
//				What: 존재하지 않으면 새롭게 생성/존재하면 RegisterTicketUI return
RegisterTicketUI& RegisterTicketUI::get()
{
	if (!var)
		var = new RegisterTicketUI();
	return *var;
}

// Function: void createNewTicket(const Info* user, int price, std::string time, std::string home, std::string away, std::string position, bool useLTA);
// Description: 판매자가 등록한 티켓을 새로 추가하기위한  boundary method
// Parameters:	info * user- 등록하려는 Seller
//				int price- 희망 판매가격
//				string time, home, away, position- 경기정보(경기 날짜, 홈팀, 어웨이팀, 좌석 위치)
//				bool useLTA- limited-time auction 사용 여부
// Author: 유새람
// Revisions:
//		1. When & Who: 2019/06/02 by 유새람
//				What: RegisterTicketManager의 addNewTicket 함수 호출
void RegisterTicketUI::createNewTicket(const Info* user, int price, std::string time, 
	std::string home, std::string away, std::string position, bool useLTA)
{
	RegisterTicketManager::get().addNewTicket(user, price, time, home, away, position, useLTA);
}

// Function: ~RegisterTicketUI()
// Description: 소멸자
// Author: 유새람
// Revisions:
//		1. When & Who: 2019/06/02 by 유새람
RegisterTicketUI::~RegisterTicketUI()
{
}
