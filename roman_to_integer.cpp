#include<iostream>
#include<string>
using namespace std;

class romanType
{
	string roman;
	int intnum;
	int M, D, C, L, X, V, I;
public:
	romanType() :intnum(0), M(1000), D(500), C(100), L(50), X(10), V(5), I(1)
	{
	}
	void conversion(string s)
	{
		int sum = 0;
		roman = s;
		int i = 0;
		while (s[i] != '\0')
		{
			if (s[i] == 'M')
				sum += M;
			else if (s[i] == 'D')
				sum += D;
			else if (s[i] == 'C')
				sum += C;
			else if (s[i] == 'L')
				sum += L;
			else if (s[i] == 'X')
				sum += X;
			else if (s[i] == 'V')
				sum += V;
			else if (s[i] == 'I')
				sum += I;
			i++;
		}
		intnum = sum;
	}
	void printRoman()
	{
		cout << "Roman = " << roman << endl;
	}
	void printNum()
	{
		cout << "Integer Number: "<<intnum << endl;
	}
};

int main()
{
	romanType R1;
	char choice;
	string s;
	cout << "Enter the roman numerals: ";
	cin >> s;
	R1.conversion(s); 

	cout << "Enter 1 to print in Roman" << endl;
	cout << "Enter 2 to print in Value" << endl;
	cin >> choice;
	if (choice == '1')
	{
		R1.printRoman();
	}
	else if (choice == '2')
	{
		R1.printNum();
	}

	system("pause");
	return 0;
}