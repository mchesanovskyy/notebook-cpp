#pragma once
#include "pch.h"
#include "abstract_cmd.h"

class login_cmd : public abstract_cmd
{
public:
	string get_cmd_name() override { return "login"; }
	void execute(cmd_context* context) override
	{
		string login;
		cout << "Username: ";
		cin >> login;

		string plainTextPassword;
		cout << "Password: ";
		cin >> plainTextPassword;

		auto user = context->user_service->get_user_by_credentials(login, plainTextPassword);
		if (user == nullptr)
		{
			cout << "Login or pass is wrong";
		}
		else
		{
			context->current_user = user;
			cout << "Welcome, " << user->login;
		}
	}
};
