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
 * PrintDigitsInOrder - this function prints the digits of a number in order
 * @n : the number whose digits are to be printed
 */
void PrintDigitsInOrder(int n)
{
    int remainder;
    if(n != 0)
    {
        remainder = (n % 10);
        PrintDigitsInOrder(n / 10);
        cout << remainder << endl;
    }
    return;
}


int main(void)
{
    PrintDigitsInOrder(ReadNumber());
}