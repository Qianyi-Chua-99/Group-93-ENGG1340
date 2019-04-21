#include <iostream>
#include <string>
#include <iomanip> 
#include "Commodity.h"
#include "Shop.h"

using namespace std;

void EnterShop();
void CreateShop();
string shop_name;
void EnterShop_Options();
void CreateShop_Functions();
	
void EnterShop() {
	/*print all shop names
	if valid option, continue on with inventory choices*/
		EnterShop_Options();
	//else
	cout << "Invalid option! Please choose again: " << endl;
}
	
void CreateShop() {
	cin >> shop_name; //add to Shop constructor
	if (shop_name.length() > 0) {
		CreateShop_Options();
	}
	else
		cout << "Invalid shop name! Please re-enter shop name: " << endl;
}

void EnterShop_Options() {
	cout << "1. All Commodities in Shop" << endl;
	cout << "2. Show Commodity History" << endl;
	cout << "3. Update Commodity Information" << endl;
	cout << "4. Remove Commodity" << endl;
	cout << "5. Filter Commodities" << endl;
	cout << "6. Exit" << endl;	
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
		cout << "1. Enter a Shop" << '\t' << "2. Create a Shop" << endl;
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
		default:
			cout << "Invalid option! Please choose again: " << endl;
		}
		
	}
	
