#include "Info.h"
#include <tuple>




bool Info::checkID(std::string id, std::string pw) const
{
	return this->id == id && this->password == pw;
}

Info::Info(std::string id, std::string pw, std::string name, std::string ssn, std::string userType)
	:id(id), password(pw), name(name), ssn(ssn), userType(userType)
{
}

bool Info::operator==(const Info & i) const
{
	return std::tie(id, password, name, ssn, userType) 
		== std::tie(i.id, i.password, i.name, i.ssn, i.userType);
}

std::string Info::getID() const
{
	return id;
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
