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
 * CountDigitFrequency - this function counts the frequency of a specific digit in a number
 * 
 * @DigitToCheck : the digit to count in the number
 * @n : the number in which to count the digit
 * 
 * Return : the frequency of the digit in the number
 */
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

/**
 * PrintAllDigitsFrequencey - this function prints the frequency of all digits (0-9) in a number
 * @n : the number in which to count the digits
 * 
 */
void PrintAllDigitsFrequencey(int n)
{
    int i, DigitFrequency;

    for (i = 0; i < 10; i++)
    {
        DigitFrequency = CountDigitFrequency(i, n);
        if (DigitFrequency > 0)
            cout << "Digit " << i << " Frequency is " << DigitFrequency << " Time(s)\n";
    }
}


int main(void)
{
    PrintAllDigitsFrequencey(ReadNumber());
}