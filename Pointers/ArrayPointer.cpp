#include<iostream>
#include<string>
using namespace std;

struct football
{
	string fn;
	string ln;
	int goals;
	int age;
	int rank;
};

void addplayer(struct football x[], int &count)
{
	cout << "Enter the First Name: ";
	cin >> x[count].fn;
	cout << "Enter the Last Name: ";
	cin >> x[count].ln;
	cout << "Enter the Goals scored: ";
	cin >> x[count].goals;
	cout << "Enter the Age: ";
	cin >> x[count].age;
	cout << "Enter the Ranking: ";
	cin >> x[count].rank;
	count++;
}

void update(struct football x[], int i)
{
	cout << "Update the First Name: ";
	cin >> x[i].fn;
	cout << "Update the Last Name: ";
	cin >> x[i].ln;
	cout << "Update the Goals: ";
	cin >> x[i].goals;
	cout << "Update the Age: ";
	cin >> x[i].age;
	cout << "Update the Ranking: ";
	cin >> x[i].rank;
}

void search(struct football x[], int i)
{
	cout << "First Name: " << x[i].fn << endl;
	cout << "Last Name: " << x[i].ln << endl;
	cout << "Goals: " << x[i].goals << endl;
	cout << "Age: " << x[i].age << endl;
	cout << "Ranking: " << x[i].rank << endl;
}

void Display(struct football x[], int size)
{
	//Display Names List
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ": " << x[i].fn << " " << x[i].ln << endl;
	}
}

int main()
{
	int count;
	cin >> count;
	football st;
	football* stptr = NEW st[input];
	int index;
	char choice;
	int count = 0;

	do {
		cout << "Press 1 to Add a new player." << endl;
		cout << "Press 2 to Update a player's record." << endl;
		cout << "Press 3 to Search for a player's record." << endl;
		cout << "Press 4 to Display complete list of players." << endl;
		cout << "Press 5 to Exit the program." << endl;
		cin >> choice;

		if (choice == '1')
		{
			addplayer(st, count);
		}
		else if (choice == '2')
		{
			cout << "Enter the Number of the player you want to update: ";
			cin >> index;
			update(st, index - 1);
		}
		else if (choice == '3')
		{
			cout << "Enter the Number of the player you wanna search for: ";
			cin >> index;
			search(st, index - 1);
		}
		else if (choice == '4')
		{
			Display(st, 10);
		}

	} while (choice != '5');

	system("pause");
	return 0;
}