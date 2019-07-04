#pragma once
#include "abstract_cmd.h"
#include "pch.h"
class register_user_cmd : public abstract_cmd
{
public:
	string get_cmd_name() override
	{
		return "register";
	}

	void execute(cmd_context* context) override
	{
		auto user = new ::user;

		cout << "Username: ";
		cin >> user->login;

		cout << "Password: ";
		cin >> user->password;

		string confirm_pwd;
		cout << "Confirm Password: ";
		cin >> confirm_pwd;

		if(user->password  != confirm_pwd)
		{
			cout << "Confirm Password != password";
			return;
		}

		context->user_service->add(user);
		cout << "user created! enter 'login'";
	}
};
