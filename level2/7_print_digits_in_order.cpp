#include <iostream>
using namespace std;


int ReadNumber()
{
    int number;

    cout << "Entre a number : ";
    cin >> number;

    return (number);
}

void PrintDigitsInOrder(int n)
{
    int remainder;
    if(n != 0)
    {
        remainder = (n%10);
        PrintDigitsInOrder(n/10);
        cout << remainder << endl;
    }
    return;
}


int main(void)
{
    PrintDigitsInOrder(ReadNumber());
}