#include "main.h"
#include "Transactions.h"




void MainMenueSwitch(vector<stClient>& AllClientsData)
{
    int YourChoice;

    do
    {
        system("cls");
        showMenueScreen();
        cin >> YourChoice;
        switch (YourChoice)
        {
            case 1: 
                    system("cls");
                    ShowClientList(AllClientsData);
                    BackToMenu();
                break;
            case 2:
                    system("cls");
                    AddClient(AllClientsData);
                    BackToMenu();
                break;
            case 3:
                    system("cls");
                    DeletClientByAccountNumber(AllClientsData);
                    BackToMenu();
                break;
            case 4:
                    system("cls");
                    UpateClientDataByAccountNumber(AllClientsData);
                    BackToMenu();
                break;
            case 5:
                    system("cls");
                    FindClient(AllClientsData);
                    BackToMenu();
                break;
            case 6:
                system("cls");
                TransactionsSwitch(AllClientsData);
            break;
            case 7:
                    system("cls");
                    ExitMenue();
                    exit(0);
                break;
            default:
                    cout << "Choice Not Found, Try Again";
                    BackToMenu();
        }
    }while(YourChoice != 7);

}


/**
 * AddClient - This Fuction is to Add Client, By collect all it Data, and add it to the file and the Vector
 * @AllClientData : This is a referance to a vector of structure 'stClient' to Add Client To it.
 *
 * Retunr : Nothing
 */
void AddClient(vector<stClient>& AllClientsData)
{
    stClient Client;
    ofstream ClientDataFile(FileName, ios::app);
    char Again;

    cout << "______________________________________________________________________________________________________________________\n";
    cout << "Adding New Client\n";
    cout << "______________________________________________________________________________________________________________________\n";
    
    do
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entre Account Number: ";
        getline(cin, Client.AccountNumber);

        if (ClientFound(AllClientsData, Client.AccountNumber, Client))
        {
            cout << "\nClient Found !\nEntre Another one? (Y/n)? ";
            cin >> Again;
            if (Again == 'y' || Again == 'Y')
                continue;
            else
                return ;
        }

        cout << "Entre Pin Code : ";
        getline(cin, Client.PinCode);
        cout << "Entre Your Name: ";
        getline(cin ,Client.Name);
        cout << "Entre Your Phone Number: ";
        getline(cin ,Client.PhoneNumber);
        cout << "Entre Account Balance: ";
        cin >> Client.accountBalance;
        

        if (ClientDataFile.is_open())
        {
            AllClientsData.push_back(Client);
            ClientDataFile << ConverClientToRecordeLine(Client);
        }
        else
        cout << "error file not opening\n";

        cout << "Client Add Successfully, Do you want to add More Client (Y/n)? ";
        cin >> Again;

    }while(Again == 'Y' || Again == 'y');
    ClientDataFile.close();
}




/**
 * DeletClient - This Function Delet Client from Vector using Target Account Number.
 * 
 * @AllClientData : This is a referance to a vector of structure 'stClient' to Delet Client From it.
 * @TargetAccountNumber : This is a referance to A string that have the target account number that we want to Delet
 * 
 * Retunr : Nothing
 */
void DeletClient(vector<stClient>& AllClientsData, string& TargetAccountNumber)
{
    int i;

    for (i = 0; i < AllClientsData.size(); i++)
    {
        if (AllClientsData[i].AccountNumber == TargetAccountNumber)
        {
            AllClientsData.erase(AllClientsData.begin() + i);
            break;
        }
    }

}



/**
 * DeletClientByAccountNumber - To Delet Client Data in file and vector using Target account Number.
 * 
 * @AllClientData : This is a referance to a vector of structure 'stClient' to Update Data in it and send it back to file
 * 
 * Return : Nothing
 */
void DeletClientByAccountNumber(vector<stClient>& AllClientsData)
{
    stClient client;
    string TargetAccountNumber;
    char Del;

    cout << "______________________________________________________________________________________________________________________\n\n";
    cout << "\tDelet Client\n";
    cout << "\n\n______________________________________________________________________________________________________________________\n\n";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Entre Client Account Number: ";
    getline(cin, TargetAccountNumber);
    
    if (ClientFound(AllClientsData, TargetAccountNumber, client))
    {
        PrintClientCard(client);
        cout << "\nAre you sure You Want To delet this Client ? (Y/N)";
        cin >> Del;
        if (Del == 'Y' || Del == 'y')
        {
            DeletClient(AllClientsData, TargetAccountNumber);
            LoadAllDataFromVecToFile(AllClientsData);
            cout << "\nClient Deleted Succ\n";
        }
        return ;
    }
    cout << "Client Not Found!!\n";

}

