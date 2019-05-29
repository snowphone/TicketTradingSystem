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
	auto info = UserCollection::get().find(id, pw);
	if (info) {
		std::cout << id << " " << pw << std::endl;
		return info;
	}
#ifdef _DEBUG
	std::cout << "wrong id" << std::endl;
#endif
	return nullptr;
}

SignIn::~SignIn()
{
}
