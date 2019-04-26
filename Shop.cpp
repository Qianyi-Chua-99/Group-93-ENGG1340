#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <iomanip> 
#include <cmath>
#include "Shop.h"
#include "Commodity.h"

using namespace std;

string SHOPNAME;

/*
 * Ascending comparator for Shop according to Shop name
 * @param A first Shop object
 * @param B second Shop object
 * @return true if Shop A name is smaller than Shop B name, false otherwise
 */
bool shopAscending(Shop& A, Shop& B) {
	return (((A).getShopName()) < ((B).getShopName()));
}

/*
 * Ascending comparator for Commodity according to Commodity name
 * @param A first Commodity object
 * @param B second Commodity object
 * @return true if Commodity A name is smaller than Commodity B name, false otherwise
 */
bool nameAscending(Commodity& A, Commodity& B) {
	return (((A).getName()) < ((B).getName()));
}

/*
 * Descending comparator for Commodity according to Commodity name
 * @param A first Commodity object
 * @param B second Commodity object
 * @return true if Commodity A name is larger than Commodity B name, false otherwise
 */
bool nameDescending(Commodity& A, Commodity& B) {
	return (((A).getName()) > ((B).getName()));
}

/*
 * Ascending comparator for Commodity according to Commodity category
 * @param A first Commodity object
 * @param B second Commodity object
 * @return true if Commodity A category is smaller than Commodity B category, false otherwise
 */
bool categoryAscending(Commodity& A, Commodity& B) {
	return (((A).getCategory()) < ((B).getCategory()));
}

/*
 * Descending comparator for Commodity according to Commodity category
 * @param A first Commodity object
 * @param B second Commodity object
 * @return true if Commodity A category is larger than Commodity B category, false otherwise
 */
bool categoryDescending(Commodity& A, Commodity& B) {
	return ((A.getCategory()) > (B.getCategory()));
}

/*
 * Ascending comparator for Commodity according to Commodity quantity of specific Shop
 * @param A first Commodity object
 * @param B second Commodity object
 * @return true if Commodity A quantity is smaller than Commodity B quantity, false otherwise
 */
bool quantityAscending(Commodity& A, Commodity& B) {
	return (((A).getQuantity(SHOPNAME)) < ((B).getQuantity(SHOPNAME)));
}

/*
 * Descending comparator for Commodity according to Commodity quantity of specific Shop
 * @param A first Commodity object
 * @param B second Commodity object
 * @return true if Commodity A quantity is larger than Commodity B quantity, false otherwise
 */
bool quantityDescending(Commodity& A, Commodity& B) {
	return (((A).getQuantity(SHOPNAME)) > ((B).getQuantity(SHOPNAME)));
}

/*
 * Ascending comparator for Commodity according to Commodity quantity
 * @param A first Commodity object
 * @param B second Commodity object
 * @return true if Commodity A quantity is smaller than Commodity B quantity, false otherwise
 */
bool quantityAllAscending(Commodity& A, Commodity& B) {
	return (((A).getTotalQuantity()) < ((B).getTotalQuantity()));
}

/*
 * Descending comparator for Commodity according to Commodity quantity
 * @param A first Commodity object
 * @param B second Commodity object
 * @return true if Commodity A quantity is larger than Commodity B quantity, false otherwise
 */
bool quantityAllDescending(Commodity& A, Commodity& B) {
	return (((A).getTotalQuantity()) > ((B).getTotalQuantity()));
}

/*
 * Ascending comparator for Commodity according to Commodity price
 * @param A first Commodity object
 * @param B second Commodity object
 * @return true if Commodity A price is smaller than Commodity B price, false otherwise
 */
bool priceAscending(Commodity& A, Commodity& B) {
	return (((A).getPrice()) < ((B).getPrice()));
}

/*
 * Descending comparator for Commodity according to Commodity price
 * @param A first Commodity object
 * @param B second Commodity object
 * @return true if Commodity A price is larger than Commodity B price, false otherwise
 */
