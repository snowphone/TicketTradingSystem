#pragma once
#include "Info.h"

class BookedTicketManager
{
	BookedTicketManager();
	static BookedTicketManager* var;
public:
	static BookedTicketManager& get();
	void print(const Info& buyerInfo);
	~BookedTicketManager();
};

