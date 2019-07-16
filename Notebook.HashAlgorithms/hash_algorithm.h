#pragma once
#include <string>
using namespace std;

class hash_algorithm
{
public:
	virtual string compute_hash(string text) = 0;
};
