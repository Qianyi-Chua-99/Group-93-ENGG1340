#include <iostream>
#include <string>
#include <iomanip> 
#include "Commodity.h"
#include "Shop.h"

using namespace std;

int main() {

	//initialize everything
	Shop::readData("Information.txt");

	void EnterShop();
	void CreateShop();
	void Inventory_Options();
	
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
			cout << "Option Invalid! Please choose again: " << endl;
		}
		
	}
	

	void EnterShop() {
		/*print all shop names
		if valid option, continue on with inventory choices*/
		Inventory_Options();
		//else
		cout << "Option Invalid! Please choose again: " << endl;
	}
	
	void CreateShop() {
	}
