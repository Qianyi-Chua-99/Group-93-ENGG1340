#include <iostream>
#include <string>
#include <vector>
#include <sstream> 
#include <fstream>
#include "Shop.h"
#include "Commodity.h"

vector<Commodity> Shop::listOfCommodity;
void Shop::readData(string filename) {
	string CommodityInformation;
	string commodityName;
	string category;
	string tmp;
	ifstream fin;
	fin.open("Information.txt");

	if (fin.fail()) {
		cout << "Error in file opening!" << endl;
		return;
	}
	
	while (getline(fin, CommodityInformation)) {
		//cout << CommodityInformation << endl;
		istringstream iss(CommodityInformation);
		getline(iss, commodityName, ',');
		getline(iss, category, ',');
		getline(iss, tmp, ',');
		double price = stoi(tmp);
		Commodity newCommodity (commodityName, category, price);
		string shopName;
		int quantity;
		bool paired = false;
		while (getline(iss, tmp, ',')) {
			if (!paired) {
				shopName = tmp;
				paired = true;
			}
			else {
				quantity = stoi(tmp);
				newCommodity.setShopQuantity(shopName, quantity);
				paired = false;
			}
		}
		Shop::listOfCommodity.push_back(newCommodity);
	}
	
}
