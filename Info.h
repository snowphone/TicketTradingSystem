// Class: Info
// Description: 구매자 및 판매자가 공통적으로 가지는 회원 정보를 모은 클래스이다.
// Author: 문준오
#pragma once
#include <string>
#include <iostream>
class Info
{
	friend std::ostream& operator<<(std::ostream& os, const Info& info);
	std::string id,
		password,
		name,
		ssn,
		userType;

public:
	//Description: 로그인을 위해 id 및 pw를 입력하였을 때 이와 일치하는지 여부를 반환하는 함수이다.
	bool checkID(std::string id, std::string pw) const;
	//Description: 회원가입시 필요한 정보로 Info 객체를 만드는 생성자이다.
	Info(std::string id, std::string pw, std::string name, std::string ssn, std::string userType);
	//Description: 두 Info 객체가 동일한지 판단하는 보조함수이다.
	bool operator==(const Info& i) const;
	//Description: id를 반환하는 getter이다.
	std::string getID() const;
	//Description: user type을 반환하는 getter이다.
	std::string getUserType() const;
	//Description: 소멸자이다.
	~Info();
};

//Description: 출력을 위한 보조함수이다.
std::ostream& operator<<(std::ostream& os, const Info& info);
