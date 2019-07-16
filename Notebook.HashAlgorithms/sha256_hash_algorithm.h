#pragma once
#include "hash_algorithm.h"

class sha256_hash_algorithm : public hash_algorithm
{
public:
	string compute_hash(string text) override;
};

