#include <iostream>
using namespace std;


int ReadNumber()
{
    int number;

    cout << "Entre a number : ";
    cin >> number;

    return (number);
}


void printInvertedLetter(int n)
{
    char a = 65 + n;

    int i, j;
    for (i = 1; i <= n; i++)
    {
        a--;
        for (j = i; j <= n; j++)
        {

            cout << a;
        }
        cout << endl;
    }

}


int main()
{
    printInvertedLetter(ReadNumber());
}