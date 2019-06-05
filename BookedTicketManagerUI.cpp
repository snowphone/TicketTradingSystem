// Class: BookedTicketManagerUI
// Description: 예약된 티켓 조회를 위한 Boundary class이다.
// Author: 김소연
// Created: 2019/06/01
// Mail: 96syk@naver.com

// Revisions:
// 		1.	When & Who: 2019/06/01 by 김소연
// 				What: create file
//
// 		2.	When & Who: 2019/06/04 by 김소연
// 				What: modify some errors


#include "BookedTicketManagerUI.h"
#include "BookedTicketManager.h"



BookedTicketManagerUI::BookedTicketManagerUI()
{
}


BookedTicketManagerUI* BookedTicketManagerUI::var = nullptr;
BookedTicketManagerUI & BookedTicketManagerUI::get()
{
	if (!var)
		var = new BookedTicketManagerUI();
	return *var;
}

void BookedTicketManagerUI::search(const Info & buyerInfo)
{
	BookedTicketManager::get().print(buyerInfo);
}

BookedTicketManagerUI::~BookedTicketManagerUI()
{
}
