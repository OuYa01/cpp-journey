#include "str.h"

std::vector<std::string> splitStringIntoVector(std::string s, std::string delim)
{
	std::vector<std::string> v;
	std::string sword;
	short pos = 0;

	while ((pos = s.find(delim)) != std::string::npos)
	{
		sword = s.substr(0, pos);
		
		if (sword != "")
		{
			v.push_back(sword);
		}

		s.erase(0, pos + delim.length());
	}

	if (s != "")
	{
		v.push_back(s);
	}

	return (v);
}
