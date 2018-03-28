#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void trim(std::string& str);
void csvRead(std::string& fileName, char seperator, std::vector< std::vector<std::string> > &csvData);
void csvPrint(std::vector< std::vector<std::string> > &csvData);
bool validTaskName(std::string& t);
bool validSlots(std::string& s);
bool validSequenceNumber(std::string& s);
bool validItemName(std::string& i);
