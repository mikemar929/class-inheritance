#ifndef Account_h
#define Account_h
#include<iostream>
#include<string>
using namespace std;

//Runtime Exception base class
class RuntimeException {
private:
    string errorMessage;
public:
    RuntimeException (string const& err) : errorMessage(err) { }
    string getMessage() const {return errorMessage;}
};

class ExceedCredit : public RuntimeException {   
public:
    ExceedCredit (const string& err) : RuntimeException(err) { } //user exceeds credit limit
}; //throw(ExceedCredit)

class ExceedBalance : public RuntimeException {
public:
    ExceedBalance (const string& err) : RuntimeException(err) { }
}; //throw(ExceedBalance)

class ArgumentNegative : public RuntimeException {
public:
    ArgumentNegative (const string& err) : RuntimeException(err) { }
}; //throw(ArgumentNegative)

// Assignment base class
class Account{
	string Name, AccountNumber;
	double balance;
	
	public:
		account(string name, string number, double balance=0);//default account constructor
		void SetName(string n);//sets account name
		string GetName();//retrieves account name
		void SetNumber(string n);//sets account number
		string GetNumber();//retrieves account number
		void SetBalance(double n);//sets account balance
		double GetBalance();//retrieves account balance
		void print();//prints account details
		
};


class CreditCard:public Account{
	float apr;//annualized percentage rate
	float rewards; //stores cash back rewards
	double cardlimit;//stores credit limt
	public:
	CreditCard(string name, string number, double balance, double cardlimit);//CreditCard constructor
	void CreditCharge(double n)throw(ExceedCredit);//Decreases remaining balance
	void DebitCharge(double n)throw(ExceedBalance, ArgumentNegative);//Increases remaining balance
	void print();//prints CreditCard account details
	void setAPR(float n);//sets apr
	float getAPR();//retrieves apr
	float getRewards();//retrieves cash back rewards
	void setRewards(float r);//sets cash back rewards
	double getCardLimit();//retrieves current credit limit
	void interestCharged();//charges interest to the current balance
};

class Bank:public Account{
	string RoutingNumber;
	public:
		bank(string name, string number, string routing, double balance=0);
		string GetRouting();
		void SetRouting(string n);
		void print();
};

class CheckingAccount:public Bank{
	int monthlyfee;
	public:
	CheckingAccount(string name, string number, string routing, double balance, int fee=0);
	void incurCredit(double n);
	void incurDebit(double n);
	void ChargeFee();
	void print();
};

class SavingsAccount:public Bank{
	double InterestRate;
	public:
		SavingsAccount(string name, string number, string routing, double balance, double interest);
		double getRate();
		void applyRate();
		void deposit(double n);
		void print();
};

#endif
