#include "str.h"

string InvertAllString(string str)
{
    short i;

    for (i = 0; i < str.length(); i++)
    {
        str[i] = InvertLetterCase(str[i]);
    }
    return (str);
}