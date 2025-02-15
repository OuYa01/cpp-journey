#include "str.h"


size_t uppercase_length(const std::string& s)
{
	size_t len;
	
	len = 0;
	for (char i : s)
	{
		if (i >= 'A' && i <= 'Z')
			len++;
	}

	return (len);
}
