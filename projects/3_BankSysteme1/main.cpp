#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include <limits>
#include <algorithm>

using namespace std;

struct stClient
{
    std::string AccountNumber;
    std::string PinCode;
    std::string Name;
    std::string PhoneNumber;
    double accountBalance;
};

string FileName = "ClientsData.txt";

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


string ConverClientToRecordeLine(stClient client, string separateur = "#//#")
{
    return (client.AccountNumber + separateur + client.PinCode + separateur + client.Name + separateur + client.PhoneNumber + separateur + to_string(client.accountBalance) + '\n');
}

bool isNumber(const string& s)
{
    return !s.empty() && all_of(s.begin(), s.end(), ::isdigit);
}


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

void PrintClientCard(stClient& Client)
{
    cout << "| " << left << setw(15) << Client.AccountNumber;
    cout << "| " << left << setw(12) << Client.PinCode;
    cout << "| " << left << setw(40) << Client.Name;
    cout << "| " << left << setw(12) << Client.PhoneNumber;
    cout << "| " << left << setw(12) << Client.accountBalance;
    cout << "\n";
}

void ShowClientList(vector<stClient> AllClientsData)
{
    cout << "\t\t\t\tClient List ("<< AllClientsData.size() << ") Client(s)\n";
    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(12) << "Pin Code";
    cout << "| " << left << setw(40) << "Name";
    cout << "| " << left << setw(12) << "PhoneNumber";
    cout << "| " << left << setw(12) << "AccountBalance";

    cout << "\n";
    for (stClient Client : AllClientsData)
    {
        PrintClientCard(Client);
    }
}




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



void LoadAllDataFromVecToFile(vector<stClient>& AllClientsData)
{
    ofstream ClientDataFile(FileName);

    for (stClient& Client : AllClientsData)
    {
        ClientDataFile << ConverClientToRecordeLine(Client);
    }
}


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

void ExitMenue()
{
    cout << "----------------------------------------------------------\n";
    cout << "\t\tProgram Ends\n";
    cout << "----------------------------------------------------------\n";
}


void BackToMenu()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\nPress any key to go back to main menue... ";
    cin.get();
}


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
}