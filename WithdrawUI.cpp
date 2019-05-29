#include "WithdrawUI.h"
#include "Withdraw.h"



WithdrawUI::WithdrawUI()
{
}


WithdrawUI* WithdrawUI::var = nullptr;
WithdrawUI & WithdrawUI::get()
{
	if (!var)
		var = new WithdrawUI();
	return *var;
}

void WithdrawUI::requestWithdraw(const Info & info)
{
	Withdraw::get().requestWithdraw(info);
}

WithdrawUI::~WithdrawUI()
{
}
