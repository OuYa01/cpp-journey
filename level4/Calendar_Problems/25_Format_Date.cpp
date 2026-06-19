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

string FormatDate(stDate date, string format, string delim)
{
    int i;
    vector<string> Vformat = splitStringIntoVector(format, delim);
    string strdate;

    for (i = 0; i < Vformat.size(); i++)
    {
        if (Vformat[i] == "dd")
        {
            strdate.append(to_string(date.day));
        }
        else if (Vformat[i] == "mm")
        {
            strdate.append(to_string(date.month));
        }
        else if (Vformat[i] == "yyyy")
        {
            strdate.append(to_string(date.year));
        }
        else
        {
            cout << "theres error in your format it should have only dd and mm and yyyy\n";
            return NULL;
        }

        if (i != Vformat.size() - 1)
        {
            strdate.append(delim);
        }
    }

    return (strdate);
}


string myReplace(string str ,int pos, int sizeOfWord, string word)
{
  
    int i;

    for (i = 0; i < sizeOfWord; i++)
    {
        str[i+pos] = word[i];
    }

    return str;
}

string ReplaceWordInString(string str, string wordToReplace, string neWord)
{
    short pos = str.find(wordToReplace);
    str = myReplace(str, pos, neWord.length(), neWord);

    return str;
}



string FormatDate_v2(stDate date, string DateFormat)
{
    string FormatedDateString = "";
    FormatedDateString = ReplaceWordInString(DateFormat, "dd", to_string(date.day));
    FormatedDateString = ReplaceWordInString(FormatedDateString, "mm", to_string(date.month));
    FormatedDateString = ReplaceWordInString(FormatedDateString, "yyyy", to_string(date.year));

    return FormatedDateString;
}


int main(void)
{
    string StrDate = ReadDateString();
    stDate Date = StringToDateV2(StrDate);

    cout << FormatDate_v2(Date, "dd/mm/yyyy") << endl;
    cout << FormatDate_v2(Date, "yyyy-dd-mm") << endl;
    cout << FormatDate_v2(Date, "mm/dd/yyyy") << endl;
    cout << FormatDate_v2(Date, "yyyy?mm?dd") << endl;
    cout << FormatDate_v2(Date, "Day:dd, Month:mm, Year:yyyy") << endl;

}