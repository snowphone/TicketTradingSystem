//Class: SignInUI
//Description: 로그인 기능을 담당하는 boundary 클래스이다.
//Author: 문준오
#pragma once
#include "Info.h"
#include <string>
class SignInUI
{
	//Description: Singleton을 위한 private 생성자이다.
	SignInUI();
	static SignInUI* var;
public:
	//Description: Singleton을 위한 instance caller이다.
	static SignInUI& get();
	//Description: 로그인을 담당하는 boundary method이다.
	const Info* requestSignIn(std::string id, std::string pw);
	//Description: 소멸자이다.
	~SignInUI();
};

