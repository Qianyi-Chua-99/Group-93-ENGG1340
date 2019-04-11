#include <iostream>
#include <string>
#include "Commodity.h"

using namespace std;

int main() {
	Commodity newCommodity("testing", "testingCategory", 10, 20);
	cout << newCommodity.getName() << " " << newCommodity.getCategory() << " " << newCommodity.getPrice() << " " << newCommodity.stockAvailable() << endl;
	newCommodity.setName("ok");
	newCommodity.setPrice(90);
	newCommodity.setCategory("OK");
	cout << newCommodity.getName() << " " << newCommodity.getCategory() << " " << newCommodity.getPrice() << " " << newCommodity.stockAvailable() << endl;
	return 0;
}
