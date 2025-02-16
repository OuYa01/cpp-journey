#include "str.h"


void PrintEachWordInString(std::string s)
{
	string delim = " ";
	short pos = 0;
	string sword;

	while ((pos = s.find(delim)) != std::string::pos)
	{
		sword = s.substr(0, pos);

		if (sword != " ")
			cout << sword << endl;

		s.erase(0, pos + delim.length());
	}

	if (s != " ")
		cout << s << endl;
}
