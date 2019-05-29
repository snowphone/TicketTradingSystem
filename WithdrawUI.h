#pragma once
#include "Info.h"
class WithdrawUI
{
	WithdrawUI();
	static WithdrawUI* var;
public:
	static WithdrawUI& get();
	void requestWithdraw(const Info& info);
	~WithdrawUI();
};

