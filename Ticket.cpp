#include "Ticket.h"
#include "SearchTicketsInAuction.h"
#include "RegisterTicketManager.h"
#include <tuple>
#include <ctime>



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

std::string Ticket::getPosition() const
{
	return seatNumber;
}

Timer & Ticket::getAuctionTimer()
{
	return auctionTimer;
}

bool Ticket::isUnderAuction() const
{
	return ltaTimer.isExpired();
}

Ticket::Ticket(int price, std::string time, std::string home, std::string away, std::string position, bool useLTA)
	:price(price), time(time), home(home), away(away), seatNumber(position), useLTA(useLTA)
{
	const time_t hour = 3600;
	time_t year = hour * 24 * 365;
	historyTimer.setTimer(makeTime(parseTime(time) + year), RegisterTicketManager::deleteHistory);
	if (useLTA) {
		time_t tt = parseTime(time);
		tt -= 24 * hour;
		char buf[128];
		this->ltaTimer.setTimer(makeTime(tt), nullptr);

		tt = parseTime(time);
		tt -= 6 * hour;
		auctionTimer.setTimer(makeTime(tt), SearchTicketsInAuction::finishBidding);
	}
}

Ticket::~Ticket()
{
}

bool Ticket::isLTA() const
{
	return useLTA;
}

std::string Ticket::getAway() const
{
	return away;
}

std::ostream & operator<<(std::ostream & os, const Ticket & ticket)
{
	if (ticket.isUnderAuction()) {
		time_t remaining = parseTime(Timer::getCurrentTime()) - parseTime(ticket.ltaTimer.getDeadline());
		char buf[32];
		strftime(buf, 32, "%H:%M", localtime(&remaining));
		os << ticket.time << " " << ticket.home << " "
			<< ticket.away << " " << ticket.seatNumber << " " << buf;
	}
	else {
		os << ticket.price << " " << ticket.time << " " << ticket.home << " "
			<< ticket.away << " " << ticket.seatNumber;

	}
	return os;
}
