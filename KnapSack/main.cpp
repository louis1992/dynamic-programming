#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

void loadData(vector<int>& weight, vector<int>& value);
int getMax(int x, int y);
int knapSack(vector<int>& weight, vector<int>& value);
void print(vector<int> data);

int main(int argc, char** argv) {
    vector<int> weight;
    vector<int> value;
    loadData(weight, value);
    cout << cutRod(10, value) << endl;
    return 0;
}

void loadData(vector<int>& weight, vector<int>& value) {
    // TODO.
    ifstream inFile("data.txt");
    string buf= "";
    string data_type = "";
    while (inFile >> buf) {
        if (data_type == "weight") {
            weight.push_back(atoi(buf.c_str()));
        }
        else if (data_type == "value") {
            value.push_back(atoi(buf.c_str()));
        }
        if (buf == "weight")
            data_type = "weight";
        else if (buf == "value")
            data_type = "value";
    }
    inFile.close();

    cout << "value : ";
    for (int i = 0; i != value.size(); ++i)
        cout << value[i] << " ";
    cout << endl;

    cout  << "weight : ";
    for (int i = 0; i != weight.size(); ++i)
        cout  << weight[i] << " ";
    cout << endl;
}

int getMax(int x, int y) {
    return x > y ? x : y;
}

int knapSack(vector<int>& weight, vector<int>& profit) {
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