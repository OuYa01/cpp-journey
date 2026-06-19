#include <iostream>
#include <sstream>
#include <string>
#include <vector>

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

std::vector<std::string> splitStringIntoVector(std::string s, std::string delim)
{
	std::vector<std::string> v;
	std::string sword;
	short pos = 0;

	while ((pos = s.find(delim)) != std::string::npos)
	{
		sword = s.substr(0, pos);
		
		if (sword != "")
		{
			v.push_back(sword);
		}

		s.erase(0, pos + delim.length());
	}

	if (s != "")
	{
		v.push_back(s);
	}

	return (v);
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

stDate StringToDateV2(const std::string& strdate)
{
    stDate date{};
    vector <string> vDate;

    vDate = splitStringIntoVector(strdate, "/");
    date.day = stoi(vDate[0]);
    date.month = stoi(vDate[1]);
    date.year = stoi(vDate[2]);

    return (date);
}

string DateToString(const stDate stdate)
{
    string strdate = to_string(stdate.day) + "/" + to_string(stdate.month) + "/" + to_string(stdate.year);
    return strdate;
}



int main(void)
{
    string StrDate = ReadDateString();
    stDate Date = StringToDateV2(StrDate);

    cout << endl;
    cout << "Day: " << Date.day << endl;
    cout << "Month: " << Date.month << endl;
    cout << "Year: " << Date.year << endl;
    cout << endl;

    cout << "You Entered : " << DateToString(Date);
}