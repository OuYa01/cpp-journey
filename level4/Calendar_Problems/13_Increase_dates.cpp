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


void IncreaseDateByXDays(stDate& date, int DaysToAdd)
{
    int daysinmonth;
    while (DaysToAdd > 0)
    {
        if (IsLastDayInTheMonth(date) && IsLastMonthInTheYear(date))
        {
            DaysToAdd -= 1;
            date.day = 1;
            date.month = 1;
            date.year ++;
        } else if (IsLastDayInTheMonth(date))
        {
            DaysToAdd -= 1;
            date.month += 1;
            date.day = 1;
        }

        daysinmonth = NumberOfDaysInAMonth(date.month, date.year);
        if (daysinmonth - date.day <= DaysToAdd)
        {
            DaysToAdd -= (daysinmonth - date.day);
            date.day = daysinmonth;
        }
        else
        {
            date.day += DaysToAdd;
            break;
        }
    }

}



void IncreaseDateByOneWeekV1(stDate& date)
{
    if (IsLastMonthInTheYear(date) && NumberOfDaysInAMonth(date.month, date.year) - date.day <= 7)
    {
        date.day = date.day + 7 - NumberOfDaysInAMonth(date.month, date.year);
        date.year += 1;
        date.month = 1;
    }
    else if (NumberOfDaysInAMonth(date.month, date.year) - date.day >= 7)
        date.day += 7;
    else
    {
        date.day = date.day + 7 - NumberOfDaysInAMonth(date.month, date.year); 
        date.month += 1;
    }
}

void IncreaseDateByOneWeekV2(stDate& date)
{
    int daysInTheMonth = NumberOfDaysInAMonth(date.month, date.year);
    date.day += 7;

    if (date.day > daysInTheMonth)
    {
        date.day -= daysInTheMonth;
        date.month += 1;
        if (date.month > 12)
        {
            date.month = 1;
            date.year += 1;
        }
    }
}

void IncreaseAdateByXweek(stDate& date, int weeks)
{
    while (weeks--)
    {
        IncreaseDateByOneWeekV2(date);
    }
}


void IncreaseAdateByOneMonthv1(stDate& date)
{
    if (IsLastMonthInTheYear(date) && IsLastDayInTheMonth(date))
    {
        date.year += 1;
        date.month = 1;
    }
    else if (IsLastDayInTheMonth(date))
    {
        date.month += 1;
        date.day = 1;
    }
    else
    {
        date.month += 1;
    }
}

void IncreaseAdateByOneMonthv2(stDate& date)
{
    date.month += 1;

    if (date.month > 12)
    {
        date.year += 1;
        date.month = 1;
    }

    int daysInNewMonth = NumberOfDaysInAMonth(date.month, date.year);
    if (date.day > daysInNewMonth)
    {
        date.day = daysInNewMonth;
    }
} 

void IncreaseAdateByXMonths(stDate& date, int months)
{
    while (months--)
    {
        IncreaseAdateByOneMonthv2(date);
    }
}

void increaseAdateByOneYear(stDate& date)
{
    date.year += 1;
    int NUmOfDaysInMonth  = NumberOfDaysInAMonth(date.month, date.year);
    if (date.day > NUmOfDaysInMonth)
     date.day = NUmOfDaysInMonth;
}


void increaseAdateByXyears(stDate& date, int years)
{
    date.year += years;
    int NUmOfDaysInMonth  = NumberOfDaysInAMonth(date.month, date.year);
    if (date.day > NUmOfDaysInMonth)
     date.day = NUmOfDaysInMonth;
}

void IncreaseDateByOneDecade(stDate& date)
{
    increaseAdateByXyears(date, 10);
}

void IncreaseDateByXDecades(stDate& date, int x)
{
    increaseAdateByXyears(date, 10 * x);
}

void IncreaseDateByOneCentury(stDate& date)
{
    increaseAdateByXyears(date, 100);
}

void IncreaseDateByXCenturys(stDate& date, int x)
{
    increaseAdateByXyears(date, 100 * x);
}


void IncreaseDateByOneMillennium(stDate& date)
{
    increaseAdateByXyears(date, 1000);
}
int main(void)
{
    stDate Date1 = {2022, 12, 29};
    // IncreaseDateByXDays(Date1, 1);
    // cout << "Date1 after add 1 day : " << Date1.year << "/"<< Date1.month << "/" << Date1.day << "\n";
    // IncreaseDateByXDays(Date1, 10);
    // cout << "Date1 after add 10 day : " << Date1.year << "/"<< Date1.month << "/" << Date1.day << "\n";
    IncreaseDateByOneWeekV1(Date1);
    cout << "Date1 after add a week : " << Date1.year << "/" << Date1.month << "/" << Date1.day << "\n";
}





