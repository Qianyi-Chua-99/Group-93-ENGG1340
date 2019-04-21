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
	newShop.printCommodity();
	return 0;
}
