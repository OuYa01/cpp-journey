#include "str.h"


std::string TrimLeft(std::string s)
{
	short i;

	for (i = 0; i < s.length(); i++)
	{
		if (s[i] != ' ')
			return (s.substr(i, s.length()-1));
	}

	return ("");
}

std::string TrimRight(std::string s)
{
	short i;

	for (i = s.length() - 1; i >= 0; i--)
	{
		if (s[i] != ' ')
			return (s.substr(0, i + 1));
	}

	return ("");
}


std::string Trim(std::string s)
{
	s = TrimLeft(s);
	s = TrimRight(s);

	return (s);
}
