#include <iostream>
using namespace std;

string ReadPinCode()
{
    string pin;
    
    cout << "Entre Pin: ";
    cin >> pin;

    return (pin);
}

bool login()
{
    string pin;
    int count = 0;
    do
    {
        pin = ReadPinCode();
        
        if (pin == "7281")
            return (true);

        system("Color 4F");
        cout << "Invalid password, Try Again\n";
        count++;

    } while (count != 3);

        return (false);
    
}

int main(void)
{
    if (login())
    {
        system("Color 2F");
        cout << "Your password is correct";
    }
    else
    {
        system("Color 1F");
        cout << "Try again after 30 min\n";
    }

    return (0);
}