//Class: SignUpMembership
//Description: 회원가입을 담당하는 boundary class이다.
//Author: 김소연
// Created: 2019/06/01
// Mail: 96syk@naver.com

// Revisions:
// 		1.	When & Who: 2019/06/01 by 김소연
// 				What: create file

#include "SignUpMembershipUI.h"
#include "SignUpMembership.h"


// Function: static SignUpMembershipUI* var
// Description: Singleton 패턴을 위한 private instance
// Author: 김소연
// Revisions:
//		1. When & Who: 2019/06/01 by 김소연
SignUpMembershipUI* SignUpMembershipUI::var = nullptr;



// Function: SignUpMembershipUI()
// Description: Singleton 패턴을 위한 private 생성자
// Author: 김소연
// Revisions:
//		1. When & Who: 2019/06/01 by 김소연
SignUpMembershipUI::SignUpMembershipUI()
{
}



// Function: static SignUpMembershipUI& get()
// Description: Singleton 패턴을 위한 instance caller
// Author: 김소연
// Revisions:
//		1. When & Who: 2019/06/01 by 김소연
SignUpMembershipUI& SignUpMembershipUI::get()
{
	if (!var)
		var = new SignUpMembershipUI();
	return *var;
}



// Function: void requestSignUP(const Info& info)
// Description: 회원가입을 담당하는 boundary class
// Author: 김소연
// Parameter: const Info & info -회원정보
// Return value: void
// Revisions:
//		1. When & Who: 2019/06/01 by 김소연
void SignUpMembershipUI::requestSignUP(const Info & info)
{
	SignUpMembership::get().signUp(info);
}
