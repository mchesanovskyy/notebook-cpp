#pragma once
#include <string>
#include <vector>
#include <sstream>

using namespace std;

inline bool is_equals_ignore_case(const string& a, const string& b)
{
	return equal(a.begin(), a.end(), b.begin(), b.end(), [](char a, char b) { return tolower(a) == tolower(b); });
}

inline vector<string> split(string str_to_split, char delimeter)
{
	stringstream ss(str_to_split);
	string item;
	vector<string> splittedStrings;
	while (getline(ss, item, delimeter))
	{
		splittedStrings.push_back(item);
	}
	return splittedStrings;
}

inline bool contains(char& source, char values[]) {
	for (int i = 0; i < (sizeof(values) / sizeof(*values)); i++)
	{
		if (values[i] == source) {
			return true;
		}
	}
	return false;
}