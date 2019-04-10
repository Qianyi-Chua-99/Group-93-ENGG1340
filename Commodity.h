#include <iostream>
#include <string>

using namespace std;

class Commodity{
	public:
		Commodity (string n, string c, double p, int q);
		string getName();
		string getCategory():
		double getPrice();
		int getTotalQuantity();
		bool stockAvailable();
		void setName();
		void setCategory();
		void setPrice();
		void setQuantity(
	private:
		string name;
		string category;
		double price;
		int totalQuantity;
		bool outOfStock;
		
};
