#ifndef COMMON_H
#define COMMON_H

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


extern stUsers RootUser;

// Common prototypes
void MainMenueSwitch(vector<stClient>& AllClientsData, vector<stUsers>& AllUsersData);
vector<string> SplitStringIntoVector(string RecordeLine, string separateur = "#//#");
string ConverClientToRecordeLine(stClient client, string separateur  = "#//#");
stClient convertClientRecordeToClient(string RecordeLine);
void BackToMenu();

#endif