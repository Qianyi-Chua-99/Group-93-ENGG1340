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
		
		static void readData(string filename);
		static void addCommodity(const Commodity& element);
		
		Shop(string n);
		void filter(int mode, string category);
		void filter(int mode, double lowerBound, double upperBound);
		void printCommodity(int mode);

	private:
		string shopName;
		
		vector<Commodity*> shopCommodityList;
		vector<Commodity*> sortedList;
		vector<Commodity*> filterList;
};

#endif
