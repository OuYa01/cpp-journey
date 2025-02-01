#include <iostream>
using namespace std;

/**
 * ReadNumber - this function just to read a number from user
 * 
 * Return : the number that get from user
 */
int ReadNumber()
{
    int number;

    cout << "Entre a number : ";
    cin >> number;

    return (number);
}


/**
 * printInvertedLetter - prints an inverted letter pattern based on the given number
 * @n: the number of rows for the pattern
 * 
 */
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