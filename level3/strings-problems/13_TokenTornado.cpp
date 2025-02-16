#include "str.h"

std::vector<std::string> splitStringIntoVector(std::string s, short& tokens)
{
	std::vector<std::string> v;
	std::string delim = " ";
	std::string sword;
	short pos = 0;
	tokens = 0;

	while ((pos = s.find(delim)) != std::string::npos)
	{
		sword = s.substr(0, pos);
		
		if (sword != " ")
		{
			v.push_back(sword);
			tokens++;
		}

		s.erase(0, pos + delim.length());
	}

	if (s != " ")
	{
		v.push_back(s);
		tokens++;
	}

	return (v);
}
