#include "Atm.h"




/**
 * Withdraw - is a helper function of NormalWithdraw and QuickWithdraw, its make all the work to withdraw money from account of client
 *            other functions just get data from client and check its correct 
 * 
 * @AllClientsData: Referance to Clients Data so we can make change in it 
 * 
 * @ToWithdraw This a vraible that it passes from NormalWithdraw and QuickWithdraw functions to withdraw it from account of client
 * 
 * Return:  True if transaction done otherwise return False
 */
bool Withdraw(vector<stClient>& AllClientsData ,int ToWithdraw)
{
    if (ToWithdraw > CurrentClient.accountBalance)
    {
        cout << "The amount excuted your balance, make another choice.\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nPress any key to continue ... ";
        cin.get();
        return false;
    }

    CurrentClient.accountBalance -= ToWithdraw;

    for (stClient& client : AllClientsData)
    {
        if (client.AccountNumber == CurrentClient.AccountNumber)
        {
            client.accountBalance -= ToWithdraw;
            LoadAllDataFromVecToFile(AllClientsData);
            return true;
        }
    }

     return false;
}


/**
 * QuickWithdraw - Show predefine options of money to withdraw from account of clinet.
 * 
 * @AllClientsData: Referance to Clients Data so we can make change in it 
 */
void QuickWithdraw(vector<stClient>& AllClientsData)
{
    int choice;
    int Towithdraw[8] = {20, 50, 100, 200, 400, 600, 800, 1000};
    char c;
    bool transactionDone = false;
    while(!transactionDone)
    {

        cout << "-------------------------------------------------------\n";
        cout << "\t\t Quick Withdraw Screen\n";
        cout << "-------------------------------------------------------\n";
        cout << "\t[1] 20  \t[2] 50\n";
        cout << "\t[3] 100 \t[4] 200\n";
        cout << "\t[5] 400 \t[6] 600\n";
        cout << "\t[7] 800 \t[8] 1000\n";
        cout << "\t[9] Exit\n";
        cout << "-------------------------------------------------------\n";
        cout << "Your Balance is " << CurrentClient.accountBalance << endl;
        cout << "Choose what to withdraw from (1-8) ? ";
        cin >> choice;



        if ( choice > 0 && choice < 9)
        {
            cout << "Are you sure you want to perform this transaction? (y/n)? ";
            cin >> c;
            if (c == 'Y' || c == 'y')
            {
                if (Withdraw(AllClientsData ,Towithdraw[choice - 1]) == true)
                {
                    cout << "Done succssfully. New Balance is : " << CurrentClient.accountBalance << endl;
                    transactionDone = true;
                }
                else
                {
                    ClearScreen();
                }
            }
            else
                break;

        }
        else if (choice == 9)
        {
            break;
        }
        else
        {
            cout << "This choice is not found please enter choice between (1-9)\n";
        }
    }

}


/**
 * NormalWithdraw - function that accept amoun multiple of 5 lik 50, 100, 200 ... to withdraw it to the client from his account.
 * 
 * @AllClientsData: Referance to Clients Data so we can make change in it 
 */
void NormalWithdraw(vector<stClient>& AllClientsData)
{
    int ToWithdraw;
    char c;
    bool transactionDone = false;

    while(!transactionDone)
    {
            cout << "-------------------------------------------------------\n";
            cout << "\t\t Normal Withdraw Screen\n";
            cout << "-------------------------------------------------------\n";

            do
            {
                cout << "Enter an Positive Amount Multiple of  5's? ";
                cin >> ToWithdraw;

            } while (ToWithdraw % 5 != 0 || ToWithdraw <= 0);



            cout << "Are you sure you want to perform this transaction? (y/n)? ";
            cin >> c;
            if (c == 'y' || c == 'Y')
            {
                if (Withdraw(AllClientsData, ToWithdraw) == true)
                {
                    cout << "Done succssfully. New Balance is : " << CurrentClient.accountBalance << endl;
                    transactionDone = true;
                }
                else 
                {
                    ClearScreen();
                }
            }
            else
                break;
    }

}


/**
 * CheckBalance - thsi function shows client money in his account
 */
void CheckBalance()
{
    cout << "-------------------------------------------------------\n";
    cout << "\t\t Check Balance Screen\n";
    cout << "-------------------------------------------------------\n";

    cout << "Your Balance is " << CurrentClient.accountBalance << endl;
}


/**
 * Deposit - This function is get the number of deposit clinet want to save in his account and add it to his balance.
 * 
 * @AllClientsData: Referance to Clients Data so we can make change in it 
 */
void Deposit(vector<stClient>& AllClientsData)
{
    int depo;
    char c;


    cout << "-------------------------------------------------------\n";
    cout << "\t\t Deposit Screen\n";
    cout << "-------------------------------------------------------\n";

    do
    {
        cout << "Enter a positive deposite amount? ";
        cin >> depo;

    } while (depo < 0);

    cout << "Are you sure you want to perform this transaction? (y/n)? ";
    cin >> c;

    if (c == 'y' || c == 'Y')
    {
        CurrentClient.accountBalance += depo;

        for (stClient& client : AllClientsData)
        {
            if (client.AccountNumber == CurrentClient.AccountNumber)
            {
                client.accountBalance += depo;
                LoadAllDataFromVecToFile(AllClientsData);
                cout << "Done succssfully. New Balance is : " << CurrentClient.accountBalance << endl;
            }
        }
    }

}   


/**
 * MainAtmMenueSwitch: This function shwo screen of all optiosn of this Atm,
 *                     and get Your choice to run the function of this option
 * 
 * @AllClientsData: Referance to Clients Data so we can make change in it 
 */
void MainAtmMenueSwitch(vector<stClient>& AllClientsData)
{
    int YourChoice;

    do
    {
        ClearScreen();
        showAtmMenueScreen();
        cin >> YourChoice;
        switch (YourChoice)
        {
            case 1:
                ClearScreen();
                QuickWithdraw(AllClientsData);
                BackToMenu();
                break;
            case 2:
                ClearScreen();
                NormalWithdraw(AllClientsData);
                BackToMenu();
                break;
            case 3:
                ClearScreen();
                Deposit(AllClientsData);
                BackToMenu();
                break;
            case 4:
                ClearScreen();
                CheckBalance();
                BackToMenu();
                break;
            case 5:
                ClearScreen();
                return;
            default:
                    cout << "Choice Not Found, Try Again";
                    BackToMenu();
        }
    }while(YourChoice != 5);

}


/**
 * Login - show login screen and get infos of clients. If client found show him the Atm menue with his data, else show an error.
 */
void Login()
{
    vector<stClient> AllClientsData;
    bool isLoginFailed;
    LoadAllClientsDataFromFile(AllClientsData);
    
    while (true)
    {

        ShowLoginScreen();
        do
        {
            GetClientInfos();
            isLoginFailed = !CheckIfClientExist(AllClientsData);

            if (!isLoginFailed)
            {
                MainAtmMenueSwitch(AllClientsData);
            }
            else
            {
                cout << "Invalide UserName/Password!\n";
            }

        }while(isLoginFailed);

    }

}