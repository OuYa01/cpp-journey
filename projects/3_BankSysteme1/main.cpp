#include "main.h"
#include "Transactions.h"

/**
 * main - Program Entry
 * 
 * Return : 0 if Succ
 */
int main(void)
{
    vector<stClient> AllClientsData;
    LoadAllClientsDataFromFile(AllClientsData);
    MainMenueSwitch(AllClientsData);

    return (0);
}