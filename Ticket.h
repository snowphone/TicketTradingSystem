#pragma once
#include <iostream>
#include <string>
class Ticket
{
	friend std::ostream& operator<<(std::ostream& os, const Ticket& ticket);
	std::string time,
		home,
		away,
		seatNumber;
	int price;
	bool useLTA;

public:
	bool operator==(const Ticket t) const;
	std::string getTime() const;
	Ticket(int price, std::string time, std::string home, std::string away, std::string position, bool useLTA);
	~Ticket();
};

std::ostream& operator<<(std::ostream& os, const Ticket& ticket);
