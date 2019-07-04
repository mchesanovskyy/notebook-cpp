#pragma once
#include "pch.h"
#include "abstract_cmd.h"
#include "register_user_cmd.h"
#include "login_cmd.h"

class cmd_factory
{
	vector<abstract_cmd*> cmds;

public:
	cmd_factory()
	{
		cmds.push_back(new register_user_cmd);
		cmds.push_back(new login_cmd);
	}

	abstract_cmd* get_cmd_by_name(string cmd)
	{
		for (auto c : cmds)
		{
			if(is_equals_ignore_case(c->get_cmd_name(), cmd))
			{
				return c;
			}
		}
		return nullptr;
	}
};
