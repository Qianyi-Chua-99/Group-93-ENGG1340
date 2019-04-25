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

bool only_spaces (const string& s) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != ' ') {
			return false;
		}
	}
	return true;
}

bool confirmation() {
	string tmp;
	cout << "Are you sure you want to proceed with the operation (y/n)? : ";
	cin >> tmp;
	if (tmp == "y")
		return true;
	else
		return false;
}

string stringInput (const string& message) {
	string result;
	while (true) {
		cout << message;
		getline(cin, result);
		if (only_spaces(result)) {
			cout << "Invalid input! Please provide a valid value." << endl;
			cout << endl;
		}
		else {
			break;
		}
	}
	return result;
}

double numberInput (const string& message) {
	double result;
	string tmp;
	while (true) {
		cout << message;
		getline(cin, tmp);
		if (!checkIsNumber(tmp, result)) {
			cout << "Invalid input! Please provide a valid value." << endl;
			cout << endl;
		}
		else {
			break;
		}
	}
	return result;
}

void Print_History() {
	string date;
	while (true) {
		int choice;
		cout << "1. Print commodity history of a specific date " << endl;
		cout << "2. Print all commodity history" << endl;
		cout << "3. Delete history on a specific date" << endl;
		cout << "4. Delete all history" << endl;
		cout << "5. Return to previous menu" << endl;
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
				cout << "Please enter a date (YYYY/MM/DD): ";
				cin >> date;
				cout << endl;
				if (confirmation()) {
					if(Shop::listOfShop[CURRENTSHOP].deleteHistory(date)) {
						cout << "Successfully deleted to the record" << endl;
						cout << endl;
					}
					else {
						cout << "Record not found" << endl;
						cout << endl;
					}
				}
				else {
					cout << "Command aborted" << endl;
					cout << endl;
				}
				break;
			case 4:
				if (confirmation()) 
					Shop::listOfShop[CURRENTSHOP].deleteHistory(date);
				else {
					cout << "Command aborted" << endl;
					cout << endl;
				}
				break;
			case 5:
				return;
			default:
				cout << "Invalid choice! Please choose again: " << endl;
		}
	}
			
}

void EnterShop() {
	int choice;
	while (true) {
		cout << "List of Shops: " << endl;
		int i;
		for (i = 0; i < Shop::listOfShop.size(); i++) {
			cout << i+1 << ". " << Shop::listOfShop[i].getShopName() << endl;
		}
		cout << i+1 << ". Return to previous menu." << endl;
		cout << "Enter your option: ";
		cin >> choice;
		cout << endl;
		if (choice < Shop::listOfShop.size()+1 && choice > 0) { //valid option, continue on with inventory choices*/
			CURRENTSHOP = choice-1;
			EnterShop_Options();
		} 
		else if (choice = i+1) {
			return;
		}
		else
			cout << "Invalid option! Please choose again: " << endl;
	}
}
	
