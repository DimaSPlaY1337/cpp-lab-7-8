#ifndef BankAccount_h
#define BankAccount_h
class BankAccount 
{
public:
	BankAccount(double Cash, size_t AccountNumber);
	BankAccount();
	virtual void Print();
	void ShowCurrentBalance();
	void ShowAccountNumber();
	void SetCash(double Cash);
	void SetAccountNumber(size_t AccountNumber);

protected:
	double Cash;
	size_t AccountNumber;
};
#endif //BankAccount_h