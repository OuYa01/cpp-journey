#include <iostream>
using namespace std;


int ReadNumber()
{
    int number;

    cout << "Entre a number : ";
    cin >> number;

    return (number);
}


void printInvertedPattern(int n)
{
    int i, j;
    int temp = n;
    for(i = 0; i < temp; i++)
    {
        for(j = i; j < temp; j++)
        {
            cout << n;
        }
        n--;
        cout << endl;
    }
}

void printInvertedPattern2(int n)
{
    int i, j;
    int temp = n;
    
    for (i = 1; i <= n; i++)
    {
        for(j = n - i; j < n; j++)
        {
            cout << i;
        }
        cout << endl;
    }
}

int main(void)
{
    printInvertedPattern2(ReadNumber());
}