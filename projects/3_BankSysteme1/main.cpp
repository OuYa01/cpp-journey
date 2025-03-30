#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include <limits>
#include <algorithm>

using namespace std;

/**
 * stClient - is a structur That will hold All Our data
 * 
 * @AccountNumber : Account Number of client
 * @PinCode : Pin code of this client
 * @Name : Full Name of Client
 * @Phone Number : Phone Number Of Client
 * @AccountBalance : How Many this Client Have
 * 
 */
struct stClient
{
    std::string AccountNumber;
    std::string PinCode;
    std::string Name;
    std::string PhoneNumber;
    double accountBalance;
};

/*@FileName - Global Variable that have the Name of File will be our data in*/
string FileName = "ClientsData.txt";


/**
 * SplitStringIntoVector - This will split A string into a Vector using separateur.
 * 
 * @RecordeLine : This is the line will be look smtg like that : "B01#//#0000#//#Oussama#//#+212608095577#//#20000".
 * @separateur : the delimiter that separte data in this line.
 * 
 * Return : Vector of strings that has each data from this line
 */
vector<string> SplitStringIntoVector(string RecordeLine, string separateur = "#//#")
{
    int pos;
    vector<string> vec;

    while ((pos = RecordeLine.find(separateur)) != std::string::npos)
    {
        vec.push_back(RecordeLine.substr(0, pos));
        RecordeLine = RecordeLine.substr(pos + separateur.length());
    }
    vec.push_back(RecordeLine);

    return (vec);
}

/**
 * ConverClientToRecordeLine - This Function will Convert Data of client in a struct to one line,
 *                             Bcs It will help us a lot in our file to can get data from it again
 * 
 * @client - its a Structure That Hold All client Data.
 * @separateur - That a separateur that we will Separte data with it in this line. Will look smtg like that
 *               "B01#//#0000#//#Oussama#//#+212608095577#//#20000"
 * 
 * Return : The line That has all data
 */
string ConverClientToRecordeLine(stClient client, string separateur = "#//#")
{
    return (client.AccountNumber + separateur + client.PinCode + separateur + client.Name + separateur + client.PhoneNumber + separateur + to_string(client.accountBalance) + '\n');
}


/**
 * convertClientRecordeToClient - Convert Client Recorde(Bcs in our File, Data looks Like one line) to Client structure
 * 
 * @RecordeLine : The line of data ~ its smtg like that "B01#//#0000#//#Oussama#//#+212608095577#//#20000"
 * 
 * Return : Client data 
 */
stClient convertClientRecordeToClient(string RecordeLine)
{
    vector<string> vec = SplitStringIntoVector(RecordeLine);
    stClient Client;

    if (vec.size() < 5) {
        cout << "Error: Record line does not contain enough fields!" << endl;
        return stClient{}; // Return an empty client structure
    }

    Client.AccountNumber = vec[0];
    Client.PinCode = vec[1];
    Client.Name = vec[2];
    Client.PhoneNumber = vec[3];
    Client.accountBalance = stod(vec[4]);

    return Client;
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
 * LoadAllDataFromVecToFile - Load All Data from Vector to file, bcs when we update a data in our programme
 *                            We Update it just in the vectore so we need to make it back to our file
 * @AllClientData : This is a referance to a vector of structure 'stClient' to Update Data in it and send it back to file
 * 
 * Return : Nothing
 */
void LoadAllDataFromVecToFile(vector<stClient>& AllClientsData)
{
    ofstream ClientDataFile(FileName);

    for (stClient& Client : AllClientsData)
    {
        ClientDataFile << ConverClientToRecordeLine(Client);
    }
}


/**
 * LoadAllClientsDataFromFile - Load All Clients Data From File To vector, This Function will help us,
 *                              bcs When programme ends data will stay always in File, But vectore will
 *                              Forget all the data, so we need always when start the programme To load
 *                              This data from file to Vector
 * 
 * @AllClientData : This is a referance to a vector of structure 'stClient' to Update Data in it and send it back to file
 * 
 * Return : Nothing
 *                              
 */
void LoadAllClientsDataFromFile(vector<stClient>& AllDataClients)
{
    ifstream ClienData;

    ClienData.open(FileName, ios::in); //open file (Read Mode)
    if (!ClienData)
    {
        std::cerr << "Error Openning the file";
        return ;
    }

    string line;
    stClient Client;

    while (getline(ClienData, line))
    {
        Client = convertClientRecordeToClient(line);
        AllDataClients.push_back(Client);
    }

    ClienData.close();  
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
    cout << "Delet Client\n";
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
    cout << "\t[6] Exit.\n";
    cout << "===============================================\n";
    cout << "Choose what do you want to do? [1 to 6]?  ";

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


/**
 * BackToMenu - When a function end in this systeme its shows this to u can see the output,
 *              Then if you want u can back to main menue by Press any key
 * 
 */
void BackToMenu()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\nPress any key to go back to main menue... ";
    cin.get();
}



/**
 * main - Program Entry
 * 
 * Return : 0 if Succ
 */
int main(void)
{
    vector<stClient> AllClientsData;
    LoadAllClientsDataFromFile(AllClientsData);
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
                    ExitMenue();
                break;
            default:
                    cout << "Choice Not Found, Try Again";
                    BackToMenu();
        }
    }while(YourChoice != 6);

    return (0);
}