#ifndef COMMODITY_H
#define COMMODITY_H

#include <iostream>
#include <string>
#include <map>

using namespace std;
/*
 * Commodity Class
 */
class Commodity{
	public:
		Commodity (string n, string c, string m, double p);
		string getName();
		string getCategory();
		string getManufacturer();
		double getPrice();
		int getTotalQuantity();
		int getQuantity(string shop);
		void setName(string n);
		void setCategory(string c);
		void setManufacturer(string m);
		void setPrice(double p);
		void setShopQuantity(string shop, int quantity);
		bool isShopPresent(string shop);
		void printDetails();
		void printDetails(string shop);
		
	private:
		map<string, int> quantity;
		string name;
		string category;
		string manufacturer;
		double price;
		int totalQuantity;
		
};

#endif
