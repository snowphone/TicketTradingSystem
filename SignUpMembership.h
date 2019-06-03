//Class: SignUpMembership
//Description: 회원가입을 담당하는 control class이다.
//Author: 문준오
#pragma once
#include "Info.h"

class SignUpMembership
{
	static SignUpMembership* var;
	//Description: Singleton 패턴을 위한 private 생성자이다.
	SignUpMembership();
public:
	//Description: Singleton 패턴을 위한 instance caller이다.
	static SignUpMembership& get();
	//Description: 회원가입을 수행하는 control method이다.
	void signUp(const Info& info);
	//Description: 소멸자이다.
	~SignUpMembership();
};

