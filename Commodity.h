#include <iostream>
#include <string>

using namespace std;

class Commodity{
	public:
		Commodity (string n, string c, double p, int q);
		string getName(string n);
		string getCategory(string c):
		double getPrice(double p);
		int getTotalQuantity(int q);
		//int getQuantity(string shop)
		bool stockAvailable();
		void setName();
		void setCategory();
		void setPrice();
		//void setQuantity(string shop);
		//static void readData(string filename);
		// static void writeData(string filename);

		

	private:
		string name;
		string category;
		double price;
		int totalQuantity;
		bool outOfStock;
		
};
