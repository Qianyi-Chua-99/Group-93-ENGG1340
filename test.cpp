#include <iostream>
#include <string>
#include <vector>
#include "Shop.h"
#include "Commodity.h"

using namespace std;

int main() {
	Shop::readData("Information1.txt");
	Shop::readShopData("Shop.txt");
	//Shop newShop("Wellcome");
	Commodity newCommodity ("Orange", "Fruit", 9);
	Shop::writeShopData("Shop.txt");
	Shop::writeData("Information1.txt");
	/*
	Shop::printAllCommodity(1);
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
	Shop::sortAllCommodity(Shop::NAME, Shop::ASCENDING);
	cout << "#####################################################" << endl;
	Shop::sortAllCommodity(Shop::NAME, Shop::DESCENDING);
	cout << "#####################################################" << endl;
	Shop::sortAllCommodity(Shop::CATEGORY, Shop::ASCENDING);
	cout << "#####################################################" << endl;
	Shop::sortAllCommodity(Shop::CATEGORY, Shop::DESCENDING);
	cout << "#####################################################" << endl;
	Shop::sortAllCommodity(Shop::QUANTITY, Shop::ASCENDING);
	cout << "#####################################################" << endl;
	cout << "QUANTITY Descending" << endl;
	Shop::sortAllCommodity(Shop::QUANTITY, Shop::DESCENDING);
	cout << "#####################################################" << endl;
	Shop::sortAllCommodity(Shop::PRICE, Shop::ASCENDING);
	cout << "#####################################################" << endl;
	Shop::sortAllCommodity(Shop::PRICE, Shop::DESCENDING);
	cout << "#####################################################" << endl;
	Shop::filterAll(Shop::CATEGORY, "Electronic");
	cout << "#####################################################" << endl;
	Shop::filterAll(Shop::CATEGORY, "Vegetable");
	cout << "#####################################################" << endl;
	Shop::filterAll(Shop::PRICE, 0, 20);
	cout << "#####################################################" << endl;
	Shop::filterAll(Shop::QUANTITY, 0, 20);
	cout << "#####################################################" << endl;
	*/
	//Shop newShop("Wellcome");
	//vector<Commodity>::iterator ptr;
	/*
	for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
		(*ptr).printDetails();
	}
	*/
	//Shop newShop("Manning");
	/*
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
	
	*/
	/*
	newShop.filter(Shop::CATEGORY, "Electronic");
	cout << "#####################################################" << endl;
	newShop.filter(Shop::CATEGORY, "Vegetable");
	cout << "#####################################################" << endl;
	newShop.filter(Shop::PRICE, 0, 20);
	cout << "#####################################################" << endl;
	newShop.filter(Shop::QUANTITY, 0, 20);
	cout << "#####################################################" << endl;
	*/
	//cout << Shop::listOfShop[0].getShopName() << endl;
	//Shop::listOfCommodity[0].printDetails();
	//Shop::listOfShop[0].debug();
	
	//newShop.printCommodity(1);
	
	//Shop newShop1("ParknShop");
	//newShop1.printCommodity(1);
	/*
	vector<Shop>::iterator ptr;
	for (ptr = Shop::listOfShop.begin(); ptr < Shop::listOfShop.end(); ptr ++) {
		cout << (*ptr).getShopName() << endl;
		(*ptr).printSpecificCommodity("Surface");
		cout << "###########################################################" << endl;
	}
	*/
	
}
