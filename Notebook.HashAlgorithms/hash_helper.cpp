#include "stdafx.h"
#include "hash_helper.h"
#include "sha256_hash_algorithm.h"

hash_algorithm* hash_helper::create(const hash_algorithm_type algorithm_type)
{
	switch (algorithm_type)
	{
	case SHA256:
		return new sha256_hash_algorithm;
	default:
		return nullptr;;
	}
}
