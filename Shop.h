#include <iostream>
#include <string>
#include <vector>
#include "Commodity.h"

using namespace std;

class Shop{
	public:
		static void readData(string filename);
	private:
		static vector<Commodity> listOfCommodity;
		
};
