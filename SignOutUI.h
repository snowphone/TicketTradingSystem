//Class: SignOut
//Description: 로그아웃을 담당하는 boundary class이다.
//Author: 문준오
#pragma once
#include "Info.h"
class SignOutUI
{
	//Description: Singleton 패턴을 위한 private 생성자이다.
	SignOutUI();
	static SignOutUI* var;
public:
	//Description: 로그아웃을 담당하는 boundary method이다.
	void requestSignOut(const Info& info);
	//Description: Singleton 패턴을 위한 instance caller이다.
	static SignOutUI& get();
	//Description: 소멸자이다.
	~SignOutUI();
};
