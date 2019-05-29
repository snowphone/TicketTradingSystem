#pragma once
#include "SignInUI.h"
class SignIn
{
	SignIn();
	static SignIn* var;
public:
	static SignIn& get();
	const Info* putIdPw(std::string id, std::string pw);

	~SignIn();
};

