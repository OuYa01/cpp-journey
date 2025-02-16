#include "str.h"


int ReadNumber()
{
    int number;

    cout << "Entre a range for Fibonacci Series: ";
    cin >> number;

    return (number);
}

string ReadString()
{
	string str;
	cout << "enter a string: " << endl;
	getline(cin, str);

	return (str);
}

int main()
{

	short tokens;
	vector<string> v= splitStringIntoVector("It's Alwyas Seems Impossible Until It's Done", tokens);
	
	cout << "Tokens = " << tokens << endl;
	for (string i : v)
		cout << i << endl;

	return (0);
}
