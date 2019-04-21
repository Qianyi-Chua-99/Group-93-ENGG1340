#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "Shop.h"
#include "Commodity.h"

vector<Commodity> Shop::listOfCommodity;

Shop::Shop(string n) {
	shopName = n;
	vector<Commodity>::iterator ptr;
	for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
		if((*ptr).isShopPresent(shopName)) {
			shopCommodityList.push_back(&(*ptr));
		}
	}
}

void Shop::readData(string filename) {
	string CommodityInformation;
	string commodityName;
	string category;
	string tmp;
	ifstream fin;
	fin.open(filename);

	if (fin.fail()) {
		cout << "Error in file opening!" << endl;
		return;
	}
	while (getline(fin, CommodityInformation)) {
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

void Shop::addCommodity(const Commodity& element) {
	Shop::listOfCommodity.push_back(element);
}

void Shop::printCommodity() {
	vector<Commodity*>::iterator ptr;
	for (ptr = Shop::shopCommodityList.begin(); ptr < Shop::shopCommodityList.end(); ptr ++) {
		(*(*ptr)).printDetails(shopName);
	}
}
