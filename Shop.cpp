#include <iostream>
#include <string>
#include <vector>
#include <sstream> 
#include <fstream>
#include "Shop.h"

void Shop::readData(string filename) {

	string CommodityInformation;
	string item;
	ifstream fin;
	fin.open("Information.txt");

	if (fin.fail()) {
		cout << "Error in file opening!" << endl;
		return;
	}
	
	while (getline(fin, CommodityInformation)) {
		cout << CommodityInformation << endl;
		istringstream iss(CommodityInformation);

		while (getline(iss, item, ',')) {
			cout << item << endl;
		}
	}
	
	
}
