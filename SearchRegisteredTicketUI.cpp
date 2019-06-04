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

void SearchRegisteredTicketUI::search(const Info& info)
{

	SearchRegisteredTicket::get().search(info);
}

SearchRegisteredTicketUI::~SearchRegisteredTicketUI()
{
}
