#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
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
	
	//Shop::listOfShop[0].alertOutOfStock();
	
	time_t now = time(0);

   	tm *ltm = localtime(&now);
   	
   	string date = to_string(1900 + ltm->tm_year) + '/' + to_string(1 + ltm->tm_mon) + '/' + to_string(ltm->tm_mday);
   	string time = to_string(ltm->tm_hour) + ':' + to_string(ltm->tm_min) + ':' + to_string(ltm->tm_sec);
   	
   	cout << date << endl;
   	cout << time << endl;
   	/*
   	Shop::listOfShop[0].readHistory();
   	Shop::listOfShop[0].printHistory();
   	Shop::listOfShop[0].writeHistory();
   	*/
   	Shop::readAllHistory();
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
