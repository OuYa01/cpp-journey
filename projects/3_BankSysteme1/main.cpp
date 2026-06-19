#include "Headers/main.h"
#include "Headers/users.h"
#include "Headers/Transactions.h"


void Login()
{
    vector<stUsers> AllUsersData;
    LoadAllUsersDataFromFile(AllUsersData);
    ShowLoginScreen();
    stUsers RootUser;
start:    
    GetUserInfos(RootUser);

    if (CheckIfUserExist(RootUser, AllUsersData))
    {
        vector<stClient> AllClientsData;
        LoadAllClientsDataFromFile(AllClientsData);
        MainMenueSwitch(AllClientsData, AllUsersData, RootUser);
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