#include "Customer.h"
#include "BankAccount.h"
#include <iostream>
using namespace std;

BankAccount::BankAccount(double Cash, size_t AccountNumber):  Cash(Cash),AccountNumber(AccountNumber) {}
void BankAccount::ShowAccountNumber() { cout << AccountNumber; }
void BankAccount::ShowCurrentBalance() { cout << Cash; }
void BankAccount::SetAccountNumber(size_t AccountNumber) { this->AccountNumber = AccountNumber; }
void BankAccount::SetCash(double Cash) { this->Cash = Cash; }
void BankAccount::Print()
{
	cout << "PinCode: " << AccountNumber << endl
		<< "Cash: " << Cash << endl;
}