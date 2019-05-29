#pragma once
#include <string>
#include "Info.h"
class RegisterTicketUI
{
	RegisterTicketUI();
	static RegisterTicketUI* var;
public:
	static RegisterTicketUI& get();
	void createNewTicket(const Info* user, int price, std::string time,
		std::string home, std::string away, std::string position, bool useLTA);
	~RegisterTicketUI();
};

