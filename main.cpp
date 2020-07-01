#include <iostream>
#include "Account.h"
#include "time.h"

int main(int argc, char** argv) {
	double b, c, n;
	float r, min1, min2, curr;
	string a;
	SavingsAccount SA1("Mark","1234560789","01245120",20,8);
	SA1.print();
	cout<<"how much would you like to deposit in the account?\n";
	cin>>n;
	SA1.deposit(n);
	
	CheckingAccount CA1("Ana","1203212584","1203355", 450, 12);
	CA1.print();
	cout<<"How much would you like to deposit?\n";
	cin>>n;
	CA1.incurCredit(n);
	cout<<"How much would you like to deposit?\n";
	cin>>n;
	CA1.incurCredit(n);
	cout<<"How much would you like to withdraw?\n";
	cin>>n;
	CA1.incurDebit(n);
	CreditCard CC1("Lisa","123357132",0,2000);
	CC1.print();
	try {
		time_t current, now; 
		current= time(NULL);
		struct tm *begin, *later;
		begin = localtime(&current);
		r = CC1.getRewards();
		b = CC1.GetBalance();
		c = CC1.getCardLimit();
		cout << asctime(begin) << endl;
    	cout << "How much is the charge? ";
        cin >> n;
        if (n > c) { throw ExceedCredit("User has exceeded credit limit. Payment denied."); }
        while (n <= c && a!="no"){
			now = time(NULL);
			later = localtime(&now);
			int t = difftime(now,current);
			r += (n*.01);//cash back reward of 1%
			b += (n-r);
			CC1.SetBalance(b);
			CC1.setRewards(r);
			CC1.interestCharged();
			cout << "Current balance: " << "$" << b << "\n";
			cout << "Available credit: " << "$" << c-b << "\n";
			cout << "Total rewards value: " << "$" << r << "\n";
			cout << "Any more charges ? (enter yes to continue): ";
			cin >> a;
			if (a == "yes"){
				cout << "How much is the charge? ";
        		cin >> n;
				cout << "\n";
				later->tm_mday += t;
				cout << asctime(later) << endl;
        		if (n > c) { throw ExceedCredit("User has exceeded credit limit. Payment denied."); }
        	}
    	}
	}
    catch(ExceedCredit credit) {
        cout << credit.getMessage() << endl;
        CC1.print();
    	}
    if (b != 0) {
    	double rate = CC1.getAPR();
    	double interest = ((b*rate)/365.0);
    	min1 = (.01*b) + interest; // 1% of the current balance + interest on balance
    	min2 = (0.015*b);//1.5% of the balance
        try {
        	cout <<"Current Balance $" <<b<<endl;
            cout << "How much would you like to pay toward the balance? ";
            cin >> n;
            if (n > b) { throw ExceedBalance ("User has tried to make a payment that has exceeded the balance due."); }
            if (n < 0) { throw ArgumentNegative ("User has tried to make a negative payment."); }
            if (n < 25) {
            	cout << "minimum payment allowed cannot be less than $25" << endl;
            	double pay = (min1 > min2) ? min1 : min2;
            	if (pay > n) { CC1.DebitCharge(pay); }
            	else
            		CC1.DebitCharge(25.0);
			}
            else { CC1.DebitCharge(n);}
            
        }
        catch(ExceedBalance balance) {
            cout << balance.getMessage() << endl;
            CC1.print();
        	}
        catch(ArgumentNegative payment) {
            cout << payment.getMessage() << endl;
            CC1.print();
        	}
    }
	system("pause");
	return 0;
}
