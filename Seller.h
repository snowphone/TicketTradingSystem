#pragma once
#include "Info.h"
#include "TicketCollection.h"

class Seller
{
	Info info;
	TicketCollection registeredTickets;
	TicketCollection soldTickets;
	
public:
	void printTickets() const;
	const Info& getInfo() const;
	bool empty() const;
	TicketCollection& getRegisteredTickets();
	TicketCollection& getSoldTickets();
	bool operator==(const Info& info) const;
	Seller(const Info& info);
	~Seller();
};

