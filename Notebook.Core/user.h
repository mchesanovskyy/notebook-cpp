#pragma once
#include "stdafx.h"
#include "entity.h"

class user : public virtual entity
{
public:
	string login;
	string password;

	user* copy() override
	{
		const auto copy = new user;
		copy->id = id;
		copy->login = login;
		copy->password = password;
		return copy;
	}
};
