#include <iostream>
#include <string>
#include "Commodity.h"

using namespace std;

Commodity::Commodity(string n, string c, double p, int q) {
	name = n;
	category = c;
	price = p;
	totalQuantity = q;
	if (totalQuantity == 0)
		outOfStock = true;
	else
		outOfStock = false;
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
void Commodity::setPrice (double p) {
	price = p;
}






