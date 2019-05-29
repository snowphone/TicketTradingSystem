#pragma once
#include "Info.h"
class SignOutUI
{
	SignOutUI();
	static SignOutUI* var;
public:
	void requestSignOut(const Info& info);
	static SignOutUI& get();
	~SignOutUI();
};

