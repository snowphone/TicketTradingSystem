#include "Info.h"




Info::Info(std::string id, std::string pw, std::string name, std::string ssn, std::string userType)
	:id(id), password(pw), name(name), ssn(ssn), userType(userType)
{
}

std::string Info::getUserType() const
{
	return this->userType;
}


Info::~Info()
{
}

std::ostream & operator<<(std::ostream & os, const Info & info)
{
	os << info.id << " " << info.password << " " << info.name << " " << info.ssn << " " << info.userType;
	return os;
}
