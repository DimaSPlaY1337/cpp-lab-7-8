#pragma once
#include "BankAccount.h"
class CheckingAccount : public BankAccount
{
public:
	void Print();
	double& GetCash();
	CheckingAccount();
	CheckingAccount(double Cash, size_t AccountNumber, int CVV);
	void ShowCVVNumber();
	void SetCVV(int CVV);
	bool operator ==(CheckingAccount Account);

private:
	int CVV;
};

