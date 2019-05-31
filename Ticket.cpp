#include "Ticket.h"
#include "SearchTicketsInAuction.h"
#include "RegisterTicketManager.h"
#include <tuple>
#include <ctime>



bool Ticket::operator==(const Ticket& t) const
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

Timer& Ticket::getAuctionTimer()
{
	return auctionTimer;
}

Timer & Ticket::getHistoryTimer()
{
	return historyTimer;
}

Timer& Ticket::getLTATimer()
{
	return ltaTimer;
}

bool Ticket::isUnderAuction() const
{
	return ltaTimer.isExpired() && !auctionTimer.isExpired();
}

int Ticket::getPrice() const
{
	return price;
}

void Ticket::setPrice(int price)
{
	this->price = price;
}

Ticket::Ticket(int price, std::string time, std::string home, std::string away, std::string position, bool useLTA)
	:price(price), time(time), home(home), away(away), seatNumber(position), useLTA(useLTA)
{
	const time_t hour = 3600;
	time_t year = hour * 24 * 365;
	historyTimer.setTimer(Timer::makeTime(Timer::parseTime(time) + year), RegisterTicketManager::deleteHistory);
	if (useLTA) {
		time_t tt = Timer::parseTime(time);
		tt -= 24 * hour;
		this->ltaTimer.setTimer(Timer::makeTime(tt), nullptr);

		tt = Timer::parseTime(time);
		tt -= 6 * hour;
		auctionTimer.setTimer(Timer::makeTime(tt), SearchTicketsInAuction::finishBidding);
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

bool operator==(const std::shared_ptr<Ticket>& lhs, Ticket * rhs)
{
	return *lhs == *rhs;
}

std::ostream & operator<<(std::ostream & os, const Ticket & ticket)
{
	if (ticket.isUnderAuction()) {
		os << ticket.time << " " << ticket.home << " "
			<< ticket.away << " " << ticket.seatNumber;
	}
	else {
		os << ticket.price << " " << ticket.time << " " << ticket.home << " "
			<< ticket.away << " " << ticket.seatNumber;

	}
	return os;
}

std::ostream & operator<<(std::ostream & os, const Ticket * ticket)
{
	return os << *ticket;
}
