#include "Withdraw.h"
#include "UserCollection.h"
#include "TicketCollection.h"



Withdraw::Withdraw()
{
}


Withdraw* Withdraw::var = nullptr;
Withdraw & Withdraw::get() {
	if (!var)
		var = new Withdraw();
	return *var;
}

void Withdraw::requestWithdraw(const Info & info) {
	if (isRemovable(info)) {
		std::cout << info.getID() << std::endl;
		UserCollection::get().erase(info);
	}
	else {
#ifdef _DEBUG
		std::cout << "ERROR" << std::endl;
#endif
	}
}

Withdraw::~Withdraw()
{
}

bool Withdraw::isRemovable(const Info & info)
{
	if (info.getUserType() == "buyer")
		return true;
	/* Else: Seller */
	auto user = UserCollection::get().at(info);
	return std::get<Seller*>(user)->empty();
}
