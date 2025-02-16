#include "str.h"


int CountEachWordInString(std::string s)
{
	string delim = " ";
	short pos = 0;
	string sword;
	int count = 0;

	while ((pos = s.find(delim)) != std::string::npos)
	{
		sword = s.substr(0, pos);

		if (sword != " ")
			count++;
		s.erase(0, pos + delim.length());
	}

	if (s != " ")
		count++;
}
