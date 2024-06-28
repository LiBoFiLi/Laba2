#include "Header.h"

vector<vector<string>> parseCSV(std::istream& input) {
    vector<vector<string>> data;
    string line;
    while (getline(input, line)) {
        stringstream lineStream(line);
        string cell;
        vector<string> parsedRow;
        while (getline(lineStream, cell, ',')) {
            parsedRow.push_back(cell);
        }
        data.push_back(parsedRow);
    }
    return data;
}

string convertToJson(const vector<vector<string>>& data) {
    if (data.size() < 2) return "[]"; // Проверка на наличие данных

    string json = "[";
    const auto& headers = data[0];
    for (size_t i = 1; i < data.size(); ++i) {
        if (data[i].size() != headers.size()) {
            throw runtime_error("Row size does not match header size");
        }
        json += "{";
        for (size_t j = 0; j < headers.size(); ++j) {
            json += "\"" + headers[j] + "\": \"" + data[i][j] + "\"";
            if (j < headers.size() - 1) {
                json += ", ";
            }
        }
        json += "}";
        if (i < data.size() - 1) {
            json += ", ";
        }
    }
    json += "]";
    return json;
}
