#include <iostream>
using namespace std;

int ReadNumber()
{
    int number;

    cout << "Entre a number : ";
    cin >> number;

    return (number);
}

void printReverseDigits(int n)
{

    while(n != 0)
    {
        cout << (n % 10)<< "\n";
        n = n / 10;
    }
}



int main(void)
{
    printReverseDigits(ReadNumber());
}