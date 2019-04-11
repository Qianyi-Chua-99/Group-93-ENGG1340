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

string Commodity::getName(string n) {
	return name;
}
double Commodity::getCategory(string c) {
	return category;
}
double Commodity::getPrice(double p) {
	return price;
}
int Commodity::getTotalQuantity(int q) {
	return totalQuantity;
}
bool Commodity::stockAvailable() {
	return (! outOfStock);
}
void setName() {

}


