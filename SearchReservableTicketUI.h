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
	void reserve(const Info& buyerInfo, std::string time, std::string away, std::string position);
	~SearchReservableTicketUI();
};

