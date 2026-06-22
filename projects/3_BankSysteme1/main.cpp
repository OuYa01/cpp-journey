#include "Headers/main.h"
#include "Headers/users.h"
#include "Headers/Transactions.h"


void Login()
{
    vector<stUsers> AllUsersData;
    LoadAllUsersDataFromFile(AllUsersData);
    ShowLoginScreen();
start:    
    GetUserInfos();

    if (CheckIfUserExist(AllUsersData))
    {
        vector<stClient> AllClientsData;
        LoadAllClientsDataFromFile(AllClientsData);
        MainMenueSwitch(AllClientsData, AllUsersData);
    }
    else
    {
        cout << "Invalide UserName/Password!\n";
        goto start;
    }
}



/**
 * main - Program Entry
 * 
 * Return : 0 if Succ
 */
int main(void)
{

    Login();

    return (0);
}