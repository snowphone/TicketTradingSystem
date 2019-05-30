#pragma once
#include "Info.h"

class BookedTicketManagerUI
{
	BookedTicketManagerUI();
	static BookedTicketManagerUI* var;
public:
	static BookedTicketManagerUI& get();
	void search(const Info& buyerInfo);
	~BookedTicketManagerUI();
};

