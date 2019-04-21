#include <iostream>
#include <string>
#include <vector>
#include "Shop.h"
#include "Commodity.h"

using namespace std;

int main() {
	Shop::readData("Information.txt");
	Commodity newCommodity ("Orange", "Fruit", 9);
	Shop::addCommodity(newCommodity);
	vector<Commodity>::iterator ptr;
	/*
	for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
		(*ptr).printDetails();
	}
	*/
	Shop newShop("Wellcome");
	
	newShop.sortCommodity(Shop::NAME, Shop::ASCENDING);
	cout << "#####################################################" << endl;
	newShop.sortCommodity(Shop::NAME, Shop::DESCENDING);
	cout << "#####################################################" << endl;
	newShop.sortCommodity(Shop::CATEGORY, Shop::ASCENDING);
	cout << "#####################################################" << endl;
	newShop.sortCommodity(Shop::CATEGORY, Shop::DESCENDING);
	cout << "#####################################################" << endl;
	newShop.sortCommodity(Shop::QUANTITY, Shop::ASCENDING);
	cout << "#####################################################" << endl;
	newShop.sortCommodity(Shop::QUANTITY, Shop::DESCENDING);
	cout << "#####################################################" << endl;
	newShop.sortCommodity(Shop::PRICE, Shop::ASCENDING);
	cout << "#####################################################" << endl;
	newShop.sortCommodity(Shop::PRICE, Shop::DESCENDING);
	cout << "#####################################################" << endl;
	return 0;
}
