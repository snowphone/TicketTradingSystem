#pragma once
#include "Info.h"
#include "TicketCollection.h"

class Seller
{
	Info info;
	std::vector<Ticket>& tickets;
public:
	Seller(const Info& info);
	~Seller();
};

