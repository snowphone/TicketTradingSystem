// Class: SearchRegisteredTicketUI
// Description: 등록된 티켓 조회를 위한 boundary class이다.
// Author: 김상엽
// Created: 2019/05/31
// Mail: natsuko0012@gmail.com

// Revisions:
// 		1.	When & Who: 2019/05/31 by 김상엽
// 				What: create file
//
// 		2.	When & Who: 2019/05/31 by 김상엽
// 				What: complete basic logic with SearchRegisterTicket
//
// 		3.	When & Who: 2019/06/01 by 김상엽
// 				What: add Korean comment and modify some miss on var name

#include "SearchRegisteredTicketUI.h"
#include "SearchRegisteredTicket.h"

// Function: SearchRegisteredTicketUI::SearchRegisteredTicketUI()
// Description: SearchRegisterTicketUI 클래스의 생성자이다.
// Author: 김상엽
// Created: 2019/05/31
// Parameters:
// Return Value: SearchRegisterTicketUI 클래스의 인스턴스

// Revisions:
// 		1.	When & Who: 2019/05/31 by 김상엽
// 				What: create function

SearchRegisteredTicketUI::SearchRegisteredTicketUI()
{
}


SearchRegisteredTicketUI* SearchRegisteredTicketUI::var = nullptr;
SearchRegisteredTicketUI & SearchRegisteredTicketUI::get()
{
	if (!var)
		var = new SearchRegisteredTicketUI();
	return *var;
}

// Function: void SearchRegisteredTicketUI::search(const Info& info)
// Description: SearchRegisterTicket 클래스의 search 함수를 호출해준다.
// Author: 김상엽
// Created: 2019/05/31
// Parameters:
// Return Value:

// Revisions:
// 		1.	When & Who: 2019/05/31 by 김상엽
// 				What: create function
// 		2.	When & Who: 2019/06/01 by 김상엽
// 				What: modify miss on var name

void SearchRegisteredTicketUI::search(const Info& info)
{
	SearchRegisteredTicket::get().search(info);
}

// Function: SearchRegisteredTicketUI::~SearchRegisteredTicketUI()
// Description: SearchRegisterTicketUI 클래스의 소멸자이다.
// Author: 김상엽
// Created: 2019/05/31
// Parameters:
// Return Value:

// Revisions:
// 		1.	When & Who: 2019/05/31 by 김상엽
// 				What: create function

SearchRegisteredTicketUI::~SearchRegisteredTicketUI()
{
}
