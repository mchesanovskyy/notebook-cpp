#pragma once
#include "user.h"

class abstract_user_service
{
public:
	virtual ~abstract_user_service() = default;
	virtual void add(user* user) = 0;
	virtual user* get_user_by_credentials(string login, string password) = 0;
};
