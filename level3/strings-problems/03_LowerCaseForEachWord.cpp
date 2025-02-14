#include "str.h"


string LowerCaseFirstLetter(string str)
{
	if (str.empty())
	{
		cout << "You Enter Empty string" << endl;
		return (str);
	}

	int i;

	if (str[0] != ' ')
	{
		if (str[0] >= 'A' && str[0] <= 'Z')
			str[0] += 32; 
	}

	for (i = 1; i < str.length(); i++)
	{
		if (str[i - 1] == ' ' &&  str[i] != ' ')
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
			    str[i] += 32;
        }
	}

	return (str);
}