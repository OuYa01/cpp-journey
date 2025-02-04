#include <iostream>
#include <cmath>
using namespace std;


float _MyAbs(float number)
{
    if (number < 0)
        return (number * -1);
    return (number);
}

int _MyRound(float number)
{
    float add = (number>=0) ? 0.5 : -0.5;
    return (int(number + add));

}


int _Myfloor(float number)
{
    if (number > 0)
        return ((int)number);

    return (int(number) - 1);
}


int _MyCeil(float number)
{
    if (number > 0)
        return ((int)number + 1);

    return (int(number));

}

int main()
{
    float a = -10.5;
    cout << _MyCeil(a) << endl;
    cout << ceil(a) << endl;

    a = 11.66;
    cout << _MyCeil(a) << endl;
    cout << ceil(a) << endl;

    a = -11.66;
    cout << _MyCeil(a) << endl;
    cout << ceil(a) << endl;

    a = 15.99;
    cout << _MyCeil(a) << endl;
    cout << ceil(a) << endl;


}