//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <vector>
//
//using namespace std;
//
//vector<vector<string>> loadData(const string& filename) {
//    vector<vector<string>> data;
//    ifstream file(filename);
//    if (!file.is_open()) {
//        cerr << "Error: Failed to open the file." << endl;
//        return data;
//    }
//
//    string line;
//    while (getline(file, line)) {
//        vector<string> rowData;
//        stringstream ss(line);
//        string cell;
//
//        while (getline(ss, cell, ',')) {
//            rowData.push_back(cell);
//        }
//
//        data.push_back(rowData);
//    }
//
//    file.close();
//    return data;
//}
//
//int main() {
//    
//
//    return 0;
//}


/*
vector <vector<string>> data = Utils::loadData("output.csv");
vector<University> v = Utils::parse(data);
vector<University>v2 = v;
auto start = std::chrono::high_resolution_clock::now();
int ls = Utils::linearSearch(v, "Yuan Ze University");
auto end = std::chrono::high_resolution_clock::now();
std::chrono::duration<double, std::milli> durationLS = end - start;

start = std::chrono::high_resolution_clock::now();
Utils::selectionSortByName(v);
end = std::chrono::high_resolution_clock::now();
std::chrono::duration<double, std::milli> sSort = end - start;

start = std::chrono::high_resolution_clock::now();
Utils::bubbleSortByName(v2);
end = std::chrono::high_resolution_clock::now();
std::chrono::duration<double, std::milli> bSort = end - start;

start = std::chrono::high_resolution_clock::now();
int bs = Utils::binarySearch(v, "Yuan Ze University");
end = std::chrono::high_resolution_clock::now();
std::chrono::duration<double, std::milli> durationBS = end - start;
int i = 0;
for (University u : v)
cout << "\n" << ++i << ": " << u.getName();
cout << "\nLinear Search : " << durationLS.count() << " Binary search : " << durationBS.count() << endl;
cout << "\nbubble : " << bSort.count() << " selection : " << sSort.count() << endl;
*/