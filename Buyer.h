#pragma once
#include <vector>
#include <memory>
#include "Info.h"
#include "Ticket.h"

class Buyer
{
	Info info;
	std::vector<std::shared_ptr<Ticket>> tickets;
public:
	const Info& getInfo() const;
	std::vector<std::shared_ptr<Ticket>>& getTickets();
	bool empty() const;
	bool operator==(const Info& i) const;
	Buyer(const Info& info);
	~Buyer();
};

