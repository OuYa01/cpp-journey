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
 * stUsers - its a structure That hold Users of the systeme
 *           , users are the ppl who have access to the systeme
 * @UserName : username of the user (should be unique for each user).
 * @PassWord : the passWord of this User
 * @permission : the permissions that's user have, its binary number
 *               * * * * * * * , each '*' means a bit can be (0 or 1).
 *               so we have (2^7) - 1 = 127 combinasion of permessions can be
 *               , the permession variable take -1 if the user should have all permessions
 *               , else its take 1 juts on bit that represent things that he should have permession
 *               and we convert it to int
 *               
 */
struct stUsers
{
    std::string UserName;
    std::string PassWord;
    int Permission;
};

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
extern string UsersFileName;


/*Prototypes of Users Op */
void Login();
void ShowLoginScreen();
bool CheckIfUserExist(stUsers& user);
void ManageUsersMenueSwitch(vector<stUsers>& AllUsersData, vector<stClient>& AllClientData, stUsers& RootUser);
string ConverUserToRecordeLine(stUsers User, string separateur="#//#");

/**
 * Permissions - bitmask permissions, enum values chosen as powers of 2 
 *               so that each value occupies exactly one bit.
 *               This allows multiple enum values to be combined
 *               into a single integer using bitwise operators
 */
enum Permissions
{
    Client_List_p=1   , //// 0000001
    Add_Client_P=2    , //// 0000010
    Delete_Client_p=4 , //// 0000100
    Update_Client_p=8 , //// 0001000
    Find_Client_p=16  , //// 0010000
    Transactions_p=32 , //// 0100000
    ManageUsers_P=64  , //// 1000000

    // 1111111 (Full access to all permissions)
    FullAccess = Client_List_p | Add_Client_P | Delete_Client_p |
                 Update_Client_p | Find_Client_p | Transactions_p |
                 ManageUsers_P
};

bool CheckAccessPermession(stUsers& RootUser, int PermessionToCheck);
void PrintAccessDenied();

/*Prototypes of Client Opertaions*/
void MainMenueSwitch(vector<stClient>& AllClientsData, vector<stUsers>& AllUsersData, stUsers& RootUser);
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