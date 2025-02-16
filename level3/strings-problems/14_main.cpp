#include "str.h"



int main(void)
{
	string s = "             As you get older, three things happen. The first is your memory goes, and I can’t remember the other two                    ";

	cout << "string: " << s << endl;
	cout << "Trim Left: " << TrimLeft(s) << endl;
	cout << "Trim Right: " << TrimRight(s) << endl;
	cout << "Trim: " << Trim(s) << endl;
}
