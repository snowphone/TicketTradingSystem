// Class: Ticket
// Description: 티켓 정보를 표현하는 클래스이다.
// Created: 2019/05/29
// Author: 김동하
// mail: kdongha1995@gmail.com
//
// Revisions:
//	1. When & Who: 2019/06/01 by 김동하
//	    What: modified Ticket
//		  added comments
//
#include "Ticket.h"
#include "SearchTicketsInAuction.h"
#include "RegisterTicketManager.h"
#include <tuple>
#include <ctime>



// Function: Ticket::operator==(const Ticket& t) const
// Description: 티켓간 동일 여부를 판단하는 보조함수이다.
// Parameters: const Ticket& t - ticket
// Return Value: bool
// Created: 2019/05/29
// Author: 김동하
bool Ticket::operator==(const Ticket& t) const
{
	using std::tie;
	return tie(time, home, away, seatNumber, price, useLTA)
		== tie(t.time, t.home, t.away, t.seatNumber, t.price, t.useLTA);
}

// Function: getTime() const
// Description: time 변수를 반환하는 getter이다.
// Parameters: void
// Return Value: time
// Created: 2019/05/29
// Author: 김동하
std::string Ticket::getTime() const
{
	return time;
}

// Function: getPosition() const
// Description: seatNumber 변수를 반환하는 getter이다.
// Parameters: void
// Return Value: seatNumber
// Created: 2019/05/29
// Author: 김동하
std::string Ticket::getPosition() const
{
	return seatNumber;
}

// Function: getSellableTimer()
// Description: sellableTimer 변수를 반환하는 getter이다.
// Parameters: void
// Return Value: Timer
// Created: 2019/05/29
// Author: 김동하
Timer& Ticket::getSellableTimer()
{
	return sellableTimer;
}

// Function: getHistoryTimer()
// Description: historyTimer 변수를 반환하는 getter이다.
// Parameters: void
// Return Value: historyTimer
// Created: 2019/05/29
// Author: 김동하
Timer & Ticket::getHistoryTimer()
{
	return historyTimer;
}

// Function: getLTATimer()
// Description: ltaTimer 변수를 반환하는 getter이다.
// Parameters: void
// Return Value: ltaTimer
// Created: 2019/05/29
// Author: 김동하
Timer& Ticket::getLTATimer()
{
	return ltaTimer;
}

// Function: isUnderAuction() const
// Description: lta 옵션이 켜져있고, 현재시각이 경기시작 24시간에서 6시간 전 사이인지 판단하는 함수이다.
// Parameters: void
// Return Value: bool
// Created: 2019/05/29
// Author: 김동하
bool Ticket::isUnderAuction() const
{
	return useLTA && ltaTimer.isExpired() && !sellableTimer.isExpired();
}

// Function: getPrice() const
// Description: price 변수를 반환하는 getter이다.
// Parameters: void
// Return Value: price
// Created: 2019/05/29
// Author: 김동하
int Ticket::getPrice() const
{
	return price;
}

// Function: setPrice() const
// Description: price 변수를 설정하는 setter이다.
// Parameters: int price
// Return Value: void
// Created: 2019/05/29
// Author: 김동하
void Ticket::setPrice(int price)
{
	this->price = price;
}

Ticket::Ticket(int price, std::string time, std::string home, std::string away, std::string position, bool useLTA)
	:price(price), time(time), home(home), away(away), seatNumber(position), useLTA(useLTA)
{
	const time_t hour = 3600;
	time_t year = hour * 24 * 365;
	historyTimer.setTimer(Timer::makeTime(Timer::parseTime(time) + year));
	if (useLTA) {
		time_t tt = Timer::parseTime(time);
		tt -= 24 * hour;
		this->ltaTimer.setTimer(Timer::makeTime(tt));

		tt = Timer::parseTime(time);
		tt -= 6 * hour;
		sellableTimer.setTimer(Timer::makeTime(tt));
	} else {
		//일반 티켓은 특별한 언급이 없으므로 경기 시작시각까지 판매 가능하도록 한다.
		sellableTimer.setTimer(time);
	}
}

// Function: ~Ticket()
// Description: 소멸자
// Created: 2019/05/29
// Author: 김동하
Ticket::~Ticket()
{
}

// Function: isLTA() const
// Description: useLTA 멤버변수를 반환하는 getter이다.
// Parameters: void
// Return Value: bool
// Created: 2019/05/29
// Author: 김동하
bool Ticket::isLTA() const
{
	return useLTA;
}

// Function: getAway() const
// Description: away 변수를 반환하는 getter이다.
// Parameters: void
// Return Value: away - away team
// Created: 2019/05/29
// Author: 김동하
std::string Ticket::getAway() const
{
	return away;
}

// Function: operator==(const std::shared_ptr<Ticket>& lhs, Ticket * rhs)
// Description: 티켓 객체와 티켓 포인터간 비교연산을 위한 보조함수이다.
// Parameters: 	const std::shared_ptr<Ticket>& lhs - 
//		Ticket * rhs
// Return Value: *lhs == *rhs
// Created: 2019/05/29
// Author: 김동하
bool operator==(const std::shared_ptr<Ticket>& lhs, Ticket * rhs)
{
	return *lhs == *rhs;
}

// Function: operator<<(std::ostream & os, const Ticket & ticket)
// Description: 티켓 객체의 출력을 위한 보조함수이다.
// Parameters: 	std::ostream & os 
//		const Ticket & ticket 
// Return Value: os
// Created: 2019/05/29
// Author: 김동하
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

// Function: operator<<(std::ostream & os, const Ticket & ticket)
// Description: 티켓 객체의 출력을 위한 보조함수이다.
// Parameters: 	std::ostream & os 
//		const Ticket * ticket 
// Return Value: os << *ticket
// Created: 2019/05/29
// Author: 김동하
std::ostream & operator<<(std::ostream & os, const Ticket * ticket)
{
	return os << *ticket;
}