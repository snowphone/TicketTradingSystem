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




bool Info::checkID(std::string id, std::string pw) const
{
	return this->id == id && this->password == pw; //회원정보 확인
}

Info::Info(std::string id, std::string pw, std::string name, std::string ssn, std::string userType)
	:id(id), password(pw), name(name), ssn(ssn), userType(userType) //회원가입시 필요한 정보로 Info객체를 생성하는 생성자
{
}

bool Info::operator==(const Info & i) const
{
	return std::tie(id, password, name, ssn, userType) 
		== std::tie(i.id, i.password, i.name, i.ssn, i.userType); //두 Info객체가 동일한지 판단하는 보조함수
}

std::string Info::getID() const
{
	return id; //id 리턴
}

std::string Info::getUserType() const
{
	return this->userType; //user type반환
}


Info::~Info()
{
}

std::ostream & operator<<(std::ostream & os, const Info & info)
{
	os << info.id << " " << info.password << " " << info.name << " " << info.ssn << " " << info.userType;
	return os; //정보 출력 보조
}
