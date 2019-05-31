#pragma once
#include <iostream>
#include <string>
#include "Timer.h"
class Ticket
{
	friend std::ostream& operator<<(std::ostream& os, const Ticket& ticket);
	std::string time,
		home,
		away,
		seatNumber;
	int price;
	bool useLTA;
	Timer ltaTimer;
	Timer auctionTimer;
	Timer historyTimer;

public:
	bool operator==(const Ticket& t) const;
	Ticket(int price, std::string time, std::string home, std::string away, std::string position, bool useLTA);
	~Ticket();
	bool isLTA() const;
	std::string getTime() const;
	std::string getAway() const;
	std::string getPosition() const;
	Timer& getAuctionTimer();
	Timer& gethistoryTimer();
	Timer& getLTATimer();
	bool isUnderAuction() const;
	int getPrice() const;
	void setPrice(int price);

};

bool operator==(const std::shared_ptr<Ticket>& lhs, Ticket* rhs);



std::ostream& operator<<(std::ostream& os, const Ticket& ticket);
std::ostream& operator<<(std::ostream& os, const Ticket* ticket);
