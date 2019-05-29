#pragma once
#include "Info.h"
class SignOut
{
	SignOut();
	static SignOut* var;
public:
	static SignOut& get();
	void requestSignOut(const Info& info);
	~SignOut();
};

