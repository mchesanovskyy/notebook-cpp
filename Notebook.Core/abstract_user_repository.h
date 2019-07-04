#pragma once
#include "user.h"
#include "abstract_repository.h"

class abstract_user_repository : public virtual abstract_repository<user>
{
public:

	virtual user* get_by_login(string login) = 0;
};
