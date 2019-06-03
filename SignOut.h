//Class: SignOut
//Description: 로그아웃을 담당하는 control class이다.
//Author: 문준오
#pragma once
#include "Info.h"
class SignOut
{
	//Description: Singleton패턴을 위한 private 생성자이다.
	SignOut();
	static SignOut* var;
public:
	//Description: Singleton패턴을 위한 instance caller이다.
	static SignOut& get();
	//Description: 로그아웃을 수행하는 control method이다.
	void requestSignOut(const Info& info);
	//Description: 소멸자이다.
	~SignOut();
};

