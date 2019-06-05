// Class: Buyer
// Descripton: 구매자 객체를 표현하는 클래스이다. 
// Author: 유새람
#include "Buyer.h"

// Function: const Info & Buyer::getInfo() const
// Description: Buyer의 정보를 얻어오는 함수
// Return Value: Buyer의 info
// Author: 유새람
// Revisions:
//		1. When & Who: 2019/06/02 by 유새람
const Info & Buyer::getInfo() const
{	
	return this->info;	
}


// Function: std::vector<std::shared_ptr<Ticket>>& getTickets();
// Description: Buyer가 구매한 티켓들의 정보를 가져오는 함수
// Return Value: ticket collection
// Author: 유새람
// Revisions:
//		1. When & Who: 2019/06/02 by 유새람
//				What: vector를 사용해 가진 ticket들을 가져옴
std::vector<std::shared_ptr<Ticket>>& Buyer::getTickets()
{
	return tickets;		
}

// Function: bool empty() const;
// Description: Buyer가 티켓을 가지고있는지 확인하는 함수
// Return Value: Buyer의 티켓 유무 여부 (bool)
// Author: 유새람
// Revisions:
//		1. When & Who: 2019/06/02 by 유새람
//				What: tickets.empty() 호출
bool Buyer::empty() const
{
	return tickets.empty();	
}

// Function: bool operator==(const Info& i) const
// Description: info instance로부터 Buyer를 찾기위해 사용하는 함수 
// Return Value: 비교연산 (bool)
// Author: 유새람
// Revisions:
//		1. When & Who: 2019/06/02 by 유새람
//				What: 연산자 오버로딩 사용
bool Buyer::operator==(const Info& i) const
{
	return this->info == i;	//info 인스턴스 중 buyer를 찾기 위한 보조함수
}

// Function: Buyer(const Info& info)
// Description: info를 사용해 Buyer instance 생성하는 constructor
// Parameters: const Info& info- Buyer의 정보
// Return Value: Buyer instance
// Author: 유새람
// Revisions:
//		1. When & Who: 2019/06/02 by 유새람
//				What: constructor 사용
Buyer::Buyer(const Info & info) : info(info)
{
}

// Function: ~Buyer()
// Description: 소멸자
// Author: 유새람
// Revisions:
//		1. When & Who: 2019/06/02 by 유새람
Buyer::~Buyer()
{
}
