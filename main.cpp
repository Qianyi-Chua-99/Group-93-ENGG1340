#include <iostream>
#include <string> 
#include "Commodity.h"
#include "Shop.h"

using namespace std;

void EnterShop();
void CreateShop();
void EnterShop_Options();
void CreateShop_Functions();
bool whiteSpaceOnly;
	
void EnterShop() {
	int choice;
	for (int i = 0; i < Shop::listOfShop.size(); i++) {
		cout << i << ". " << Shop::listOfShop[i] << endl;
	}
	cin >> choice;
	if (choice < Shop::listOfShop.size() && choice > -1) //valid option, continue on with inventory choices*/
		EnterShop_Options();
	else
		cout << "Invalid option! Please choose again: " << endl;
}
	
void CreateShop() {
	string shop_name; 
	while (true) {
		cin >> shop_name;
		if (all_of(shop_name.begin(),shop_name.end(),isspace) {
			cout << "Invalid shop name! Please re-enter shop name: " << endl;
		}
		else {
			Shop (shop_name);
			CreateShop_Options();
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
		case '1':
			//print all commodities in shop
			break;
		case '2':
			//print commodity history
			break;
		case '3':
			/*change quantity
			change price
			change category */
			break; 
		case '4':
			//add commodity
			break;
		case '5':
			//delete commodity
			break
		case '6':
			//filter commodity
		case '7':
			//check out of stock commodities	
		case '8':
			return;
		default:
			"Invalid option! Please choose again: "
		}
	}	
}

void CreateShop_Option() {
	cout << "1. Add Commodity" << endl;
	cout << "2. Remove Commodity" << endl;
	cout << "3. Update Commodity Information" << endl;
	cout << "4. Exit" << endl;
	
	int choice = 0;
	cin >> choice
	
	while (true){
		switch(choice){
			case '1':
				//add commodity
			case '2':
				//remove commodity
			case '3':
				//update commodity
			case '4':
				return;
			default:
				"Invalid option! Please choose again: "
		}
	}
}

int main() {

	//initialize everything
	Shop::readData("Information.txt");

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
		case '1':
			//Enter shop options function
			EnterShop();
			break;
		case '2':
			//Create shop options fucntion
			CreateShop()
			break;
		case '3':
			return 0;
		default:
			cout << "Invalid option! Please choose again: " << endl;
		}
		
	}
	
