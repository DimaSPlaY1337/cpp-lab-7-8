#pragma once
#include "Customer.h"
#include "Transaction.h"
using namespace std;

void Menu(int NumberOfUsers, Customer* ListOfUsers)
{
	cout << "Choice the function of the bank:" << endl;
	cout << "1 - show all users" << endl;
	cout << "2 - show all accounts of one user" << endl;
	cout << "3 - add a new user" << endl;
	cout << "4 - add an account to user" << endl;
	cout << "5 - transfer money from one user to another" << endl;
	cout << "6 - transfer money from a user to a phone number" << endl;
	cout << "7 - invest money at an interest rate" << endl;
	cout << "8 - withdraw money" << endl;
	cout << "9 - compare two accounts" << endl;
	cout << "10 - exit" << endl;
	int Action;
	cin >> Action;
	switch (Action)
	{
	case 1:
	{
		if (NumberOfUsers == 0)
		{
			cout << "There are no users! But you can add them" << endl;
			Menu(NumberOfUsers, ListOfUsers);
		}
		else
		{
			for (int i = 0; i < NumberOfUsers; i++)
			{
				ListOfUsers[i].Print();
			}
		}
		cout << endl;
		Menu(NumberOfUsers, ListOfUsers);
	}
	case 2:
	{
		string Name;
		cout << "Enter the name" << endl;
		cin >> Name;
		bool HaveFound = false;
		for (int i = 0; i < NumberOfUsers; i++)
		{
			if (ListOfUsers[i].GetName() == Name)
			{
				HaveFound = true;
				for (int j = 0; j < ListOfUsers[i].GetNumberOfCheckingAccounts(); j++)
				{
					ListOfUsers[i].GetListOfCheckingAccounts()[j].Print();
				}
				for (int j = 0; j < ListOfUsers[i].GetNumberOfSavingsAccounts(); j++)
				{
					ListOfUsers[i].GetListOfSavingsAccounts()[j].Print();
				}
			}
		}
		if (HaveFound == false)
		{
			cout << "There are no users with such name" << endl;
			Menu(NumberOfUsers, ListOfUsers);
		}
		cout << endl;
		Menu(NumberOfUsers, ListOfUsers);
	}
	case 3:
	{
		Customer* NewList = new Customer[NumberOfUsers + 1];
		if (NumberOfUsers != 0)
		{
			for (int i = 0; i < NumberOfUsers; i++)
			{
				NewList[i] = ListOfUsers[i];
			}
		}
		string FirstName;
		cout << "Enter the First Name" << endl;
		cin >> FirstName;
		string LastName;
		cout << "Enter the Last Name" << endl;
		cin >> LastName;
		int Password;
		cout << "Enter the Password" << endl;
		cin >> Password;
		Customer NewUser(FirstName, LastName, Password, 0, 0);
		NewList[NumberOfUsers] = NewUser;
		delete[] ListOfUsers;
		ListOfUsers = NewList;
		NumberOfUsers += 1;
		cout << "The user has been successfully added!" << endl;
		cout << endl;
		Menu(NumberOfUsers, ListOfUsers);
	}
	case 4:
	{
		string Name;
		bool IfFound = false;
		cout << "Type the Name of User" << endl;
		cin >> Name;
		for (int i = 0; i < NumberOfUsers; i++)
		{
			if (ListOfUsers[i].GetName() == Name)
			{
				IfFound = true;
				cout << "Which type of account do you want to add? (Checking/Savings)" << endl;
				cin >> Name;
				while (Name != "Checking" && Name != "Savings")
				{
					cout << "I don't understand! Enter the type again." << endl;
					cin >> Name;
				}
				if (Name == "Checking")
				{
					ListOfUsers[i].AddCheckingAccount();
				}
				else if (Name == "Savings")
				{
					ListOfUsers[i].AddSavingsAccount();
				}
				break;
			}
		}
		string Choice;
		if (!(IfFound))
		{
			cerr << "The specified user does not exist." << endl;
			cout << endl;
			Menu(NumberOfUsers, ListOfUsers);
			return;
		}
		cout << "The account has been successfully added!" << endl;
		cout << endl;
		Menu(NumberOfUsers, ListOfUsers);
	}
	case 5:
	{
		string FirstName;
		string SecondName;
		bool FirstFound = false;
		bool SecondFound = false;
		cout << "Enter the name of sender" << endl;
		cin >> FirstName;
		cout << "Enter the name of recipient" << endl;
		cin >> SecondName;
		int FirstIndex;
		int SecondIndex;
		for (int i = 0; i < NumberOfUsers; i++)
		{
			if (ListOfUsers[i].GetName() == FirstName)
			{
				FirstIndex = i;
				FirstFound = true;
			}
			if (ListOfUsers[i].GetName() == SecondName)
			{
				SecondIndex = i;
				SecondFound = true;
			}
		}
		string Choice;
		if (!(SecondFound && FirstFound))
		{
			cerr << "At least one specified user is missing from the list." << endl;
			cout << endl;
			Menu(NumberOfUsers, ListOfUsers);
			return;
		}
		Transaction Transfer(ListOfUsers[FirstIndex]);
		Transfer.TransferMoneyToAnotherPerson(ListOfUsers[SecondIndex]);
		cout << "The operation was completed successfully!" << endl;
		cout << endl;
		Menu(NumberOfUsers, ListOfUsers);
	}
	case 6:
	{
		string Name;
		bool IfFound = false;
		cout << "Enter the name of sender" << endl;
		cin >> Name;
		int Index;
		for (int i = 0; i < NumberOfUsers; i++)
		{
			if (ListOfUsers[i].GetName() == Name)
			{
				Index = i;
				IfFound = true;
			}
		}
		string Choice;
		if (!(IfFound))
		{
			cerr << "The specified user does not exist." << endl;
			cout << endl;
			Menu(NumberOfUsers, ListOfUsers);
			return;
		}
		int PhoneNumber;
		cout << "Enter the mobile phone number" << endl;
		cin >> PhoneNumber;
		Transaction Transfer(ListOfUsers[Index]);
		Transfer.TransferMoneyToAMobilePhoneNumber(PhoneNumber);
		cout << "The operation was completed successfully!" << endl;
		cout << endl;
		Menu(NumberOfUsers, ListOfUsers);
	}
	case 7:
	{
		string Name;
		bool IfFound = false;
		cout << "Enter the name of the participant" << endl;
		cin >> Name;
		for (int i = 0; i < NumberOfUsers; i++)
		{
			if (ListOfUsers[i].GetName() == Name)
			{
				Transaction Invest(ListOfUsers[i]);
				Invest.MakeADepositWithInterest();
				IfFound = true;
				break;
			}
		}
		if (!(IfFound))
		{
			cerr << "The specified user does not exist." << endl;
			cout << endl;
			Menu(NumberOfUsers, ListOfUsers);
			return;
		}
	}
	case 8:
	{
		string Name;
		bool IfFound = false;
		cout << "Enter the name of user" << endl;
		cin >> Name;
		int Index;
		for (int i = 0; i < NumberOfUsers; i++)
		{
			if (ListOfUsers[i].GetName() == Name)
			{
				Index = i;
				IfFound = true;
			}
		}
		string Choice;
		if (!(IfFound))
		{
			cerr << "The specified user does not exist." << endl;
			cout << endl;
			Menu(NumberOfUsers, ListOfUsers);
			return;
		}
		Transaction Transfer(ListOfUsers[Index]);
		Transfer.WithdrawMoney();
		cout << "The operation was completed successfully!" << endl;
		cout << endl;
		Menu(NumberOfUsers, ListOfUsers);
	}
	case 9:
	{
		string FirstName;
		string SecondName;
		bool FirstFound = false;
		bool SecondFound = false;
		cout << "Enter the name of first user" << endl;
		cin >> FirstName;
		cout << "Enter the name of second user" << endl;
		cin >> SecondName;
		int FirstIndex;
		int SecondIndex;
		for (int i = 0; i < NumberOfUsers; i++)
		{
			if (ListOfUsers[i].GetName() == FirstName)
			{
				FirstIndex = i;
				FirstFound = true;
			}
			if (ListOfUsers[i].GetName() == SecondName)
			{
				SecondIndex = i;
				SecondFound = true;
			}
		}
		string Choice;
		if (!(SecondFound && FirstFound))
		{
			cerr << "At least one specified user is missing from the list." << endl;
			cout << endl;
			Menu(NumberOfUsers, ListOfUsers);
			return;
		}
		cout << "Which types of accounts do you want to compare?(Checking/Savings)" << endl;
		cin >> Choice;
		while (Choice != "Checking" && Choice != "Savings")
		{
			cout << "Error! Enter the type again." << endl;
			cin >> Choice;
		}
		int FirstAccount;
		int SecondAccount;
		if (Choice == "Checking")
		{
			cout << "Enter the number of first account" << endl;
			cin >> FirstAccount;
			cout << "Enter the number of second account" << endl;
			cin >> SecondAccount;
			if (ListOfUsers[FirstIndex].GetCheckingAccountFromList(FirstAccount) == ListOfUsers[SecondIndex].GetCheckingAccountFromList(SecondAccount))
			{
				cout << "They are equal!" << endl;
			}
			else
			{
				cout << "They aren't equal!" << endl;
			}

		}
		else if (Choice == "Savings")
		{
			cout << "Enter the number of first account" << endl;
			cin >> FirstAccount;
			cout << "Enter the number of second account" << endl;
			cin >> SecondAccount;
			if ((ListOfUsers[FirstIndex].GetSavingsAccountFromList(FirstAccount)) == (ListOfUsers[SecondIndex].GetSavingsAccountFromList(SecondAccount)))
			{
				cout << "They are equal!" << endl;
			}
			else
			{
				cout << "They aren't equal!" << endl;
			}
		}
		cout << "The operation was completed successfully!" << endl;
		cout << endl;
		Menu(NumberOfUsers, ListOfUsers);

	}
	case 10:
		cout << "Chao!" << endl;
		return;
	default:
		cout << "There is no operation with such number! Try again." << endl;
		Menu(NumberOfUsers, ListOfUsers);
		break;
	}
}
