#include "str.h"


void PrintFirstLetter(string str)
{
	int i;
	if (str.empty())
	{
		cout << "there is no string";
		return;
	}

	cout << "First letters of each word in this string:\n";
	if (str[0] != ' ')
		cout << str[0] << endl;

	for (i = 1; i < str.length(); i++)
	{
		if (str[i - 1] == ' ' && str[i] != ' ')
		{
			cout << str[i] << endl;
		}
	}
}
