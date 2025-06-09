#include <iostream>

using namespace std;

bool IsLeapYear(int year)
{
    
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
    
}


int DaysInMonth(int year, int month)
{
    if (month < 1 || month > 12)
       return 0;

    int NumberOfDyas[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return ((month != 2) ? NumberOfDyas[month - 1] : (IsLeapYear(year) ? 29 : 28));
}


int HoursInMonth(int year, int month)
{
    return (DaysInMonth(year, month) * 24);
}

int MinutesInMonth(int year, int month)
{
    return (HoursInMonth(year, month) * 60);
}

int secondsInMonth(int year, int month)
{
    return (MinutesInMonth(year, month) * 60);
}

int main(void)
{
    int year = 2000;
    int month = 2;

    cout << "Number of Days in Month [" << month << "] is " << DaysInMonth(year, month) << endl;
    cout << "Number of Hours in Month [" << month << "] is " << HoursInMonth(year, month) << endl;
    cout << "Number of minutes in month [" << month << "] is " << MinutesInMonth(year, month) << endl;
    cout << "Number of seconds in month [" << month << "] is " << secondsInMonth(year, month)<< endl;
}