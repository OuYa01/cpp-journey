#include "str.h"

string UpperAllString(string str)
{
    for (short i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
    }
    return (str);
}

string LowerAllString(string str)
{
    for (short i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
			 str[i] += 32;
    }
    return (str);
}