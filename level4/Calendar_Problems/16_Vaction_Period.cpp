#include <iostream>
using namespace std;

enum DayOfTheWeek { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };

// 005
struct stDate {
    int year;
    int month;
    int day;
};

/**
 * NameOfToda - this fuction use "Zeller's Congruence formula" to find out the Day for a Date
 * @date : its a structur that holds year/month/day of the date we want to find out the day for it
 * 
 * Return : I ruturn the result of formula wich will be in range of [0...6] ∈ (int)  
 */
DayOfTheWeek NameOfToday(stDate& date)
{
    int h;
    int q = date.day;
    int m = date.month;
    int y = date.year;

    /**
     * The formula was designed to work smoothly if the year starts in March instead of January.
     * In the formula, months are numbered March = 3 … December = 12.
     * But what about January and February?
     * They are treated as months 13 and 14 of the previous year.
     */
    if (m == 1) { m = 13; y--;} // January becomes month 13 of previous year
    if (m == 2) { m = 14; y--;} // February becomes month 14 of previous year

    int k = y % 100;
    int j = y / 100;

    h = (q + ((13 * (m + 1)) / 5) + k + (k / 4) + (j / 4) + (5 * j)) % 7;

    // Shift result so Monday=0 ... Sunday=6
    int dayIndex = (h + 5) % 7;

    return (static_cast<DayOfTheWeek>(dayIndex));
}


void PrintTodayDate(stDate& Date)
{
    DayOfTheWeek today = NameOfToday(Date);
    switch (today)
    {
        case DayOfTheWeek::Saturday :
            cout << "Today is Saturday, ";
            break;
        case DayOfTheWeek::Sunday :
            cout << "Today is Sunday, ";
            break;
        case DayOfTheWeek::Monday :
            cout << "Today is Monday, ";
            break;
        case DayOfTheWeek::Tuesday :
            cout << "Today is Tuesday, ";
            break;
        case DayOfTheWeek::Wednesday :
            cout << "Today is Wednesday, ";
            break;
        case DayOfTheWeek::Thursday :
            cout << "Today is Thursday, ";
            break;
        case DayOfTheWeek::Friday :
            cout << "Today is Friday, ";
            break;
        default:
            cout << "Invalid day, ";
            break;
    }
    cout << Date.year << "/" << Date.month << "/" << Date.day << endl;

}

bool ItIsEndOfWeek(stDate& Date)
{
    if (NameOfToday(Date) == DayOfTheWeek::Sunday)
        return (true);
    return (false);
}


bool isWeekEnd(stDate& Date)
{
    if (NameOfToday(Date) == DayOfTheWeek::Saturday || NameOfToday(Date) == DayOfTheWeek::Sunday)
        return (true);
    return (false);
}

bool isBusinessDay(stDate& Date)
{
    return (!isWeekEnd(Date));
}

int DaysUntilEndOfWeek(stDate& Date)
{
    DayOfTheWeek today = NameOfToday(Date);

    return (6 - int(today));
}

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

int DaysUntilEndOfMonth(stDate& Date)
{
   return(NumberOfDaysInAMonth(Date.month, Date.year) - Date.day); 
}

int DaysUntilEndOfYear(stDate& Date)
{
   int i;
   int Days = 0;
   for (i = Date.month + 1; i <= 12; i++)
   {
        Days += NumberOfDaysInAMonth(i, Date.year);
   } 
   Days += (NumberOfDaysInAMonth(Date.month, Date.year) - Date.day);

   return (Days);
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

int DaysInYear(int year)
{
    return ((isLeapYear(year) ? 366 : 365));
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

void SwapDates(stDate& date1, stDate& date2)
{
    stDate temp = date1;
    date1 = date2;
    date2 = temp;
}


int DifferenceInDaysWithoutWeekends(stDate date1, stDate date2, bool IncludeEndDay = false)
{
    int Days = 0;
    int multiplier = 1;

    if (!IsDate1IsLessThanDate2(date1, date2))
    {
        SwapDates(date1, date2);
        multiplier = -1;
    }
    
    if (!isWeekEnd(date1))
        Days++;

    while (IsDate1IsLessThanDate2(date1, date2))
    {
        IncreaseAdateByOneDay(date1);
        if (!isWeekEnd(date1))
            Days++;
    }

    if (IncludeEndDay && !isWeekEnd(date2))
        Days++;

    return Days * multiplier;
    
}


/**
 * WeekEnd days are Excluded
 */
int CalculeVacationPeriod(stDate& VactionStartDate, stDate& VactionEndDate)
{
    return (DifferenceInDaysWithoutWeekends(VactionStartDate, VactionEndDate));
}


int CalculeVacationPeriodV2(stDate& VactionStartDate, stDate& VactionEndDate)
{
    int DaysCount = 0;
    while (IsDate1IsLessThanDate2(VactionStartDate, VactionEndDate))
    {
        if (isBusinessDay(VactionStartDate))
            DaysCount++;
        IncreaseAdateByOneDay(VactionStartDate);
    }
    return (DaysCount);
}

stDate VactionRetunDate(stDate& VactionStartDate, int VactionDays)
{
    stDate VactionEndDate = VactionStartDate;

    // Skip to next business day if start date is weekend
    while (isWeekEnd(VactionEndDate))
        IncreaseAdateByOneDay(VactionEndDate);

    while (VactionDays > 0)
    {
        if (isBusinessDay(VactionEndDate))
        {
            VactionDays--;
        }
    
            IncreaseAdateByOneDay(VactionEndDate);
    }

     // Ensure return date is also a business day
    while (isWeekEnd(VactionEndDate))
        IncreaseAdateByOneDay(VactionEndDate);
        
    return VactionEndDate;
}

int main()
{
    stDate VactionStartDate;
    VactionStartDate.day = 1;
    VactionStartDate.month = 1;
    VactionStartDate.year = 2022;

    stDate VactionEndDate = VactionRetunDate(VactionStartDate, 22);


    cout << VactionEndDate.day << "/" << VactionEndDate.month << "/" << VactionEndDate.year  << endl; 

    return 0;
}