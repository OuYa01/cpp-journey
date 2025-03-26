#include "str.h"
#include <fstream>
#include <iomanip>

struct stClient
{
    std::string AccountNumber;
    std::string PinCode;
    std::string Name;
    std::string PhoneNumber;
    double accountBalance;
};

std::vector<std::string> splitStringIntoVector(std::string s, const std::string Seperator)
{
    std::vector<std::string> vec;
    size_t pos;

    // Split string based on the separator
    while ((pos = s.find(Seperator)) != std::string::npos)
    {
        vec.push_back(s.substr(0, pos));
        s = s.substr(pos + Seperator.length()); // Move past the separator
    }

    vec.push_back(s); // Add the last segment after the last separator
    return vec;
}

// Function to convert a formatted string back into stClient data
stClient ConvertLineData(const std::string ClientRecord, const std::string Seperator = "#//#")
{
    std::vector<std::string> vec = splitStringIntoVector(ClientRecord, Seperator);
    stClient Data;

    
    Data.AccountNumber = vec[0];
    Data.PinCode = vec[1];
    Data.Name = vec[2];
    Data.PhoneNumber = vec[3];
    Data.accountBalance = std::stod(vec[4]);

    return Data;
}


std::string ConvertRecordLine(const stClient& Data, const std::string& Seperator = "#//#")
{
    return Data.AccountNumber + Seperator + Data.PinCode + Seperator + Data.Name + Seperator + Data.PhoneNumber + Seperator + std::to_string(Data.accountBalance);
}

void PrintHeader(int NumberOfClients)
{
    cout << "\t\t\t\tClient List ("<< NumberOfClients << ") Client(s)\n";
    cout << "\n_______________________________________________________________________________________________________\n\n";
    cout << "| " << left << setw(15) <<"Account Number";
    cout << "| " << left << setw(10) <<"PinCode";
    cout << "| " << left << setw(40) <<"Client Name";
    cout << "| " << left << setw(12) <<"PhoneNumber";
    cout << "| " << left << setw(12) <<"Account Balance";
    cout << "\n_______________________________________________________________________________________________________\n\n";
}


void PrintData(vector<stClient> Data)
{
    PrintHeader(Data.size());
    

    for (stClient Client: Data)
    {
        cout << "| " << setw(15) << left << Client.AccountNumber;
        cout << "| " << setw(10) << left << Client.PinCode;
        cout << "| " << setw(40) << left << Client.Name;
        cout << "| " << setw(12) << left << Client.PhoneNumber;
        cout << "| " << setw(12) << left << Client.accountBalance;
        cout << endl;
    }
    cout << "\n_______________________________________________________________________________________________________\n";

}

 vector<stClient> LoadAllClientsDataFromFile(string filename)
{
    ifstream ClienData;

    ClienData.open(filename, ios::in); //open file (Read Mode)
    if (!ClienData)
    {
        std::cerr << "Error Openning the file";
        exit(1);
    }

    string line;
    vector<stClient> Clientss;
    stClient Client;

    while (getline(ClienData, line))
    {
        Client = ConvertLineData(line);
        Clientss.push_back(Client);
    }

    ClienData.close();
    return (Clientss);
    
}

void LoadAllClientsDataToFile(vector<stClient>& AllClientsData ,string FileName)
{
    ofstream ClientDataFile(FileName);
    string line;

    if (ClientDataFile.is_open())
    {
        for (stClient& client: AllClientsData)
        {
            line = ConvertRecordLine(client);
            ClientDataFile << line << '\n';
        }
        ClientDataFile.close();
    }
}



void PrintClientCrad(stClient client)
{
    cout << "\nThe following are the client detiles:" << endl;
    cout << "Account Number: " << client.AccountNumber << endl;
    cout << "Client Name: " << client.Name << endl;
    cout << "PinCode: " << client.PinCode << endl;
    cout << "Phone Number: " << client.PhoneNumber << endl;
    cout << "Account Balance: " << client.accountBalance << endl;
}

