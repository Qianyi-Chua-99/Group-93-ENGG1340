#include <iostream>
#include <string>

using namespace std;

class Commodity{
	public:
		Commodity (string n, string c, double p, int q);
		string getName();
	private:
		string name;
		string category;
		double price;
		int totalQuantity;
		bool outOfStock;
};
