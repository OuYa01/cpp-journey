#include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct stDate {
    int year;
    int month;
    int day;
};

string ReadDateString()
{
    string Date;
    cout << "Please Enter a Date dd/mm/yyyy?  ";
    cin >> Date;

    return Date;
}

stDate StringToDate(const std::string& strdate)
{
    stDate date{};
    stringstream ss(strdate);
    string part;

    getline(ss, part, '/');
    date.day = std::stoi(part);

    getline(ss, part, '/');
    date.month = std::stoi(part);

    getline(ss, part, '/');
    date.year = std::stoi(part);

    return date;
}

string DateToString(const stDate stdate)
{
    string strdate = to_string(stdate.day) + "/" + to_string(stdate.month) + "/" + to_string(stdate.year);
    return strdate;
}



int main(void)
{
    string StrDate = ReadDateString();
    stDate Date = StringToDate(StrDate);

    cout << endl;
    cout << "Day: " << Date.day << endl;
    cout << "Month: " << Date.month << endl;
    cout << "Year: " << Date.year << endl;
    cout << endl;

    cout << "You Entered : " << DateToString(Date);
}