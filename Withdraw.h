#pragma once
#include "Info.h"

class Withdraw
{
	Withdraw();
	static Withdraw* var;
public:
	static Withdraw& get();
	void requestWithdraw(const Info& info);
	~Withdraw();
private:
	bool isRemovable(const Info& info);
};

