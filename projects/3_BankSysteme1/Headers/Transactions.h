#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include "main.h"
using namespace std;

void TransactionsSwitch(vector<stClient>& AllClientsData);
void ShowTransactionsMenue();
string GetString(string msg);
void UpdateClient(vector<stClient>& AllClientsData, stClient& Client);
void Deposit(vector<stClient>& AllClientsData);
void Withdraw(vector<stClient>& AllClientsData);
void PrintBalanceClient(stClient& ClientData);
float CalculeTotalBalance(vector<stClient>& AllClientsData);
void TotalBalance(vector<stClient>& AllClientsData);


#endif