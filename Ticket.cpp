//Class: Ticket
//Description: 티켓 정보를 표현하는 클래스이다.
//Author: 김동하
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

Timer& Ticket::getSellableTimer()
{
	return sellableTimer;
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
	//LTA 옵션이 선택되었고, 경기시작 24-6시간 전 사이인 경우 경매중이다.
	return useLTA && ltaTimer.isExpired() && !sellableTimer.isExpired();
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
	const time_t year = hour * 24 * 365;
	historyTimer.setTimer(Timer::makeTime(Timer::parseTime(time) + year));

	if (useLTA) {
		time_t tt = Timer::parseTime(time);
		tt -= 24 * hour;
		this->ltaTimer.setTimer(Timer::makeTime(tt));

		tt = Timer::parseTime(time);
		tt -= 6 * hour;
		sellableTimer.setTimer(Timer::makeTime(tt));
	} else {
		// 일반 티켓은 특별한 언급이 없으므로 경기 시작시각까지 판매 가능하도록 한다. 
		sellableTimer.setTimer(time);
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
