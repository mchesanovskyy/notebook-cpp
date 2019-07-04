#pragma once
#include "abstract_user_repository.h"
#include "base_file_repository.h"

class file_user_repository :
	public virtual abstract_user_repository,
	public virtual base_file_repository<user>
{
public:
	user* get_by_login(string login) override
	{
		const auto entities = load_entities();
		for(auto user : *entities)
		{
			if(is_equals_ignore_case(user->login, login))
			{
				return user;
			}
		}
		return nullptr;
	}

protected:
	string get_file_name() override { return "users.txt"; }
	
	string to_string(user* entity) override
	{
		return std::to_string(entity->id) + delimiter
			+ entity->login + delimiter
			+ entity->password + delimiter;
	}

	user* to_entity(vector<string> values) override
	{
		auto user = new ::user;
		user->id = std::stoi(values[0]);
		user->login = values[1];
		user->password = values[2];
		return user;
	}
};
