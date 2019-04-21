#include <iostream>
#include <string>
#include <map>
#include "Commodity.h"

using namespace std;

Commodity::Commodity(string n, string c, double p) {
	name = n;
	category = c;
	price = p;
	totalQuantity = 0;
	outOfStock = true;
}

string Commodity::getName() {
	return name;
}

string Commodity::getCategory() {
	return category;
}

double Commodity::getPrice() {
	return price;
}

int Commodity::getTotalQuantity() {
	return totalQuantity;
}

int Commodity::getQuantity(string shop) {
	if (quantity.find(shop) != quantity.end())
		return quantity[shop];
	else
		return 0;
}

bool Commodity::stockAvailable() {
	return (! outOfStock);
}

void Commodity::setName(string n) {
	name = n;
}

void Commodity::setCategory(string c) {
	category = c;
}

void Commodity::setPrice(double p) {
	price = p;
}

void Commodity::setShopQuantity(string shop, int q) {
	map<string, int>::iterator itr;
	itr = quantity.find(shop);
	if (quantity.find(shop) != quantity.end()) {
		totalQuantity -= quantity[shop];
	}
	quantity[shop]=q;
	totalQuantity += quantity[shop];
}

bool Commodity::isShopPresent(string shop) {
	if (quantity.find(shop) != quantity.end())
		return true;
	return false;
}

void Commodity::printDetails() {
	cout << "Name: " << name << endl;
	cout << "Category: " << category << endl;
	cout << "Price: " << price << endl;
	cout << "Quantities: " << endl;
	map <string, int>::iterator itr;
	for (itr = quantity.begin(); itr != quantity.end(); itr++) {
		cout << itr->first << ' ' << itr->second << endl;
	}
	cout << "Total quantities: " << totalQuantity << endl;
	cout << endl;
}

void Commodity::printDetails(string shop) {
	cout << "Name: " << name << endl;
	cout << "Category: " << category << endl;
	cout << "Price: " << price << endl;
	cout << "Quantities: " << quantity[shop] << endl;
	cout << endl;
}






