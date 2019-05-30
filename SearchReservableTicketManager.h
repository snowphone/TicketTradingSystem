#pragma once
#include <string>
#include "Info.h"
class SearchReservableTicketManager
{
	SearchReservableTicketManager();
	static SearchReservableTicketManager* var;
public:
	static SearchReservableTicketManager& get();
	~SearchReservableTicketManager();
	void show(const std::string home);
};

