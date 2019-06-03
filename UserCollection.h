//Class: UserCollection
//Description: 판매자 및 구매자들의 정보를 저장 및 관리하는 클래스이다.
//Author: 문준오
#pragma once
#include <vector>
#include <algorithm>
#include <variant>

#include "Buyer.h"
#include "Seller.h"

class UserCollection
{
	static UserCollection* var;
	std::vector<Seller> sellers;
	std::vector<Buyer> buyers;
	//Description: Singleton을 위한 private 생성자이다.
	UserCollection();
public:
	//Description: Singleton을 위한 instance caller이다.
	static UserCollection& get();
	//Description: 새로운 구매자를 UserCollection에 추가하는 함수이다.
	void insert(const Buyer& buyer);
	//Description: 새로운 판매자를 UserCollection에 추가하는 함수이다.
	void insert(const Seller& seller);
	//Description: info에 해당하는 판매자 혹은 구매자 정보를 user collection에서 삭제하는 함수이다.
	void erase(const Info& info);
	//Description: 판매자 리스트를 반환하는 getter이다.
	std::vector<Seller>& getSellers();
	//Description: 구매자 리스트를 반환하는 getter이다.
	std::vector<Buyer>& getBuyers();
	//Description: 모든 판매자로부터 판매중인 티켓을 모아 시간순으로 정렬하여 반환하는 함수이다.
	std::vector<Ticket*> getReservableTickets(const std::string& home);
	//Description: user collection에 해당 (id, pw)를 가지는 계정이 있는지 확인하고, 있는 경우 해당 계정의 info를 반환한다. 
	//				계정이 없는 경우는 null을 반환한다.
	const Info* find(std::string id, std::string pw);
	//Description: UML의 getSeller 및 getBuyer에 해당하는 method로, 주어진 info와 동일한 회원정보인 회원을 반환한다.
	//				C++에서는 반환값만으로 method signature을 구분할 수 없어, 오버로딩 대신 std::variant를 이용하였다.
	std::variant<Seller*, Buyer*> operator[](const Info& info);
	//Description: 전체 회원수를 반환하는 getter이다.
	size_t size() const;
	//Description: 소멸자이다.
	~UserCollection();
};

