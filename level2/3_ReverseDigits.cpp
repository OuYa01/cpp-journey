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
 * printReverseDigits - this function prints the digits of a number in reverse order
 * @n: the number to be reversed
 * 
 */
void printReverseDigits(int n)
{
    while(n != 0)
    {
        cout << (n % 10) << "\n";
        n = n / 10;
    }
}



int main(void)
{
    printReverseDigits(ReadNumber());
}