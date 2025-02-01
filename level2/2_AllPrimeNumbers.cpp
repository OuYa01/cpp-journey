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
 * PrimeNumber - Checks if a number is a prime number.
 * @n The integer to check for primality.
 * 
 * return : true If the number is a prime number, or false If the number is not a prime number.
 */
bool PrimeNumber(int n)
{
    int i;
    for (i = 2; i < n; i++)
    {
        if (n % i == 0)
            return (false);
    }
    return (true);
}

/**
 * PrintAllPrimeNumbers - this function prints all prime numbers up to a given number N 
 * @N: the upper limit up to which prime numbers are to be printed
 * 
 */
void PrintAllPrimeNumbers(int N)
{
    int i;
    for(i = 1; i <= N; i++)
    {
        if (PrimeNumber(i))
            cout << i<< " Its A Prime Number\n";
    }
}



int main()
{
    PrintAllPrimeNumbers(ReadNumber());

    return (0);
}