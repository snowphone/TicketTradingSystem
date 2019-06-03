//Class: Withdraw
//Description: 회원 탈퇴기능을 수행하는 boundary class이다.
//Author: 문준오
#pragma once
#include "Info.h"
class WithdrawUI
{
	//Singleton 패턴을 위한 private 생성자이다.
	WithdrawUI();
	static WithdrawUI* var;
public:
	//Singleton 패턴을 위한 instance caller이다.
	static WithdrawUI& get();
	//Description: 회원가입을 처리하는 boundary method이다.
	void requestWithdraw(const Info& info);
	//Description: 소멸자이다.
	~WithdrawUI();
};

