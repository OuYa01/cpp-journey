#ifndef MAIN_H
#define MAIN_H

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
extern string FileName;



/*Prototypes of Client Opertaions*/
void MainMenueSwitch(vector<stClient>& AllClientsData);
void AddClient(vector<stClient>& AllClientsData);
void DeletClient(vector<stClient>& AllClientsData, string& TargetAccountNumber);
void DeletClientByAccountNumber(vector<stClient>& AllClientsData);
void UpdateClient(vector<stClient>& AllClientsData, string& TargetAccountNumber);
void UpateClientDataByAccountNumber(vector<stClient>& AllClientsData);
void FindClient(vector<stClient>& AllClientsData);
bool ClientFound(vector<stClient>& AllClientsData, string& TargetAccountNumber, stClient& client);

/*Prototypes of Helpers*/
void LoadAllDataFromVecToFile(vector<stClient>& AllClientsData);
void LoadAllClientsDataFromFile(vector<stClient>& AllDataClients);
void BackToMenu();
vector<string> SplitStringIntoVector(string RecordeLine, string separateur = "#//#");
string ConverClientToRecordeLine(stClient client, string separateur  = "#//#");
stClient convertClientRecordeToClient(string RecordeLine);

/*prototypes of Print details of clients*/
void showMenueScreen();
void PrintClientCard(stClient& Client);
void ShowClientList(vector<stClient>& AllClientsData);
void ExitMenue();


#endif 