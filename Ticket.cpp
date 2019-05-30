#include "Ticket.h"
#include <tuple>



bool Ticket::operator==(const Ticket t) const
{
	using std::tie;
	return tie(time, home, away, seatNumber, price, useLTA) 
		== tie(t.time, t.home, t.away, t.seatNumber, t.price, t.useLTA);
}

std::string Ticket::getTime() const
{
	return time;
}

Ticket::Ticket(int price, std::string time, std::string home, std::string away, std::string position, bool useLTA)
	:price(price), time(time), home(home), away(away), seatNumber(position), useLTA(useLTA)
{
}

Ticket::~Ticket()
{
}

bool Ticket::isLTA() const
{
	return useLTA;
}

std::ostream & operator<<(std::ostream & os, const Ticket & ticket)
{
	os << ticket.price << " " << ticket.time << " " << ticket.home << " "
		<< ticket.away << " " << ticket.seatNumber;
	return os;
}
