#pragma once
#include <vector>

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
	size_t size() const;
	~UserCollection();
};

