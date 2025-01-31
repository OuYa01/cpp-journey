#include <iostream>
using namespace std;

int ReadNumber()
{
    int number;

    cout << "Entre a number : ";
    cin >> number;

    return (number);
}



int CountDigitFrequency(short DigitToCheck, int n)
{
    int remainder;
    int count = 0;
    while (n != 0)
    {
        remainder = n % 10;
        n = n / 10; 
        if (remainder == DigitToCheck)
            count++;
    }
    return (count);
}

void PrintAllDigitsFrequencey(int n)
{
    int i, DigitFrequency;

    for (i = 0; i < 10; i++)
    {
        DigitFrequency = CountDigitFrequency(i, n);
        if ( DigitFrequency > 0)
            cout << "Digit "<< i << " Frequencey is " << DigitFrequency << "Time(s)\n";
    }
}


int main(void)
{
    PrintAllDigitsFrequencey(ReadNumber());
}