#include <iostream>

using namespace std;

 struct stDate
 {
    int year;
    int month;
    int day;
 };
 

bool IsLeapYear(int Year) 
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

int NumberOfDaysInAMonth(int Month, int Year) 
{ 
    if (Month < 1 || Month>12)
    return  0;
    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31};
    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : days[Month - 1]; 
}


int DaysInYear(int year)
{
    return ((IsLeapYear(year) ? 366 : 365));
}


bool IsLastDayInTheMonth(stDate& date)
{    
    return ((NumberOfDaysInAMonth(date.month, date.year) == date.day));
}

bool IsLastMonthInTheYear(stDate& date)
{
    return(date.month == 12);
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
/**
 * Pros:
 *      Very simple to understand.
 *      Automatically handles all cases, including leap years and month/year changes, because IncreaseAdateByOneDay is assumed correct.
 *      Optional IncludeEndDay is convenient.
 * Cons:
 *      Very slow for dates far apart (e.g., 10+ years difference → loops tens of thousands of times).
 *      Uses a loop for each day, which is inefficient.
 */
int DiffranceInDay_V2(stDate date1, stDate date2, bool IncludeEndDay = false)
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

/***
 * Pros:
 *      Very fast, even for large date differences.
 *      Only loops over months and years, not every single day.
 *      Handles leap years correctly.
 * Cons:
 *     Slightly more complex to read, especially with multiple loops and subtractions.
 *     Must carefully handle same-year logic, else risk errors.
 *     Returns -1 / -2 for invalid cases instead of automatically handling date1 > date2.
 */
int DiffranceInDays(stDate date1, stDate date2)
{
    int DiffranceTotal = 0;
    int i;

    if (date1.year == date2.year)
    {
        if (date1.month == date2.month)
        {
            return (date2.day - date1.day);
        }
        else if (date1.month < date2.month)
        {
            for (i = date1.month; i < date2.month; i++)
            {
                DiffranceTotal += NumberOfDaysInAMonth(i, date1.year);
            }
            return (DiffranceTotal - date1.day + date2.day);
        }
        else
            return (-1);
    }
    else if (date1.year < date2.year)
    {
        for (i = date1.year; i < date2.year; i++)
            DiffranceTotal += DaysInYear(i);

        for (i = 1; i < date1.month; i++)
        {
            DiffranceTotal -= NumberOfDaysInAMonth(i, date1.year);
        }
        DiffranceTotal -= date1.day;

        for (i = 1; i < date2.month; i++)
        {
            DiffranceTotal += NumberOfDaysInAMonth(i, date2.year);
        }

        DiffranceTotal += date2.day;

        return (DiffranceTotal);
    }
    
    return (-2);

}

int main() {
    // Test case 1: normal difference
    stDate date1 = {1950, 1, 1};
    stDate date2 = {2022, 1, 1};

    cout << DiffranceInDay_V2(date1, date2) << endl;
    cout << DiffranceInDay_V2(date2, date1) << endl;

    return 0;
}