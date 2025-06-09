#include <iostream>


using namespace std;

bool IsLeapYear(int year)
{
    
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
    
}



int DaysInMonth(int year, int month)
{
    if (month < 1 || month > 12)
       return 0;

    int NumberOfDyas[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return ((month != 2) ? NumberOfDyas[month - 1] : (IsLeapYear(year) ? 29 : 28));
}

int DayOrderInMonth(int year, int month, int day)
{
    int YearCode, MonthCode;
    int daysInMonth = DaysInMonth(year, month);
    int DayOrder;
    int i;
    int MonthsCode[] = {6, 2, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};

    if (IsLeapYear(year))
    {
        MonthsCode[0] = 5;
        MonthsCode[1] = 1;
    }

    YearCode = ((year % 100) + ((year % 100) / 4)) % 7;
    MonthCode = MonthsCode[month - 1];
    DayOrder = (MonthCode + day + YearCode);

    i = 0;
    while (i <= DayOrder)
    {
        i += 7;
    }
    if (i != DayOrder)
        i -= 7;

    DayOrder = DayOrder - i;

    if (DayOrder  == 7 || DayOrder == 0)
        return (7);
    else
        return (DayOrder);
}

string NameofTheDay(int DayOrder)
{
    string Days[] = {"Mo", "Tu", "We", "Th", "Fr" , "Sa", "Su"};

    return (Days[DayOrder - 1]);
}


int main(void)
{
    int year = 2022;
    int month = 9;
    int day = 25;
    int DayOrdre = DayOrderInMonth(year, month, day);

    cout << "Date : " << day << "/" << month << "/" << year << endl;
    cout << "DayOrder: " << DayOrdre << endl;
    cout << "DayName: " << NameofTheDay(DayOrdre)<< endl;
}