// Class: UserCollection
// Description: 판매자 및 구매자들의 정보를 저장 및 관리하는 클래스이다.
// Created: 2019/05/29
// Author: 김동하
// mail: kdongha1995@gmail.com
//

#include <algorithm>
#include "UserCollection.h"


// Function: UserCollection()
// Description: 생성자
// Created: 2019/05/29
// Author: 김동하
UserCollection::UserCollection()
{
}

UserCollection* UserCollection::var = nullptr;

// Function: get()
// Description: Singleton을 위한 instance caller이다.
// Created: 2019/05/29
// Author: 김동하
UserCollection& UserCollection::get()
{
	if (!var)
		var = new UserCollection();
	return *var;
}

// Function: insert(const Buyer & buyer)
// Description: 새로운 구매자를 UserCollection에 추가하는 함수이다.
// Parameters: const Buyer & buyer
// Return value : void
// Created: 2019/05/29
// Author: 김동하
void UserCollection::insert(const Buyer & buyer)
{
	buyers.push_back(buyer);
}

// Function: insert(const Seller & seller)
// Description: 새로운 판매자를 UserCollection에 추가하는 함수이다.
// Parameters: const Seller & seller
// Return value : void
// Created: 2019/05/29
// Author: 김동하
void UserCollection::insert(const Seller & seller)
{
	sellers.push_back(seller);
}


// Function: erase(const Info & info)
// Description: info에 해당하는 판매자 혹은 구매자 정보를 user collection에서 삭제하는 함수이다.
// Parameters: const Info & info - information of sellor or buyer
// Return value : void
// Created: 2019/05/29
// Author: 김동하
void UserCollection::erase(const Info & info)
{
	if (info.getUserType() == "seller") {
		auto it = std::find_if(sellers.begin(), sellers.end(), [&info](const Seller& i) { return i == info; });
		sellers.erase(it);
	}
	else {
		auto it = std::find_if(buyers.begin(), buyers.end(), [&info](const Buyer& i) { return i == info; });
		buyers.erase(it);
	}
}

// Function: getSellers()
// Description: 판매자 리스트를 반환하는 getter이다.
// Parameters: void
// Return value : sellors - sellors list
// Created: 2019/05/29
// Author: 김동하
std::vector<Seller>& UserCollection::getSellers()
{
	return sellers;
}

// Function: getBuyers()
// Description: 구매자 리스트를 반환하는 getter이다.
// Parameters: void
// Return value : buyers - buyers list
// Created: 2019/05/29
// Author: 김동하
std::vector<Buyer>& UserCollection::getBuyers()
{
	return buyers;
}

// Function: getReservableTickets(const std::string& home)
// Description: 모든 판매자로부터 판매중인 티켓을 모아 시간순으로 정렬하여 반환하는 함수이다.
// Parameters: const std::string& home
// Return value : reservableTickets
// Created: 2019/05/29
// Author: 김동하
std::vector<Ticket*> UserCollection::getReservableTickets(const std::string& home)
{
	std::vector<Ticket*> reservableTickets;
	//모든 판매자로부터
	for (Seller& seller : sellers) {
		//판매중인 티켓 선택
		std::vector<std::shared_ptr<Ticket>>& tickets = seller.getRegisteredTickets();

		for (auto it = tickets.begin(); it != tickets.end(); ++it)
		{
			reservableTickets.push_back(it->get());
		}
	}
	//시간순 정렬
	sort(reservableTickets.begin(), reservableTickets.end(), [](Ticket* lhs, Ticket* rhs) { return lhs->getTime() < rhs->getTime(); });

	return reservableTickets;
}

// Function: find(std::string id, std::string pw)
// Description: user collection에 해당 (id, pw)를 가지는 계정이 있는지 확인하고, 있는 경우 해당 계정의 info를 반환한다. 
//		계정이 없는 경우는 null을 반환한다.
// Parameters: 	std::string id
//		std::string pw
// Return value : 	&buyerIter->getInfo() - 계정이 있는 경우
//			nullptr - 계정이 없는 경우
// Created: 2019/05/29
// Author: 김동하
const Info * UserCollection::find(std::string id, std::string pw)
{
	auto buyerIter = std::find_if(buyers.begin(), buyers.end(), 
		[&id, &pw](const Buyer& i) { return i.getInfo().checkID(id, pw); });
	if (buyerIter != buyers.end())
		return &buyerIter->getInfo();

	auto sellerIter = std::find_if(sellers.begin(), sellers.end(), 
		[&id, &pw](const Seller& i) { return i.getInfo().checkID(id, pw); });
	if (sellerIter != sellers.end())
		return &sellerIter->getInfo();

	return nullptr;

}

// Function: operator[](const Info & info)
// Description:	UML의 getSeller 및 getBuyer에 해당하는 method로, 주어진 info와 동일한 회원정보인 회원을 반환한다.
//		C++에서는 반환값만으로 method signature을 구분할 수 없어, 오버로딩 대신 std::variant를 이용하였다.
// Parameters: 	const Info & info - information of member
// Return value : 	&*find_if(sellers.begin(), sellers.end(), [&info](const Seller& i) {return i == info; }) - sellor
//			&*find_if(buyers.begin(), buyers.end(), [&info](const Buyer& i) {return i == info; }) - buyer
// Created: 2019/05/29
// Author: 김동하
std::variant<Seller*, Buyer*> UserCollection::operator[](const Info & info)
{
	if (info.getUserType() == "seller") {
		return &*find_if(sellers.begin(), sellers.end(), [&info](const Seller& i) {return i == info; });
	}
	else {
		return &*find_if(buyers.begin(), buyers.end(), [&info](const Buyer& i) {return i == info; });
	}
}

// Function: size() const
// Description:	전체 회원수를 반환하는 getter이다.
// Parameters: 	void
// Return value : sellers.size() + buyers.size() - total member
// Created: 2019/05/29
// Author: 김동하
size_t UserCollection::size() const
{
	return sellers.size() + buyers.size();
}

// Function: ~UserCollection()
// Description:	소멸자
// Created: 2019/05/29
// Author: 김동하
UserCollection::~UserCollection()
{
}
