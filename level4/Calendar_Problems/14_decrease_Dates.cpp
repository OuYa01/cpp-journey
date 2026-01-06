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



void DecreasAdateByOneDay(stDate& date)
{
    if (IsfirstDayInTheMonth(date) && IsFirstMonthInTheYear(date)) 
    {
        date.year -= 1;
        date.month = 12;
        date.day = NumberOfDaysInAMonth(date.month, date.year);
    }

    else if (IsfirstDayInTheMonth(date)) 
    {
        date.month -= 1;
        date.day = NumberOfDaysInAMonth(date.month, date.year);
    }
    else
        date.day -= 1;

}


void DecreasADateByXDays(stDate& date, int DaysToSub)
{
    while (DaysToSub--)
    {
        DecreasAdateByOneDay(date);
    }
}




void DecreasADateByOneWeek(stDate& date)
{
    date.day -= 7;

    if (date.day < 1)
    {
        date.month -= 1;
        
        if (date.month < 1)
        {
            date.month = 12;
            date.year -= 1;
        }
        date.day = NumberOfDaysInAMonth(date.month, date.year) + date.day;
    }
}

void DecreasAdateByXweek(stDate& date, int weeksToSub)
{
    while (weeksToSub--)
    {
        DecreasADateByOneWeek(date);
    }
}




void DecreasAdateByOneMonthv2(stDate& date)
{
    date.month -= 1;

    if (date.month < 1)
    {
        date.year -= 1;
        date.month = 12;
    }

    int daysInNewMonth = NumberOfDaysInAMonth(date.month, date.year);
    if (date.day > daysInNewMonth)
    {
        date.day = daysInNewMonth;
    }
} 

void  DecreasAdateByXMonths(stDate& date, int months)
{
    while (months--)
    {
         DecreasAdateByOneMonthv2(date);
    }
}

void  DecreasAdateByOneYear(stDate& date)
{
    date.year -= 1;

    int NUmOfDaysInMonth  = NumberOfDaysInAMonth(date.month, date.year);
    if (date.day > NUmOfDaysInMonth)
     date.day = NUmOfDaysInMonth;
}


void  DecreasAdateByXyears(stDate& date, int years)
{
    date.year -= years;

    int NUmOfDaysInMonth  = NumberOfDaysInAMonth(date.month, date.year);
    if (date.day > NUmOfDaysInMonth)
     date.day = NUmOfDaysInMonth;
}

void  DecreasDateByOneDecade(stDate& date)
{
    DecreasAdateByXyears(date, 10);
}

void  DecreasDateByXDecades(stDate& date, int x)
{
    DecreasAdateByXyears(date, 10 * x);
}

void  DecreasDateByOneCentury(stDate& date)
{
    DecreasAdateByXyears(date, 100);
}

void  DecreasDateByXCenturys(stDate& date, int x)
{
    DecreasAdateByXyears(date, 100 * x);
}


void DecreasDateByOneMillennium(stDate& date)
{
    DecreasAdateByXyears(date, 1000);
}


int main(void)
{
    stDate Date1 = {2022, 1, 1};

    DecreasAdateByOneDay(Date1);
    cout << "Date1 after sub one day : " << Date1.year << "/" << Date1.month << "/" << Date1.day << "\n";
}





