#include <iostream>
#include <vector>
#include <string>

// client data
struct stClient
{
    std::string AccountNumber;
    std::string PinCode;
    std::string Name;
    std::string PhoneNumber;
    double accountBalance;
};

// Function to read new client data from user input
stClient ReadNewClient()
{
    stClient Data;

    std::cout << "Enter Account Number: ";
    std::getline(std::cin, Data.AccountNumber);

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

std::vector<std::string> splitStringIntoVector(std::string s, const std::string& Seperator)
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



std::string ConvertRecordLine(const stClient& Data, const std::string& Seperator = "#//#")
{
    return Data.AccountNumber + Seperator + Data.PinCode + Seperator + Data.Name + Seperator + Data.PhoneNumber + Seperator + std::to_string(Data.accountBalance);
}


// Function to convert a formatted string back into stClient data
stClient ConvertLineData(const std::string& ClientRecord, const std::string& Seperator = "#//#")
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

int main()
{
    stClient Client;
    std::string ClientRecord;

    Client = ReadNewClient();

    ClientRecord = ConvertRecordLine(Client);

    std::cout << "\n\nClient Record for saving is:\n" << ClientRecord << std::endl;


    stClient Data = ConvertLineData(ClientRecord);


    std::cout << "Account Number: " << Data.AccountNumber << "\n";
    std::cout << "Pin Code: " << Data.PinCode << "\n";
    std::cout << "Name: " << Data.Name << "\n";
    std::cout << "Phone Number: " << Data.PhoneNumber << "\n";
    std::cout << "Account Balance: " << Data.accountBalance << "\n";

    return 0;
}
