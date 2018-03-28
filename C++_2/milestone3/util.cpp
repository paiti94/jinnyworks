#include "util.h"

void trim(std::string& str) {
	while (!str.empty() && str[0] == ' ') {
		str.erase(0, 1); // Deliting the first Character
	}
	while (!str.empty() && str[str.size() - 1] == ' ') {
		str.erase(str.size() - 1, 1); // Deliting the last Character
	}
}
void csvRead(std::string& fileName, char seperator, std::vector< std::vector<std::string> > &csvData) {
	std::fstream is(fileName, std::ios::in);
	if (!is.is_open()) {
		throw std::string("Cannot open file '") + fileName + "'";
	}
	std::string line;
	while (getline(is, line)) {
		//Handeling an CR '\r' in data
		auto cr = line.find('\r');
		if (cr != std::string::npos) {
			line.erase(cr);
		}
		size_t index = 0;
		std::string field;
		std::vector<std::string> fields;
		while (index < line.size()) {
			while (index < line.size() && line[index] != seperator) {
				field += line[index];
				index++;
			}
			
			index++; // Skipping the seperator
			trim(field);
			if (field != " " && !(field.empty())) {
				fields.push_back(std::move(field));
			}
		}
		if (line.size() != 0) {
			csvData.push_back(std::move(fields));
		}
	}
	is.close();
	/*std::fstream is(fileName, std::ios::in);
	if (!is.is_open())
	{
		throw std::string("Cannot open file ") + fileName;
	}
	std::string line;
	while (getline(is, line))
	{
		auto cr = line.find('\r');
		if (cr != std::string::npos)
		{
			line.erase(cr);
		}
		//cout << "line -->" << line << "<---\n";
		std::vector <std::string> fields;
		std::string field;
		size_t i = 0;

		while (i < line.size())
		{
			if (line[i] != seperator) {
				field += line[i];
			}
			else
			{
				trim(field);
				fields.push_back(move(field));
			}
			i++;
		}
		// If last entry was not a delimiter?
		if (!field.empty())
		{
			trim(field);
			fields.push_back(move(field));
		}
		csvData.push_back(move(fields));
	}*/
	is.close();
}
void csvPrint(std::vector< std::vector<std::string> > &csvData) {
	std::cout << std::endl;
	for (auto row : csvData) {
		for (auto column : row) {
			/*if (column.empty()) {
				break;
			}*/
			std::cout << "(" << column << ") ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	for (size_t row = 0; row < csvData.size(); row++) {
		for (size_t column = 0; column < csvData[row].size(); column++) {
			if (csvData[row][column].empty()) {
				break;
			}
			std::cout << "--" << csvData[row][column] << "-- ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	for (auto row = csvData.begin(); row != csvData.end(); row++) {
		for (auto column = row->begin(); column != row->end(); column++) {
			if (column->empty()) {
				break;
			}
			std::cout << "[" << *column << "] ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
bool validTaskName(std::string& t) {
	if (t.empty()) {
		return false;
	}
	for (auto chr : t) {
		if (!(isalnum(chr) || chr == ' ' || chr == '#')) {
			return false;
		}
	}
	return true;
}
bool validSlots(std::string& s) {
	if (s.empty()) {
		return false;
	}
	for (auto chr : s) {
		if (!isdigit(chr)) {
			return false;
		}
	}
	return true;
}


bool validSequenceNumber(std::string& s) {
	for (auto chr : s) {
		if (!isdigit(chr))
		{
			return false;
		}
	}
	return true;
}
bool validItemName(std::string& i) {
	if (i.empty())
	{
		return false;
	}
	for (auto chr : i) {
		if (!(isspace(chr) || isalnum(chr) || chr == '_'|| chr == ' '))
		{
			return false;
		}
	}
	return true;
}