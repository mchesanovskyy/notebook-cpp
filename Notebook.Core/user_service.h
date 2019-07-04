#pragma once
#include "abstract_user_service.h"
#include "abstract_user_repository.h"
#include "notebook_exception.h"
#include "file_user_repository.h"

class user_service : public abstract_user_service
{
	abstract_user_repository* repository_ = new file_user_repository;

public:
	void add(user* user) override
	{
		if (user->login.empty() || user->password.empty())
			throw notebook_exception(ERR001);

		// todo: encrypt password

		repository_->add(user);
		repository_->save_changes();
	}

	user* get_user_by_credentials(string login, string password) override
	{
		const auto user = repository_->get_by_login(login);

		if (user != nullptr && user->password == password)
			return user;

		return nullptr;
	}
};
