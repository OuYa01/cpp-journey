#include <iostream>
#include <string>

using namespace std;

void ReadNumbers(int &num1, int &num2)
{
    cout << "Entre number 1: ";
    cin >> num1;
    cout << "Entre number 2: ";
    cin >> num2;
}

int MaxOf2Numbers(int num1, int num2)
{
    if (num1 > num2)
        return (num1);
    else
        return (num2);
}

void PrintResult(int max)
{
    cout << "the max is : " << max;
}


int main(void)
{
    int num1, num2;

    ReadNumbers(num1, num2);
    PrintResult(MaxOf2Numbers(num1, num2));
}