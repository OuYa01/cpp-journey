#include "str.h"


int main(void)
{
	string s = "Welcome to usa , usa loves you";
	
	cout << "Original string: " << s << endl;
	s = RaplaceWordInString(s, "usa", "Morocco");
	cout << "Aftre change the word: " << s << endl;

	
	s = "My name is oussama , oussama loves you";
	
	cout << "Original string: " << s << endl;
	s = RaplaceWordInStringV2(s, "oussama", "OuYa01");
	cout << "Aftre change the word: " << s << endl;
}
