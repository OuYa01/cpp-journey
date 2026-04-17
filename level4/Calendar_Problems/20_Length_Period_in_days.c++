#include <iostream>

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

int DaysInMonth(int& Month, int& Year) 
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

int DaysInYear(int year)
{
    return ((isLeapYear(year) ? 366 : 365));
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


int PeriodLengthInDays(stPeriod period)
{

    if (Date1IsBeforeDate2(period.StartDate, period.EndDate) == false)
    {
        stDate Temp;
        Temp = period.StartDate;
        period.StartDate = period.EndDate;
        period.EndDate = Temp;
    }

    int i;
    int DaysInPeriod;
    int temp;

    DaysInPeriod = 1;

    // sum of days from strat Year to end Year (end year not included)
    for (i = period.StartDate.year; i < period.EndDate.year; i++)
    {
        DaysInPeriod += DaysInYear(i);
    }

    // sum of days from month 1 to the month of my start date (start month not included)
    temp = 0;
    for (i = 1; i < period.StartDate.month; i++)
    {
        temp += DaysInMonth(i, period.StartDate.year);
    }
    temp += period.StartDate.day;
    DaysInPeriod -= temp;

    // sum of ays from month 1 to the month of my end date (end month not included)
    temp = 0;
    for(i = 1; i < period.EndDate.month; i++)
    {
        temp += DaysInMonth(i, period.EndDate.year);
    }
    temp += period.EndDate.day;
    DaysInPeriod += temp;

    return (DaysInPeriod);

}


bool IsDate1IsLessThanDate2(stDate date1, stDate date2)
{
    return (
        (date1.year < date2.year) ? true 
        : (date1.year > date2.year) ? false 
        : ((date1.month < date2.month) ? true 
        : (date1.month > date2.month) ? false
        : ((date1.day < date2.day) ? true 
        : false )));
}

bool IsLastDayInTheMonth(stDate& date)
{    
    return ((DaysInMonth(date.month, date.year) == date.day));
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

void SwapDates(stDate& date1, stDate& date2)
{
    stDate temp = date1;
    date1 = date2;
    date2 = temp;
}

int DiffranceInDay(stDate date1, stDate date2, bool IncludeEndDay = false)
{
    int Days = 0;
    int multiplier = 1;

    if (!IsDate1IsLessThanDate2(date1, date2))
    {
        SwapDates(date1, date2);
        multiplier = -1;
    }
    
    while (IsDate1IsLessThanDate2(date1, date2))
    {
        Days++;
        IncreaseAdateByOneDay(date1);
    }

    
    return (IncludeEndDay ? (++Days)* multiplier: Days * multiplier);
}


int PeriodLengthInDaysV2(stPeriod period)
{
    return (DiffranceInDay(period.StartDate, period.EndDate, true));
}


int main(void)
{
    stPeriod period;

    // 1. Minimal period: same day
    period.StartDate = {2022, 01, 01};
    period.EndDate   = {2022, 01, 01};
    cout << PeriodLengthInDays(period) << endl; // Expected: 1

    // 2. Small period: few days within a month
    period.StartDate = {2022, 01, 01};
    period.EndDate   = {2022, 01, 05};
    cout << PeriodLengthInDays(period) << endl; // Expected: 5

    // 3. Small period across months
    period.StartDate = {2022, 01, 30};
    period.EndDate   = {2022, 02, 02};
    cout << PeriodLengthInDays(period) << endl; // Expected: 4

    // 4. Small period across February (non-leap year)
    period.StartDate = {2021, 02, 27};
    period.EndDate   = {2021, 03, 01};
    cout << PeriodLengthInDays(period) << endl; // Expected: 3

    // 5. Small period across February (leap year)
    period.StartDate = {2020, 02, 28};
    period.EndDate   = {2020, 03, 01};
    cout << PeriodLengthInDays(period) << endl; // Expected: 3

    // 6. Medium period within a year
    period.StartDate = {2022, 03, 01};
    period.EndDate   = {2022, 06, 01};
    cout << PeriodLengthInDays(period) << endl; // Expected: 93

    // 7. Long period across years
    period.StartDate = {2019, 12, 31};
    period.EndDate   = {2022, 01, 01};
    cout << PeriodLengthInDays(period) << endl; // Expected: 733

    // 8. Very long period (decades)
    period.StartDate = {2000, 01, 01};
    period.EndDate   = {2050, 12, 31};
    cout << PeriodLengthInDays(period) << endl; // Expected: 18628 (includes leap years)

    // 9. Extreme edge case: period across century (non-leap century)
    period.StartDate = {1899, 12, 31};
    period.EndDate   = {2001, 01, 01};
    cout << PeriodLengthInDays(period) << endl; // Expected: 36651 (checks century leap rules)

    // 10. Invalid period: end before start (should handle gracefully)
    period.StartDate = {2022, 01, 10};
    period.EndDate   = {2022, 01, 05};
    cout << PeriodLengthInDays(period) << endl; // Expected: maybe 0 or error depending on implementation
}