bool priceDescending(Commodity& A, Commodity& B) {
	return (((A).getPrice()) > ((B).getPrice()));
}

/*
 * Ascending comparator for Commodity according to Commodity manufacturer
 * @param A first Commodity object
 * @param B second Commodity object
 * @return true if Commodity A manufacturer is smaller than Commodity B manufacturer, false otherwise
 */
bool manufacturerAscending(Commodity& A, Commodity& B) {
	return (((A).getManufacturer()) < ((B).getManufacturer()));
}

/*
 * Descending comparator for Commodity according to Commodity manufacturer
 * @param A first Commodity object
 * @param B second Commodity object
 * @return true if Commodity A manufacturer is larger than Commodity B manufacturer, false otherwise
 */
bool manufacturerDescending(Commodity& A, Commodity& B) {
	return (((A).getManufacturer()) > ((B).getManufacturer()));
}

/*
 * Check if the file exists
 * @param fileName file name
 * @return true if file exists, false otherwise
 */
bool fileExist (const string& fileName) {
	ifstream fin;
	fin.open(fileName);
	if (fin.fail()) {
		fin.close();
		return false;
	}
	fin.close();
	return true;
}

/*
 * Add padding to the string
 * @param s string to be padded
 * @param n number of characters
 * @param c character used for padding
 * @return padded string
 */
string padding (const string& s, int n, char c) {
	string temp = s;
	int len = s.length();
	if (len < n) {
		for (int i = 0; i < (n-len); i++)
			temp += c;
	}
	return temp;
}

/*
 * Round up double to decimal places
 * @param d value to be rounded up
 * @param n number of decimal places
 * @return rounded-up value
 */
double roundToDP (double d, int n) {
	double tens = pow(10, n);
	int tmp = (int)(d*tens);
	return (tmp/tens);
}

extern int column1;
extern int column2;
extern int column3;
extern int column4;
extern int column5;
extern int column6;

int Shop::NAME = 0;
int Shop::CATEGORY = 1;
int Shop::QUANTITY = 2;
int Shop::PRICE = 3;
int Shop::MANUFACTURER = 4;
		
int Shop::ASCENDING = 1;
int Shop::DESCENDING = 2;

string Shop::dataDirectory = "data/";
string Shop::historyDirectory = "history/";

vector<Commodity> Shop::listOfCommodity {};
vector<Shop> Shop::listOfShop {};
vector<Commodity*> Shop::filterAllList {};
map<string, string> Shop::allHistory {};

/*
 * Read Commodity information from a file and
 * add them to the Commodity list
 * @param filename file name
 */
void Shop::readData(string filename) {
	string CommodityInformation;
	string commodityName;
	string category;
	string manufacturer;
	string tmp;
	if (!fileExist(Shop::dataDirectory + filename))
		return;
	ifstream fin;
	fin.open(Shop::dataDirectory + filename);

	if (fin.fail()) {
		cout << "Error in file opening!" << endl;
		return;
	}
	while (getline(fin, CommodityInformation)) {
		istringstream iss(CommodityInformation);
		getline(iss, commodityName, ',');
		getline(iss, category, ',');
		getline(iss, manufacturer, ',');
		getline(iss, tmp, ',');
		double price = stoi(tmp);
		Commodity newCommodity (commodityName, category, manufacturer, price);
		string shopName;
		int quantity;
		bool paired = false;
		while (getline(iss, tmp, ',')) {
			if (!paired) {
				shopName = tmp;
				paired = true;
			}
			else {
				quantity = stoi(tmp);
				newCommodity.setShopQuantity(shopName, quantity);
				paired = false;
			}
		}
		Shop::listOfCommodity.push_back(newCommodity);
	}
	fin.close();
}

/*
 * Read Shop information from a file and
 * add them to the Shop list
 * @param filename file name
 */
void Shop::readShopData(string filename) {
	string ShopInformation;
	string tmp;
	if (!fileExist(Shop::dataDirectory + filename))
		return;
	ifstream fin;
	fin.open(Shop::dataDirectory + filename);

	if (fin.fail()) {
		cout << "Error in file opening!" << endl;
		return;
	}
	while (getline(fin, ShopInformation)) {
		istringstream iss(ShopInformation);
		while (getline(iss, tmp, ',')) {
			Shop newShop(tmp);
		}
	}
	fin.close();
}

