// Class: Buyer
// Descripton: 구매자 객체를 표현하는 클래스이다. 
// Author: 문준오
#pragma once
#include <vector>
#include <memory>
#include "Info.h"
#include "Ticket.h"

class Buyer
{
	Info info;
	// UML상에서 그려진 TicketCollection으로 std::vector를 사용하였다.
	// 
	// shared_ptr는 객체의 수명이 다 할때, 자동으로 소멸자에서 delete를 호출하여 메모리를 해제한다.
	// 즉, shard_ptr의 수명은 vector에서 옮기지 않는 한 Seller와 수명을 같이한다.
	// 따라서 이는 Composition의 사용이라고 볼 수 있다. 
	std::vector<std::shared_ptr<Ticket>> tickets;
public:
	//Description: info의 getter이다.
	const Info& getInfo() const;
	//Description: tickets의 getter이다.
	std::vector<std::shared_ptr<Ticket>>& getTickets();
	//Description: 구매자가 티켓을 가지고 있는지 여부를 판단하는 method이다.
	bool empty() const;
	//Description: info instance로부터 buyer를 찾아내기 위한 보조함수이다.
	bool operator==(const Info& i) const;
	//Description: info를 기반으로 Buyer instance를 생성하는 생성자이다.
	Buyer(const Info& info);
	//Description: 소멸자이다.
	~Buyer();
};