void CreateShop() {
	cin.ignore();
	cout << "Please enter shop name (0 to return to previous menu): ";
	string shop_name; 
	while (true) {
		cout << endl;
		getline(cin,shop_name);
		if (only_spaces(shop_name) || shop_name.length() == 0) {
			cout << "Invalid shop name! Please re-enter shop name (0 to return to previous menu): ";
		}
		else if (shop_name == "0"){
			return;
		}		
		else {
			Shop newShop(shop_name);
			cout << shop_name << " successfully created." << endl;
			cout << endl;
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
		cin.ignore();
		cout << endl;
		if (choice < 4) {
			cout << "Value to be updated: ";
			getline(cin, input);
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
		choice = stringInput("Input the name of commodity you wish to update (0 to return to previous menu)\n");
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
	commodityName = stringInput("Input the commodity name: ");
	cout << endl;
	for (int i = 0; i < Shop::listOfCommodity.size(); i++) {
		if (Shop::listOfCommodity[i].getName() == commodityName) {
			Shop::listOfShop[CURRENTSHOP].printSpecificCommodity(commodityName);
			return;
		}
	}
	cout << "Commodity not found." << endl;
	cout << endl;
}

void Add_Commodity() {
	bool isPresent = false;
	while (true) {
		isPresent = false;
		string commodityName = stringInput("Input the commodity name to be added: ");
		for (int i = 0; i < Shop::listOfCommodity.size(); i++) {
			if (Shop::listOfCommodity[i].getName() == commodityName) {
				cout << "Commodity already present in the record." << endl;
				isPresent = true;
				break;
			}
		}
		if (isPresent) continue;
		string categoryName = stringInput("Input the category of the commodity: ");;
		double price = numberInput("Input the price of the commodity: ");
	
		cout << endl;
		Commodity newCommodity(commodityName, categoryName, price);
		Shop::addCommodity(newCommodity);
		cout << commodityName << " successfully added to the record" << endl;
		cout << endl;
		break;
	}
}

void Delete_Commodity() {
	bool isPresent = false;
	while (true) {
		isPresent = false;
		string commodityName = stringInput("Input the commodity name to be removed (0 to return to previous menu): ");
		if (commodityName == "0")
			return;
		for (int i = 0; i < Shop::listOfCommodity.size(); i++) {
			if (Shop::listOfCommodity[i].getName() == commodityName) {
				isPresent = true;
				break;
			}
		}
		if (!isPresent) {
			cout << "Commodity not found." << endl;
			cout << endl;
			return;
		}	
		cout << endl;
		if (confirmation()) {
			if (Shop::deleteCommodity(commodityName))
				cout << commodityName << " successfully deleted to the record" << endl;
			else
				cout << "Record not found" << endl;
		}
		else
			cout << "Command aborted" << endl;
		cout << endl;
		break;
	}
}

void Sort_Commodity(int mode = 0) {
	while (true) {
		int choice;
		int order;
		cout << "Sort by:" << endl;
		cout << "1. Name" << endl;
		cout << "2. Category" << endl;
		cout << "3. Price" << endl;
		cout << "4. Quantity" << endl;
		cout << "5. Return to previous menu" << endl;
		cout << "Enter your option: ";
		cin >> choice;
		cout << endl;
		while (true) {
			cout << "1. Ascending" << endl;
			cout << "2. Descending" << endl;
			cout << "Enter your option: ";
			cin >> order;
			cout << endl;
			if (order == 1 || order == 2)
				break;
			cout << "Invalid input." << endl;
		}
		switch (choice) {
			case 1: {
				if (mode == 0)
					Shop::listOfShop[CURRENTSHOP].sortCommodity(Shop::NAME, order);
				else
					Shop::sortAllCommodity(Shop::NAME, order);
				cout << endl;
				return;
				break;
			}
			case 2: {
				if (mode == 0)
					Shop::listOfShop[CURRENTSHOP].sortCommodity(Shop::CATEGORY, order);
				else
					Shop::sortAllCommodity(Shop::CATEGORY, order);
				cout << endl;
				return;
				break;
			}
			case 3: {
				if (mode == 0)
					Shop::listOfShop[CURRENTSHOP].sortCommodity(Shop::PRICE, order);
				else
					Shop::sortAllCommodity(Shop::PRICE, order);
				cout << endl;
				return;
				break;
			}
			case 4:{
				if (mode == 0)
					Shop::listOfShop[CURRENTSHOP].sortCommodity(Shop::QUANTITY, order);
				else
					Shop::sortAllCommodity(Shop::QUANTITY, order);
				cout << endl;
				return;
			}
			case 5:
				return;
			default:
				continue;
		}
	}
}

void Filter_Commodity(int mode = 0) {
	while (true) {
		int choice;
		cout << "Filter by:" << endl;
		cout << "1. Category" << endl;
		cout << "2. Price" << endl;
		cout << "3. Quantity" << endl;
		cout << "4. Return to previous menu" << endl;
		cout << "Enter your option: ";
		cin >> choice;
		cin.ignore();
		cout << endl;
		switch (choice) {
			case 1: {
				string categoryName = stringInput("Enter the category: ");
				cout << endl;
				if (mode == 0)
					Shop::listOfShop[CURRENTSHOP].filter(1, categoryName);
				else 
					Shop::filterAll(1, categoryName);
				cout << endl;
				return;
				break;
			}
			case 2: {
				double lb = numberInput("Enter the lower bound: ");
				double ub = numberInput("Enter the upper bound: ");
				cout << endl;
				if (mode == 0)
					Shop::listOfShop[CURRENTSHOP].filter(3, lb, ub);
				else 
					Shop::filterAll(3, lb, ub);
				cout << endl;
				return;
				break;
			}
			case 3: {
				double lb = numberInput("Enter the lower bound: ");
				double ub = numberInput("Enter the upper bound: ");
				cout << endl;
				if (mode == 0)
					Shop::listOfShop[CURRENTSHOP].filter(2, lb, ub);
				else
					Shop::filterAll(2, lb, ub);
				cout << endl;
				return;
				break;
			}
			case 4:
				return;
			default:
				continue;
		}
	}
}

void EnterShop_Options() {
	while (true) {
		cout << "Current shop: " << Shop::listOfShop[CURRENTSHOP].getShopName() << endl;
		cout << endl;
		cout << "1. All Commodities in Shop" << endl;
		cout << "2. History" << endl;
		cout << "3. Show Commodity Information" << endl;
		cout << "4. Add Commodity" << endl;
		cout << "5. Update Commodity Information" << endl;
		cout << "6. Remove Commodity" << endl;
		cout << "7. Filter Commodities" << endl;
		cout << "8. Sort Commodities" << endl;
		cout << "9. Out-of-Stock Commodites" << endl;
		cout << "10. Return to previous menu" << endl;

		cout << "Enter your option: ";
	
		int choice = 0;
		cin >> choice;
		cin.ignore();
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
				//add commodity
				Add_Commodity();
				break;
			case 5:
				Update_Commodity();
				break; 
			case 6:
				//delete commodity
				Delete_Commodity();
				break;
			case 7:
				//filter commodity
				Filter_Commodity();
				break;
			case 8:
				Sort_Commodity();
				break;	
			case 9:
				//check out of stock commodities
				Shop::listOfShop[CURRENTSHOP].alertOutOfStock();
				break;
			case 10:
				return;
			default:
				cout << "Invalid option! Please choose again: " << endl;
		}
	}	
}

void Overall_Options() {
	cout << "1. Sort" << endl;
	cout << "2. Filter" << endl;
	cout << "3. Return to previous menu" << endl;
	cout << "Enter your option: ";	
	int choice = 0;
	cin >> choice;
	cout << endl;
	if (choice < 1 || choice > 3)
		return;
	switch (choice) {
		case 1:
			Sort_Commodity(1);
			break;
		case 2:
			Filter_Commodity(1);
			break;
		case 3:
			return;
	}
} 

int main() {

	//initialize everything
	Shop::readData("Information.txt");
	Shop::readShopData("Shop.txt");
	Shop::readAllHistory();
	//Welcome message
	cout << "******************************" << endl;
	cout << " Welcome to Inventory System! " << endl;
	cout << "******************************" << endl;
	cout << endl;

	while(true) {
		cout << "Please choose an option: " << endl;
		cout << "1. Enter a Shop" << "\t\t" << "2. Create a Shop" << '\t' << "3. Show Overall Report" << '\t'<< "4. Exit" << endl;
		int choice;
		cin >> choice;
		cout << endl;
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
			Overall_Options();
			break;
		case 4:
			Shop::writeAllHistory();
			Shop::writeData("InformationNew.txt");
			Shop::writeShopData("ShopNew.txt");
			cout << "Good Bye :D" << endl;
			return 0;
		default:
			cout << "Invalid option! Please choose again: " << endl;
		}
		
	}
}
