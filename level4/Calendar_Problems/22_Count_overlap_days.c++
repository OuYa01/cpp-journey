#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
struct stDate {
    int year;
    int month;
    int day;
};

struct stPeriod {
    stDate StartDate;
    stDate EndDate;
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

bool IsLastDayInTheMonth(stDate& date)
{    
    return ((NumberOfDaysInAMonth(date.month, date.year) == date.day));
}

bool IsLastMonthInTheYear(stDate& date)
{
    return(date.month == 12);
}

bool IsOverlapDates(stPeriod& period1, stPeriod& period2)
{

    if (compareDate1AndDate2(period2.StartDate, period1.EndDate) == enDateCompare::After)
        return (false);
    
    if (compareDate1AndDate2(period2.EndDate, period1.StartDate) == enDateCompare::Before)
        return (false);
        
    return (true);
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

int countOverlapdays(stPeriod& period1, stPeriod& period2)
{
    
    if (!IsOverlapDates(period1, period2))
        return 0;
    
    int count_overlaps_days = 0;
    stDate start;
    stDate end;

    if (compareDate1AndDate2(period1.StartDate, period2.StartDate) == enDateCompare::Before)
        start = period2.StartDate;
    else
        start = period1.StartDate;
    
    if (compareDate1AndDate2(period1.EndDate, period2.EndDate) == enDateCompare::Before)
        end = period1.EndDate;
    else 
        end = period2.EndDate;

    while (compareDate1AndDate2(start, end) == enDateCompare::Before)
    {
        count_overlaps_days += 1;
        IncreaseAdateByOneDay(start);
    }

    count_overlaps_days += 1;

    return (count_overlaps_days);

}




int main(void)
{

}