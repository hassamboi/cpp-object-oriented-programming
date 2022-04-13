#include<iostream>
#include<string>
using namespace std;

//ABSTRACT CLASS BANK ACCOUNT
class bankAccount 
{
protected:
	int accNumber;
	string name;
	double balance;
public:
	//setter
	void setAccountInfo(int a, string n) 
	{
		accNumber = a;
		name = n;
	}

	//retrievers
	string retrieve_name()
	{
		return name;
	}

	int retrieve_accNumber() 
	{
		return accNumber;
	}

	double retrieve_balance() 
	{
		return balance;
	}

	//pure virtual ftns
	virtual void withdraw(float) = 0;
	virtual void deposit(float) = 0;
	virtual void monthly_statements() = 0;
};

//ABSTRACT CLASS CHECKING ACCOUNT
class checkingAccount:public bankAccount 
{
protected:
	int checksAmount;
public:
	virtual void writeCheck(float) = 0;
};

//charge checking account
class serviceChargeChecking:public checkingAccount 
{
private:
	int charge;
public:
	//constructor & deconstructor
	serviceChargeChecking() 
	{
		checksAmount = 5;
		charge = 10;
		balance = 0.0;
	}
	~serviceChargeChecking() {}

	//check writing ftn
	void writeCheck(float amount)
	{
		if (checksAmount == 0)
			cout << "You can't write anymore cheques this month." << endl;
		else
		{
			cout << "You can only write " << checksAmount << " cheques this month." << endl;
			balance = balance - amount;
			cout << "You wrote a check for " << amount << "$" << endl;
			checksAmount--;
		}
	}

	//withdraw & deposit
	void withdraw(float amount) 
	{
		if (amount > balance)
			cout << "you don't have enough balance to withdraw the amount" << endl;
		else
		{
			balance = balance - amount;
			cout << "Withdrawn amount: " << amount << "$" << endl;
			cout << "Balance left: " << balance << "$" << endl;
		}
	}

	void deposit(float amount) 
	{
		balance += amount;
		cout << "Deposited amount: " << amount << "$" << endl;
		cout << "Updated balance: " << balance << "$" << endl;
	}

	//monthly statements 
	void monthly_statements() 
	{
		balance = balance - charge; //Subtracting charge every month
		cout << "CHEQUING ACCOUNT STATEMENT" << endl;
		cout << "Account Number: " << accNumber << endl;
		cout << "Name: " << name << endl;
		cout << "Balance: " << balance << "$" << endl;
		cout << "Cheques written: " << 5 - checksAmount << endl;
	}
};

//no charge checking
class noServiceChargeChecking :public checkingAccount
{
private:
	int minBalance;
	double interest;
public:
	//constructor & deconstructor
	noServiceChargeChecking() 
	{
		minBalance = 50;
		interest = 0.01;
		checksAmount = 0;
		balance = 0.0;
	}
	~noServiceChargeChecking() {}

	//check writing ftn
	void writeCheck(float amount) 
	{
		if (balance >= minBalance)
		{
			cout << "You've written " << checksAmount << " cheques this month" << endl;
			balance -= amount;
			checksAmount++;
			cout << "You wrote a check for " << amount << "$" << endl;
		}
		else
			cout << "You don't have enough balance" << endl;
	}

	//withdraw & deposit
	void withdraw(float amount)
	{
		if (amount > balance)
			cout << "you don't have enough balance to withdraw the amount" << endl;

		else if (balance >= minBalance)
		{
			balance -= amount;
			cout << "Withdrawn amount: " << amount << "$" << endl;
			cout << "Balance left: " << balance << "$" << endl;
		}
		else
			cout << "You don't have enough balance" << endl;
	}

	void deposit(float amount) 
	{
		balance += amount;
		cout << "Deposited amount: " << amount << "$" << endl;
		cout << "Updated balance: " << balance << "$" << endl;
	}

	//monthly statements
	void monthly_statements() 
	{
		balance += (balance * (interest / 12.0)); //Adding 12th of interest every month
		cout << "CHEQUING ACCOUNT STATEMENT" << endl;
		cout << "Account Number: " << accNumber << endl;
		cout << "Name: " << name << endl;
		cout << "Balance: " << balance << "$" << endl;
		cout << "Cheques written: " << checksAmount << endl;
		cout << "Interest per year: " << (balance * interest) << "$" << endl;
		cout << "Interest per month: " << (balance * (interest / 12.0)) << "$" << endl;
	}
};

//high interest checking
class highInterestChecking :public noServiceChargeChecking 
{
private:
	int minBalance;
	double interest;

public:
	highInterestChecking() 
	{
		minBalance = 500;
		interest = 0.05;
		checksAmount = 0;
		balance = 0.0;
	}
	~highInterestChecking() {}

	//inherits all ftns with greater interest and min balance
};

//low interest savings account
class savingsAccount :public bankAccount 
{
protected:
	double interest;
public:
	//constructor & deconstructor
	savingsAccount() 
	{
		interest = 0.01;
		balance = 0.0;
	}
	~savingsAccount() {}

	//withdraw & deposit
	void withdraw(float amount) 
	{
		if (amount <= balance)
		{
			balance -= amount;
			cout << "Withdrawn amount: " << amount << "$" << endl;
			cout << "Balance left: " << balance << "$" << endl;
		}
		else
			cout << "you don't have enough balance" << endl;
	}

	void deposit(float amount) 
	{
		balance += amount;
		cout << "Deposited amount: " << amount << "$" << endl;
		cout << "Updated balance: " << balance << "$" << endl;
	}

