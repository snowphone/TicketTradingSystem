#include "SignIn.h"
#include "UserCollection.h"
#include <algorithm>



SignIn::SignIn()
{
}


SignIn* SignIn::var = nullptr;
SignIn & SignIn::get()
{
	if (!var)
		var = new SignIn();
	return *var;
}

const Info * SignIn::putIdPw(std::string id, std::string pw)
{
	std::cout << "2.1. 로그인" << std::endl
		<< "> ";
	auto info = UserCollection::get().find(id, pw);
	if (info) {
		std::cout << id << " " << pw << std::endl;
		return info;
	}
	return nullptr;
}

SignIn::~SignIn()
{
}
