#pragma once
#include "Info.h"
class SearchRegisteredTicketUI
{
	SearchRegisteredTicketUI();
	static SearchRegisteredTicketUI* var;
public:
	static SearchRegisteredTicketUI& get();
	void search(const Info& info);
	~SearchRegisteredTicketUI();
};

