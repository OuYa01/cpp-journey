#include <iostream>
using namespace std;

struct info
{
    string firstName;
    string LastName;
    int age;
    string phone;
};

void readInfo(info &prs)
{
    cout << "first Name: ";
    cin >> prs.firstName;
    cout << "Last Name: ";
    cin >> prs.LastName;
    cout << "Age: ";
    cin >> prs.age;
    cout << "Phone number: ";
    cin >> prs.phone;
}

void printInfo(info prs)
{
    cout << "first Name: "<< prs.firstName<< "\n";
    cout << "Last Name: "<< prs.LastName<< "\n";
    cout << "Age: "<< prs.age<< "\n";
    cout << "Phone number: "<< prs.phone;
}

int main(void)
{
    info prs1;
    readInfo(prs1);
    printInfo(prs1);
}
