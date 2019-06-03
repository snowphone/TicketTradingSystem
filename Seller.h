//Class: Seller
//Description: 판매자 정보를 표현하는 클래스이다.
//Author: 문준오
#pragma once
#include <vector>
#include <memory>
#include "Info.h"
#include "Ticket.h"

class Seller
{
	Info info;
	// UML상에서 그려진 TicketCollection으로 std::vector를 사용하였다.
	// 
	// shared_ptr는 객체의 수명이 다 할때, 자동으로 소멸자에서 delete를 호출하여 메모리를 해제한다.
	// 즉, shard_ptr의 수명은 vector에서 옮기지 않는 한 Seller와 수명을 같이한다.
	// 따라서 이는 Composition의 사용이라고 볼 수 있다. 
	std::vector<std::shared_ptr<Ticket> > registeredTickets;
	std::vector<std::shared_ptr<Ticket> > soldTickets;
	
public:
	//Description: info를 반환하는 getter이다.
	const Info& getInfo() const;
	//Description: 등록된 티켓이 없는지 여부를 판별하는 method이다.
	bool empty() const;
	//Description: registeredTickets를 반환하는 getter이다.
	std::vector<std::shared_ptr<Ticket>>& getRegisteredTickets();
	//Description: soldTickets를 반환하는 getter이다.
	std::vector<std::shared_ptr<Ticket>>& getSoldTickets();
	//Description: 판매자의 판매중인 티켓 및 판매된 티켓을 모두 반환하는 getter이다.
	std::vector<Ticket*> getTickets();
	//Description: info객체가 판매자의 정보와 같은지를 판별하는 보조함수이다.
	bool operator==(const Info& info) const;
	//Description: info를 기반으로 판매자 객체를 생성하는 생성자이다.
	Seller(const Info& info);
	//Description: 소멸자이다.
	~Seller();
};

