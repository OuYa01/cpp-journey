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

bool IsfirstDayInTheMonth(stDate& date)
{    
    return ((date.day == 1));
}

bool IsFirstMonthInTheYear(stDate& date)
{
    return(date.month == 1);
}

bool Date1IsBeforeDate2(stDate& date1, stDate& date2)
{
    if (date1.year < date2.year)
    {
        return (true);
    }
    else if (date1.year > date2.year)
    {
        return (false);
    }
    else
    {
        if (date1.month < date2.month)
            return (true);
        else if (date1.month > date2.month)
            return (false);
        else
        {
            if (date1.day < date2.day)
                return (true);
            else if (date1.day > date2.day)
                return (false);
        }

    }

    return (false);
}

bool date1IsEqualToDate2(stDate& date1, stDate& date2)
{
    return (date1.day == date2.day && date1.year == date2.year && date1.month == date2.month);
}

bool Date1IsAfterDate2(stDate& date1, stDate& date2)
{
    if (!Date1IsBeforeDate2(date1, date2) && !date1IsEqualToDate2(date1, date2))
        return (true);
    return (false);
}

enum enDateCompare { Before = -1, Equal = 0, After = 1};

enDateCompare compareDate1AndDate2(stDate& date1, stDate& date2)
{
    if (date1IsEqualToDate2(date1, date2))
        return (enDateCompare::Equal);
    else if (Date1IsBeforeDate2(date1, date2))
        return (enDateCompare::Before);
    else
        return (enDateCompare::After);
}

int main()
{
    stDate Date1 = {2022, 1, 1};
    stDate Date2 = {2000, 1, 1};

    cout << Date1IsAfterDate2(Date1, Date2) << endl;
}