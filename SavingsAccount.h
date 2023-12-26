#pragma once
#include "BankAccount.h"
class SavingsAccount : public BankAccount
{
public:
	void Print();
	SavingsAccount();
	SavingsAccount(double Cash, size_t AccountNumber, double DepositRate);
	void ShowPercentageOfTheDeposit();
	void SetDepositRate(double DepositRate);
	bool operator ==(SavingsAccount Account);

private:
	double DepositRate;
};

