#include <iostream>
using namespace std;

int ReadNumber()
{
    int number;

    cout << "Entre a number : ";
    cin >> number;

    return (number);
}


int sumOfdigits(int n)
{
    int sum = 0;
    while(n != 0)
    {
        sum += (n%10);
        n = n / 10;
    }

    return (sum);
}

int main(void)
{
    cout << sumOfdigits(ReadNumber());
}