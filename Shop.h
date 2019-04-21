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
		static void int NAME = 0;
		static void int CATEGORY = 1;
		static void int QUANTITY = 2;
		static void int PRICE = 3;
		static void int ASCENDING = 4;
		static void int DESCENDING = 5;
		
	private:
};

#endif
