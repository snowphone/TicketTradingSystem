#pragma once
#include "Info.h"
class SearchRegisteredTicket
{
	SearchRegisteredTicket();
	static SearchRegisteredTicket* var;
public:
	static SearchRegisteredTicket& get();
	void search(const Info& info);
	~SearchRegisteredTicket();
};

