#pragma once
#include "Transaction.h"
using namespace std;

Transaction::Transaction(Customer Client): Client(Client) {}
void Transaction::TransferMoneyToAnotherPerson(Customer Recipient)
{
	int Sum;
	cout << "Specify the amount of money you want to transfer\n";
	cin >> Sum;
	int IndexOfFirstAccount, IndexOfSecondAccount;
	cout << "Enter the account number of the first user";
	cin >> IndexOfFirstAccount;
	while (Sum > Client.GetCheckingAccountFromList(IndexOfFirstAccount).GetCash())
	{
		cerr << "Error. You don't have enough money! Type again.";
		cin >> Sum;
	}
	cout << "Enter the account number of the second user";
	cin >> IndexOfSecondAccount;
	Client.GetCheckingAccountFromList(IndexOfFirstAccount).GetCash() -= Sum;
	Recipient.GetCheckingAccountFromList(IndexOfSecondAccount).GetCash() += Sum;
}
void Transaction::TransferMoneyToAMobilePhoneNumber(int MobilePhoneNumber)
{
	int Sum;
	cout << "Specify the amount of money you want to transfer";
	cin >> Sum;
	int IndexOfFirstAccount;
	cout << "Enter the account number of the user";
	cin >> IndexOfFirstAccount;
	while (Sum > Client.GetCheckingAccountFromList(IndexOfFirstAccount).GetCash())
	{
		cerr << "Error. You don't have enough money! Type again.";
		cin >> Sum;
	}
	Client.GetCheckingAccountFromList(IndexOfFirstAccount).GetCash() -= Sum;
}
void Transaction::MakeADepositWithInterest()
{
	int Sum;
	cout << "Enter the amount you want to invest\n";
	cin >> Sum;
	double DepositRate;
	cout << "Enter the interest rate\n";
	cin >> DepositRate;
	Client.AddSavingsAccount(DepositRate);
}
void Transaction::WithdrawMoney()
{
	int Sum;
	cout << "Specify the amount of money you want to withdraw\n";
	cin >> Sum;
	int IndexOfFirstAccount;
	cout << "Enter the account number of the user";
	cin >> IndexOfFirstAccount;
	while (Sum > Client.GetCheckingAccountFromList(IndexOfFirstAccount).GetCash())
	{
		cerr << "Error. You don't have enough money! Type again.";
		cin >> IndexOfFirstAccount;
	}
	Client.GetCheckingAccountFromList(IndexOfFirstAccount).GetCash() -= Sum;
}