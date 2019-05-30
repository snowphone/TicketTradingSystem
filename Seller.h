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
	const TicketCollection& getRegisteredTickets() const;
	void addTicket(const Ticket ticket);
	bool operator==(const Info& info) const;
	Seller(const Info& info);
	~Seller();
};

