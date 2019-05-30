#pragma once
#include <vector>
#include <algorithm>
#include <variant>

#include "Seller.h"
#include "Buyer.h"

class UserCollection
{
	static UserCollection* var;
	std::vector<Seller> sellers;
	std::vector<Buyer> buyers;
	UserCollection();
public:
	static UserCollection& get();
	void insert(const Seller& seller);
	void insert(const Buyer& buyer);
	void erase(const Info& info);
	std::vector<Seller>& getSellers();
	std::vector<Buyer>& getBuyers();
	std::vector<Ticket*> getReservableTickets(const std::string& home);
	const Info* find(std::string id, std::string pw);
	const Info* find(std::string id);
	std::variant<Seller*, Buyer*> at(const Info& info);
	size_t size() const;
	~UserCollection();
};

