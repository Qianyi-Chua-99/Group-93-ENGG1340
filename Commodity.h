#include <iostream>
#include <string>
#include <map>

using namespace std;

class Commodity{
	public:
		Commodity (string n, string c, double p, int q);
		string getName();
		string getCategory();
		double getPrice();
		int getTotalQuantity();
		//int getQuantity(string shop);
		bool stockAvailable();
		void setName(string n);
		void setCategory(string c);
		void setPrice(double p);
		//void setQuantity(string shop);
		//static void readData(string filename);
		//static void writeData(string filename);
		

	private:
		string name;
		string category;
		double price;
		int totalQuantity;
		bool outOfStock;
		
};
