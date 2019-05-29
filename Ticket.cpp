#include "Ticket.h"



Ticket::Ticket(int price, std::string time, std::string home, std::string away, std::string position, bool useLTA)
	:price(price), time(time), home(home), away(away), seatNumber(position), useLTA(useLTA)
{
}

Ticket::~Ticket()
{
}

std::ostream & operator<<(std::ostream & os, const Ticket & ticket)
{
	os << ticket.price << " " << ticket.time << " " << ticket.home << " "
		<< ticket.away << " " << ticket.seatNumber << " " << ticket.useLTA;
	return os;
}
