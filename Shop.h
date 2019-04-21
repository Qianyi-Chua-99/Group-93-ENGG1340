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
	private:
};

#endif
