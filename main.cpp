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

bool checkIsNumber (const string& input, double &result) {
	char* end;
    	result = strtod(input.c_str(), &end);
    	if (end == input.c_str() || *end != '\0') 
    		return false;
    	return true;
}

void Print_History() {
	string date;
	int choice;
	cout << "1. Print commodity history of a specific date " << endl;
	cout << "2. Print all commodity history" << endl;
	cout << "3. Return to previous menu" << endl;
	cout << "Enter your option: ";
	cin >> choice;
	cout << endl;
	switch(choice) 
	{
		case 1:
			cout << "Please enter a date (YYYY/MM/DD): ";
			cin >> date;
			cout << endl;
			Shop::listOfShop[CURRENTSHOP].printHistory(date);
			break;
		case 2:
		 	Shop::listOfShop[CURRENTSHOP].printHistory();
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
	cout << endl;
	cout << "List of Shops: " << endl;
	for (int i = 0; i < Shop::listOfShop.size(); i++) {
		cout << i+1 << ". " << Shop::listOfShop[i].getShopName() << endl;
	}
	cout << "Enter your option: ";
	cin >> choice;
	cout << endl;
	if (choice < Shop::listOfShop.size()+1 && choice > 0) { //valid option, continue on with inventory choices*/
		CURRENTSHOP = choice-1;
		EnterShop_Options();
	}
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

void UpdateCommodity_Options(string commodityName) {
	int choice;
	string input;
	double result;
	bool isNumber;
	while (true) {
		cout << "Commodity: " << commodityName << endl;
		cout << "1. Update quantity" << endl;
		cout << "2. Update category" << endl;
		cout << "3. Update price" << endl;
		cout << "4. Done update" << endl;
		cout << "Enter your option: ";
		
		cin >> choice;
		cout << endl;
		if (choice < 4) {
			cout << "Value to be updated: ";
			cin >> input;
			cout << endl;
			isNumber = checkIsNumber(input, result);
		}
		switch (choice) {
			case 1:
				if (isNumber) {
					int quantity = (int)result;
					Shop::listOfShop[CURRENTSHOP].setCommodityQuantity(commodityName, quantity);
					cout << "Quantity updated!" << endl;
					cout << endl;
				}
				else {
					cout << "Invalid value given." << endl;
					cout << endl;
				}
				break;
			case 2:
				if (!isNumber) {
					Shop::listOfShop[CURRENTSHOP].setCommodityCategory(commodityName, input);
					cout << "Category updated!" << endl;
					cout << endl;
				}
				else {
					cout << "Invalid value given." << endl;
					cout << endl;
				}
				break;
			case 3:
				if (isNumber) {
					Shop::listOfShop[CURRENTSHOP].setCommodityPrice(commodityName, result);
					cout << "Price updated!" << endl;
					cout << endl;
				}
				else {
					cout << "Invalid value given." << endl;
					cout << endl;
				}
				break;
			case 4:
				return;
			default:
				cout << "Invalid option." << endl;
				cout << endl;
		}
	}
}

void Update_Commodity() {
	string choice;
	while (true) {
		bool commodityPresent = false;
		cout << "Input the name of commodity you wish to update (0 to return to previous menu)" << endl;
		cin >> choice;
		cout << endl;
		if (choice == "0") {
			return;
		}
		for (int i = 0; i < Shop::listOfCommodity.size(); i++) {
			if (Shop::listOfCommodity[i].getName() == choice) {
				commodityPresent = true;
				break;
			}
		}
		if (!commodityPresent) {
			cout << "Commodity not present!" << endl;
			cout << endl;
			continue;
		}
		UpdateCommodity_Options(choice);
		break;
	}
}

void Show_Commodity() {
	string commodityName;
	cout << "Input the commodity name: ";
	cin >> commodityName;
	cout << endl;
	for (int i = 0; i < Shop::listOfCommodity.size(); i++) {
		if (Shop::listOfCommodity[i].getName() == commodityName) {
			Shop::listOfShop[CURRENTSHOP].printSpecificCommodity(commodityName);
			return;
		}
	}
	cout << "Commodity not found." << endl;
}

void EnterShop_Options() {
	while (true) {
		cout << "Current shop: " << Shop::listOfShop[CURRENTSHOP].getShopName() << endl;
		cout << endl;
		cout << "1. All Commodities in Shop" << endl;
		cout << "2. Show Commodity History" << endl;
		cout << "3. Show Commodity Information" << endl;
		cout << "4. Update Commodity Information" << endl;
		cout << "5. Add Commodity" << endl;
		cout << "6. Remove Commodity" << endl;
		cout << "7. Filter Commodities" << endl;
		cout << "8. Out-of-Stock Commodites" << endl;
		cout << "9. Return to previous menu" << endl;
		cout << "10. Exit" << endl;
		cout << "Enter your option: ";
	
		int choice = 0;
		cin >> choice;
		cout << endl;
	
		switch (choice) {
			case 1:
				Shop::listOfShop[CURRENTSHOP].printCommodity(1);
				break;
			case 2:
				Print_History();
				break;
			case 3:
				Show_Commodity();
				break;
			case 4:
				/*change quantity
				change price
				change category */
				Update_Commodity();
				break; 
			case 5:
				//add commodity
				break;
			case 6:
				//delete commodity
				break;
			case 7:
				//filter commodity
				break;
			case 8:
				//check out of stock commodities
				break;	
			case 9:
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
	Shop::readAllHistory();
	//Welcome message
	cout << "******************************" << endl;
	cout << " Welcome to Inventory System! " << endl;
	cout << "******************************" << endl;
	cout << endl;

	while(true) {
		cout << "Please choose an option: " << endl;
		cout << "1. Enter a Shop" << "\t\t" << "2. Create a Shop" << '\t'<< "3. Exit" << endl;
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
	
