#include "CheckingAccount.h"
#include <iostream>
using namespace std;

CheckingAccount::CheckingAccount() : BankAccount(0, 0)
{
	this->CVV = 0;
}
CheckingAccount::CheckingAccount(double Cash, size_t AccountNumber, int CVV) : BankAccount(Cash, AccountNumber)
{
	this->CVV = CVV;
}
void CheckingAccount::SetCVV(int CVV) { this->CVV = CVV; }
void CheckingAccount::ShowCVVNumber() { cout << CVV; }
void CheckingAccount::Print()
{
	cout << "PinCode: " << AccountNumber << endl;
	cout << "Cash: " << Cash << endl;
	cout << "CVV Number: " << CVV << endl;
}
double& CheckingAccount::GetCash()
{
	return Cash;
}
bool CheckingAccount::operator==(CheckingAccount Account)
{
	if (Cash == Account.Cash)
	{
		return true;
	}
	else
	{
		return false;
	}
}