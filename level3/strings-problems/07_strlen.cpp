#include "str.h"

size_t _strlen(const std::string& s)
{
	size_t len = 0;

	for (char i : s)
	{
		len++;
	}
	return (len);
}
