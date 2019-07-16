#include "stdafx.h"
#include "sha256_hash_algorithm.h"
#include "sha256.h"

string sha256_hash_algorithm::compute_hash(const string text)
{
	SHA256 sha256;
	return  sha256(text);
}
