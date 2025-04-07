#include "Transactions.h"


void ShowTransactionsMenue()
{
    cout << "===============================================\n";
    cout << "\t\tTransactions Menue Screen\n";
    cout << "===============================================\n";
    cout << "\t[1] Deposit.\n";
    cout << "\t[2] Withdraw.\n";
    cout << "\t[3] TotalBalance.\n";
    cout << "\t[4] Main menue.\n";
    cout << "===============================================\n";
    cout << "Choose what do you want to do? [1 to 4]?  ";
}

void TransactionsSwitch(vector<stClient>& AllClientsData)
{
    int YourChoice;

    do
    {
        system("cls");
        ShowTransactionsMenue();
        cin >> YourChoice;
        switch (YourChoice)
        {
            case 1: 
                    system("cls");
                    Deposit(AllClientsData);
                    BackToMenu();
                break;
            case 2:
                    system("cls");
                    Withdraw(AllClientsData);
                    BackToMenu();
                break;
            case 3:
                    system("cls");
                    TotalBalance(AllClientsData);
                    BackToMenu();
                break;
            case 4:
                    system("cls");
                break;
            default:
                    cout << "Choice Not Found, Try Again";
                    BackToMenu();
        }
    }while(YourChoice != 4);

}


string GetString(string msg)
{
    string str;
    cout << msg ;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, str);

    return (str);
}

void UpdateClient(vector<stClient>& AllClientsData, stClient& Client)
{
    for (stClient& c : AllClientsData)
    {
        if (c.AccountNumber == Client.AccountNumber)
            c = Client;
    }
}

void Deposit(vector<stClient>& AllClientsData)
{

    cout << "______________________________________________________________________________________________________________________\n\n";
    cout << "\t\tDeposit Screen\n";
    cout << "\n\n______________________________________________________________________________________________________________________\n\n";

    while (1)
    {
    
        string AccountNumber = GetString("Enter Account Number: ");
        stClient ClientData;
        float DepositAmount;
        char perform;

        if (ClientFound(AllClientsData ,AccountNumber, ClientData))
        {
            PrintClientCard(ClientData);
            cout << "Please Enter deposit amount: ";
            cin >> DepositAmount;
            cout << "\nAre You sur you want perform this transaction (y/n)? ";
            cin >> perform;

            if (perform == 'y' || perform == 'Y')
            {
                ClientData.accountBalance += DepositAmount;
                UpdateClient(AllClientsData, ClientData);
                LoadAllDataFromVecToFile(AllClientsData);
                break;
            }
            else
                break;
        }
        else
        {
            cout << "Client Not Found\n";
            cout << "Try Again (y/n)? ";
            cin >> perform;
            if (perform != 'y' && perform != 'Y')
                break;
        }
    }

}

void Withdraw(vector<stClient>& AllClientsData)
{
    cout << "______________________________________________________________________________________________________________________\n\n";
    cout << "\t\tWithdraw Screen\n";
    cout << "\n\n______________________________________________________________________________________________________________________\n\n";

    while (true)
    {
        string AccountNumber = GetString("Enter Account Number: ");
        stClient ClientData;
        float WithdrawAmount;
        char perform;

        if (ClientFound(AllClientsData ,AccountNumber, ClientData))
        {
            PrintClientCard(ClientData);
            
            do 
            {
                cout << "Please Enter Withdraw amount: ";
                cin >> WithdrawAmount;


                if (WithdrawAmount > ClientData.accountBalance || WithdrawAmount <= 0)
                {
                    cout << "The Amount Exceeds the balance You Have, You can withdraw up to : " << ClientData.accountBalance << endl;
                }

            }while(WithdrawAmount > ClientData.accountBalance || WithdrawAmount <= 0);


            cout << "\nAre You sur you want perform this transaction (y/n)? ";
            cin >> perform;
            if (perform == 'y' || perform == 'Y')
            {
                ClientData.accountBalance -= WithdrawAmount;
                UpdateClient(AllClientsData, ClientData);
                LoadAllDataFromVecToFile(AllClientsData);
                cout << "\nTransaction completed successfully!\n";
                break;
            }
            else
                break;;
        }
        else
        {
            cout << "Client Not Found\n";
            cout << "Try Again (y/n)? ";
            cin >> perform;
            if (perform != 'y' && perform != 'Y')
                break;
        }
    }

}

void PrintBalanceClient(stClient& ClientData)
{
    cout << "| " << left << setw(15) << ClientData.AccountNumber;
    cout << "| " << left << setw(20) << ClientData.Name;
    cout << "| " << left << setw(15) << ClientData.accountBalance;
    cout << endl;
}

float CalculeTotalBalance(vector<stClient>& AllClientsData)
{
    float TotalBalance;

    TotalBalance = 0;
    for (stClient& c : AllClientsData)
    {
        TotalBalance += c.accountBalance;
    }
    return (TotalBalance);
}

void TotalBalance(vector<stClient>& AllClientsData)
{
    cout << "\t\tBalances List (" << AllClientsData.size() << ") Client(s).\n";
    cout << "----------------------------------------------------------------------------\n";
    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(20) << "Client Name";
    cout << "| " << left << setw(15) << "Balance";
    cout << "\n----------------------------------------------------------------------------\n";


    for (stClient& c : AllClientsData)
    {
        PrintBalanceClient(c);
    }
    cout << "----------------------------------------------------------------------------\n";
    cout << "\t\tTotal Balances = " << CalculeTotalBalance(AllClientsData);

}