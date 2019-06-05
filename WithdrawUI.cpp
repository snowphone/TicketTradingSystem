//Class: Withdraw
//Description: 회원 탈퇴기능을 수행하는 boundary class이다.
//Author: 김상엽
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

void WithdrawUI::requestWithdraw(const Info & info)
{
	Withdraw::get().requestWithdraw(info);
}

WithdrawUI::~WithdrawUI()
{
}
