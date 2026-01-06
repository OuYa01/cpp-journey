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



int main()
{
    // Example date structure
    stDate today;
    today.day = 7;
    today.month = 10;
    today.year = 2025;

    // Test PrintTodayDate
    cout << "==============================" << endl;
    cout << "Testing PrintTodayDate:" << endl;
    cout << "------------------------------" << endl;
    PrintTodayDate(today);
    cout << endl;

    // Test isWeekEnd
    cout << "==============================" << endl;
    cout << "Testing isWeekEnd:" << endl;
    cout << "------------------------------" << endl;
    if (isWeekEnd(today))
        cout << "The given date is a weekend." << endl;
    else
        cout << "The given date is not a weekend." << endl;
    cout << endl;

    // Test isBusinessDay
    cout << "==============================" << endl;
    cout << "Testing isBusinessDay:" << endl;
    cout << "------------------------------" << endl;
    if (isBusinessDay(today))
        cout << "The given date is a business day." << endl;
    else
        cout << "The given date is not a business day." << endl;
    cout << endl;

    // Test DaysUntilEndOfWeek
    cout << "==============================" << endl;
    cout << "Testing DaysUntilEndOfWeek:" << endl;
    cout << "------------------------------" << endl;
    int daysToEndOfWeek = DaysUntilEndOfWeek(today);
    cout << "Days until the end of the week: " << daysToEndOfWeek << endl;
    cout << endl;

    // Test isLeapYear
    cout << "==============================" << endl;
    cout << "Testing isLeapYear:" << endl;
    cout << "------------------------------" << endl;
    if (isLeapYear(today.year))
        cout << today.year << " is a leap year." << endl;
    else
        cout << today.year << " is not a leap year." << endl;
    cout << endl;

    // Test NumberOfDaysInAMonth
    cout << "==============================" << endl;
    cout << "Testing NumberOfDaysInAMonth:" << endl;
    cout << "------------------------------" << endl;
    int daysInMonth = NumberOfDaysInAMonth(today.month, today.year);
    cout << "Number of days in month " << today.month << ": " << daysInMonth << endl;
    cout << endl;

    // Test DaysUntilEndOfMonth
    cout << "==============================" << endl;
    cout << "Testing DaysUntilEndOfMonth:" << endl;
    cout << "------------------------------" << endl;
    int daysToEndOfMonth = DaysUntilEndOfMonth(today);
    cout << "Days until the end of the month: " << daysToEndOfMonth << endl;
    cout << endl;

    // Test DaysUntilEndOfYear
    cout << "==============================" << endl;
    cout << "Testing DaysUntilEndOfYear:" << endl;
    cout << "------------------------------" << endl;
    int daysToEndOfYear = DaysUntilEndOfYear(today);
    cout << "Days until the end of the year: " << daysToEndOfYear << endl;
    cout << endl;

    return 0;
}