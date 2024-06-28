
#include "Header.h"


int main() {
    try {
        cout << "Reading CSV data..." << endl;
        vector<vector<string>> data = parseCSV(cin);
        if (data.empty() || data[0].empty()) {
            throw runtime_error("CSV data is invalid");
        }
        cout << "Converting to JSON..." << endl;
        string jsonData = convertToJson(data);
        cout << jsonData << endl;
        return 0;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
}
