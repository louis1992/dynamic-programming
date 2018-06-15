

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

class KnapSack {
public:
    KnapSack() {}
    void loadData(vector<int>& weight, vector<int>& value);
    int getMax(int x, int y);
    int knapSack(int cap, vector<int>& weight, vector<int>& value, int n);
    void print(int cap, vector<int> weight, vector<int> value, int maxProfit);

private:
    //int capacity = 50;
    vector<int> weight;
    vector<int> value;
    string dataPath;
};

void KnapSack::loadData(vector<int>& weight, vector<int>& value) {
    // TODO.
    ifstream inFile("data.txt");
    string buf= "";
    string data_type = "";
    while (inFile >> buf) {
        if (data_type == "weight" && buf != "value") {
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
}

int KnapSack::getMax(int x, int y) {
    return x > y ? x : y;
}

int KnapSack::knapSack(int cap, vector<int>& weight, vector<int>& value, int n) {
    if (n == 0 || cap == 0)
        return 0;
    
    if (weight[n-1] > cap)
        return knapSack(cap, weight, value, n-1);
    else 
        return getMax(value[n-1] + knapSack(cap-weight[n-1], weight, value, n-1), knapSack(cap, weight, value, n-1));
}

void KnapSack::print(int cap, vector<int> weight, vector<int> value, int maxProfit) {
    cout << "//////////////////////////////////////" << endl;
    cout << "// Capacity : " << cap << endl;
    cout << "// Weights : ";
    for (int i = 0; i != weight.size(); ++i)
        cout << weight[i] << " ";
    cout << endl;
    cout << "// Values : ";
    for (int i = 0; i !=value.size(); ++i)
        cout << value[i] << " ";
    cout << endl;
    cout << "// Max Profit : " << maxProfit << endl;
    cout << "//////////////////////////////////////" << endl;
}