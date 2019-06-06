// Class: Info
// Description: 구매자 및 판매자가 공통적으로 가지는 회원 정보를 모은 클래스이다.
// Author: 김소연
// Created: 2019/06/01
// Mail: 96syk@naver.com

// Revisions:
// 		1.	When & Who: 2019/06/01 by 김소연
// 				What: create file
//
// 		2.	When & Who: 2019/06/02 by 김소연
// 				What: modify some errors and add comments
#include "Info.h"
#include <tuple>



// Function: bool checkID(std::string id, std::string pw) const
// Description: 로그인을 위해 id 및 pw를 입력하였을 때 이와 일치하는지 여부를 반환하는 함수
// Author: 김소연
// Revisions:
//		1. When & Who: 2019/06/01 by 김소연
bool Info::checkID(std::string id, std::string pw) const
{
	return this->id == id && this->password == pw; //회원정보 확인
}

// Function: Info(std::string id, std::string pw, std::string name, std::string ssn, std::string userType)
// Description: 회원가입시 필요한 정보로 Info 객체를 만드는 생성자
// Author: 김소연
// Revisions:
//		1. When & Who: 2019/06/01 by 김소연

Info::Info(std::string id, std::string pw, std::string name, std::string ssn, std::string userType)
	:id(id), password(pw), name(name), ssn(ssn), userType(userType) //회원가입시 필요한 정보로 Info객체를 생성하는 생성자
{
}


// Function: bool operator==(const Info & i) const
// Description: 두 Info 객체가 동일한지 판단하는 보조함수
// Author: 김소연
// Revisions:
//		1. When & Who: 2019/06/01 by 김소연
bool Info::operator==(const Info & i) const
{
	return std::tie(id, password, name, ssn, userType) 
		== std::tie(i.id, i.password, i.name, i.ssn, i.userType); //두 Info객체가 동일한지 판단하는 보조함수
}


// Function: std::string Info::getID() const
// Description: id를 반환하는 getter
// Author: 김소연
// Revisions:
//		1. When & Who: 2019/06/01 by 김소연
std::string Info::getID() const
{
	return id; //id 리턴
}

// Function: std::string Info::getUserType() const
// Description: user type을 반환하는 getter
// Author: 김소연
// Revisions:
//		1. When & Who: 2019/06/01 by 김소연
std::string Info::getUserType() const
{
	return this->userType; //user type반환
}



// Function: ~Info()
// Description: 소멸자
// Author: 김소연
// Revisions:
//		1. When & Who: 2019/06/01 by 김소연
Info::~Info()
{
}



// Function: std::ostream & operator<<(std::ostream & os, const Info & info)
// Description: 출력을 위한 보조함수
// Author: 김소연
// Revisions:
//		1. When & Who: 2019/06/01 by 김소연
std::ostream & operator<<(std::ostream & os, const Info & info)
{
	os << info.id << " " << info.password << " " << info.name << " " << info.ssn << " " << info.userType;
	return os; //정보 출력 보조
}
