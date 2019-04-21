#include <iostream>
#include <string>
#include <vector>
#include "Shop.h"
#include "Commodity.h"

using namespace std;

int main() {
	Shop::readData("Information.txt");
	vector<Commodity>::iterator ptr;
	for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
		(*ptr).printDetails();
	}
	return 0;
}
