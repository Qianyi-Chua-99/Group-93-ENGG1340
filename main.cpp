#include <iostream>
#include <string>
#include "Commodity.h"
#include "Shop.h"

using namespace std;

void displayWelcome();
void displayShop();
bool validChoiceShop(int);
void displayFunc();

int main() {

	//initialize everything
	readData("Information.txt");

	//welcome message
	displayWelcome();

	//while loop, select functions
	string page = "chooseShop";
	int choiceShop = 0;
	int choice;
	while (true){

		//check ChoiceStop if valid
		if ( validChoiceShop(choiceShop) == false ){
			cout << "Invalid Choice! Please try again." << endl;
			page = "chooseShop";
		}
		if ( validChoiceShop(choiceShop) == true ){
			page = "funcList";
		}

		//layouts
		switch ( page ) {

			case chooseShop:
				displayShop();
				cin >> choiceShop;
				break;

			case funcList:
				displayFunc();
				cin >> choice;
				break;

		}

	return 0;
}

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
}

bool validChoiceShop(int n){
	//if ( n < VECTOR_SHOP.size() + 1 && n > 0 )
	//	return true;
	//else:
	//  return true;
}

void displayFunc(){
	cout << endl;
	cout << setfill('*') << setw(30) << endl;
	cout << "Please select a function" << endl;
	cout << "		1. Find Item\n		2. Search Item\n		3. Another Function" << endl;
}
