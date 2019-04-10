#include <iostream>
#include <string>
#include "Commodity.h"

using namespace std;

int main() {
	Commodity newCommodity("testing", "testingCategory", 10, 20);
	cout << newCommodity.getName() << endl;
	return 0;
}