/*
 * Write Commodity information into a file 
 * @param filename file name
 */
void Shop::writeData(string filename) {
	ofstream fout;
	fout.open(Shop::dataDirectory + filename);

	if (fout.fail()) {
		cout << "Error in file opening!" << endl;
		return;
	}
	
	string tmp = "";
	vector<Commodity>::iterator ptr;
	for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
		tmp = "";
		tmp += (*ptr).getName() + ',';
		tmp += (*ptr).getCategory() + ',';
		tmp += (*ptr).getManufacturer() + ',';
		tmp += to_string((*ptr).getPrice()) + ',';
		vector<Shop>::iterator ptr1;
		for (ptr1 = Shop::listOfShop.begin(); ptr1 < Shop::listOfShop.end(); ptr1++) {
			tmp += (*ptr1).getShopName() + ',';
			tmp += to_string((*ptr).getQuantity((*ptr1).getShopName())) + ',';
		}
		tmp += '\n';
		fout << tmp;
	}
	
	fout.close();
}

/*
 * Write Commodity information from a file and
 * @param filename file name
 */
void Shop::writeShopData(string filename) {
	string tmp = "";
	ofstream fout;
	fout.open(dataDirectory + filename);

	if (fout.fail()) {
		cout << "Error in file opening!" << endl;
		return;
	}
	sort(Shop::listOfShop.begin(), Shop::listOfShop.end(), shopAscending);
	vector<Shop>::iterator ptr;
	for (ptr = Shop::listOfShop.begin(); ptr < Shop::listOfShop.end(); ptr++) {
		tmp += (*ptr).getShopName();
		tmp += ',';
	}
	fout << tmp;
	fout.close();
}

/*
 * Read History information of all shops from a file and
 * add them to the History list
 */
void Shop::readAllHistory() {
	string fileName = "History.txt";
	if (fileExist(Shop::historyDirectory + fileName)) {
		ifstream fin;
		fin.open(Shop::historyDirectory + fileName);

		if (fin.fail()) {
			cout << "Error in file opening!" << endl;
			return;
		}
		string tmp1, tmp2;
		while (getline(fin, tmp1, ';')) {
			if (tmp1 == "\n") 
				break;
			getline(fin, tmp2, ';');
			Shop::allHistory[tmp1] = tmp2;
		}
		fin.close();
	}
	
	vector<Shop>::iterator shopptr;
	for (shopptr = Shop::listOfShop.begin(); shopptr != Shop::listOfShop.end(); shopptr ++) {
		(*shopptr).readHistory();
	}
}

/*
 * Print History information of a specific date
 * @param date date in string
 */
void Shop::printAllHistory(string date) {
	if (date == "") {
		map<string, string>::iterator ptr;
		for (ptr = Shop::allHistory.begin(); ptr != Shop::allHistory.end(); ptr ++) {
			cout << (*ptr).first << endl;
			cout << (*ptr).second << endl;
		}
	} 
	else {
		map<string, string>::iterator ptr;
		ptr = Shop::allHistory.find(date);
		if (ptr != Shop::allHistory.end()) {
			cout << (*ptr).first << endl;
			cout << (*ptr).second << endl;
		}
		else {
			cout << "No history record found" << endl;
			cout << endl;
		}
	}	
}

/*
 * Write History information of all shops into a file
 */
