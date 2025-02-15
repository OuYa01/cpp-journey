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

	string s = ReadString();
	cout << "string length: "<< _strlen(s) << endl;
	cout << "capital letters length: "<< uppercase_length(s) << endl;
	cout << "small letters length: "<< lowercase_length(s) << endl;
}
