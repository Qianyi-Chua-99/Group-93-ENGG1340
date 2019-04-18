#ifndef COMMODITY_H
#define COMMODITY_H

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Commodity{
	public:
		Commodity (string n, string c, double p);
		string getName();
		string getCategory();
		double getPrice();
		int getTotalQuantity();
		int getQuantity(string shop);
		bool stockAvailable();
		void setName(string n);
		void setCategory(string c);
		void setPrice(double p);
		void setShopQuantity(string shop, int quantity);
		void printDetails();
		
	private:
		map<string, int> quantity;
		string name;
		string category;
		double price;
		int totalQuantity;
		bool outOfStock;
		
};

#endif
