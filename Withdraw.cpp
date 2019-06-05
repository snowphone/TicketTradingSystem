//Class: Withdraw
//Description: 회원 탈퇴기능을 수행하는 control class이다.
//Author: 김상엽
// Created: 2019/06/02
// Mail: natsuko0012@gmail.com

// Revisions:
// 		1.	When & Who: 2019/06/02 by 김상엽
// 				What: create file
//
// 		2.	When & Who: 2019/06/02 by 김상엽
// 				What: complete basic logic & add some comment

#include "Withdraw.h"
#include "UserCollection.h"
#include "Ticket.h"



Withdraw::Withdraw()
{
}


Withdraw* Withdraw::var = nullptr;
Withdraw & Withdraw::get() {
	if (!var)
		var = new Withdraw();
	return *var;
}

void Withdraw::requestWithdraw(const Info & info) {
	std::cout << "1.2. 회원탈퇴" << std::endl
		<< "> ";
	if (isRemovable(info)) {
		std::cout << info.getID() << std::endl;
		UserCollection::get().erase(info);
	}
}

Withdraw::~Withdraw()
{
}

bool Withdraw::isRemovable(const Info & info)
{
	if (info.getUserType() == "buyer")
		return true;
	// 판매자의 경우, 등록된 티켓이 없어야 한다.
	auto user = UserCollection::get()[info];
	return std::get<Seller*>(user)->empty();
}
