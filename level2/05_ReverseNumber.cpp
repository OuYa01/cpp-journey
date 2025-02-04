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
 * ReverseNumber - this function reverses the digits of a number
 * 
 * @param n : the number to be reversed
 * 
 * Return : the reversed number
 */
int ReverseNumber(int n)
{
    int remainder = 0;
    int Rnumber = 0;
    while(n != 0)
    {
        remainder = n % 10;
        n = n / 10;
        Rnumber = Rnumber * 10 + remainder;
    }

    return (Rnumber);
}



int main(void)
{
    cout << ReverseNumber(ReadNumber());
}