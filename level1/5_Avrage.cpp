#include <iostream>
using namespace std;

enum passfail {pass = 1, fail = 0};

void ReadMarks(int &mark1, int &mark2, int &mark3)
{
    cout << "entre mark1 : ";
    cin >> mark1;
    cout << "entre mark2 : ";
    cin >> mark2;
    cout << "entre mark3 : ";
    cin >> mark3;
}

int sumof3Marks(int mark1, int mark2, int mark3)
{
    return (mark1 + mark2 + mark3);
}

float calculateAvrage(int mark1, int mark2, int mark3)
{
    return (float(sumof3Marks(mark1, mark2, mark3)) / 3);
}

passfail CkeckAvrage(float Avrage)
{
    if (Avrage >= 10)
     return (passfail::pass);
    else
        return (passfail::fail);
}

void PrintResults(float Avrage)
{
    cout << "Your Average is: " << Avrage << endl;

    if (CkeckAvrage(Avrage) == passfail::pass)
        cout << "\n You passed" << endl;
    else
        cout << "\n You faild" << endl;
}


int main(void)
{
    int mark1, mark2, mark3;
    ReadMarks(mark1, mark2, mark3);
    PrintResults(calculateAvrage(mark1, mark2, mark3));
}