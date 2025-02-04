#include <iostream>
using namespace std;

int sum(int a, int b)
{
    return (a + b);
}

int main(void)
{
    int a, b;

    cout << "number1: ";
    cin >> a;
    cout << "number2: ";
    cin >> b;
    cout << a << " + " << b << " = " << sum(a, b);
}