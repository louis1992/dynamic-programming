#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void loadData(vector<int>& length, vector<int>& profit);
int getMax(int x, int y);
void cutRod(int length, int profit);
void print(vector<int> data);

int main(int argc, char** argv) {
    //vector<int> length;
    //vector<int> profit;
    //loadData(length, profit);
    int length[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int profit[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    //print(length);
    return 0;
}

void loadData(vector<int>& length, vector<int>& profit) {
    // TODO.
}

int getMax(int x, int y) {
    return x > y ? x : y;
}

void cutRod(int length, int profit) {
    int maxProfit;

}

void print(vector<string> data) {
    for (int i = 0; i !=data.size(); ++i)
        cout << data[i] << endl;
}