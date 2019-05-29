#pragma once
#include "Info.h"
class RegisterTicketManager
{
	RegisterTicketManager();
	static RegisterTicketManager* var;

	const Info* currentUser = nullptr;
public:
	static RegisterTicketManager& get();
	void addNewTicket(const Info * currentUser, int price,
 std::string time,
		std::string home, std::string away, std::string position, bool useLTA);
	~RegisterTicketManager();
};

