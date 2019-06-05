// Class: Withdraw
// Description: 회원 탈퇴기능을 수행하는 boundary class이다.
// Author: 김상엽
// Created: 2019/06/02
// Mail: natsuko0012@gmail.com

// Revisions:
// 		1.	When & Who: 2019/06/02 by 김상엽
// 				What: create file
//
// 		2.	When & Who: 2019/06/02 by 김상엽
// 				What: complete with withdraw control class
//
// 		3.	When & Who: 2019/06/03 by 김상엽
// 				What: add comment and modify some miss

#include "WithdrawUI.h"
#include "Withdraw.h"

// Function: WithdrawUI::WithdrawUI()
// Description: WithdrawUI 클래스의 생성자이다.
// Author: 김상엽
// Created: 2019/06/02
// Parameters:
// Return Value: WithdrawUI 클래스의 인스턴스

// Revisions:
// 		1.	When & Who: 2019/06/02 by 김상엽
// 				What: create function

WithdrawUI::WithdrawUI()
{
}


WithdrawUI* WithdrawUI::var = nullptr;
WithdrawUI & WithdrawUI::get()
{
	if (!var)
		var = new WithdrawUI();
	return *var;
}

// Function: void WithdrawUI::requestWithdraw(const Info & info)
// Description: WithdrawUI 클래스의 생성자이다.
// Author: 김상엽
// Created: 2019/06/02
// Parameters: const Info & info(탈퇴할 회원 정보)
// Return Value:

// Revisions:
// 		1.	When & Who: 2019/06/02 by 김상엽
// 				What: create function
// 		2.	When & Who: 2019/06/03 by 김상엽
// 				What: modify miss

void WithdrawUI::requestWithdraw(const Info & info)
{
	Withdraw::get().requestWithdraw(info);
}

// Function: WithdrawUI::~WithdrawUI()
// Description: WithdrawUI 클래스의 소멸자이다.
// Author: 김상엽
// Created: 2019/06/02
// Parameters:
// Return Value:

// Revisions:
// 		1.	When & Who: 2019/06/02 by 김상엽
// 				What: create function

WithdrawUI::~WithdrawUI()
{
}
