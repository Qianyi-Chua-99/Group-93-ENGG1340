#include <iostream>
#include <string>
#include <map>
#include <iomanip> 
#include "Commodity.h"

using namespace std;

int column1 = 20;
int column2 = 20;
int column3 = 15;
int column4 = 15;
int column5 = 15;
int column6 = 20;

/*
 * Commodity constructor
 * @param n Commodity name
 * @param c Commodity category
 * @param m Commodidty manufacturer
 * @param p Commodity price
 */
Commodity::Commodity(string n, string c, string m, double p) {
	name = n;
	category = c;
	price = p;
	manufacturer = m;
	totalQuantity = 0;
}

/*
 * Return the name of Commodity
 * @return Commodity name
 */
string Commodity::getName() {
	return name;
}

/*
 * Return the category of Commodity
 * @return Commodity category
 */
string Commodity::getCategory() {
	return category;
}

/*
 * Return the manufacturer of Commodity
 * @return Commodity manufacturer
 */
string Commodity::getManufacturer() {
	return manufacturer;
}

/*
 * Return the price of Commodity
 * @return Commodity price
 */
double Commodity::getPrice() {
	return price;
}

/*
 * Return the total quantity of Commodity
 * @return Commodity total quantity
 */
int Commodity::getTotalQuantity() {
	return totalQuantity;
}

/*
 * Return the quantity of Commodity of a specific shop
 * @param shop Shop name
 * @return Commodity quantity of the specific shop
 */
int Commodity::getQuantity(string shop) {
	if (quantity.find(shop) != quantity.end()) {
		return quantity[shop];
	}
	else {
		return 0;
	}
}

/*
 * Set the name of Commodity
 * @param n new Commodity name
 */
void Commodity::setName(string n) {
	name = n;
}

/*
 * Set the category of Commodity
 * @param c new Commodity category
 */
void Commodity::setCategory(string c) {
	category = c;
}

/*
 * Set the manufacturer of Commodity
 * @param m new Commodity manufacturer
 */
void Commodity::setManufacturer(string m) {
	manufacturer = m;
}

/*
 * Set the price of Commodity
 * @param p new Commodity price
 */
void Commodity::setPrice(double p) {
	price = p;
}

/*
 * Set the quantity of Commodity for a specific shop
 * @param shop Shop name
 * @param q quantity
 */
void Commodity::setShopQuantity(string shop, int q) {
	map<string, int>::iterator itr;
	itr = quantity.find(shop);
	if (quantity.find(shop) != quantity.end()) {
		totalQuantity -= quantity[shop];
	}
	quantity[shop]=q;
	totalQuantity += quantity[shop];
}

/*
 * Check if the shop is already recorded for this commodity
 * @param shop Shop name
 * @return true if the shop is in the record, false otherwise
 */
bool Commodity::isShopPresent(string shop) {
	if (quantity.find(shop) != quantity.end())
		return true;
	return false;
}

/*
 * Print the details of the Commodity
 */
void Commodity::printDetails() {
	cout << left << setw(column1) << name << setw(column2) << category << setw(column3) << price << setw(column4) << totalQuantity << setw(column5) << ((totalQuantity == 0)? "Out of stock" : "Available") << setw(column6) << manufacturer <<endl;
}

/*
 * Print the details of the Commodity for a specific shop
 */
void Commodity::printDetails(string shop) {
	cout << left << setw(column1) << name << setw(column2) << category << setw(column3) << price << setw(column4) << quantity[shop] << setw(column5) << ((quantity[shop] == 0)? "Out of stock" : "Available") << setw(column6) << manufacturer <<endl;
}





