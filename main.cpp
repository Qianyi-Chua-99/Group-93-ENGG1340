#include <iostream>
#include <string>
#include <iomanip> 
#include "Commodity.h"
#include "Shop.h"

using namespace std;

int main() {

	//initialize everything
	Shop::readData("Information.txt");
	
	//Welcome message
	cout << "******************************" << endl;
	//cout << endl;
	cout << " Welcome to Inventory System! " << endl;
	//cout << endl;
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
			cout << "Successfully entered a shop" << endl;
			break;
		case '2':
			//Create shop options fucntion
			cout << "Successfully entered a shop" << endl;
			break;
		}
		return 0;
	}
	


/*
//Welcome message
void displayWelcome() {
	cout << setfill('*') << setw(30) << endl;
	cout << endl;
	cout << " Welcome to Inventory System! " << endl;
	cout << endl;
	cout << setfill('*') << setw(30) << endl;
}

//Choose store
void displayShop() {
	int i;
	cout << endl;
	cout << setfill('*') << setw(30) << endl;
	cout << "Please select a store" << endl;
	// for ( i = 0; i < VECTOR_SHOP??.size() ; i ++)
		//cout << "		" << i << '.' << " " << Shop[i] << endl;
	cout << "		" << (i+1) << '.' << " " << "Create New Shop" << endl;
	cout << endl;
	cout << setfill('*') << setw(30) << endl;
	cout << endl;
*/
}




