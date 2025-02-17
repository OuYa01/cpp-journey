#include "str.h"


int main(void)
{
	vector<string> v = {"I came", "I saw", "I forget what I was doing."};
	string arr[] = {"Oops", "I did it", "Again"};
	string s1 = JoinString(v, ", ");
	string s2 = JoinString(arr, 3, ", ");
	cout <<  s1 << endl;
	cout <<  s2 << endl;
}
