#ifndef SHOP_H
#define SHOP_H

#include <iostream>
#include <string>
#include <vector>
#include "Commodity.h"

using namespace std;

class Shop{
	public:
		static vector<Commodity> listOfCommodity;
		static void readData(string filename);
		static void addCommodity(const Commodity& element);
		Shop(string n);
		void printCommodity();
	private:
		string shopName;
		vector<Commodity*> shopCommodityList;
		vector<Commodity*> sortedList;
		vector<Commodity*> filterList;
};

#endif
