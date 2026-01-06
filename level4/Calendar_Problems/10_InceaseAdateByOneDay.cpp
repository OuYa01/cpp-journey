#include <iostream>

using namespace std;

 struct stDate
 {
    int year;
    int month;
    int day;
 };
 

bool isLeapYear(int Year) 
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

int NumberOfDaysInAMonth(int Month, int Year) 
{ 
    if (Month < 1 || Month>12)
    return  0;
    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31};
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1]; 
}

bool IsLastDayInTheMonth(stDate& date)
{    
    return ((NumberOfDaysInAMonth(date.month, date.year) == date.day));
}

bool IsLastMonthInTheYear(stDate& date)
{
    return(date.month == 12);
}


void IncreaseAdateByOneDay(stDate& date)
{
    if (IsLastDayInTheMonth(date) && IsLastMonthInTheYear(date)) 
    {
        date.year += 1;
        date.month = 1;
        date.day = 1;
    }
    else if (IsLastDayInTheMonth(date)) 
    {
        date.month += 1;
        date.day = 1;
    }
    else
        date.day += 1;

}

int main(void)
{
    stDate date = {2002, 12, 31};
    IncreaseAdateByOneDay(date);
    cout << "Date after Increased by 1 day : " << date.year << "/"<< date.month << "/" << date.day;
}