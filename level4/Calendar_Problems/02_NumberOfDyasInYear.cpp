#include <iostream>

using namespace std;

bool IsLeapYear(int year)
{
    
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
    
}

int DaysInYear(int year)
{
    return ((IsLeapYear(year) ? 366 : 365));
}

int HoursInYear(int year)
{
    return (DaysInYear(year) * 24);
}

int MinutesInYear(int year)
{
    return (HoursInYear(year) * 60);
}

int SecondsInYear(int year)
{
    return (MinutesInYear(year) * 60);
}

int main(void)
{
    int year = 2000;

    cout << "Number of Days in year [" << year << "] is " << DaysInYear(year) << endl;
    cout << "Number of Hours in year [" << year << "] is " << HoursInYear(year) << endl;
    cout << "Number of minutes in year [" << year << "] is " << MinutesInYear(year) << endl;
    cout << "Number of seconds in year [" << year << "] is " << SecondsInYear(year) << endl;
}