#pragma once
#include <vector>
#include "Info.h"
#include "TicketCollection.h"

class Buyer
{
	Info info;
	TicketCollection tickets;
public:
	const Info& getInfo() const;
	bool empty() const;
	bool operator==(const Info& i) const;
	Buyer(const Info& info);
	~Buyer();
};

