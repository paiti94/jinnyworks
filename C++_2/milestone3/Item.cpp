#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "util.h"
using namespace std;

class Item {
	string name, installer, remover, sequenceNumber, description;
public:
	Item() {}
	Item(vector<string>& line) {
		switch (line.size()) {
		case 5:
			description = line[4];
		case 4:
			 if (validSequenceNumber(line[3])) {
				 sequenceNumber = line[3];
			 }
			 else {
				 throw string("sequence number not understood -->") + line[3] + "<--";
			 }
			 if (validTaskName(line[2])) {
				 remover = line[2];
			 }
			 else {
				 throw string("remover task name not understood -->") + line[2] + "<--";
			 }
			 if (validTaskName(line[1])) {
				 installer = line[1];
			 }
			 else {
				 throw string("installer task name not understood -->") + line[1] + "<--";
			 }
			 if (validItemName(line[0])) {
				name = line[0];
			 }
			 else {
				 throw string("Item name not understood -->") + line[0] + "<--";
			 }
			 break;
		default:
			throw string("bad line, found") + to_string(line.size()) + "fields, expected 4 or 5";
		}
	}
	void print() {
		cout << "|name|installer|remover|SequenceNumber|description| = "
			<< "|" << name
			<< "|" << installer
			<< "|" << remover
			<< "|" << sequenceNumber
			<< "|" << description
			<< "\n";
	#if 0
		cout << "name/slots/pass/fail/ = /" << name << "/" << slots << "/" << pass << "/" << fail << "/" << "\n";
	#endif
	}
	void graph(fstream& dotFile) {
	
		/*if (pass.empty() && fail.empty()) {
			dotFile << '"' << name << '"' << ";\n";
		}
		if (!pass.empty()) {*/
			dotFile << '"' << "item" <<"\\n" << name << '"'
				<< " -> "
				<< '"' << "installer" << "\\n" <<installer << '"'
				<< "[color=green]; \n";
		//}
		//if (!fail.empty()) {
			dotFile << '"' << "item\\n" << name << '"'
				<< " -> "
				<< '"' << "remover\\n" << remover << '"'
				<< "[color=red]; \n";
		//}
	
	}
};

class ItemManager {
	vector<Item> ItemList;
public:
	ItemManager() {}
	ItemManager(vector<vector<string>> & csvItemData)
	{
		for (auto line : csvItemData) {
			try {
				ItemList.push_back(move(Item(line)));
			}
			catch (const string& e) {
				cerr << "Problem" << e << "\n";
			}
		}
	}
	void print() {
		int lineNumber = 0;
		for (auto& t : ItemList) {
			lineNumber++;
			cout << lineNumber << ": ";
			t.print();
		}
	}
	void graph(string& filename) {
		fstream os(filename + ".gv", ios::out);
		os << "digraph TaskGraph {\n";
		for (auto t : ItemList) {
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
	vector<vector<string>>csvItemData;

	try {
		csvRead(filename, sep, csvItemData);
		csvPrint(csvItemData);

		ItemManager tm(csvItemData);
		tm.print();
		tm.graph(filename);
	}
	catch (const string& e) {
		cerr << "It threw! - " << e << "\n";
	}
	return 0;
}

