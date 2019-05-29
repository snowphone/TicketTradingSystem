#pragma once
#include <vector>
#include "Info.h"
#include "TicketCollection.h"

class Buyer
{
	Info info;
	std::vector<Ticket>& tickets;
public:
	Buyer(const Info& info);
	~Buyer();
};

