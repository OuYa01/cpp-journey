#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main(void)
{
    int a = 4;
    int b = 5;
    swap(a, b);
    cout << a << endl;
    cout << b << endl;
}