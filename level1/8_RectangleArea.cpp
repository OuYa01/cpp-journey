#include <iostream>
#include <cmath>

using namespace std;

void ReadInfo(int &a, int &d)
{
    cout << "give me diagonal: ";
    cin >> d;
    cout << "give me side area: ";
    cin >> a;
}

int CalculeRectangleArea(int a, int d)
{
    return (a*sqrt(pow(d, 2) - pow(a, 2)));
}

void printResult(int Area)
{
    cout << "the RectangleArea is : " << Area;
}

int main(void)
{
    int a, d;
    
    ReadInfo(a, d);
    printResult(CalculeRectangleArea(a, d));
}