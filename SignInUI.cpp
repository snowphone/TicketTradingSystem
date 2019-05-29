#include "SignInUI.h"
#include "SignIn.h"



SignInUI::SignInUI()
{
}


SignInUI* SignInUI::var = nullptr;
SignInUI & SignInUI::get()
{
	if (!var)
		var = new SignInUI();
	return *var;
}

const Info * SignInUI::requestSignIn(std::string id, std::string pw)
{
	return SignIn::get().putIdPw(id, pw);
}

SignInUI::~SignInUI()
{
}
