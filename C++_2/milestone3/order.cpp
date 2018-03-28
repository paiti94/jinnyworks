#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "util.h"
using namespace std;

bool validCustomerName(std::string& c) {
	if (c.empty())
	{
		return false;
	}
	for (auto chr : c) {
		if (!(isspace(chr) || isalnum(chr) || chr == '\''))
		{
			return false;
		}
	}
	return true;

}
bool validProductName(std::string& p) {
	if (p.empty())
	{
		return false;
	}
	for (auto chr : p) {
		if (!(isspace(chr) || isalnum(chr) || chr == '\'' || chr == '#' || chr == '$'))
		{
			return false;
		}
	}

	return true;
}
class Order {
	string customer, product;
	vector<string> itemList;
	string dump;
public:
	Order() {}
	Order(vector<string>& line) {
	/*	if (line.size() == 0) {
			cout << "meh \n";
		}*/
		if (line.size() < 3) {
			throw string("expected at least 3 fields, found ") + to_string(line.size());
			
		}
		if (validCustomerName(line[0])) {
			customer = line[0];
		}
		else {
			throw string("customer name not understood -->") + line[0] + "<--";
		}
		if (validProductName(line[1])) {
			product = line[1];
		}
		else {
			throw string("product name not understood -->") + line[1] + "<--";
		}
		/*cout << customer << product << "\n";
		cout << line[2] << "!!!\n";
		cout << validItemName(line[2]);*/
		for (size_t i = 2; i < line.size(); i++) {
			if (validItemName(line[i])) {
				itemList.push_back(move(line[i]));
			}
			else {
				throw string("item name not understood -->") + line[i] + "<--";
			}	
		}
	}
	void print() {
		
		cout << "|customer|product|item1|item2|...| = "
			<< "|" << customer
			<< "|" << product;
		for (auto item : itemList) {
			cout << "|" << item;
		}
		cout << "\n";
			

#if 0
		cout << "name/slots/pass/fail/ = /" << name << "/" << slots << "/" << pass << "/" << fail << "/" << "\n";
#endif
	}
	void graph(fstream& dotFile) {

		for (auto& item : itemList) {
			dotFile <<" " <<'"' << customer <<"\\n" 
			<<product << '"'
				<< "->"
				<< '"' << item << '"'
				<< " [color=blue]; \n";
	
		}

	}
};

class OrderManager {
	vector<Order> OrderList;
public:
	OrderManager() {}
	OrderManager(vector<vector<string>> & csvItemData)
	{
		for (auto& line : csvItemData) {
			try {
				OrderList.push_back(move(Order(line)));
			}
			catch (const string& e) {
				cerr << "Problem" << e << "\n";
			}
		}
	}
	void print() {
		for (auto t : OrderList) {
			t.print();
		}
	}
	void graph(string& filename) {
		fstream os(filename + ".gv", ios::out);
		os << "digraph TaskGraph {\n";
		for (auto t : OrderList) {
			t.graph(os);
		}
		os << "}\n";
		os.close();
		string cmd;
		cmd += string("dot -Tpng ") + filename + ".gv > " + filename + ".gv.png";
		cout << cmd << "\n";
		system(cmd.c_str());
	}

};

int main(int argc, char* argv[]) {
	if (argc != 3) {
		cerr << "Usage: " << argv[0] << "Item-csv-file task-csv-seperator-character\n";
		return 1;
		//csvdump main same
	}
	string filename = argv[1];
	char sep = argv[2][0];
	vector<vector<string>>csvOrderData;

	try {
		csvRead(filename, sep, csvOrderData);
		csvPrint(csvOrderData);

		OrderManager tm(csvOrderData);
		tm.print();
		tm.graph(filename);
	}
	catch (const string& e) {
		cerr << "It threw! - " << e << "\n";
	}
	return 0;
}

