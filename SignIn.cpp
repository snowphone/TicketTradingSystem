//Class: SignIn
//Description: 로그인 기능을 담당하는 control class이다.
//Author: 김소연
// Created: 2019/06/01
// Mail: 96syk@naver.com

// Revisions:
// 		1.	When & Who: 2019/06/01 by 김소연
// 				What: create file
//
// 		2.	When & Who: 2019/06/03 by 김소연
// 				What: modify some errors
#include "SignIn.h"
#include "UserCollection.h"
#include <algorithm>


// Function: SignIn()
// Description: Singleton을 위한 private 생성자
// Author: 김소연
// Revisions:
//		1. When & Who: 2019/06/01 by 김소연
SignIn::SignIn()
{
}



// Function: static SignInUI* var;
// Description: Singleton을 적용한 private instance 변수
// Author: 김소연
// Revisions:
//		1. When & Who: 2019/06/01 by 김소연
SignIn* SignIn::var = nullptr;




// Function: static SignInUI& get();
// Description: Singleton을 위한 instance caller
// Author: 김소연
// Revisions:
//		1. When & Who: 2019/06/01 by 김소연
SignIn & SignIn::get()
{
	if (!var)
		var = new SignIn();
	return *var; //instance caller
}




// Function: const Info* requestSignIn(std::string id, std::stringpw);
// Description: 로그인을 담당하는 boundary method
// Author: 김소연
// Revisions:
//		1. When & Who: 2019/06/01 by 김소연
const Info * SignIn::putIdPw(std::string id, std::string pw)
{
	std::cout << "2.1. 로그인" << std::endl
		<< "> ";
	auto info = UserCollection::get().find(id, pw);
	if (info) {
		std::cout << id << " " << pw << std::endl;
	}
	return info; //로그인 
}





// Function: ~SignInUI()
// Description: 소멸자
// Author: 김소연
// Revisions:
//		1. When & Who: 2019/06/01 by 김소연
SignIn::~SignIn()
{
}
