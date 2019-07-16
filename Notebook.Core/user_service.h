#pragma once
#include "abstract_user_service.h"
#include "abstract_user_repository.h"
#include "notebook_exception.h"
#include "file_user_repository.h"
#include "hash_helper.h"
#include "hash_algorithm.h"

class user_service : public abstract_user_service
{
	abstract_user_repository* repository_ = new file_user_repository;

public:
	void add(user* user) override
	{
		if (user->login.empty() || user->password.empty())
			throw notebook_exception(ERR001);

		const auto encrypted_password = encrypt_user_password(user->password);
		user->password = encrypted_password;

		repository_->add(user);
		repository_->save_changes();
	}

	user* get_user_by_credentials(string login, string password) override
	{
		const auto user = repository_->get_by_login(login);

		if (user == nullptr)
			return nullptr;

		const auto encrypted_entered_pwd = encrypt_user_password(password);
		if (user != nullptr && user->password == encrypted_entered_pwd)
			return user;

		return nullptr;
	}

private:
	static string encrypt_user_password(string password)
	{
		auto hasher = hash_helper::create(SHA256);
		return hasher->compute_hash(password);
	}
};
