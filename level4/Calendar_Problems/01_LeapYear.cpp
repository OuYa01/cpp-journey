#include <iostream>

using namespace std;

/**
 * IsLeapYear - this function cheack if a giving Year is a leap year or not
 * @year : the year to check
 * 
 * Return : true if year is leap otherwise false
 *
 * Description : A normal year has 365 days. A leap year has 366 days (with the extra day occurring in February - Month 2)
 */
bool IsLeapYear(int year)
{
    
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
    
}

int main(void)
{
    cout << IsLeapYear(2000) << endl;
    cout << IsLeapYear(1971) << endl;
    cout << IsLeapYear(2004) << endl;
    cout << IsLeapYear(2006) << endl;
    cout << IsLeapYear(2012) << endl;
}