void Shop::writeAllHistory() {
	time_t now = time(0);
   	tm *ltm = localtime(&now);
   	int day = ltm->tm_mday;
   	string strDay = day < 10 ? ("0" + to_string(day)) : to_string(day);
   	int month = 1 + ltm->tm_mon;
   	string strMonth = month < 10 ? ("0" + to_string(month)) : to_string(month);
   	string date = to_string(1900 + ltm->tm_year) + '/' + strMonth + '/' + strDay;
   	int hour = ltm->tm_hour;
   	string strHour = hour < 10 ? ("0" + to_string(hour)) : to_string(hour);
   	int min = ltm->tm_min;
   	string strMin = min < 10 ? ("0" + to_string(min)) : to_string(min);
   	int sec = ltm->tm_sec;
   	string strSec = sec < 10 ? ("0" + to_string(sec)) : to_string(sec);
   	string time = strHour + ':' + strMin + ':' + strSec;
   	
   	string data;
   	vector<Commodity>::iterator ptr;
   	sort(Shop::listOfCommodity.begin(), Shop::listOfCommodity.end(), nameAscending);
   	
   	data += "Recorded at time: " + time + "\n\n";
   	
   	data += padding("Commodity", column1, ' ');
   	data += padding("Category", column2, ' ');
   	data += padding("Price", column3, ' ');
   	data += padding("Total Quantity", column4, ' ');
   	data += padding("Status", column5, ' ');
   	data += padding("Manufacturer", column6, ' ');
   	data += '\n';
   	stringstream ss;
   	string price;
	for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
		ss.str(string());
		data += padding((*ptr).getName(), column1, ' ');
	   	data += padding((*ptr).getCategory(), column2, ' ');
		ss << fixed << setprecision(2) << (*ptr).getPrice();
		price = ss.str();
	   	data += padding(price, column3, ' ');
	   	data += padding(to_string((*ptr).getTotalQuantity()), column4, ' ');
	   	data += padding(((*ptr).getTotalQuantity() == 0)?"Out of stock" : "Available" , column5, ' ');
	   	data += padding((*ptr).getManufacturer(), column6, ' ');
	   	data += '\n';
	}
	
	Shop::allHistory[date] = data;
	
	string fileName = "History.txt";
	ofstream fout;
	fout.open(Shop::historyDirectory + fileName);

	if (fout.fail()) {
		cout << "Error in file opening!" << endl;
		return;
	}
	
	map<string, string>::iterator ptr1;
	for (ptr1 = Shop::allHistory.begin(); ptr1 != Shop::allHistory.end(); ptr1 ++) {
		fout << (*ptr1).first;
		fout << ';';
		fout << (*ptr1).second;
		fout << ';';
	}
	
	fout.close();
	
	vector<Shop>::iterator shopptr;
	for (shopptr = Shop::listOfShop.begin(); shopptr != Shop::listOfShop.end(); shopptr ++) {
		(*shopptr).writeHistory();
	}
}

/*
 * Delete History information of a specific date
 * @param date date in string
 */
void Shop::deleteAllHistory(string date) {
	map<string, string>::iterator ptr;
	ptr = Shop::allHistory.find(date);
	if (ptr != Shop::allHistory.end()) {
		Shop::allHistory.erase(ptr);
	}
	vector<Shop>::iterator shopptr;
	for (shopptr = Shop::listOfShop.begin(); shopptr != Shop::listOfShop.end(); shopptr ++) {
		(*shopptr).deleteHistory(date);
	}
}

/*
 * Delete all History information
 */
void Shop::clearAllHistory() {
	Shop::allHistory.clear();
	vector<Shop>::iterator shopptr;
	for (shopptr = Shop::listOfShop.begin(); shopptr != Shop::listOfShop.end(); shopptr ++) {
		(*shopptr).clearHistory();
	}
}

/*
 * Add Commodity to the list of Commodity
 * @param element Commodity object to be added
 */
void Shop::addCommodity(Commodity& element) {
	vector<Shop>::iterator ptr;
	for (ptr = Shop::listOfShop.begin(); ptr < Shop::listOfShop.end(); ptr++) {
		if(!element.isShopPresent((*ptr).getShopName())) {
			element.setShopQuantity((*ptr).getShopName(), 0);
		}
	}
	Shop::listOfCommodity.push_back(element);
}

/*
 * Delete Commodity from the list of Commodity
 * @param n Commodity name to be deleted
 */
