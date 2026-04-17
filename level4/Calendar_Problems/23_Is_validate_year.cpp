#include <iostream>

using namespace std;
struct stDate {
    int year;
    int month;
    int day;
};



bool isLeapYear(int Year) 
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

int NumberOfDaysInAMonth(int& Month, int& Year) 
{ 
    if (Month < 1 || Month>12)
    return  0;
    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31};
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1]; 
}


bool ValidateDate(stDate date)
{
    if (date.year < 1)
        return false;
    else if (date.month < 1 || date.month > 12)
        return false;
    else if (date.day < 1 || date.day > NumberOfDaysInAMonth(date.month, date.year) )
        return false;

    return true;
}


int main(void)
{
}