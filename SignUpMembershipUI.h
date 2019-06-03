//Class: SignUpMembership
//Description: 회원가입을 담당하는 boundary class이다.
//Author: 문준오
#pragma once

#include "Info.h"

class SignUpMembershipUI
{
private:
	//Description: Singleton 패턴을 위한 private 생성자이다.
	SignUpMembershipUI();
	static SignUpMembershipUI* var;
public:
	//Description: Singleton 패턴을 위한 instance caller이다.
	static SignUpMembershipUI& get();
	//Description: 회원가입을 담당하는 boundary class이다.
	void requestSignUP(const Info& info);
};

