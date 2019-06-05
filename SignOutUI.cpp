// Class: SignOut
// Description: 로그아웃을 담당하는 boundary class이다.
// Author: 김상엽

// Revisions:
// 		1.	When & Who: 2019/06/01 by 김상엽
// 				What: create file
//
// 		2.	When & Who: 2019/06/01 by 김상엽
// 				What: add some include
//
// 		3.	When & Who: 2019/06/03 by 김상엽
// 				What: remove redundant include
//
// 		4.	When & Who: 2019/06/03 by 김상엽
// 				What: add debugging code
//
// 		5.	When & Who: 2019/06/03 by 김상엽
// 				What: complete Seller.cpp

#include "SignOutUI.h"
#include "SignOut.h"

// Function: SignOutUI::SignOutUI()
// Description: SignOutUI 클래스의 생성자이다.
// Author: 김상엽
// Created: 2019/06/01
// Parameters:
// Return Value:

// Revisions:
// 		1.	When & Who: 2019/06/01 by 김상엽
// 				What: create function

SignOutUI::SignOutUI()
{
}

// Function: void SignOutUI::requestSignOut(const Info & info)
// Description: SignOut 클래스의 SignOut을 호출하는 함수이다.
// Author: 김상엽
// Created: 2019/06/01
// Parameters: const Info & info(로그아웃할 계정의 정보)
// Return Value:

// Revisions:
// 		1.	When & Who: 2019/06/01 by 김상엽
// 				What: create function
//
// 		2.	When & Who: 2019/06/03 by 김상엽
// 				What: add debugging code
//
// 		3.	When & Who: 2019/06/03 by 김상엽
// 				What: complete function

SignOutUI* SignOutUI::var = nullptr;
void SignOutUI::requestSignOut(const Info & info)
{
	SignOut::get().requestSignOut(info);
}
SignOutUI & SignOutUI::get()
{
	if (!var)
		var = new SignOutUI();
	return *var;
}

// Function: SignOutUI::~SignOutUI()
// Description: SignOutUI 클래스의 소멸자이다.
// Author: 김상엽
// Created: 2019/06/01
// Parameters:
// Return Value:

// Revisions:
// 		1.	When & Who: 2019/06/01 by 김상엽
// 				What: create function

SignOutUI::~SignOutUI()
{
}
