#include <iostream>
using namespace std;
int ReadNumber()
{
    int number;

    cout << "Entre a number : ";
    cin >> number;

    return (number);
}

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