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


/**
 * DayOfYear - Number of days from the begining of the year
 */
int DayOfYear(int year, int month, int day)
{
    int i, j;
    int total = 0;
    for (i = 1; i < month; i++)
    {
        total += DaysInMonth(year, i);
    }

    return (total + day);
}

stdate GetDateFromDayOrderInYear(int year, int total)
{
    int i, temp;
    stdate date;

    date.year = year;
    date.month = 12;
    temp = (IsLeapYear(year)) ? 366 : 365;
    while (date.month > 1)
    {
        temp -= DaysInMonth(year, date.month);
        if (temp < total)
            break;
        date.month--;
    }
    date.day = total - temp;

    return (date);
}




stdate AddDaysTospecifiqueDate(stdate date, int days)
{
    int total = DayOfYear(date.year, date.month, date.day) + days;
    int monthDays;

    date.month = 1;
    while (true)
    {
        monthDays = DaysInMonth(date.year, date.month);

        if (total > monthDays)
        {
            total -= monthDays;
            date.month++;

            if (date.month > 12)
            {
                date.month = 1;
                date.year++;
            }
        }
        else
        {
            date.day = total;
            break;
        }
    
    }

    return date; 

}



int main(void)
{
    stdate date = {2002, 12, 24};
    date = AddDaysTospecifiqueDate(date, 365);

    cout << date.year << "/" << date.month << "/" << date.day << endl;
}