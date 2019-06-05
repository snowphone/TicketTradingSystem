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



SignInUI::SignInUI()
{
}


SignInUI* SignInUI::var = nullptr;
SignInUI & SignInUI::get()
{
	if (!var)
		var = new SignInUI();
	return *var; //instance caller
}

const Info * SignInUI::requestSignIn(std::string id, std::string pw)
{
	return SignIn::get().putIdPw(id, pw); //로그인화면 UI로 제공
}

SignInUI::~SignInUI()
{
}