bool Shop::deleteCommodity(string n) {
	vector<Commodity>::iterator ptr;
	for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
		if((*ptr).getName() == n) {
			Shop::listOfCommodity.erase(ptr);
			return true;
		}
	}
	return false;
}

/*
 * Print the list of Commodity
 * @param mode 0 to print from filter list; 1 to print from normal list
 */
void Shop::printAllCommodity(int mode) {
	cout << left << setw(column1) << "Commodity" << setw(column2) << "Category" << setw(column3) << "Price" << setw(column4) << "Total Quantity" << setw(column5) << "Status" << setw(column6) << "Manufacturer" << endl;
	
	switch (mode) {
		case 0:
		{
			vector<Commodity*>::iterator ptr1;
			for (ptr1 = Shop::filterAllList.begin(); ptr1 < Shop::filterAllList.end(); ptr1 ++) {
				(*(*ptr1)).printDetails();
			}
			break;
		}
		default:
		{
			vector<Commodity>::iterator ptr;
			for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
				(*ptr).printDetails();
			}
		}
	}
}

/*
 * Sort the list of Commodity
 * @param mode sort by name, category, manufacturer, quantity or price
 * @param order sort ascedingly or descendingly
 */
void Shop::sortAllCommodity(int mode, int order) {
	switch (mode) {
		case 0:
		{
			if (order == Shop::ASCENDING)
				sort(Shop::listOfCommodity.begin(), Shop::listOfCommodity.end(), nameAscending);
			else
				sort(Shop::listOfCommodity.begin(), Shop::listOfCommodity.end(), nameDescending);
			break;
		}
		case 1:
		{
			if (order == Shop::ASCENDING)
				sort(Shop::listOfCommodity.begin(), Shop::listOfCommodity.end(), categoryAscending);
			else
				sort(Shop::listOfCommodity.begin(), Shop::listOfCommodity.end(), categoryDescending);
			break;
		}
		case 2:
		{
			if (order == Shop::ASCENDING)
				sort(Shop::listOfCommodity.begin(), Shop::listOfCommodity.end(), quantityAllAscending);
			else
				sort(Shop::listOfCommodity.begin(), Shop::listOfCommodity.end(), quantityAllDescending);
			break;
		}
		case 3:
		{
			if (order == Shop::ASCENDING)
				sort(Shop::listOfCommodity.begin(), Shop::listOfCommodity.end(), priceAscending);
			else
				sort(Shop::listOfCommodity.begin(), Shop::listOfCommodity.end(), priceDescending);
			break;
		}
		case 4:
		{
			if (order == Shop::ASCENDING)
				sort(Shop::listOfCommodity.begin(), Shop::listOfCommodity.end(), manufacturerAscending);
			else
				sort(Shop::listOfCommodity.begin(), Shop::listOfCommodity.end(), manufacturerDescending);
			break;
		}
	}
	printAllCommodity(1);
}

/*
 * Filter the list of Commodity
 * @param mode sort by category or manufacturer
 * @param s category or manufacturer
 */
void Shop::filterAll(int mode, string s) {
	vector<Commodity>::iterator ptr;
	filterAllList.clear();
	switch (mode) {
		case 1:
			for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
				if ((*ptr).getCategory() == s){
					filterAllList.push_back(&(*ptr));
				}
			}
			printAllCommodity(0);
			break;
		case 4:
			for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
				if ((*ptr).getManufacturer() == s){
					filterAllList.push_back(&(*ptr));
				}
			}
			printAllCommodity(0);
			break;
	}
}

/*
 * Filter the list of Commodity
 * @param mode sort by price or quantity
 * @param lowerBound lower boundary for price or quantity
 * @param upperBound upper boundary for price or quantity
 */
