#pragma once
#include "Info.h"
#include <string>
class SignInUI
{
	SignInUI();
	static SignInUI* var;
public:
	static SignInUI& get();
	const Info* requestSignIn(std::string id, std::string pw);
	~SignInUI();
};

