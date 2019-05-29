#pragma once
#include "Info.h"
#include "TicketCollection.h"

class Seller
{
	Info info;
	std::vector<Ticket> tickets;
public:
	const Info& getInfo() const;
	bool empty() const;
	bool operator==(const Info& info) const;
	Seller(const Info& info);
	~Seller();
};

