#include "str.h"

/**
 * main - Entry point
 *
 * Return : 0 if succ
 */
int main()
{

	short tokens;
	vector<string> v= splitStringIntoVector("It's Alwyas Seems Impossible Until It's Done", tokens);
	
	cout << "Tokens = " << tokens << endl;
	for (string i : v)
		cout << i << endl;

	return (0);
}
