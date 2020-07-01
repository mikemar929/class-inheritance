#include "Account.h"

Account::account(string name, string number, double balance)
{
	Name=name;
	AccountNumber=number;
	balance=balance;
}

void Account::SetName(string n){Name=n;}

void Account::SetNumber(string n){AccountNumber=n;}

void Account::SetBalance(double n){balance=n;}

string Account::GetName(){return Name;}

string Account::GetNumber(){return AccountNumber;}

double Account::GetBalance(){return balance;}

void Account::print(){
	cout<<"The name on the Account is "<<Name<<endl;
	cout<<"The Account Number is "<<AccountNumber<<endl;
	cout<<"The balance on the account is $ "<<balance<<endl;
}



CreditCard::CreditCard(string name, string number, double balance, double cardlimit){
	account(name, number, balance);
	apr = 14.49/100;
	rewards = 0;
	CreditCard::SetBalance(0);
	CreditCard::cardlimit=cardlimit;
	}
	
void CreditCard::CreditCharge(double n) throw(ExceedCredit) {
	double b=CreditCard::GetBalance();
	double r=CreditCard::getRewards();
	r+=n*0.1;//1% of purchase is credited to cash back rewards
	b+=n;
	CreditCard::SetBalance(b);
	CreditCard::setRewards(r);
	cout<<"Your remaining balance is $"<<b<<endl;
	cout<<"Your current cash rewards value is $"<<r<<endl;
}

void CreditCard::DebitCharge(double n) throw(ExceedBalance, ArgumentNegative){
	double b=CreditCard::GetBalance();
	double r=CreditCard::getRewards();
	r+=n*0.1;//1% of payment is credited to cash back rewards
	b-=n-r;
	CreditCard::SetBalance(b);
	CreditCard::setRewards(r);
	cout<<"Your remaining balance is $"<<b<<endl;
	cout<<"Your current cash rewards value is $"<<r<<endl;
}

void CreditCard::print(){
	cout<<"Account info as follows:\n"<<"Name: "
	<<CreditCard::GetName()<<endl
	<<"Acount Number: "<<CreditCard::GetNumber()<<endl
	<<"Current Balance: "<<CreditCard::GetBalance()<<endl;
//	<<"Credit Limit: "<<CreditCard::getCardLimit()<<endl;
}
void CreditCard::setAPR(float n) { apr = n;}
float CreditCard::getAPR() {return apr;}
float CreditCard::getRewards() {return rewards;}
void CreditCard::setRewards(float r) { rewards = r;}
double CreditCard::getCardLimit() { return cardlimit;}
void CreditCard::interestCharged() {
	double b=CreditCard::GetBalance();
	double c=CreditCard::getCardLimit();
	double charge = b-((b*apr)/365.0);//apr is divided by 365 to get the daily rate
	b -= charge;//balance after subtracting the monthly interest
	cout<<"Interest charged: $" << charge << endl;
	CreditCard::SetBalance(b);
}

Bank::bank(string name, string number, string routing, double balance){
	Bank::SetName(name);
	Bank::SetNumber(number);
	RoutingNumber=routing;
	Bank::SetBalance(balance);
}

void Bank::SetRouting(string n){RoutingNumber=n;}

string Bank::GetRouting(){return RoutingNumber;}

void Bank::print(){
	cout<<"Account info as follows\n"<<"Name: "
	<<Bank::GetName()<<endl<<"Account Number: "
	<<Bank::GetNumber()<<endl<<"Routing number: "
	<<Bank::GetRouting()<<endl<<"Current balance: "
	<<Bank::GetBalance();
}

CheckingAccount::CheckingAccount(string name, string number, string routing, double balance, int fee){
	CheckingAccount::SetName(name);
	CheckingAccount::SetNumber(number);
	CheckingAccount::SetRouting(routing);
	CheckingAccount::SetBalance(balance);
	monthlyfee=fee;
}

void CheckingAccount::incurCredit(double n){
	double b=CheckingAccount::GetBalance();
	b+=n;
	CheckingAccount::SetBalance(b);
	cout<<"Current balance is: $"<<b<<endl;
}

void CheckingAccount::incurDebit(double n){
	double b=CheckingAccount::GetBalance();
	b-=n;
	CheckingAccount::SetBalance(b);
	cout<<"Current balance is: $"<<b<<endl;
}

void CheckingAccount::ChargeFee(){
	double b=CheckingAccount::GetBalance();
	b-=monthlyfee;
	CheckingAccount::SetBalance(b);
	cout<<"After charging monthly fee, your curremt balance is $"<<b<<endl;
}

void CheckingAccount::print(){
	cout<<"Account info as follows:\n"<<"Name: "
	<<CheckingAccount::GetName()<<endl<<"Account Number: "
	<<CheckingAccount::GetNumber()<<" with routing number: "<<CheckingAccount::GetRouting()
	<<endl<<"and a balance of $"<<CheckingAccount::GetBalance()<<endl;	
	}
	
SavingsAccount::SavingsAccount(string name, string number, string routing, double balance, double interest){
	SavingsAccount::SetName(name);
	SavingsAccount::SetNumber(number);
	SavingsAccount::SetRouting(routing);
	SavingsAccount::SetBalance(balance);
	InterestRate=interest;
}

double SavingsAccount::getRate(){return InterestRate;}

void SavingsAccount::applyRate(){
	double b=SavingsAccount::GetBalance();
	b*=(SavingsAccount::getRate()/100);
	SavingsAccount::SetBalance(b);
	cout<<"After interest, your current balance is $"<<b<<endl;
}

void SavingsAccount::deposit(double n){
	double b=SavingsAccount::GetBalance();
	b+=n;
	SavingsAccount::SetBalance(b);
	cout<<"your current balance is $"<<b<<endl;
}

void SavingsAccount::print(){
	cout<<"Account info as follows:\n"<<"Name: "<<SavingsAccount::GetName()<<endl
	<<"Account number: "<<SavingsAccount::GetNumber()<<" with routing number "<<SavingsAccount::GetRouting()<<endl
	<<"Current interest rate of "<<SavingsAccount::getRate()<<"% and a balance of $"<<SavingsAccount::GetBalance()<<endl;
}
