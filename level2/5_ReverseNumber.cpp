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



int main(void)
{
    cout << ReverseNumber(ReadNumber());
}