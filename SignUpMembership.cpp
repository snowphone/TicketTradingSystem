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
		UserCollection::get().getBuyers().push_back(buyer);
	}
	else {
		Seller seller(info);
		UserCollection::get().getSellers().push_back(seller);
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
