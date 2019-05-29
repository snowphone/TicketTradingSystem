#include "SignOutUI.h"
#include "SignOut.h"


SignOutUI::SignOutUI()
{
}


SignOutUI* SignOutUI::var = nullptr;
void SignOutUI::requestSignOut(const Info & info)
{
	SignOut::get().requestSignOut(info);
}
SignOutUI & SignOutUI::get()
{
	if (!var)
		var = new SignOutUI();
	return *var;
}

SignOutUI::~SignOutUI()
{
}
