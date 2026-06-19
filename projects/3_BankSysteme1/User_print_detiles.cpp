#include "Headers/users.h"


void ShowLoginScreen()
{
    cout << "-------------------------------------------\n";
    cout << "\t\t Login Screen\n";
    cout << "-------------------------------------------\n";
}


void showUsersMenueScreen()
{
    cout << "===============================================\n";
    cout << "\t\tUsers Menue Screen\n";
    cout << "===============================================\n";
    cout << "\t[1] List Users.\n";
    cout << "\t[2] Add New User.\n";
    cout << "\t[3] Delet User.\n";
    cout << "\t[4] Update User.\n";
    cout << "\t[5] Find User.\n";
    cout << "\t[6] Main Menue.\n";
    cout << "===============================================\n";
    cout << "Choose what do you want to do? [1 to 6]?  ";
}


void PrintUserCard(stUsers& user)
{
    cout << "| " << left << setw(15) << user.UserName;
    cout << "| " << left << setw(12) << user.PassWord;
    cout << "| " << left << setw(40) << user.Permission;
    cout << "\n";
}

void ShowUsersList(vector<stUsers>& AllUsersList)
{
    cout << "\tUsers List ("<< AllUsersList.size() << ") User(s)\n\n";
    cout << "| " << left << setw(15) << "User Name";
    cout << "| " << left << setw(12) << "PassWord";
    cout << "| " << left << setw(40) << "Permissions";


    cout << "\n";
    for (stUsers& user : AllUsersList)
    {
         PrintUserCard(user);
    }
}

void PrintAccessDenied()
{
    cout << "-----------------------------------\n";
    cout << "\t Access Denied,\nYou Don't Have Permission To Do This,\nPlease contact your admin.\n";
    cout << "-----------------------------------\n";
}
