#pragma once

template <class TEntity>
class abstract_repository
{
public:
	virtual void add(TEntity* entity) = 0;
	virtual void save_changes() = 0;
};