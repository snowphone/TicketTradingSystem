//Class: Ticket
//Description: 티켓 정보를 표현하는 클래스이다.
//Author: 문준오
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
	//Description: 티켓간 동일 여부를 판단하는 보조함수이다.
	bool operator==(const Ticket& t) const;
	//Description: boundary를 통해 넘어온 인자를 기반으로 티켓 객체를 생성하는 생성자이다.
	Ticket(int price, std::string time, std::string home, std::string away, std::string position, bool useLTA);
	//Description: 소멸자이다.
	~Ticket();
	//Description: useLTA 멤버변수를 반환하는 getter이다.
	bool isLTA() const;
	//Description: time 변수를 반환하는 getter이다.
	std::string getTime() const;
	//Description: away 변수를 반환하는 getter이다.
	std::string getAway() const;
	//Description: seatNumber 변수를 반환하는 getter이다.
	std::string getPosition() const;
	//Description: auctionTimer 변수를 반환하는 getter이다.
	Timer& getAuctionTimer();
	//Description: historyTimer 변수를 반환하는 getter이다.
	Timer& getHistoryTimer();
	//Description: ltaTimer 변수를 반환하는 getter이다.
	Timer& getLTATimer();
	//Description: lta 옵션이 켜져있고, 현재시각이 경기시작 24시간에서 6시간 전 사이인지 판단하는 함수이다.
	bool isUnderAuction() const;
	//Description: price 변수를 반환하는 getter이다.
	int getPrice() const;
	//Description: price 변수를 설정하는 setter이다.
	void setPrice(int price);
};

//티켓 객체와 티켓 포인터간 비교연산을 위한 보조함수이다.
bool operator==(const std::shared_ptr<Ticket>& lhs, Ticket* rhs);



//티켓 객체의 출력을 위한 보조함수이다.
std::ostream& operator<<(std::ostream& os, const Ticket& ticket);
std::ostream& operator<<(std::ostream& os, const Ticket* ticket);
