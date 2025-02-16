#include "str.h"

char ToLower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

bool IsVowel(char c)
{
	c = ToLower(c);

	return ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u'));
}

