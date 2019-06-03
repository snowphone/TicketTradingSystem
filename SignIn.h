//Class: SignIn
//Description: 로그인 기능을 담당하는 control class이다.
//Author: 문준오
#pragma once
#include "SignInUI.h"
class SignIn
{
	//Description: Singleton을 위한 private 생성자이다.
	SignIn();
	static SignIn* var;
public:
	//Description: Singleton을 위한 instance caller이다.
	static SignIn& get();
	//Description: 로그인을 담당하는 control method이다.
	const Info* putIdPw(std::string id, std::string pw);
	//Description: 소멸자이다.
	~SignIn();
};

