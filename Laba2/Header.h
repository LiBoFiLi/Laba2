#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <exception>

using namespace std;

vector<vector<string>> parseCSV(std::istream&);
string convertToJson(const vector<vector<string>>&);
