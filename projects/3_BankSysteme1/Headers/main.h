#ifndef MAIN_H
#define MAIN_H
#include "Common.h"






/*@FileName - Global Variable that have the Name of File will be our data in*/
extern string FileName;




/*Prototypes of Client Opertaions*/
void AddClient(vector<stClient>& AllClientsData);
void DeletClient(vector<stClient>& AllClientsData, string& TargetAccountNumber);
void DeletClientByAccountNumber(vector<stClient>& AllClientsData);
void UpdateClient(vector<stClient>& AllClientsData, string& TargetAccountNumber);
void UpateClientDataByAccountNumber(vector<stClient>& AllClientsData);
void FindClient(vector<stClient>& AllClientsData);
bool ClientFound(vector<stClient>& AllClientsData, string& TargetAccountNumber, stClient& client);

/*Prototypes of Helpers for Client things*/
void LoadAllDataFromVecToFile(vector<stClient>& AllClientsData);
void LoadAllClientsDataFromFile(vector<stClient>& AllDataClients);



/*prototypes of Print details of clients*/
void showMenueScreen();
void PrintClientCard(stClient& Client);
void ShowClientList(vector<stClient>& AllClientsData);
void ExitMenue();


#endif 