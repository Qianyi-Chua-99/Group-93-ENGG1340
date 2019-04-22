#include <iostream>
#include <string> 
#include <algorithm>
#include "Commodity.h"
#include "Shop.h"

using namespace std;

int CURRENTSHOP = -1;

void EnterShop();
void CreateShop();
void EnterShop_Options();
void CreateShop_Options();
void Print_History();

void Print_History(); {
	string date;
	int choice;
	cout << "1. Print commodity history of a specific date " << endl;
	cout << "2. Print all commodity history" << endl;
	cout << "3. Return to previous menu" << endl;
	
	cin >> choice;
	switch(choice) 
	{
		case 1:
			cout << "Please enter a date (YYYY/MM/DD): " << endl;
			cin >> date;
			Shop::printHistory(date);
			break;
		case 2:
		 	printHistory();
		 	break;
		case 3:
			return;
		default:
			cout << "Invalid choice! Please choose again: " << endl;
	}
			
}

bool only_spaces (const string& s) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != ' ') {
			return false;
		}
	}
	return true;
}

void EnterShop() {
	int choice;
	for (int i = 0; i < Shop::listOfShop.size(); i++) {
		cout << i+1 << ". " << Shop::listOfShop[i].getShopName() << endl;
	}
	cin >> choice;
	if (choice < Shop::listOfShop.size()+1 && choice > 0) //valid option, continue on with inventory choices*/
		CURRENTSHOP = choice-1;
		EnterShop_Options();
	else
		cout << "Invalid option! Please choose again: " << endl;
}
	
void CreateShop() {
	cin.ignore();
	cout << "Please enter shop name: ";
	string shop_name; 
	while (true) {
		getline(cin,shop_name);
		if (only_spaces(shop_name) || shop_name.length() == 0) {
			cout << "Invalid shop name! Please re-enter shop name: ";
		}
		else {
			cout << "Creating shop: " << shop_name << endl;
			Shop newShop(shop_name);
			CreateShop_Options();
			break;
		}
	}
}

void EnterShop_Options() {
	cout << "1. All Commodities in Shop" << endl;
	cout << "2. Show Commodity History" << endl;
	cout << "3. Update Commodity Information" << endl;
	cout << "4. Add Commodity" << endl;
	cout << "5. Remove Commodity" << endl;
	cout << "6. Filter Commodities" << endl;
	cout << "7. Out-of-Stock Commodites" << endl;
	cout << "8. Exit" << endl;	
	
	int choice = 0;
	cin >> choice;
	
	while (true) {
		switch (choice) {
		case 1:
			Shop::listOfShop[CURRENTSHOP].printCommodities(1);
			break;
		case 2:
			//print commodity history
			Print_History();
			break;
		case 3:
			/*change quantity
			change price
			change category */
			break; 
		case 4:
			//add commodity
			break;
		case 5:
			//delete commodity
			break;
		case 6:
			//filter commodity
			break;
		case 7:
			//check out of stock commodities
			break;	
		case 8:
			return;
		default:
			cout << "Invalid option! Please choose again: " << endl;
		}
	}	
}

void CreateShop_Options() {
	cout << "1. Add Commodity" << endl;
	cout << "2. Remove Commodity" << endl;
	cout << "3. Update Commodity Information" << endl;
	cout << "4. Exit" << endl;
	
	int choice = 0;
	cin >> choice;
	
	while (true){
		switch(choice){
			case 1:
				//add commodity
			case 2:
				//remove commodity
			case 3:
				//update commodity
			case 4:
				cout << "Bye bye!" << endl;
				return;
			default:
				cout << "Invalid option! Please choose again: " << endl;
		}
	}
}

int main() {

	//initialize everything
	Shop::readData("Information1.txt");
	Shop::readShopData("Shop.txt");
	//Welcome message
	cout << "******************************" << endl;
	cout << " Welcome to Inventory System! " << endl;
	cout << "******************************" << endl;
	cout << endl;

	while(true) {
		cout << "Please choose an option: " << endl;
		cout << "1. Enter a Shop" << '\t' << "2. Create a Shop" << '\t'<< "3. Exit" << endl;
		int choice;
		cin >> choice;
		switch (choice) 
		{
		case 1:
			//Enter shop options function
			EnterShop();
			break;
		case 2:
			//Create shop options fucntion
			CreateShop();
			break;
		case 3:
			return 0;
		default:
			cout << "Invalid option! Please choose again: " << endl;
		}
		
	}
}
	
