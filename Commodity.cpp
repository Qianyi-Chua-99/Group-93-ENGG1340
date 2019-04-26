#include <iostream>
#include <string>
#include <map>
#include <iomanip> 
#include "Commodity.h"

using namespace std;

int column1 = 20;
int column2 = 20;
int column3 = 15;
int column4 = 10;

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
	if (quantity.find(shop) != quantity.end()) {
		return quantity[shop];
	}
	else {
		return 0;
	}
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
	cout << left << setw(column1) << name << setw(column2) << category << setw(column3) << price << setw(column4) << totalQuantity << endl;
}

void Commodity::printDetails(string shop) {
	cout << left << setw(column1) << name << setw(column2) << category << setw(column3) << price << setw(column4) << quantity[shop] << endl;
}





