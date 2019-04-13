#include <iostream>
#include <string>
#include "Commodity.h"

using namespace std;

int main() {
	Commodity newCommodity("testing", "testingCategory", 10);
	newCommodity.printDetails();
	
	newCommodity.setShopQuantity("Tesco", 10);
	newCommodity.setShopQuantity("Giant", 20);
	newCommodity.printDetails();
	
	newCommodity.setShopQuantity("Giant", 30);
	newCommodity.printDetails();
	
	cout << newCommodity.getQuantity("Giant") << endl;
	return 0;
}