	//monthly statement
	void monthly_statements()
	{
		balance += (balance * (interest / 12.0)); //adding 12th of interest every month
		cout << "SAVINGS ACCOUNT STATEMENT" << endl;
		cout << "Account Number: " << accNumber << endl;
		cout << "Name: " << name << endl;
		cout << "Balance: " << balance << "$" << endl;
		cout << "Interest per year: " << (balance * interest) << "$" << endl;
		cout << "Interest per month: " << (balance * (interest / 12.0)) << "$" << endl;
	}
};

//high interest savings account
class highInterestSavings : public savingsAccount
{
private:
	int minBalance;
public:
	//constructor & deconstructor
	highInterestSavings()
	{
		minBalance = 500;
		interest = 0.05;
		balance = 0.0;
	}
	~highInterestSavings() {}

	//withdraw & deposit
	void withdraw(float amount)
	{
		if (amount > balance)
			cout << "you don't have enough balance to withdraw the amount" << endl;

		else if (balance >= minBalance)
		{
			balance = balance - amount;
			cout << "Withdrawn amount: " << amount << "$" << endl;
			cout << "Balance left: " << balance << "$" << endl;
		}
		else
			cout << "You don't have enough balance" << endl;
	}

	void deposit(float amount) 
	{
		balance += amount;
		cout << "Deposited amount: " << amount << "$" << endl;
		cout << "Updated balance: " << balance << "$" << endl;
	}

	//monthly statement
	void monthly_statements()
	{
		balance += (balance * (interest / 12.0)); //adding 12th of interest every month
		cout << "SAVINGS ACCOUNT STATEMENT" << endl;
		cout << "Account Number: " << accNumber << endl;
		cout << "Name: " << name << endl;
		cout << "Balance: " << balance << "$" << endl;
		cout << "Interest per year: " << (balance * interest) << "$" << endl;
		cout << "Interest per month: " << (balance * (interest / 12.0)) << "$" << endl;
	}
};



class certificateOfDeposit :public bankAccount 
{
private:
	int maturity_months;
	double interest;
	int current_month;

public:
	//constructor & deconstructor
	certificateOfDeposit() 
	{
		maturity_months = 0;
		interest = 0.0;
		current_month = 0;
		balance = 0.0;
	}
	~certificateOfDeposit() {}

	//setting up a CD
	void setCD(int months)
	{
		maturity_months = months;
		//interest rate will increase as the months increase
		interest = maturity_months / 100.0; 
		//e.g for 6 months interest rate would be 6%
		current_month = 1;
	}

	//withdraw ftn
	void withdraw(float amount)
	{
		if (amount > balance)
			cout << "you don't have enough balance to withdraw the amount" << endl;

		else if (current_month > maturity_months)
		{
			cout << "You withdrew money without any penalty" << endl;
			balance -= amount;
			cout << "Withdrawn amount: " << amount << endl;
			cout << "Balance left: " << balance << endl;
		}
		else
		{
			double penalty;
			penalty = (balance*(interest / maturity_months))*(maturity_months / 3.0);

			//penalty=balance* interestPerMonth* No.OfMonthsInterest

			balance -= penalty;
			balance -= amount;
			cout << "Withdrawn amount: " << amount << "$" << endl;
			cout << "Updated balance: " << balance << "$" << endl;
			cout << "Penalty for early withdrawal: " << penalty << "$" << endl;
		}
	}

	//deposit ftn
	void deposit(float amount)
	{
		balance += amount;
		cout << "Deposited amount: " << amount << "$" << endl;
		cout << "Updated balance: " << balance << "$" << endl;
	}

	//monthly statements
	void monthly_statements() 
	{
		balance += (balance * (interest / maturity_months)); //adding interest every month
		current_month++;
		cout << "CD ACCOUNT STATEMENT" << endl;
		cout << "Account Number: " << accNumber << endl;
		cout << "Name: " << name << endl;
		cout << "Balance: " << balance << "$" << endl;
		cout << "Interest after " << maturity_months << " months: " << (balance * interest) << "$" << endl;
		cout << "Interest per month: " << (balance * (interest / maturity_months)) << "$" << endl;
	}
};

//testing out three accounts in main instead of creating a menu for all accounts
int main()
{
	//testing a High interest chequing account
	highInterestChecking H;
	H.setAccountInfo(13, "Hassam");
	cout << "Account Number: " << H.retrieve_accNumber() << endl;
	cout << "Name: " << H.retrieve_name() << endl;
	H.deposit(200);
	H.withdraw(100);
	H.withdraw(200);
	H.deposit(5000);
	cout << endl;
	H.monthly_statements();
	cout << endl;
	H.withdraw(2500);
	H.writeCheck(2000);
	cout << "Balance: " << H.retrieve_balance() << endl << endl;

	//testing a Low interest savings account
	savingsAccount S;
	S.setAccountInfo(11, "Hassam Ud Din");
	S.deposit(5000);
	S.withdraw(1000);
	cout << endl;
	S.monthly_statements();
	cout << endl;
	S.withdraw(7000);
	cout << "Balance: " << S.retrieve_balance() << endl << endl;

	//testing a CD account
	certificateOfDeposit C;
	C.setAccountInfo(34, "Hassam Ud Din");
	C.setCD(6); //setting a cd for 6 months
	C.deposit(5000);
	cout << endl;
	C.monthly_statements();
	cout << endl;
	C.withdraw(2000);
	cout << endl << endl;

	return 0;
}