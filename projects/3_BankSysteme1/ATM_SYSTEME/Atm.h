#ifndef ATM_H
#define ATM_H

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

extern string FileName;
extern stClient CurrentClient;


/*ATM PRINT DETIKES FUNC PROTOTYPES*/
void ShowLoginScreen();
void showAtmMenueScreen();

/*Atm operations functions Prototypes*/
void Deposit(vector<stClient>& AllClientsData);
void NormalWithdraw(vector<stClient>& AllClientsData);
void CheckBalance();
void QuickWithdraw(vector<stClient>& AllClientsData);
bool Withdraw(vector<stClient>& AllClientsData ,int ToWithdraw);
bool CheckIfClientExist(vector<stClient>& AllClientData);
void GetClientInfos();
stClient convertClientRecordeToClient(string RecordeLine);
string ConverClientToRecordeLine(stClient client, string separateur="#//#");
vector<string> SplitStringIntoVector(string RecordeLine, string separateur="#//#");
void BackToMenu();
void LoadAllClientsDataFromFile(vector<stClient>& AllDataClients);
void LoadAllDataFromVecToFile(vector<stClient>& AllClientsData);
void MainAtmMenueSwitch(vector<stClient>& AllClientsData);
void Login();

#endif