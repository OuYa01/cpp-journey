#include <iostream>


using namespace std;

struct stdate {
    int year;
    int month;
    int day;
};

bool IsLeapYear(int year)
{
    
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
    
}


int DaysInMonth(int year, int month)
{
    if (month < 1 || month > 12)
    {
        cout << "You enter month out of range (1 - 12)" << endl;
        exit(1);
    }

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


bool Date1IsLessThanDate2(stdate date1, stdate date2)
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

bool Date1IsLessThanDate2v2(stdate date1, stdate date2)
{
    return (
        (date1.year < date2.year) ? true 
        : (date1.year > date2.year) ? false 
        : ((date1.month < date2.month) ? true 
        : (date1.month > date2.month) ? false
        : ((date1.day < date2.day) ? true 
        : false )));
}


int main()
{
    stdate date1 = {2002, 12, 24};
    stdate date2 = {2003, 11, 23};

    if (Date1IsLessThanDate2v2(date1, date2))
    {
        cout << "Date1 is less than date2" << endl;
    }
    else
    {
        cout << "Date1 is not less than date2" << endl;
    }
}