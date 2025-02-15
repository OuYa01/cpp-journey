#include "str.h"


size_t lowercase_length(const std::string& s)
{
	size_t len;
	
	len = 0;
	for (char i : s)
	{
		if (i >= 'a' && i <= 'z')
			len++;
	}
	return (len);
}
