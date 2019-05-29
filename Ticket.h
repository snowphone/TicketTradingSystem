#pragma once
#include <string>
class Ticket
{
	std::string time,
		city,
		home,
		away,
		seatNumber;
	int price;
	bool useLTA;
	std::string owner;

public:
	Ticket();
	~Ticket();
};

