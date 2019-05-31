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
	bool checkID(std::string id, std::string pw) const;
	Info() = default;
	Info(std::string id, std::string pw, std::string name, 
		std::string ssn, std::string userType);
	bool operator==(const Info& i) const;
	std::string getID() const;
	std::string getUserType() const;
	~Info();
};

std::ostream& operator<<(std::ostream& os, const Info& info);
