#include "str.h"
#include <fstream>

/**
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

std::string ConvertRecordLine(const stClient& Data, const std::string& Seperator = "#//#")
{
    return Data.AccountNumber + Seperator + Data.PinCode + Seperator + Data.Name + Seperator + Data.PhoneNumber + Seperator + std::to_string(Data.accountBalance);
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

void AddDataLineToFile(stClient client, string RecordeLine)
{
    fstream ClientData;
    ClientData.open("Client.txt", ios::out | ios::app);
    
    
    if (ClientData.is_open())
    {
        ClientData << RecordeLine << endl;
        ClientData.close();
    }
}

 void AddNewClient()
 {
    stClient client;
    client = ReadNewClient();
    AddDataLineToFile(client, ConvertRecordLine(client));
 }

void AddClients()
{
    char AddMore = 'Y';

    do
    {
        system("cls");
        cout << "Adding New Clients:\n\n";

        AddNewClient();
        cout << "Client added succ, Do you want to add more clients (Y/N):  ";
        cin >> AddMore;
    } while (AddMore == 'Y' || AddMore == 'y');
    
}

int main(void)
{
    AddClients();
}