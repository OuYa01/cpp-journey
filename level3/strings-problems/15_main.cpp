#include "str.h"


int main(void)
{
	vector<string> v = {"I came", "I saw", "I forget what I was doing."};

	string s = JoinString(v, ", ");
	cout << s << endl;
}
