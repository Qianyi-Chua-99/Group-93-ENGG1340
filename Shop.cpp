#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "Shop.h"
#include "Commodity.h"

using namespace std;

int Shop::NAME = 0;
int Shop::CATEGORY = 1;
int Shop::QUANTITY = 2;
int Shop::PRICE = 3;
		
int Shop::ASCENDING = 0;
int Shop::DESCENDING = 1;

vector<Commodity> Shop::listOfCommodity;

string SHOPNAME;

Shop::Shop(string n) {
	shopName = n;
	SHOPNAME = n;
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

void Shop::filter(int mode, string category) {
	vector<Commodity*>::iterator ptr;
	filterList.clear();
	switch (mode) {
		case 1:
			for (ptr = Shop::shopCommodityList.begin(); ptr < Shop::shopCommodityList.end(); ptr ++) {
				if ((*(*ptr)).getCategory() == category){
					filterList.push_back((*ptr));
				}
			}
			printCommodity(1);
			break;
	}
}

void Shop::filter(int mode, double lowerBound, double upperBound) {
	vector<Commodity*>::iterator ptr;
	filterList.clear();
	switch (mode) {
		case 2:
		{
			int lb = (int)lowerBound;
			int ub = (int)upperBound;
			for (ptr = Shop::shopCommodityList.begin(); ptr < Shop::shopCommodityList.end(); ptr ++) {
				if (((*(*ptr)).getQuantity(shopName) >= lb) && ((*(*ptr)).getQuantity(shopName) <= ub)){
					filterList.push_back((*ptr));
				}
			}
			printCommodity(0);
			break;
		}
		case 3:
		{
			for (ptr = Shop::shopCommodityList.begin(); ptr < Shop::shopCommodityList.end(); ptr ++) {
				if (((*(*ptr)).getPrice() >= lowerBound) && ((*(*ptr)).getPrice() <= upperBound)){
					filterList.push_back((*ptr));
				}
			}
			printCommodity(0);
		}
	}
}

bool nameAscending(Commodity* A, Commodity* B) {
	return (((*A).getName()) < ((*B).getName()));
}

bool nameDescending(Commodity* A, Commodity* B) {
	return (((*A).getName()) > ((*B).getName()));
}

bool categoryAscending(Commodity* A, Commodity* B) {
	return (((*A).getCategory()) < ((*B).getCategory()));
}

bool categoryDescending(Commodity* A, Commodity* B) {
	return (((*A).getCategory()) > ((*B).getCategory()));
}

bool quantityAscending(Commodity* A, Commodity* B) {
	return (((*A).getQuantity(SHOPNAME)) < ((*B).getQuantity(SHOPNAME)));
}

bool quantityDescending(Commodity* A, Commodity* B) {
	return (((*A).getQuantity(SHOPNAME)) > ((*B).getQuantity(SHOPNAME)));
}

bool priceAscending(Commodity* A, Commodity* B) {
	return (((*A).getPrice()) < ((*B).getPrice()));
}

bool priceDescending(Commodity* A, Commodity* B) {
	return (((*A).getPrice()) > ((*B).getPrice()));
}

void Shop::sortCommodity(int mode, int order) {
	switch (mode) {
		case 0:
		{
			if (order == Shop::ASCENDING)
				sort(shopCommodityList.begin(), shopCommodityList.end(), nameAscending);
			else
				sort(shopCommodityList.begin(), shopCommodityList.end(), nameDescending);
			break;
		}
		case 1:
		{
			if (order == Shop::ASCENDING)
				sort(shopCommodityList.begin(), shopCommodityList.end(), categoryAscending);
			else
				sort(shopCommodityList.begin(), shopCommodityList.end(), categoryDescending);
			break;
		}
		case 2:
		{
			if (order == Shop::ASCENDING)
				sort(shopCommodityList.begin(), shopCommodityList.end(), quantityAscending);
			else
				sort(shopCommodityList.begin(), shopCommodityList.end(), quantityDescending);
			break;
		}
		case 3:
		{
			if (order == Shop::ASCENDING)
				sort(shopCommodityList.begin(), shopCommodityList.end(), priceAscending);
			else
				sort(shopCommodityList.begin(), shopCommodityList.end(), priceDescending);
			break;
		}
	}
	printCommodity(1);
}

void Shop::printCommodity(int mode) {
	vector<Commodity*>::iterator ptr;
	switch (mode) {
		case 0:
			for (ptr = Shop::filterList.begin(); ptr < Shop::filterList.end(); ptr ++) {
				(*(*ptr)).printDetails(shopName);
			}
			break;
		default:
			for (ptr = Shop::shopCommodityList.begin(); ptr < Shop::shopCommodityList.end(); ptr ++) {
				(*(*ptr)).printDetails(shopName);
			}
	}
}
