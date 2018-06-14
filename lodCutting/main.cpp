#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

void loadData(vector<int>& length, vector<int>& profit);
int getMax(int x, int y);
int cutRod(int length, vector<int>& profit);
void print(vector<int> data);

int main(int argc, char** argv) {
    vector<int> length;
    vector<int> profit;
    loadData(length, profit);
    cout << cutRod(10, profit) << endl;
    return 0;
}

void loadData(vector<int>& length, vector<int>& profit) {
    // TODO.
    ifstream inFile("data.txt");
    string buf= "";
    string data;
    string data_type = "";
    while (inFile >> buf) {
        if (data_type == "length") {
            length.push_back(atoi(buf.c_str()));
        }
        else if (data_type == "profit") {
            profit.push_back(atoi(buf.c_str()));
        }
        if (buf == "length")
            data_type = "length";
        else if (buf == "profit")
            data_type = "profit";
    }
    inFile.close();

    cout << "profit : ";
    for (int i = 0; i != profit.size(); ++i)
        cout << profit[i] << " ";
    cout << endl;

    cout  << "length : ";
    for (int i = 0; i != length.size(); ++i)
        cout  << length[i] << " ";
    cout << endl;
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