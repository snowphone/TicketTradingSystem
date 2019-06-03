//Class: SignUpMembership
//Description: 회원가입을 담당하는 boundary class이다.
//Author: 김소연
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
