#include "SavingsAccount.h"
#include <iostream>
using namespace std;

SavingsAccount::SavingsAccount() : BankAccount(0, 0)
{
	DepositRate = 0;
}
SavingsAccount::SavingsAccount(double Cash, size_t AccountNumber, double DepositRate) : BankAccount(Cash, AccountNumber)
{
	this->DepositRate = DepositRate;
}
void SavingsAccount::ShowPercentageOfTheDeposit() { cout << DepositRate; }
void SavingsAccount::SetDepositRate(double DepositRate) { this->DepositRate = DepositRate; }
void SavingsAccount::Print()
{
	cout << "PinCode: " << AccountNumber << endl
		<< "Cash: " << Cash << endl
		<< "Deposit Rate: " << DepositRate << endl;
}
bool SavingsAccount::operator==(SavingsAccount Account)
{
	if (Cash == Account.Cash && DepositRate == Account.DepositRate)
	{
		return true;
	}
	else
	{
		return false;
	}
}