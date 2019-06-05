// Class: Withdraw
// Description: 회원 탈퇴기능을 수행하는 control class이다.
// Author: 김상엽
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

// Function: Withdraw::Withdraw()
// Description: WithdrawUI 클래스의 생성자이다.
// Author: 김상엽
// Created: 2019/06/02
// Parameters:
// Return Value: Withdraw 클래스의 인스턴스

// Revisions:
// 		1.	When & Who: 2019/06/02 by 김상엽
// 				What: create function

Withdraw::Withdraw()
{
}


Withdraw* Withdraw::var = nullptr;
Withdraw & Withdraw::get() {
	if (!var)
		var = new Withdraw();
	return *var;
}

// Function: void Withdraw::requestWithdraw(const Info & info)
// Description: 회원 탈퇴를 수행하는 함수이다.
// Author: 김상엽
// Created: 2019/06/02
// Parameters: const Info & info(탈퇴할 회원의 정보)
// Return Value:

// Revisions:
// 		1.	When & Who: 2019/06/02 by 김상엽
// 				What: create function
// 		2.	When & Who: 2019/06/02 by 김상엽
// 				What: complete function

void Withdraw::requestWithdraw(const Info & info) {
	std::cout << "1.2. 회원탈퇴" << std::endl
		<< "> ";
	if (isRemovable(info)) {
		std::cout << info.getID() << std::endl;
		UserCollection::get().erase(info);
	}
}

// Function: Withdraw::~WithdrawUI()
// Description: WithdrawUI 클래스의 소멸자이다.
// Author: 김상엽
// Created: 2019/06/02
// Parameters:
// Return Value:

// Revisions:
// 		1.	When & Who: 2019/06/02 by 김상엽
// 				What: create function

Withdraw::~Withdraw()
{
}

// Function: bool Withdraw::isRemovable(const Info & info)
// Description: 회원 탈퇴가 가능한지 확인하는 함수이다.
// Author: 김상엽
// Created: 2019/06/02
// Parameters: const Info & info(탈퇴할 회원의 정보)
// Return Value: std::get<Seller*>(user)->empty() (boolean type의 탈퇴 가능 여부)

// Revisions:
// 		1.	When & Who: 2019/06/02 by 김상엽
// 				What: create function
// 		2.	When & Who: 2019/06/02 by 김상엽
// 				What: add if statement for buyer


bool Withdraw::isRemovable(const Info & info)
{
	if (info.getUserType() == "buyer")
		return true;
	// 판매자의 경우, 등록된 티켓이 없어야 한다.
	auto user = UserCollection::get()[info];
	return std::get<Seller*>(user)->empty();
}
