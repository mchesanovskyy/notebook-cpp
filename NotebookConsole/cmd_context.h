#pragma once
#include "abstract_user_service.h"

class cmd_context
{
public:
	abstract_user_service* user_service;
	user* current_user;

	bool is_authorized()
	{
		return current_user != nullptr;
	}
};