void Shop::filterAll(int mode, double lowerBound, double upperBound) {
	vector<Commodity>::iterator ptr;
	filterAllList.clear();
	switch (mode) {
		case 2:
		{
			int lb = (int)lowerBound;
			int ub = (int)upperBound;
			for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
				if (((*ptr).getTotalQuantity() >= lb) && ((*ptr).getTotalQuantity() <= ub)){
					filterAllList.push_back(&(*ptr));
				}
			}
			printAllCommodity(0);
			break;
		}
		case 3:
		{
			for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
				if (((*ptr).getPrice() >= lowerBound) && ((*ptr).getPrice() <= upperBound)){
					filterAllList.push_back(&(*ptr));
				}
			}
			printAllCommodity(0);
		}
	}
}

/*
 * Constructor for Shop
 * @param n shop name
 */
Shop::Shop(string n) {
	shopName = n;
	SHOPNAME = n;
	vector<Commodity>::iterator ptr;
	for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
		if(!(*ptr).isShopPresent(shopName)) {
			(*ptr).setShopQuantity(shopName, 0);
		}
	}
	Shop::listOfShop.push_back(*this);
}

/*
 * Return Shop name of the shop
 * @return shop name
 */
string Shop::getShopName() {
	return shopName;
}

/*
 * Set the quantity for the Commodity
 * @param n Commodity name
 * @param quantity Commodity quantity
 */
void Shop::setCommodityQuantity (string n, int quantity) {
	vector<Commodity>::iterator ptr;
	for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
		if(((*ptr).getName()) == n) {
			(*ptr).setShopQuantity(shopName, quantity);
			break;
		}
	}
}

/*
 * Set the price for the Commodity
 * @param n Commodity name
 * @param price Commodity price
 */
void Shop::setCommodityPrice (string n, double price) {
	vector<Commodity>::iterator ptr;
	for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
		if(((*ptr).getName()) == n) {
			(*ptr).setPrice(price);
			break;
		}
	}
}

/*
 * Set the category for the Commodity
 * @param n Commodity name
 * @param category Commodity category
 */
void Shop::setCommodityCategory (string n, string category) {
	vector<Commodity>::iterator ptr;
	for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
		if(((*ptr).getName()) == n) {
			(*ptr).setCategory(category);
			break;
		}
	}
}

/*
 * Set the manufacturer for the Commodity
 * @param n Commodity name
 * @param category Commodity manufacturer
 */
void Shop::setCommodityManufacturer (string n, string manufacturer) {
	vector<Commodity>::iterator ptr;
	for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
		if(((*ptr).getName()) == n) {
			(*ptr).setManufacturer(manufacturer);
			break;
		}
	}
}

/*
 * List out the Commodities that are out of stock
 */
void Shop::alertOutOfStock () {
	vector<Commodity>::iterator ptr;
	string message = "";
	for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
		if(((*ptr).getQuantity(shopName)) == 0) {
			message += (*ptr).getName();
			message += '\n';
		}
	}
	if (message == "") {
		cout << "There is no commodities that are currently out of stock" << endl;
	}
	else {
		cout << "List of commodities that are currently out of stock" << endl;
		cout << endl;
		cout << message << endl;
	}
}

/*
 * Filter the list of Commodity of specific shop
 * @param mode sort by category or manufacturer
 * @param s category or manufacturer
 */
void Shop::filter(int mode, string s) {
	vector<Commodity>::iterator ptr;
	filterList.clear();
	switch (mode) {
		case 1:
			for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
				if ((*ptr).getCategory() == s){
					filterList.push_back(&(*ptr));
				}
			}
			printCommodity(0);
			break;
		case 4:
			for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
				if ((*ptr).getManufacturer() == s){
					filterList.push_back(&(*ptr));
				}
			}
			printCommodity(0);
			break;
	}
}

/*
 * Filter the list of Commodity of specific Shop
 * @param mode sort by price or quantity
 * @param lowerBound lower boundary for price or quantity
 * @param upperBound upper boundary for price or quantity
 */
void Shop::filter(int mode, double lowerBound, double upperBound) {
	vector<Commodity>::iterator ptr;
	filterList.clear();
	switch (mode) {
		case 2:
		{
			int lb = (int)lowerBound;
			int ub = (int)upperBound;
			for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
				if (((*ptr).getQuantity(shopName) >= lb) && ((*ptr).getQuantity(shopName) <= ub)){
					filterList.push_back(&(*ptr));
				}
			}
			printCommodity(0);
			break;
		}
		case 3:
		{
			for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
				if (((*ptr).getPrice() >= lowerBound) && ((*ptr).getPrice() <= upperBound)){
					filterList.push_back(&(*ptr));
				}
			}
			printCommodity(0);
		}
	}
}

