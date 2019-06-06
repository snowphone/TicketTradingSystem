//Class: SignUpMembership
//Description: 회원가입을 담당하는 control class이다.
//Author: 김소연
// Created: 2019/06/01
// Mail: 96syk@naver.com

// Revisions:
// 		1.	When & Who: 2019/06/01 by 김소연
// 				What: create file

#include <iostream>

#include "UserCollection.h"
#include "SignUpMembership.h"
#include "Seller.h"


// Function: static SignUpMembership* var
// Description: singleton을 위한 private instance 변수
// Author: 김소연
// Revisions:
//		1. When & Who: 2019/06/01 by 김소연
SignUpMembership* SignUpMembership::var = nullptr;


// Function: static SignUpMembership& get()
// Description:Singleton 패턴을 위한 instance caller
// Author: 김소연
// Revisions:
//		1. When & Who: 2019/06/01 by 김소연
SignUpMembership&  SignUpMembership::get()
{
	if (!var)
		var = new SignUpMembership();
	return *var;
}



// Function: void signUp(const Info& info)
// Description: 회원가입을 수행하는 control method
// Author: 김소연
// Revisions:
//		1. When & Who: 2019/06/01 by 김소연
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


// Function: SignUpMembership()
// Description: Singleton 패턴을 위한 private 생성자
// Author: 김소연
// Revisions:
//		1. When & Who: 2019/06/01 by 김소연
SignUpMembership::SignUpMembership()
{
}



// Function: ~SignUpMembership()
// Description: 소멸자
// Author: 김소연
// Revisions:
//		1. When & Who: 2019/06/01 by 김소연
SignUpMembership::~SignUpMembership()
{
}
