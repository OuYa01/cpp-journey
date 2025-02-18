#include "str.h"


std::string ReverseString(std::string s1)
{
	std::vector<string> v =  splitStringIntoVector(s1, " ");
	std:: string s2;

	std::vector<string>::iterator iter = v.end();

	while (iter != v.begin())
	{
		iter--;
		s2 += *iter + " ";
	}


	return (s2.substr(0, s2.length() - 1));
}
