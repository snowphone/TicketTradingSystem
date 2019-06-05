// Class: Buyer
// Descripton: 구매자 객체를 표현하는 클래스이다. 
// Author: 유새람

// Revisions:
// 		1.	When & Who: 2019/06/02 by 유새람
// 				What: create file
//
// 		2.	When & Who: 2019/06/02 by 유새람
// 				What: complete logic
//
// 		3.	When & Who: 2019/06/04 by 유새람
// 				What: add comment

#include "Buyer.h"


const Info & Buyer::getInfo() const
{	
	return this->info;	//info(사용자정보) get
}

std::vector<std::shared_ptr<Ticket>>& Buyer::getTickets()
{
	return tickets;		//tickets get
}


bool Buyer::empty() const
{
	return tickets.empty();	//buyer(구매자)가 티켓을 가지고있는지 확인
}

bool Buyer::operator==(const Info& i) const
{
	return this->info == i;	//
}

Buyer::Buyer(const Info & info) : info(info)
{
}

Buyer::~Buyer()
{
}
