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
 * sumOfdigits - this function calculates the sum of the digits of a number
 * 
 * @n: the number whose digits are to be summed
 * 
 * Return: the sum of the digits of the number
 */
int sumOfdigits(int n)
{
    int sum = 0;
    while(n != 0)
    {
        sum += (n % 10);
        n = n / 10;
    }

    return (sum);
}

int main(void)
{
    cout << sumOfdigits(ReadNumber());
}