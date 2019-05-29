#include "SignUpMembershipUI.h"
#include "SignUpMembership.h"
SignUpMembershipUI* SignUpMembershipUI::var = nullptr;

SignUpMembershipUI::SignUpMembershipUI()
{
}

SignUpMembershipUI& SignUpMembershipUI::get()
{
	if (!var)
		var = new SignUpMembershipUI();
	return *var;
}

void SignUpMembershipUI::requestSignUP(const Info & info)
{
	SignUpMembership::get().signUp(info);
}
