#include "str.h"

char InvertLetterCase(char char1)
{
    if (char1 >= 'a' && char1 <= 'z')
		char1 -= 32;
    else
        char1 += 32;

    return (char1);
}