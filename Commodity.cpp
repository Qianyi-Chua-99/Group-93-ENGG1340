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
	if (quantity.find(shop) != quantity.end())
		totalQuantity -= quantity[shop];
	quantity[shop]=q;
	totalQuantity += quantity[shop];
}

void Commodity::printDetails() {
	cout << "Name:\t" << name << endl;
	cout << "Category:\t" << category << endl;
	cout << "Price:\t" << price << endl;
	cout << "Quantities:" << endl;
	map <string, int>::iterator itr;
	for (itr = quantity.begin(); itr != quantity.end(); itr++) {
		cout << itr->first << '\t' << itr->second << endl;
	}
	cout << "Total quantities:\t" << totalQuantity << endl;
	cout << endl;
}





