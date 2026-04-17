#include <iostream>

using namespace std;
struct stDate {
    int year;
    int month;
    int day;
};

struct stPeriod {
    stDate StartDate;
    stDate EndDate;
};
 


bool Date1IsBeforeDate2(stDate date1, stDate date2)
{
    return (
        (date1.year < date2.year) ? true 
        : (date1.year > date2.year) ? false 
        : ((date1.month < date2.month) ? true 
        : (date1.month > date2.month) ? false
        : ((date1.day < date2.day) ? true 
        : false )));
}

bool date1IsEqualToDate2(stDate& date1, stDate& date2)
{
    return (date1.day == date2.day && date1.year == date2.year && date1.month == date2.month);
}

bool Date1IsAfterDate2(stDate& date1, stDate& date2)
{
    if (!Date1IsBeforeDate2(date1, date2) && !date1IsEqualToDate2(date1, date2))
        return (true);
    return (false);
}




bool isDateinPeriod(stDate& date, stPeriod& period)
{
    
    if (Date1IsAfterDate2(date, period.StartDate) && Date1IsBeforeDate2(date, period.EndDate))
        return true;
    else if (date1IsEqualToDate2(date, period.StartDate) || date1IsEqualToDate2(date, period.EndDate))
        return true;
    
    return false;
}


bool isDateinPeriodv2(stDate& date, stPeriod& period)
{
    return !(Date1IsBeforeDate2(date, period.StartDate) || Date1IsAfterDate2(date, period.EndDate));
}


int main(void)
{
    stPeriod period = { {2024, 3, 10}, {2024, 3, 20} };

    stDate testDates[] =
    {
        {2024, 3, 9},
        {2024, 3, 10},
        {2024, 3, 15},
        {2024, 3, 20},
        {2024, 3, 21}
    };

    cout << "Period: "
         << period.StartDate.day << "/" << period.StartDate.month << "/" << period.StartDate.year
         << " -> "
         << period.EndDate.day << "/" << period.EndDate.month << "/" << period.EndDate.year
         << endl << endl;

    for (stDate date : testDates)
    {
        cout << "Date "
             << date.day << "/" << date.month << "/" << date.year
             << " : "
             << (isDateinPeriodv2(date, period) ? "Inside period" : "Outside period")
             << endl;
    }

    return 0;

}
