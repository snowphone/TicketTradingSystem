#pragma once
#include <string>
#include <algorithm>
#include <vector>
#include "Info.h"
#include "Ticket.h"
class SearchReservableTicketManager
{
	SearchReservableTicketManager();
	static SearchReservableTicketManager* var;
	std::vector<Ticket*> watchingTickets;
public:
	static SearchReservableTicketManager& get();
	~SearchReservableTicketManager();
	void show(const std::string home);
	void reserve(const Info& buyerInfo, std::string time, std::string away, std::string position);
};

