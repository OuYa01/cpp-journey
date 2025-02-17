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



std::string JoinString(std::string arr[], short size, string delim)
{
	if (arr == NULL)
		return ("");

	std::string str;
	int i;
	for (i = 0; i < size; i++)
	{
		str += arr[i];

		if (i < size - 1)
			str += delim;
	}

	return (str);
}
