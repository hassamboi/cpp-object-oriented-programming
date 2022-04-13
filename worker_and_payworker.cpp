#include<iostream>
#include<string>
using namespace std;

class worker {
private:
	char* workerName;
	string SSN;

public:
	worker() :workerName(0), SSN("") {}

	worker(string n, string s)
	{
		workerName = new char[n.length() + 1];
		int i;
		for (i = 0; n[i] != '\0'; i++)
			workerName[i] = n[i];
		workerName[i] = '\0';

		SSN = s;
	}

	~worker() {}
	
	void setWorkerName(string s)
	{
		workerName = new char[s.length() + 1];
		int i;
		for (i = 0; s[i] != '\0'; i++)
			workerName[i] = s[i];
		workerName[i] = '\0';
	}

	void setSSN(string s)
	{
		SSN = s;
	}

	char* getWorkerName()
	{
		return workerName;
	}

	string getSSN()
	{
		return SSN;
	}

	virtual void printValues()
	{
		cout << "in base class worker workerName is " << workerName << endl;
		cout << "in base class worker SSN is " << SSN << endl;
	}
};

class payWorker :public worker
{
private:
	int dependents;
	double payRate;

public:
	payWorker(int a = 0, double b = 0) :dependents(a), payRate(b) {}
	~payWorker() {}

	void setPayRate(double p)
	{
		payRate = p;
	}
	
	void setDependents(int d)
	{
		dependents = d;
	}

	double getPayRate()
	{
		return payRate;
	}

	int getDependents()
	{
		return dependents;
	}

	void printValues()
	{
		worker::printValues();
		cout << "In derived class payWorker PayRate is " << payRate << endl;
		cout << "In derived class payWorker Dependents is " << dependents << endl;
	}
};

int main()
{
	payWorker *p = new payWorker;
	p->setWorkerName("Jesus Guerra");
	p->setSSN("555-22-7788");
	p->setDependents(5);
	p->setPayRate(12.50);

	p->printValues();

	cout << "Worker Name: " << p->getWorkerName() << endl;
	cout << "Social Security Number: " << p->getSSN() << endl;
	cout << "Pay Rate: $" << p->getPayRate() << endl;
	cout << "Number of dependents: " << p->getDependents() << endl;

	delete(p);

	system("pause");
	return 0;
}