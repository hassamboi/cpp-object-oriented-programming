#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct menuItem
{
	string name;
	int quant;
	float tax = 0.00;
	float fee = 0.00;
	string ing;
};

//DATA WILL BE TAKEN FROM FILE(NOT ATTACHED)
void getData(menuItem menuList[], int size)
{
	ifstream file;
	file.open("menu.txt");
	for (int i = 0; i < size; i++)
	{
		file >> menuList[i].name;
		file >> menuList[i].quant;
		file >> menuList[i].tax;
		file >> menuList[i].fee;
		file >> menuList[i].ing;
	}
}

//DISPLAYING MENU
void showMenu(menuItem menuList[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Enter " << i + 1 << " for " << menuList[i].name << endl;
	}
}

//PROVIDING OPTIONS AND CALCULATING BILL ACCORDINGLY
void  printCheck(menuItem menuList[])
{
	string names[8];
	float total=0;
	float totalTax = 0;
	float totalSum = 0;
	int quantity;
	char choice;
	char x;

	//MENU DRIVEN LOOP
	do {
		cin >> choice;
		cout << "Enter the quantity: ";
		cin >> quantity;

		for (int i = 0; i < 8; i++)
		{
			if (choice == i - 1)
			{
				total = menuList[i].fee + quantity + menuList[i].tax;
				names[i] = menuList[i].name;
				totalTax += menuList[i].tax;
			}
		}

		totalSum += total;
		cout << "Is that all or would you like something else as well. Press n to exit." << endl;
		cin >> x;
	} while (x != 'n');

	cout << "Item:\t" << "Quantity\t" << "Price/Item\t" << "Ingredients" << endl;

	//DISPLAYING ACCORDING TO SELECTION OF USER
	for (int k = 0; k < 8; k++)
	{
		if (names[k] == menuList[k].name)
			cout << names[k] << "\t" << quantity << "\t" << menuList[k].fee << "\t" << menuList[k].ing << endl;
	}
	cout << "Total Tax\t" << totalTax << endl;
	cout << "Amount Due\t" << totalSum << endl;
}

int main()
{
	menuItem menuList[8];
	getData(menuList, 8);
	showMenu(menuList, 8);
	printCheck(menuList);
	system("pause");
	return 0;
}
