#ifndef Customer_h
#define Customer_h
#include "BankAccount.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include <iostream>
#include <string>
using namespace std;

class Customer
{
	string FirstName;
	string LastName;
	int Password;
	CheckingAccount* ListOfCheckingAccounts;
	SavingsAccount* ListOfSavingsAccounts;
	int NumberOfCheckingAccounts;
	int NumberOfSavingsAccounts;
public:
	Customer();
	Customer(string FirstName, string LastName, int Password, int NumberOfCheckingAccounts, int NumberOfSavingsAccounts);
	Customer(string FirstName, string LastName);
	~Customer();
	void AddCheckingAccount();
	void AddSavingsAccount();
	void AddSavingsAccount(double Deposit);
	CheckingAccount& GetCheckingAccountFromList(int index);
	SavingsAccount& GetSavingsAccountFromList(int index);
	void Print();
	void PrintOneCheckingAccount(int index);
	void PrintOneSavingsAccount(int index);
	string GetName();
	int GetNumberOfCheckingAccounts();
	int GetNumberOfSavingsAccounts();
	CheckingAccount* GetListOfCheckingAccounts();
	SavingsAccount* GetListOfSavingsAccounts();
}; 
#endif //Customer_h