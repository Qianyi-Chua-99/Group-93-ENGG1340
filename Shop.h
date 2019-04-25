#ifndef SHOP_H
#define SHOP_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
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
		
		static string dataDirectory;
		static string historyDirectory;
		
		static vector<Commodity> listOfCommodity;
		static vector<Shop> listOfShop;
		static vector<Commodity*> filterAllList;
		static map<string, string> allHistory;
		
		static void readData(string filename);
		static void readShopData(string filename);
		static void writeData(string filename);
		static void writeShopData(string filename);
		
		static void readAllHistory();
		static void printAllHistory(string date = "");
		static void writeAllHistory();
		static void deleteAllHistory(string date);
		static void clearAllHistory();
		
		static void addCommodity(Commodity& element);
		static void deleteCommodity(string n);
		static void printAllCommodity(int mode);
		static void sortAllCommodity(int mode, int order);
		static void filterAll(int mode, string category);
		static void filterAll(int mode, double lowerBound, double upperBound);
		
		Shop(string n);
		string getShopName();
		void setCommodityQuantity(string n, int quantity);
		void setCommodityPrice(string n, double price);
		void setCommodityCategory(string n, string category);
		void printSpecificCommodity(string n);
		void alertOutOfStock();
		void filter(int mode, string category);
		void filter(int mode, double lowerBound, double upperBound);
		void sortCommodity(int mode, int order);
		void printCommodity(int mode);
		void readHistory();
		void printHistory(string date = "");
		void writeHistory();
		void deleteHistory(string date);
		void clearHistory();
		
		void debug();
		
	private:
		string shopName;
		vector<Commodity*> filterList;
		map<string, string> history;
};

#endif