/*
 * Sort the list of Commodity of specific Shop
 * @param mode sort by name, category, manufacturer, quantity or price
 * @param order sort ascedingly or descendingly
 */
void Shop::sortCommodity(int mode, int order) {
	SHOPNAME = shopName;
	switch (mode) {
		case 0:
		{
			if (order == Shop::ASCENDING)
				sort(Shop::listOfCommodity.begin(), Shop::listOfCommodity.end(), nameAscending);
			else
				sort(Shop::listOfCommodity.begin(), Shop::listOfCommodity.end(), nameDescending);
			break;
		}
		case 1:
		{
			if (order == Shop::ASCENDING)
				sort(Shop::listOfCommodity.begin(), Shop::listOfCommodity.end(), categoryAscending);
			else
				sort(Shop::listOfCommodity.begin(), Shop::listOfCommodity.end(), categoryDescending);
			break;
		}
		case 2:
		{
			if (order == Shop::ASCENDING)
				sort(Shop::listOfCommodity.begin(), Shop::listOfCommodity.end(), quantityAscending);
			else
				sort(Shop::listOfCommodity.begin(), Shop::listOfCommodity.end(), quantityDescending);
			break;
		}
		case 3:
		{
			if (order == Shop::ASCENDING)
				sort(Shop::listOfCommodity.begin(), Shop::listOfCommodity.end(), priceAscending);
			else
				sort(Shop::listOfCommodity.begin(), Shop::listOfCommodity.end(), priceDescending);
			break;
		}
		case 4:
		{
			if (order == Shop::ASCENDING)
				sort(Shop::listOfCommodity.begin(), Shop::listOfCommodity.end(), manufacturerAscending);
			else
				sort(Shop::listOfCommodity.begin(), Shop::listOfCommodity.end(), manufacturerDescending);
			break;
		}
	}
	printCommodity(1);
}

/*
 * Print the list of Commodity of specific Shop
 * @param mode 0 to print from filter list; 1 to print from normal list
 */
void Shop::printCommodity(int mode) {
	cout << left << setw(column1) << "Commodity" << setw(column2) << "Category" << setw(column3) << "Price" << setw(column4) << "Quantity" << setw(column5) << "Status" << setw(column6) << "Manufacturer" << endl;
	switch (mode) {
		case 0:
		{
			vector<Commodity*>::iterator ptr1;
			for (ptr1 = filterList.begin(); ptr1 < filterList.end(); ptr1 ++) {
				(*(*ptr1)).printDetails(shopName);
			}
			break;
		}
		default:
		{
			vector<Commodity>::iterator ptr;
			for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
				(*ptr).printDetails(shopName);
			}
		}
	}
	cout << endl;
}

/*
 * Print the information of specific Commodity of specific Shop
 * @param n Commodity name
 */
void Shop::printSpecificCommodity(string n) {
	cout << left << setw(column1) << "Commodity" << setw(column2) << "Category" << setw(column3) << "Price" << setw(column4) << "Quantity" << setw(column5) << "Status" << setw(column6) << "Manufacturer" << endl;
	vector<Commodity>::iterator ptr;
	for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
		if ((*ptr).getName() == n) {
			(*ptr).printDetails(shopName);
			cout << endl;
			break;
		}
	}	
}

/*
 * Read History information of specific shop from a file and
 * add them to the History list
 */
void Shop::readHistory() {
	string fileName = shopName + "History.txt";
	ifstream fin;
	if (!fileExist(Shop::historyDirectory + fileName))
		return;
	fin.open(Shop::historyDirectory + fileName);

	if (fin.fail()) {
		cout << "Error in file opening!" << endl;
		return;
	}
	string tmp1, tmp2;
	while (getline(fin, tmp1, ';')) {
		if (tmp1 == "\n") 
			break;
		getline(fin, tmp2, ';');
		history[tmp1] = tmp2;
	}
	fin.close();
}

