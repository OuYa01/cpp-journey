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
 * printInvertedPattern - this function prints an inverted pattern of numbers
 * @n : the number of rows for the pattern
 */
void printInvertedPattern(int n)
{
    int i, j;
    int temp = n;
    for(i = 0; i < temp; i++)
    {
        for(j = i; j < temp; j++)
        {
            cout << n;
        }
        n--;
        cout << endl;
    }
}

/**
 * printInvertedPattern2 - this function prints an inverted pattern of numbers
 * @n : the number of rows for the pattern
 */
void printInvertedPattern2(int n)
{
    int i, j;
    int temp = n;
    
    for (i = 1; i <= n; i++)
    {
        for(j = n - i; j < n; j++)
        {
            cout << i;
        }
        cout << endl;
    }
}

int main(void)
{
    printInvertedPattern2(ReadNumber());
}