#include <iomanip>
#include <ios>
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


void PrintMonthCalendar(int year, int month)
{
    string months[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                        "Jul","Aug", "Sep", "Oct", "Nov", "Dec" };
    int i, count;
    
    cout << "_______________" << months[month - 1] << "_______________" << endl;
    cout <<"Sun  Mon  Tue  Wed  Thu  Fri  Sat" << endl;

    int FirsDayOfMonthOrder = DayOrderInMonth(year, month, 1);
    count = 0;

    if (FirsDayOfMonthOrder != 7)
    {
            cout << right << setw(FirsDayOfMonthOrder * 5) << " ";
            count = FirsDayOfMonthOrder;
    }


    
    for (i = 1; i <= DaysInMonth(year, month); i++)
    {
        if (count == 7)
        {
            count = 0;
            cout << "\n";
        }
        cout << right << setw(3) << i << right << "  ";
        count++;
    }
    cout << "\n";

    cout << "__________________________________\n\n";
    
}


void PrintYearCalendar(int year)
{
    int i;
    cout << "__________________________________\n";
    cout << "\n        Calendar - " << year << endl;
    cout << "__________________________________\n" << endl;

    for (i = 1; i <= 12; i++)
    {
        PrintMonthCalendar(year, i);
    }

}

int main(void)
{
    PrintYearCalendar(2025);    
}