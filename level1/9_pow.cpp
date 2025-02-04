#include <iostream>
using namespace std;

int _pow(int number, int power)
{
    int i;
    int temp = 1;

    if (power == 0)
    {
        return temp;
    }

    for (i = 0; i < power; i++)
    {
        temp *= number;
    }

    return (temp);
}

int main(void)
{
    cout << _pow(2, 4);
}