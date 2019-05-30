#pragma once
#include <string>
#include "Info.h"
class SearchReservableTicketUI
{
	SearchReservableTicketUI();
	static SearchReservableTicketUI* var;
public:
	static SearchReservableTicketUI& get();
	void search(std::string home);
	~SearchReservableTicketUI();
};

