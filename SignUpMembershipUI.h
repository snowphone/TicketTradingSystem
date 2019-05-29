#pragma once

#include "Info.h"

class SignUpMembershipUI
{
private:
	SignUpMembershipUI();
	static SignUpMembershipUI* var;
public:
	static SignUpMembershipUI& get();
	void requestSignUP(const Info& info);
};

