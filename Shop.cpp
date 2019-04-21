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

vector<Commodity> Shop::listOfCommodity {};
vector<Shop> Shop::listOfShop {};
vector<Commodity*> Shop::filterAllList {};

string SHOPNAME;

Shop::Shop(string n) {
	shopName = n;
	SHOPNAME = n;
	vector<Commodity>::iterator ptr;
	for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
		if(!(*ptr).isShopPresent(shopName)) {
			(*ptr).setShopQuantity(shopName, 0);
		}
	}
	Shop::listOfShop.push_back(*this);
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

void Shop::readShopData(string filename) {
	string ShopInformation;
	string tmp;
	ifstream fin;
	fin.open(filename);

	if (fin.fail()) {
		cout << "Error in file opening!" << endl;
		return;
	}
	while (getline(fin, ShopInformation)) {
		istringstream iss(ShopInformation);
		while (getline(iss, tmp, ',')) {
			Shop newShop(tmp);
		}
	}
}

void Shop::addCommodity(Commodity& element) {
	vector<Shop>::iterator ptr;
	for (ptr = Shop::listOfShop.begin(); ptr < Shop::listOfShop.end(); ptr ++) {
		if(!element.isShopPresent((*ptr).getShopName())) {
			element.setShopQuantity((*ptr).getShopName(), 0);
		}
	};
	Shop::listOfCommodity.push_back(element);
}

void Shop::deleteCommodity(string n) {
	vector<Commodity>::iterator ptr;
	for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
		if((*ptr).getName() == n) {
			Shop::listOfCommodity.erase(ptr);
			break;
		}
	};
}


string Shop::getShopName() {
	return shopName;
}

void Shop::setCommodityQuantity (string n, int quantity) {
	vector<Commodity>::iterator ptr;
	for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
		if(((*ptr).getName()) == n) {
			(*ptr).setShopQuantity(shopName, quantity);
			break;
		}
	}
}

void Shop::setCommodityPrice (string n, double price) {
	vector<Commodity>::iterator ptr;
	for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
		if(((*ptr).getName()) == n) {
			(*ptr).setPrice(price);
			break;
		}
	}
}

void Shop::setCommodityCategory (string n, string category) {
	vector<Commodity>::iterator ptr;
	for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
		if(((*ptr).getName()) == n) {
			(*ptr).setCategory(category);
			break;
		}
	}
}

void Shop::alertOutOfStock () {
	vector<Commodity>::iterator ptr;
	string message = "";
	for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
		if(((*ptr).getQuantity(shopName)) == 0) {
			message += (*ptr).getName();
			message += '\n';
		}
	}
	if (message == "") {
		cout << "There is no commodities that are currently out of stock" << endl;
	}
	else {
		cout << "List of commodities that are currently out of stock" << endl;
		cout << message << endl;
	}
}

void Shop::filterAll(int mode, string category) {
	vector<Commodity>::iterator ptr;
	filterAllList.clear();
	switch (mode) {
		case 1:
			for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
				if ((*ptr).getCategory() == category){
					filterAllList.push_back(&(*ptr));
				}
			}
			printAllCommodity(0);
			break;
	}
}

void Shop::filterAll(int mode, double lowerBound, double upperBound) {
	vector<Commodity>::iterator ptr;
	filterAllList.clear();
	switch (mode) {
		case 2:
		{
			int lb = (int)lowerBound;
			int ub = (int)upperBound;
			for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
				if (((*ptr).getTotalQuantity() >= lb) && ((*ptr).getTotalQuantity() <= ub)){
					filterAllList.push_back(&(*ptr));
				}
			}
			printAllCommodity(0);
			break;
		}
		case 3:
		{
			for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
				if (((*ptr).getPrice() >= lowerBound) && ((*ptr).getPrice() <= upperBound)){
					filterAllList.push_back(&(*ptr));
				}
			}
			printAllCommodity(0);
		}
	}
}

void Shop::filter(int mode, string category) {
	vector<Commodity>::iterator ptr;
	filterList.clear();
	switch (mode) {
		case 1:
			for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
				if ((*ptr).getCategory() == category){
					filterList.push_back(&(*ptr));
				}
			}
			printCommodity(0);
			break;
	}
}

void Shop::filter(int mode, double lowerBound, double upperBound) {
	vector<Commodity>::iterator ptr;
	filterList.clear();
	switch (mode) {
		case 2:
		{
			int lb = (int)lowerBound;
			int ub = (int)upperBound;
			for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
				if (((*ptr).getQuantity(shopName) >= lb) && ((*ptr).getQuantity(shopName) <= ub)){
					filterList.push_back(&(*ptr));
				}
			}
			printCommodity(0);
			break;
		}
		case 3:
		{
			for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
				if (((*ptr).getPrice() >= lowerBound) && ((*ptr).getPrice() <= upperBound)){
					filterList.push_back(&(*ptr));
				}
			}
			printCommodity(0);
		}
	}
}

bool nameAscending(Commodity A, Commodity B) {
	return (((A).getName()) < ((B).getName()));
}

