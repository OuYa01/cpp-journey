#include "main.h"



/**
 * showMenueScreen - Menue Screen for print
 */
void showMenueScreen()
{
    cout << "===============================================\n";
    cout << "\t\tMain Menue Screen\n";
    cout << "===============================================\n";
    cout << "\t[1] Show Client list.\n";
    cout << "\t[2] Add Client.\n";
    cout << "\t[3] Delet Client.\n";
    cout << "\t[4] Upate Client.\n";
    cout << "\t[5] Find Client.\n";
    cout << "\t[6] Transactions menue.\n";
    cout << "\t[7] Exit.\n";
    cout << "===============================================\n";
    cout << "Choose what do you want to do? [1 to 7]?  ";

}


/**
 * PrintClientCard - It's Print One Client detiles(Data).
 */
void PrintClientCard(stClient& Client)
{
    cout << "| " << left << setw(15) << Client.AccountNumber;
    cout << "| " << left << setw(12) << Client.PinCode;
    cout << "| " << left << setw(40) << Client.Name;
    cout << "| " << left << setw(12) << Client.PhoneNumber;
    cout << "| " << left << setw(12) << Client.accountBalance;
    cout << "\n";
}


/**
 * ShowClientList - This Function is Just To Show Client List
 * 
 * @AllClientData : This is a referance to a vector of structure 'stClient' that Have All Clients Data.
 * 
 * Return : Nothing
 */
void ShowClientList(vector<stClient>& AllClientsData)
{
    cout << "\t\t\t\tClient List ("<< AllClientsData.size() << ") Client(s)\n";
    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(12) << "Pin Code";
    cout << "| " << left << setw(40) << "Name";
    cout << "| " << left << setw(12) << "PhoneNumber";
    cout << "| " << left << setw(12) << "AccountBalance";

    cout << "\n";
    for (stClient& Client : AllClientsData)
    {
        PrintClientCard(Client);
    }
}



/**
 * ExitMenue - Just small thing to print when user want to Exit
 */
void ExitMenue()
{
    cout << "----------------------------------------------------------\n";
    cout << "\t\tProgram Ends\n";
    cout << "----------------------------------------------------------\n";
}