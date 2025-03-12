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
	
	//This loop runs as long as StringToReplace is found in s1.
	while (pos != std::string::npos) //If StringToReplace is not found, s1.find() returns std::string::npos (which means "not found")
	{
		s1 = s1.replace(pos, StringToReplace.length(), ReplaceTo);
		pos = s1.find(StringToReplace);
	}

	return (s1);
}
