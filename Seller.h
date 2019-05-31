#pragma once
#include <vector>
#include <memory>
#include "Info.h"
#include "Ticket.h"

class Seller
{
	Info info;
	std::vector<std::shared_ptr<Ticket> > registeredTickets;
	std::vector<std::shared_ptr<Ticket> > soldTickets;
	
public:
	const Info& getInfo() const;
	bool empty() const;
	std::vector<std::shared_ptr<Ticket>>& getRegisteredTickets();
	std::vector<std::shared_ptr<Ticket>>& getSoldTickets();
	bool operator==(const Info& info) const;
	Seller(const Info& info);
	~Seller();
};

