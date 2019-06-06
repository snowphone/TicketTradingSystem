// Class: BookedTicketManagerUI
// Description: 예약된 티켓 조회를 위한 Boundary class이다.
// Author: 김소연
// Created: 2019/06/01
// Mail: 96syk@naver.com

// Revisions:
// 		1.	When & Who: 2019/06/01 by 김소연
// 				What: create file


#include "BookedTicketManagerUI.h"
#include "BookedTicketManager.h"


// Function: BookedTicketManagerUI()
// Description: private 생성자(singleton)
// Author: 김소연
// Revisions:
//		1. When & Who: 2019/06/01 by 김소연
BookedTicketManagerUI::BookedTicketManagerUI()
{
}


// Function: static BookedTicketManagerUI* var
// Description: private instance변수(singleton)
// Author: 김소연
// Revisions:
//		1. When & Who: 2019/06/01 by 김소연
BookedTicketManagerUI* BookedTicketManagerUI::var = nullptr;

// Function: static BookedTicketManagerUI& get();
// Description: instance caller(singleton)
// Author: 김소연
// Revisions:
//		1. When & Who: 2019/06/01 by 김소연
BookedTicketManagerUI & BookedTicketManagerUI::get()
{
	if (!var)
		var = new BookedTicketManagerUI();
	return *var;
}

// Function: void search(const Info& buyerInfo);
// Description: 예약 티켓 조회를 위한 boundary method
// Author: 김소연
// Revisions:
//		1. When & Who: 2019/06/01 by 김소연
void BookedTicketManagerUI::search(const Info & buyerInfo)
{
	BookedTicketManager::get().print(buyerInfo);
}


// Function: ~BookedTicketManagerUI()
// Description: 소멸자
// Author: 김소연
// Revisions:
//		1. When & Who: 2019/06/01 by 김소연
BookedTicketManagerUI::~BookedTicketManagerUI()
{
}
