#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
#include <algorithm>
#include <iomanip> 
#include <cmath>
#include "Shop.h"
#include "Commodity.h"

using namespace std;

int main() {

	Shop::readData("Information1.txt");
	Shop::readShopData("Shop.txt");
	
	//vector<Shop>::iterator ptr;
	//for (ptr = Shop::listOfShop.begin(); ptr < Shop::listOfShop.end(); ptr++) {
	//	cout << (*ptr).getShopName() << endl;
	//}
	//Shop::readAllHistory();
	//Shop::listOfShop[0].alertOutOfStock();
	//Shop::listOfShop[0].sortCommodity(Shop::NAME, Shop::ASCENDING);
   	//Shop::listOfShop[0].readHistory();
   	//Shop::listOfShop[0].printHistory();
   	//Shop::listOfShop[0].writeHistory();
   	//Shop::printAllCommodity(1);
   	//Shop::listOfShop[0].printCommodity(1);
   	//Shop::writeShopData("Shop.txt");
   	//Shop::deleteAllHistory("2019/4/22");
   	//Shop::printAllHistory();
   	Shop::writeAllHistory();   	
   	/*
   	ofstream fout;
	fout.open("ParknShopHistory.txt");
	
	if (fout.fail()) {
		cout << "Error in file opening!" << endl;
		return 0;
	}
	fout << "2019/4/21;" ;
	fout << "a\nb;" ;
	fout.close();
	
	ifstream fin;
	fin.open("test.txt");
	
	if (fin.fail()) {
		cout << "Error in file opening!" << endl;
		return 0;
	}
	string tmp;
	getline(fin, tmp, ',');
	cout << tmp;
	fin.close();
	*/
   	
	//Shop::writeShopData("Shop.txt");
	//Shop::writeData("Information1.txt");

	return 0;
	
}
