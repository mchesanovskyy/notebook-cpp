#pragma once
class entity
{
public:
	int id;

	virtual entity* copy()
	{
		const auto copy = new entity;
		copy->id = id;
		return copy;
	}
};