bool FindClientByAccountNumber(vector<stClient> AllClientsData, string TargetAccountNumber, stClient& C)
{
    for (stClient client : AllClientsData)
    {
        if (client.AccountNumber == TargetAccountNumber)
        {
            C = client;
            return (true);
        }
    }
    return (false);
}

void DeletClient(vector<stClient>& AllClientsData, stClient ClientToBeDeleted)
{
    int i;

    for (i = 0; i < AllClientsData.size(); i++)
    {
        if (AllClientsData[i].AccountNumber == ClientToBeDeleted.AccountNumber)
        {
            AllClientsData.erase(AllClientsData.begin() + i);
            i--;
        }
        i++;
    }
}

void DeletClientByAccountNumber(vector<stClient> AllClientsData, string TargetAccountNumber, string FileName)
{
    stClient client;
    char DeletIt;
    if (FindClientByAccountNumber(AllClientsData, TargetAccountNumber, client))
    {
        PrintClientCrad(client);
        cout << "Are you sure You want delet this client? (y/n) ";
        cin >> DeletIt;
        if (DeletIt == 'y' || DeletIt == 'Y')
        {
            DeletClient(AllClientsData, client);
            LoadAllClientsDataToFile(AllClientsData, FileName);
            cout << "Client deleted Succ\n\n";
        }
        return;
    }
    cout << "This client is not found!!";
}

stClient  ReadNewClient()
{
    stClient Data;

    std::cout << "Enter Account Number: ";
    std::getline(std::cin >> ws, Data.AccountNumber);

    std::cout << "Enter PinCode: ";
    std::getline(std::cin, Data.PinCode);

    std::cout << "Enter Your Name: ";
    std::getline(std::cin, Data.Name);

    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, Data.PhoneNumber);

    std::cout << "Enter Account Balance: ";
    std::cin >> Data.accountBalance;

    return Data;
}

stClient  UpdateClientData(string AccountNumber)
{
    stClient Data;

    Data.AccountNumber = AccountNumber;
    std::cout << "Enter PinCode: ";
    std::cin.ignore(1, '\n');
    std::getline(std::cin, Data.PinCode);

    std::cout << "Enter Your Name: ";
    std::getline(std::cin, Data.Name);

    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, Data.PhoneNumber);

    std::cout << "Enter Account Balance: ";
    std::cin >> Data.accountBalance;

    return Data;
}



void UpdateClientInAllData(vector<stClient>& AllClientsData, stClient Client)
{
    int i;
    for (i = 0; i < AllClientsData.size(); i++)
    {
        if (AllClientsData[i].AccountNumber == Client.AccountNumber)
        {
            AllClientsData[i] = Client;
            break;
        }
    }
}

void UpdateClientByAccountNumber(vector<stClient> AllClientsData, string TargetAccountNumber, string FileName)
{
    stClient Client;
    if (FindClientByAccountNumber(AllClientsData, TargetAccountNumber, Client))
    {
        char Updateit;
        PrintClientCrad(Client);
        cout << "Are you sure You want to update this client? (y/n) ";
        cin >> Updateit;
        if (Updateit == 'y' || Updateit == 'Y')
        {
            Client = UpdateClientData(TargetAccountNumber);
            UpdateClientInAllData(AllClientsData, Client);
            LoadAllClientsDataToFile(AllClientsData, FileName);
        }

    }
    else
        cout << "Client Not Found!!\n";
}

int main()
{

    vector<stClient> AllClientsData;
    stClient client;
    string TargetAccountNumber = "HH";

    AllClientsData = LoadAllClientsDataFromFile("Client.txt");
    PrintData(AllClientsData);

    UpdateClientByAccountNumber(AllClientsData, TargetAccountNumber, "Client.txt");
    AllClientsData = LoadAllClientsDataFromFile("Client.txt");
    PrintData(AllClientsData);
}
