//Class: Withdraw
//Description: 회원 탈퇴기능을 수행하는 control class이다.
//Author: 문준오
#pragma once
#include "Info.h"

class Withdraw
{
	//Description: Singleton패턴을 위한 private class이다.
	Withdraw();
	static Withdraw* var;
public:
	//Description: Singleton패턴을 위한 instance caller이다.
	static Withdraw& get();
	//Description: 회원가입을 처리하는 control method이다.
	void requestWithdraw(const Info& info);
	//Description: 소멸자이다.
	~Withdraw();
private:
	//Description: specification과 같이 판매자의 경우 등록된 티켓이 없는지를 판별하는 보조함수이다.
	bool isRemovable(const Info& info);
};

