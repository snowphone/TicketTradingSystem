#pragma once
#include "Info.h"

class SignUpMembership
{
	static SignUpMembership* var;
	SignUpMembership();
public:
	static SignUpMembership& get();
	void signUp(const Info& info);
	~SignUpMembership();
};

