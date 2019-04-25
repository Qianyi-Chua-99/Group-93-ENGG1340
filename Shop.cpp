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

extern int column1;
extern int column2;
extern int column3;
extern int column4;

int Shop::NAME = 0;
int Shop::CATEGORY = 1;
int Shop::QUANTITY = 2;
int Shop::PRICE = 3;
		
int Shop::ASCENDING = 1;
int Shop::DESCENDING = 2;

string Shop::dataDirectory = "data/";
string Shop::historyDirectory = "history/";

vector<Commodity> Shop::listOfCommodity {};
vector<Shop> Shop::listOfShop {};
vector<Commodity*> Shop::filterAllList {};
map<string, string> Shop::allHistory {};

string SHOPNAME;

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

void Shop::readData(string filename) {
	string CommodityInformation;
	string commodityName;
	string category;
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
		getline(iss, tmp, ',');
		double price = stoi(tmp);
		Commodity newCommodity (commodityName, category, price);
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

bool shopAscending(Shop& A, Shop& B) {
	return (((A).getShopName()) < ((B).getShopName()));
}

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

void Shop::addCommodity(Commodity& element) {
	vector<Shop>::iterator ptr;
	for (ptr = Shop::listOfShop.begin(); ptr < Shop::listOfShop.end(); ptr++) {
		if(!element.isShopPresent((*ptr).getShopName())) {
			element.setShopQuantity((*ptr).getShopName(), 0);
		}
	}
	Shop::listOfCommodity.push_back(element);
}

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


string Shop::getShopName() {
	return shopName;
}

void Shop::setCommodityQuantity (string n, int quantity) {
	vector<Commodity>::iterator ptr;
	for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
		if(((*ptr).getName()) == n) {
			(*ptr).setShopQuantity(shopName, quantity);
			break;
		}
	}
}

void Shop::setCommodityPrice (string n, double price) {
	vector<Commodity>::iterator ptr;
	for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
		if(((*ptr).getName()) == n) {
			(*ptr).setPrice(price);
			break;
		}
	}
}

void Shop::setCommodityCategory (string n, string category) {
	vector<Commodity>::iterator ptr;
	for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
		if(((*ptr).getName()) == n) {
			(*ptr).setCategory(category);
			break;
		}
	}
}

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

void Shop::filterAll(int mode, string category) {
	vector<Commodity>::iterator ptr;
	filterAllList.clear();
	switch (mode) {
		case 1:
			for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
				if ((*ptr).getCategory() == category){
					filterAllList.push_back(&(*ptr));
				}
			}
			printAllCommodity(0);
			break;
	}
}

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

void Shop::filter(int mode, string category) {
	vector<Commodity>::iterator ptr;
	filterList.clear();
	switch (mode) {
		case 1:
			for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
				if ((*ptr).getCategory() == category){
					filterList.push_back(&(*ptr));
				}
			}
			printCommodity(0);
			break;
	}
}

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

bool nameAscending(Commodity& A, Commodity& B) {
	return (((A).getName()) < ((B).getName()));
}

bool nameDescending(Commodity& A, Commodity& B) {
	return (((A).getName()) > ((B).getName()));
}

bool categoryAscending(Commodity& A, Commodity& B) {
	return (((A).getCategory()) < ((B).getCategory()));
}

bool categoryDescending(Commodity& A, Commodity& B) {
	return ((A.getCategory()) > (B.getCategory()));
}

bool quantityAscending(Commodity& A, Commodity& B) {
	return (((A).getQuantity(SHOPNAME)) < ((B).getQuantity(SHOPNAME)));
}

bool quantityDescending(Commodity& A, Commodity& B) {
	return (((A).getQuantity(SHOPNAME)) > ((B).getQuantity(SHOPNAME)));
}


bool quantityAllAscending(Commodity& A, Commodity& B) {
	return (((A).getTotalQuantity()) < ((B).getTotalQuantity()));
}

bool quantityAllDescending(Commodity& A, Commodity& B) {
	return (((A).getTotalQuantity()) > ((B).getTotalQuantity()));
}

bool priceAscending(Commodity& A, Commodity& B) {
	return (((A).getPrice()) < ((B).getPrice()));
}

bool priceDescending(Commodity& A, Commodity& B) {
	return (((A).getPrice()) > ((B).getPrice()));
}

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
	}
	printCommodity(1);
}

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
	}
	printAllCommodity(1);
}

void Shop::printCommodity(int mode) {
	cout << left << setw(column1) << "Commodity" << setw(column2) << "Category" << setw(column3) << "Price" << setw(column4) << "Quantity" << endl;
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

void Shop::printAllCommodity(int mode) {
	cout << left << setw(column1) << "Commodity" << setw(column2) << "Category" << setw(column3) << "Price" << setw(column4) << "Total Quantity" << endl;
	
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


void Shop::printSpecificCommodity(string n) {
	cout << left << setw(column1) << "Commodity" << setw(column2) << "Category" << setw(column3) << "Price" << setw(column4) << "Quantity" << endl;
	vector<Commodity>::iterator ptr;
	for (ptr = Shop::listOfCommodity.begin(); ptr < Shop::listOfCommodity.end(); ptr ++) {
		if ((*ptr).getName() == n) {
			(*ptr).printDetails(shopName);
			cout << endl;
			break;
		}
	}	
}

string padding (const string& s, int n, char c) {
	string temp = s;
	int len = s.length();
	if (len < n) {
		for (int i = 0; i < (n-len); i++)
			temp += c;
	}
	return temp;
}

double roundToDP (double d, int n) {
	double tens = pow(10, n);
	int tmp = (int)(d*tens);
	return (tmp/tens);
}

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

void Shop::clearHistory() {
	history.clear();
}

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

void Shop::clearAllHistory() {
	Shop::allHistory.clear();
	vector<Shop>::iterator shopptr;
	for (shopptr = Shop::listOfShop.begin(); shopptr != Shop::listOfShop.end(); shopptr ++) {
		(*shopptr).clearHistory();
	}
}

void Shop::debug() {
	cout << (Shop::listOfCommodity).size() << endl;
}
