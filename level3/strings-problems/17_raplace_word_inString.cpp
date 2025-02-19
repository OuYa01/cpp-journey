#include "str.h"

std::string RaplaceWordInString(std::string s1, std::string StringToReplace, std::string ReplaceTo)
{
	std::vector<string> v = splitStringIntoVector(s1, " ");
	std::string s2;
	int i;

	for (i = 0; i < v.size(); i++)
	{
		if (v[i] == StringToReplace)
			v[i] = ReplaceTo;
		s2 += v[i] + " ";
	}

	return (s2.substr(0, s2.length() - 1));
}



std::string RaplaceWordInStringV2(std::string s1, std::string StringToReplace, std::string ReplaceTo)
{
	short pos = s1.find(StringToReplace);

	while (pos != std::string::npos)
	{
		s1 = s1.replace(pos, StringToReplace.length(), ReplaceTo);
		pos = s1.find(StringToReplace);
	}

	return (s1);
}
