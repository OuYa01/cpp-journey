#include <iostream>
#include <ctime>

using namespace std;


struct stDate {
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

int DiffranceInDay(stDate date1, stDate date2, bool IncludeEndDay = false)
{
    int Days = 0;

    while (IsDate1IsLessThanDate2(date1, date2))
    {
        Days++;
        IncreaseAdateByOneDay(date1);
    }

    return (IncludeEndDay ? ++Days : Days);
}

stDate GetSystemDate()
{
    time_t now = time(0);  // Get the current time
    tm *localTime = localtime(&now); // Convert to local time
    stDate current_date = {1900 + localTime->tm_year, 1 + localTime->tm_mon, localTime->tm_mday};

    return (current_date);
}

int YourAgeInDays(stDate BirthDate)
{
    return (DiffranceInDay(BirthDate, GetSystemDate()));
}
int main()
{
    stDate BirthDate1 = {2002, 12, 24};
    stDate BirthDate2 = {1977, 11, 06};

    cout << "Your age in days is : " << YourAgeInDays(BirthDate1) << "\n";
    cout << "Your age in days is : " << YourAgeInDays(BirthDate2) << "\n";


    return 0;
}