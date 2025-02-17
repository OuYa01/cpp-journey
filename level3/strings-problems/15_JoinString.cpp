#include "str.h"


std::string JoinString(std::vector<string> v, string delim)
{
	if (v.empty()) return ("");

	std::string str;
	int count;

	count = 0;
	for (string& s : v)
	{
		str += s;
		if (++count != v.size())
			str += delim;
	}

	return str;
}
