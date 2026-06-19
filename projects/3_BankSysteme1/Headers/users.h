#ifndef USERS_H
#define USERS_H
#include "Common.h"
extern string UsersFileName;


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



/*prototypes for users print detiles*/
void ShowLoginScreen();
void showUsersMenueScreen();
void PrintAccessDenied();
void PrintUserCard(stUsers& user);
void ShowUsersList(vector<stUsers>& AllUsersList);


/*Prototypes of Users Op */
void Login();
void LoadAllUsersDataFromFile(vector<stUsers>& AllUsersData);
void GetUserInfos(stUsers& user);
bool CheckIfUserExist(stUsers& user, vector<stUsers>& AllUsersData);
void ManageUsersMenueSwitch(vector<stUsers>& AllUsersData, vector<stClient>& AllClientData, stUsers& RootUser);
void SetPermissionToUser(stUsers& User);
string ConverUserToRecordeLine(stUsers User, string separateur="#//#");
bool CheckAccessPermession(stUsers& RootUser, int PermessionToCheck);
bool UserFound(vector<stUsers>& AllUserData, string& TargetUserName, stUsers& User);
void FindUser(vector<stUsers>& AllUsersData);
void UpateUserDataByUserName(vector<stUsers>& AllUsersData);
void UpdateUser(vector<stUsers>& AllUsersData, string& TargetUsername);
void DeletUser(vector<stUsers>& AllUsersData, string& TargetUsername);
void DeletUserByUserName(vector<stUsers>& AllUsersData);
void AddNewUser(vector<stUsers>& AllUsersData);


#endif