/*
 * Print History information of a specific date of specific Shop
 * @param date date in string
 */
void Shop::printHistory(string date) {
	if (date == "") {
		map<string, string>::iterator ptr;
		for (ptr = history.begin(); ptr != history.end(); ptr ++) {
			cout << (*ptr).first << endl;
			cout << (*ptr).second << endl;
		}
	} 
	else {
		map<string, string>::iterator ptr;
		ptr = history.find(date);
		if (ptr != history.end()) {
			cout << (*ptr).first << endl;
			cout << (*ptr).second << endl;
		}
		else {
			cout << "No history record found" << endl;
			cout << endl;
		}
	} 	
}

/*
 * Write History information of specific shop into a file
 */
void Shop::writeHistory() {
	time_t now = time(0);
   	tm *ltm = localtime(&now);
   	int day = ltm->tm_mday;
   	string strDay = day < 10 ? ("0" + to_string(day)) : to_string(day);
   	int month = 1 + ltm->tm_mon;
   	string strMonth = month < 10 ? ("0" + to_string(month)) : to_string(month);
   	string date = to_string(1900 + ltm->tm_year) + '/' + strMonth + '/' + strDay;
   	int hour = ltm->tm_hour;
   	string strHour = hour < 10 ? ("0" + to_string(hour)) : to_string(hour);
   	int min = ltm->tm_min;
   	string strMin = min < 10 ? ("0" + to_string(min)) : to_string(min);
   	int sec = ltm->tm_sec;
   	string strSec = sec < 10 ? ("0" + to_string(sec)) : to_string(sec);
   	string time = strHour + ':' + strMin + ':' + strSec;
   	
   	string data;
   	vector<Commodity>::iterator ptr;
   	sort(Shop::listOfCommodity.begin(), Shop::listOfCommodity.end(), nameAscending);
   	data += "Recorded at time: " + time + "\n\n";
   	
   	data += padding("Commodity", column1, ' ');
   	data += padding("Category", column2, ' ');
   	data += padding("Price", column3, ' ');
   	data += padding("Quantity", column4, ' ');
   	data += padding("Status", column5, ' ');
   	data += padding("Manufacturer", column6, ' ');
   	data += '\n';
   	
	stringstream ss;
   	string price;
	for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
		ss.str(string());
		data += padding((*ptr).getName(), column1, ' ');
	   	data += padding((*ptr).getCategory(), column2, ' ');
		ss << fixed << setprecision(2) << (*ptr).getPrice();
		price = ss.str();
	   	data += padding(price, column3, ' ');
	   	data += padding(to_string((*ptr).getQuantity(shopName)), column4, ' ');
	   	data += padding(((*ptr).getQuantity(shopName) == 0)?"Out of stock" : "Available" , column5, ' ');
	   	data += padding((*ptr).getManufacturer(), column6, ' ');
	   	data += '\n';
	}
	history[date] = data;
	
	string fileName = shopName + "History.txt";
	ofstream fout;
	fout.open(Shop::historyDirectory + fileName);

	if (fout.fail()) {
		cout << "Error in file opening!" << endl;
		return;
	}
	
	map<string, string>::iterator ptr1;
	for (ptr1 = history.begin(); ptr1 != history.end(); ptr1 ++) {
		fout << (*ptr1).first;
		fout << ';';
		fout << (*ptr1).second;
		fout << ';';
	}
	
	fout.close();
}

/*
 * Delete History information of a specific date of specific shop
 * @param date date in string
 */
bool Shop::deleteHistory(string date) {
	map<string, string>::iterator ptr;
	ptr = history.find(date);
	if (ptr != history.end()) {
		history.erase(ptr);
		return true;
	}
	else {
		return false;
	}
}

/*
 * Delete all History information of specific shop
 */
void Shop::clearHistory() {
	history.clear();
}
