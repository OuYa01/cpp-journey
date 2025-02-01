#include <iostream>
using namespace std;


int ReadNumber()
{
    int number;

    cout << "Entre a number : ";
    cin >> number;

    return (number);
}


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