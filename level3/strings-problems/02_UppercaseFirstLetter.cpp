#include "str.h"


string UpperCaseFirstLetter(string str)
{
	if (str.empty())
	{
		cout << "You Enter Empty string" << endl;
		return (str);
	}

	int i;

	if (str[0] != ' ')
	{
		if (str[0] >= 'a' && str[0] <= 'z')
			str[0] -= 32; 
	}

	for (i = 1; i < str.length(); i++)
	{
		if (str[i - 1] == ' ' &&  str[i] != ' ')
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 32;
		}
	}

	return (str);
}
