// NotebookConsole.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "user_service.h"
#include "cmd_context.h"
#include "cmd_factory.h"

void process_exception(notebook_error_code code)
{
	switch (code)
	{
	case ERR000: cout << "Something went wrong";
		break;
	case ERR001: cout << "login or pass is empty";
		break;
	default: cout << "Internal server error!";
		break;
	}
}

int main()
{
	auto context = new cmd_context;
	context->user_service = new user_service;

	cmd_factory factory;
	while (true)
	{
		cout << "==> cmd: ";
		string cmd;
		getline(cin, cmd);

		try
		{
			auto command = factory.get_cmd_by_name(cmd);

			if (command == nullptr)
			{
				cout << "CMD not found!";
			}
			else
			{
				command->execute(context);
			}
		}
		catch (notebook_exception& ex)
		{
			process_exception(ex.code());
		}
		catch (exception& ex)
		{
			cout << ex.what();
		}

		cout << endl;
		cin.ignore();
	}
}
