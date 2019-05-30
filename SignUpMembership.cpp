#include "SignUpMembership.h"
#include "UserCollection.h"
#include "Seller.h"

#include <iostream>

SignUpMembership* SignUpMembership::var = nullptr;

SignUpMembership&  SignUpMembership::get()
{
	if (!var)
		var = new SignUpMembership();
	return *var;
}

void SignUpMembership::signUp(const Info & info)
{
	if (info.getUserType() == "seller") {
		UserCollection::get().insert(Seller(info));
	}
	else {
		UserCollection::get().insert(Buyer(info));
	}
	std::cout << "1.1. 회원가입" << std::endl
		<< "> " << info << std::endl;
}



SignUpMembership::SignUpMembership()
{
}


SignUpMembership::~SignUpMembership()
{
}