bool nameDescending(Commodity A, Commodity B) {
	return (((A).getName()) > ((B).getName()));
}

bool categoryAscending(Commodity A, Commodity B) {
	return (((A).getCategory()) < ((B).getCategory()));
}

bool categoryDescending(Commodity A, Commodity B) {
	return ((A.getCategory()) > (B.getCategory()));
}

bool quantityAscending(Commodity A, Commodity B) {
	return (((A).getQuantity(SHOPNAME)) < ((B).getQuantity(SHOPNAME)));
}

bool quantityDescending(Commodity A, Commodity B) {
	return (((A).getTotalQuantity()) > ((B).getTotalQuantity()));
}

bool quantityAllAscending(Commodity A, Commodity B) {
	return (((A).getTotalQuantity()) < ((B).getTotalQuantity()));
}

bool quantityAllDescending(Commodity A, Commodity B) {
	return (((A).getTotalQuantity()) > ((B).getTotalQuantity()));
}

bool priceAscending(Commodity A, Commodity B) {
	return (((A).getPrice()) < ((B).getPrice()));
}

bool priceDescending(Commodity A, Commodity B) {
	return (((A).getPrice()) > ((B).getPrice()));
}

void Shop::sortCommodity(int mode, int order) {
	switch (mode) {
		case 0:
		{
			if (order == Shop::ASCENDING)
				sort(Shop::listOfCommodity.begin(), Shop::listOfCommodity.end(), nameAscending);
			else
				sort(Shop::listOfCommodity.begin(), Shop::listOfCommodity.end(), nameDescending);
			break;
		}
		case 1:
		{
			if (order == Shop::ASCENDING)
				sort(Shop::listOfCommodity.begin(), Shop::listOfCommodity.end(), categoryAscending);
			else
				sort(Shop::listOfCommodity.begin(), Shop::listOfCommodity.end(), categoryDescending);
			break;
		}
		case 2:
		{
			if (order == Shop::ASCENDING)
				sort(Shop::listOfCommodity.begin(), Shop::listOfCommodity.end(), quantityAscending);
			else
				sort(Shop::listOfCommodity.begin(), Shop::listOfCommodity.end(), quantityDescending);
			break;
		}
		case 3:
		{
			if (order == Shop::ASCENDING)
				sort(Shop::listOfCommodity.begin(), Shop::listOfCommodity.end(), priceAscending);
			else
				sort(Shop::listOfCommodity.begin(), Shop::listOfCommodity.end(), priceDescending);
			break;
		}
	}
	printCommodity(1);
}

void Shop::sortAllCommodity(int mode, int order) {
	switch (mode) {
		case 0:
		{
			if (order == Shop::ASCENDING)
				sort(Shop::listOfCommodity.begin(), Shop::listOfCommodity.end(), nameAscending);
			else
				sort(Shop::listOfCommodity.begin(), Shop::listOfCommodity.end(), nameDescending);
			break;
		}
		case 1:
		{
			if (order == Shop::ASCENDING)
				sort(Shop::listOfCommodity.begin(), Shop::listOfCommodity.end(), categoryAscending);
			else
				sort(Shop::listOfCommodity.begin(), Shop::listOfCommodity.end(), categoryDescending);
			break;
		}
		case 2:
		{
			if (order == Shop::ASCENDING)
				sort(Shop::listOfCommodity.begin(), Shop::listOfCommodity.end(), quantityAllAscending);
			else
				sort(Shop::listOfCommodity.begin(), Shop::listOfCommodity.end(), quantityAllDescending);
			break;
		}
		case 3:
		{
			if (order == Shop::ASCENDING)
				sort(Shop::listOfCommodity.begin(), Shop::listOfCommodity.end(), priceAscending);
			else
				sort(Shop::listOfCommodity.begin(), Shop::listOfCommodity.end(), priceDescending);
			break;
		}
	}
	printAllCommodity(1);
}

void Shop::printCommodity(int mode) {
	switch (mode) {
		case 0:
		{
			vector<Commodity*>::iterator ptr1;
			for (ptr1 = filterList.begin(); ptr1 < filterList.end(); ptr1 ++) {
				(*(*ptr1)).printDetails(shopName);
			}
			break;
		}
		default:
		{
			vector<Commodity>::iterator ptr;
			for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
				(*ptr).printDetails(shopName);
			}
		}
	}
}

void Shop::printAllCommodity(int mode) {
	switch (mode) {
		case 0:
		{
			vector<Commodity*>::iterator ptr1;
			for (ptr1 = Shop::filterAllList.begin(); ptr1 < Shop::filterAllList.end(); ptr1 ++) {
				(*(*ptr1)).printDetails();
			}
			break;
		}
		default:
		{
			vector<Commodity>::iterator ptr;
			for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
				(*ptr).printDetails();
			}
		}
	}
}


void Shop::printSpecificCommodity(string n) {
	vector<Commodity>::iterator ptr;
	for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
		if ((*ptr).getName() == n) {
			(*ptr).printDetails(shopName);
			break;
		}
	}	
}

void Shop::debug() {
	cout << (Shop::listOfCommodity).size() << endl;
}
