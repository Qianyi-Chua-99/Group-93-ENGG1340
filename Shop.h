#ifndef SHOP_H
#define SHOP_H

#include <iostream>
#include <string>
#include <vector>
#include "Commodity.h"

using namespace std;

class Shop{
	public:
		static int NAME;
		static int CATEGORY;
		static int QUANTITY;
		static int PRICE;
		
		static int ASCENDING;
		static int DESCENDING;
		
		static vector<Commodity> listOfCommodity;
		static vector<Shop> listOfShop;
		
		static void readData(string filename);
		static void readShopData(string filename);
		static void addCommodity(Commodity& element);
		
		Shop(string n);
		string getShopName ();
		void setCommodityQuantity (string n, int quantity);
		void setCommodityPrice (string n, double price);
		void setCommodityCategory (string n, string category);
		void alertOutOfStock ();
		void filter(int mode, string category);
		void filter(int mode, double lowerBound, double upperBound);
		void sortCommodity(int mode, int order);
		void printCommodity(int mode);
		
		void debug();
		
	private:
		string shopName;
		vector<Commodity*> filterList;
};

#endif
