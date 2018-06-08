#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void loadData(vector<int>& length, vector<int>& profit);
int getMax(int x, int y);
int cutRod(int length, vector<int> profit);
void print(vector<int> data);

int main(int argc, char** argv) {
    vector<int> length;
    vector<int> profit;
    loadData(length, profit);
    return 0;
}

void loadData(vector<int>& length, vector<int>& profit) {
    // TODO.
    ifstream inFile("data.txt");
    string buf;
    string data_type;
    while (inFile >> buf) {
        if (buf == "length")
            data_type = "length";
        else if (buf == "profit")
            data_type = "profit";
        if (data_type == "length") {
            length.push_back(std::stoi(buf));
        }
        else if (data_type == "profit") {
            profit.push_back(std::stoi(buf));
        }
    }
    inFile.close();
}

int getMax(int x, int y) {
    return x > y ? x : y;
}

int cutRod(int length, vector<int>& profit) {
    int maxProfit = 0;
    if (length <= 0)
        return 0;
    
    for (int i = 0; i < length; ++i)
        maxProfit = getMax(maxProfit, profit[i] + cutRod(length - i - 1, profit));
    return maxProfit;
}

void print(vector<string> data) {
    for (int i = 0; i !=data.size(); ++i)
        cout << data[i] << endl;
}