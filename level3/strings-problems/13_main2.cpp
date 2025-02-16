#include "str.h"

/**
 * main - Entry point
 *
 * Return : 0 if succ
 */
int main()
{
	//test 1
	vector<string> v = splitStringIntoVector("It's Alwyas Seems Impossible Until It's Done", " ");
	short tokens = 	v.size();

	cout << "Tokens = " << tokens << endl;
	for (string& i : v)
		cout << i << endl;

	cout << endl;
	
	//test 2
	v = splitStringIntoVector("We,Do,Hard,Things", ",");
	tokens = v.size();

	cout << "Tokens = " << tokens << endl;
	for (string& i : v)
		cout << i << endl;

	cout << endl;
	
	//test 3
	v = splitStringIntoVector("Ouya#,,#01#,,#01", "#,,#");
	tokens = v.size();

	cout << "Tokens = " << tokens << endl;
	for (string& i : v)
		cout << i << endl;

	return (0);
}
