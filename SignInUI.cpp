//Class: SignInUI
//Description: 로그인 기능을 담당하는 boundary 클래스이다.
//Author: 김소연
// Created: 2019/06/01
// Mail: 96syk@naver.com

// Revisions:
// 		1.	When & Who: 2019/06/01 by 김소연
// 				What: create file
//
// 		2.	When & Who: 2019/06/03 by 김소연
// 				What: modify some errors and add comments
#include "SignInUI.h"
#include "SignIn.h"


// Function: SignInUI()
// Description: Singleton을 위한 private 생성자
// Author: 김소연
// Revisions:
//		1. When & Who: 2019/06/01 by 김소연
SignInUI::SignInUI()
{
}

// Function: static SignInUI* var
// Description: Singleton을 위한 private instance 변수
// Author: 김소연
// Revisions:
//		1. When & Who: 2019/06/01 by 김소연
SignInUI* SignInUI::var = nullptr;

// Function: static SignInUI& get()
// Description: Singleton을 위한 instance caller
// Author: 김소연
// Revisions:
//		1. When & Who: 2019/06/01 by 김소연
SignInUI & SignInUI::get()
{
	if (!var)
		var = new SignInUI();
	return *var; //instance caller
}

// Function: const Info* requestSignIn(std::string id, std::stringpw)
// Description: 로그인을 담당하는 boundary method
// Author: 김소연
// Revisions:
//		1. When & Who: 2019/06/01 by 김소연
const Info * SignInUI::requestSignIn(std::string id, std::string pw)
{
	return SignIn::get().putIdPw(id, pw); //로그인화면 UI로 제공
}

// Function: ~SignInUI()
// Description: 소멸자
// Author: 김소연
// Revisions:
//		1. When & Who: 2019/06/01 by 김소연
SignInUI::~SignInUI()
{
}
