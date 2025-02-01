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
 * @n : the number to be reversed
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

/**
 * PalindromeNumber - this function checks if a number is a palindrome
 * 
 * @n : the number to be checked
 * 
 * Return : true if the number is a palindrome, false otherwise
 */
bool PalindromeNumber(int n)
{
    int temp = ReverseNumber(n);

    if (temp == n)
        return (true);
    return (false);
}

int main(void)
{
    if (PalindromeNumber(ReadNumber()))
        cout << "its a palindrome Number";
    else
        cout << "not a palindrome Number";
}