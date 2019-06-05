// Class: Seller
// Description: 판매자 정보를 표현하는 클래스이다.
// Author: 김상엽

// Revisions:
// 		1.	When & Who: 2019/06/03 by 김상엽
// 				What: create file
//
// 		2.	When & Who: 2019/06/03 by 김상엽
// 				What: add some include
//
// 		3.	When & Who: 2019/06/03 by 김상엽
// 				What: remove redundant include
//
// 		4.	When & Who: 2019/06/03 by 김상엽
// 				What: add debugging code
//
// 		5.	When & Who: 2019/06/03 by 김상엽
// 				What: complete Seller.cpp

#include "Seller.h"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

// Function: const Info & Seller::getInfo() const
// Description: info를 가져오는 함수이다.
// Author: 김상엽
// Created: 2019/06/03
// Parameters:
// Return Value: Info의 주소

// Revisions:
// 		1.	When & Who: 2019/06/03 by 김상엽
// 				What: create function

const Info & Seller::getInfo() const
{
	return this->info;
}

// Function: bool Seller::empty() const
// Description: 해당 seller의 티켓 목록이 비었는지 확인하는 함수이다.
// Author: 김상엽
// Created: 2019/06/03
// Parameters:
// Return Value: boolean 형식의 비었는지 여부

// Revisions:
// 		1.	When & Who: 2019/06/03 by 김상엽
// 				What: create function

bool Seller::empty() const
{
	return registeredTickets.empty();
}

// Function: std::vector<std::shared_ptr<Ticket>> & Seller::getRegisteredTickets()
// Description: 해당 seller의 등록된 티켓 목록을 가져오는 함수이다.
// Author: 김상엽
// Created: 2019/06/03
// Parameters:
// Return Value: vector 형식의 등록된 티켓 목록

// Revisions:
// 		1.	When & Who: 2019/06/03 by 김상엽
// 				What: create function
// 		2.	When & Who: 2019/06/03 by 김상엽
// 				What: test function

std::vector<std::shared_ptr<Ticket>> & Seller::getRegisteredTickets()
{
	return registeredTickets;
}

// Function: std::vector<std::shared_ptr<Ticket>> & Seller::getSoldTickets()
// Description: 해당 seller의 판매된 티켓 목록을 가져오는 함수이다.
// Author: 김상엽
// Created: 2019/06/03
// Parameters:
// Return Value: vector 형식의 판매된 티켓 목록

// Revisions:
// 		1.	When & Who: 2019/06/03 by 김상엽
// 				What: create function
// 		2.	When & Who: 2019/06/03 by 김상엽
// 				What: test function

std::vector<std::shared_ptr<Ticket>> & Seller::getSoldTickets()
{
	return soldTickets;
}

// Function: std::vector<Ticket*> Seller::getTickets()
// Description: 해당 seller의 티켓 목록을 가져오는 함수이다.
// Author: 김상엽
// Created: 2019/06/03
// Parameters:
// Return Value: vector 형식의 티켓 목록

// Revisions:
// 		1.	When & Who: 2019/06/03 by 김상엽
// 				What: create function
// 		2.	When & Who: 2019/06/03 by 김상엽
// 				What: test function

std::vector<Ticket*> Seller::getTickets()
{
	std::vector<Ticket*> ticketList;

	auto& registeredTickets = getRegisteredTickets();
	for (auto it = registeredTickets.begin(); it != registeredTickets.end(); ++it)
		ticketList.push_back(it->get());

	auto& soldTickets = getSoldTickets();
	for (auto it = soldTickets.begin(); it != soldTickets.end(); ++it)
		ticketList.push_back(it->get());

	return ticketList;
}

// Function: bool Seller::operator==(const Info & info) const
// Description: 비교용 operator overriding
// Author: 김상엽
// Created: 2019/06/03
// Parameters:
// Return Value: boolean 형식의 동일 여부

// Revisions:
// 		1.	When & Who: 2019/06/03 by 김상엽
// 				What: create function

bool Seller::operator==(const Info & info) const
{
	return this->info == info;
}

// Function: Seller::Seller(const Info & info) :info(info)
// Description: Seller 클래스의 생성자
// Author: 김상엽
// Created: 2019/06/03
// Parameters: const Info & info(생성될 seller의 정보)
// Return Value: Seller 클래스의 인스턴스

// Revisions:
// 		1.	When & Who: 2019/06/03 by 김상엽
// 				What: create function

Seller::Seller(const Info & info) :info(info)
{
}

// Function: Seller::~Seller()
// Description: Seller 클래스의 소멸자
// Author: 김상엽
// Created: 2019/06/03
// Parameters:
// Return Value: 

// Revisions:
// 		1.	When & Who: 2019/06/03 by 김상엽
// 				What: create function

Seller::~Seller()
{
}
