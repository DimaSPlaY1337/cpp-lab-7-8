#include "Customer.h"
using namespace std;

Customer::Customer(string FirstName, string LastName, int Password, int NumberOfCheckingAccounts, int NumberOfSavingsAccounts) :
	FirstName(FirstName),
	LastName(LastName),
	Password(Password),
	ListOfCheckingAccounts(nullptr),
	ListOfSavingsAccounts(nullptr),
	NumberOfCheckingAccounts(NumberOfCheckingAccounts),
	NumberOfSavingsAccounts(NumberOfSavingsAccounts)
{
	ListOfCheckingAccounts = new CheckingAccount[NumberOfCheckingAccounts];
	ListOfSavingsAccounts = new SavingsAccount[NumberOfSavingsAccounts];
}
Customer::Customer(): FirstName("Unknown"),LastName("Unknown"), Password(0), ListOfCheckingAccounts(nullptr), ListOfSavingsAccounts(nullptr), NumberOfCheckingAccounts(0), NumberOfSavingsAccounts(0) {}
Customer::Customer(string FirstName, string LastName):
	FirstName(FirstName), 
	LastName(LastName), 
	ListOfCheckingAccounts(nullptr),
	ListOfSavingsAccounts(nullptr),
	NumberOfCheckingAccounts(0),
	NumberOfSavingsAccounts(0)
{}
Customer::~Customer()
{
	//cout << "Call destructor" << endl;
	delete[] ListOfCheckingAccounts;
	delete[] ListOfSavingsAccounts;
}
void Customer::AddCheckingAccount()
{
	cout << "Type the password. You have 3 attempts!";
	int Attempt;
	int RemainingAttempts = 2;
	cin >> Attempt;
	while (Attempt != Password)
	{
		if (RemainingAttempts == 0) 
		{
			cerr << "You've run out of attempts! The operation was rejected.\n";
			return;
		}
		cerr << "Password is incorrect. You have " << RemainingAttempts-- << " attempts left. Try again!";
		cin >> Attempt;
	}
	CheckingAccount* NewList = new CheckingAccount[NumberOfCheckingAccounts + 1];
	int Cash; size_t AccountNumber;
	int CVV;
	CheckingAccount NewAccount;
	cout << "Enter the cash:";
	cin >> Cash; NewAccount.SetCash(Cash);
	cout << "Enter the PinCode:";
	cin >> AccountNumber; NewAccount.SetAccountNumber(AccountNumber);
	cout << "Enter the CVV:";
	cin >> CVV; NewAccount.SetCVV(CVV);
	NewList[NumberOfCheckingAccounts] = NewAccount;
	if (NumberOfCheckingAccounts != 0) 
	{
		for (int i = 0; i < NumberOfCheckingAccounts; i++)
		{
			NewList[i] = ListOfCheckingAccounts[i];
		}
		delete[] ListOfCheckingAccounts;
	}
	ListOfCheckingAccounts = NewList;
	NumberOfCheckingAccounts += 1;
}
void Customer::AddSavingsAccount()
{
	cout << "Type the password. You have 3 attempts!";
	int Attempt;
	int RemainingAttempts = 2;
	cin >> Attempt;
	while (Attempt != Password)
	{
		if (RemainingAttempts == 0)
		{
			cerr << "You've run out of attempts! The operation was rejected.\n";
			return;
		}
		cerr << "Password is incorrect. You have " << RemainingAttempts-- << " attempts left. Try again!";
		cin >> Attempt;
	}
	SavingsAccount* NewList = new SavingsAccount[NumberOfSavingsAccounts + 1];
	int Cash;size_t AccountNumber;
	double DepositRate;
	SavingsAccount NewAccount;
	cout << "Enter the cash:";
	cin >> Cash; NewAccount.SetCash(Cash);
	while (Cash < 0)
	{
		cerr << "Error. The value must be greater than zero\n";
		cin >> Cash;
	}
	cout << "Enter the PinCode:";
	cin >> AccountNumber; 
	while (AccountNumber < 0)
	{
		cerr << "Error. The number must be greater than zero\n";
		cin >> AccountNumber;
	}
	NewAccount.SetAccountNumber(AccountNumber);
	cout << "Enter the deposit rate:";
	cin >> DepositRate; 
	while (DepositRate < 0)
	{
		cerr << "Error. The deposit rate must be greater than zero\n";
		cin >> DepositRate;
	}
	NewAccount.SetDepositRate(DepositRate);
	NewList[NumberOfSavingsAccounts] = NewAccount;
	if (NumberOfSavingsAccounts != 0)
	{
		for (int i = 0; i < NumberOfSavingsAccounts; i++)
		{
			NewList[i] = ListOfSavingsAccounts[i];
		}
		delete[] ListOfSavingsAccounts;
	}
	ListOfSavingsAccounts = NewList;
	NumberOfSavingsAccounts += 1;
}
void Customer::AddSavingsAccount(double Deposit)
{
	cout << "Type the password. You have 3 attempts!";
	int Attempt;
	int RemainingAttempts = 2;
	cin >> Attempt;
	while (Attempt != Password)
	{
		if (RemainingAttempts == 0)
		{
			cerr << "You've run out of attempts! The operation was rejected.\n";
			return;
		}
		cerr << "Password is incorrect. You have " << RemainingAttempts-- << " attempts left. Try again!";
		cin >> Attempt;
	}
	SavingsAccount* NewList = new SavingsAccount[NumberOfSavingsAccounts + 1];
	int Cash; size_t AccountNumber;
	SavingsAccount NewAccount;
	cout << "Enter the cash:";
	cin >> Cash; 
	while (Cash<0) 
	{
		cerr << "Error. The value must be greater than zero\n";
		cin >> Cash;
	}
	NewAccount.SetCash(Cash);
	cout << "Enter the Account Number:";
	cin >> AccountNumber; 
	while (AccountNumber < 0)
	{
		cerr << "Error. The number must be greater than zero\n";
		cin >> AccountNumber;
	}
	NewAccount.SetAccountNumber(AccountNumber);
	NewAccount.SetDepositRate(Deposit);
	NewList[NumberOfSavingsAccounts] = NewAccount;
	if (NumberOfSavingsAccounts != 0)
	{
		for (int i = 0; i < NumberOfSavingsAccounts; i++)
		{
			NewList[i] = ListOfSavingsAccounts[i];
		}
		delete[] ListOfSavingsAccounts;
	}
	ListOfSavingsAccounts = NewList;
	NumberOfSavingsAccounts += 1;
}
CheckingAccount& Customer::GetCheckingAccountFromList(int index)
{
	return ListOfCheckingAccounts[index - 1];
}
SavingsAccount& Customer::GetSavingsAccountFromList(int index)
{
	return ListOfSavingsAccounts[index - 1];
}
void Customer::Print()
{
	cout << FirstName << " " << LastName << " Number of checking accounts:" << NumberOfCheckingAccounts << " Number of savings accounts:" << NumberOfSavingsAccounts << endl<<endl;
}
void Customer::PrintOneCheckingAccount(int index)
{
	(ListOfCheckingAccounts[index - 1]).Print();
}
void Customer::PrintOneSavingsAccount(int index)
{
	(ListOfSavingsAccounts[index - 1]).Print();
	cout << endl;
}
string Customer::GetName()
{
	return FirstName;
}
int Customer::GetNumberOfCheckingAccounts()
{
	return NumberOfCheckingAccounts;
}
int Customer::GetNumberOfSavingsAccounts()
{
	return NumberOfSavingsAccounts;
}
CheckingAccount* Customer::GetListOfCheckingAccounts()
{
	return ListOfCheckingAccounts;
}
SavingsAccount* Customer::GetListOfSavingsAccounts()
{
	return ListOfSavingsAccounts;
}