/**
 * UpdateClient - This is a subfunction of {UpateClientDataByAccountNumber} function,
 *                Is just to get information from user to update them
 * 
 * @AllClientData : This is a referance to a vector of structure 'stClient' to Update Data in it and send it back to file
 * @TargetAccountNumber : This is a referance to A string that have the target account number that we want to update
 * 
 * Return : Nothing
 */
void UpdateClient(vector<stClient>& AllClientsData, string& TargetAccountNumber)
{

    for (stClient& Client : AllClientsData)
    {
        if (Client.AccountNumber == TargetAccountNumber)
        {
            Client.AccountNumber = TargetAccountNumber;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entre New Pin Code : ";
            getline(cin, Client.PinCode);
            cout << "Entre New Name: ";
            getline(cin ,Client.Name);
            cout << "Entre New Phone Number: ";
            getline(cin ,Client.PhoneNumber);
            cout << "Entre Account Balance: ";
            cin >> Client.accountBalance;
            break;
        }
    }

}


/**
 * UpateClientDataByAccountNumber - To update Client Data in file and vector using Target account Number.
 * 
 * @AllClientData : This is a referance to a vector of structure 'stClient' to Update Data in it and send it back to file
 * 
 * Return : Nothing
 */
void UpateClientDataByAccountNumber(vector<stClient>& AllClientsData)
{
    stClient client;
    string TargetAccountNumber;
    char Update;

    cout << "______________________________________________________________________________________________________________________\n\n";
    cout << "\t\tUpdate Client\n";
    cout << "\n\n______________________________________________________________________________________________________________________\n\n";
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Entre Client Account Number: ";
    getline(cin, TargetAccountNumber);

    if (ClientFound(AllClientsData, TargetAccountNumber, client))
    {
        PrintClientCard(client);
        cout << "\nAre you sure You Want To Upate this Client ? (Y/N)";
        cin >> Update;
        if (Update == 'Y' || Update == 'y')
        {
            UpdateClient(AllClientsData, TargetAccountNumber);
            LoadAllDataFromVecToFile(AllClientsData);
            cout << "\nClient Updated succ!!\n";
        }
        return ;
    }
    
    cout << "\nClient Not Found!!\n";
}


/**
 * FinClient - This function checks if the client is already in our data using their Target Account Number.
 *             If we find the client, we display their details. If not, we say that the client was not found.
 * 
 * @AllClientData : This is a referance to a vector of structure 'stClient' that we will check if Client are in it or not.
 * 
 * Return : Nothing
 */
void FindClient(vector<stClient>& AllClientsData)
{
    string TargetAccountNumber;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Entre Account Number: ";
    getline(cin, TargetAccountNumber);

    int i;

    for (i = 0; i < AllClientsData.size(); i++)
    {
        if (TargetAccountNumber == AllClientsData[i].AccountNumber)
        {
            cout << "THe follwoing are client details: \n";
            cout << "-------------------------------------------------------\n";
            PrintClientCard(AllClientsData[i]);
            cout << "-------------------------------------------------------\n";
            return ;
        }
    }

    cout << "Client with account number : " << TargetAccountNumber << " is not found!\n";
}


/**
 * ClientFound - This Function Is like  {FinClient} Function, But its just simple, bcs we will use it a lot in other functions
 * 
 * @AllClientData : This is a referance to a vector of structure 'stClient' that we will check if Client are in it or not.
 * @TargetAccountNumber : This is a referance to A string that have the target account number that we want To serach about.
 * 
 * Return : True if Client Found, otherwise False
 */
bool ClientFound(vector<stClient>& AllClientsData, string& TargetAccountNumber, stClient& client)
{
    int i;

    for (i = 0; i < AllClientsData.size(); i++)
    {
        if (TargetAccountNumber == AllClientsData[i].AccountNumber)
        {
            client = AllClientsData[i];
            return true;
        }
            
    }
    return (false);
}