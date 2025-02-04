#include <iostream>
#include <string>

using namespace std;

void ReadNumbers(int &num1, int &num2, int &num3)
{
    cout << "Entre number 1: ";
    cin >> num1;
    cout << "Entre number 2: ";
    cin >> num2;
    cout << "Entre number 3: ";
    cin >> num3;
}

int MaxOf3Numbers(int num1, int num2, int num3)
{
    if (num1 > num2)
    {
        if (num1 > num3)
            return num1;
        else
            return num3;
    }
    else
    {
        if (num2 > num3)
            return (num2);
        else 
            return (num3);
    }
}

void PrintResult(int max)
{
    cout << "the max is : " << max;
}


int main(void)
{
    int num1, num2, num3;

    ReadNumbers(num1, num2, num3);
    PrintResult(MaxOf3Numbers(num1, num2, num3));
}