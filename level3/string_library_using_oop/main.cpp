#include "ClsString.h"
#include <iostream>
using namespace std;

int main(void)
{
    clsString s1 ("Hello Oussama!!");
    clsString s2 ("Bonjour Saber!!! hhh!!");

    cout << s1.GetValue() << endl;
    cout << s2.GetValue() << endl;
    cout << s1.CountUppercase() << endl;
    cout << s2.CountUppercase() << endl;
    cout << s1.CountWords()<< endl;
    cout << s2.CountWords()<< endl;
    cout << s2.LowerFirstLetter() << endl;
    cout << s2.GetValue() << endl;
}