//Class: SignUpMembership
//Description: 회원가입을 담당하는 control class이다.
//Author: 김소연
#include <iostream>

#include "UserCollection.h"
#include "SignUpMembership.h"
#include "Seller.h"

SignUpMembership* SignUpMembership::var = nullptr;

SignUpMembership&  SignUpMembership::get()
{
	if (!var)
		var = new SignUpMembership();
	return *var;
}

void SignUpMembership::signUp(const Info & info)
{
	if (info.getUserType() == "buyer") {
		Buyer buyer(info);
		UserCollection::get().insert(buyer);
	}
	else {
		Seller seller(info);
		UserCollection::get().insert(seller);
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
