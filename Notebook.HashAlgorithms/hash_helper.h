#pragma once
#include "hash_algorithm_type.h"
#include "hash_algorithm.h"

class hash_helper
{
public:
	static hash_algorithm* create(const hash_algorithm_type algorithm_type);
};

