#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void loadData(vector<string>& data);
int getMax(int x, int y);
void LCS(vector<string>& data);
void print(vector<string> data);

int main(int argc, char** argv) {
    vector<string> data;
    loadData(data);
    LCS(data);
    print(data);
    return 0;
}

void loadData(vector<string>& data) {
    ifstream inFile("input.txt");
    string buf;
    while (inFile >> buf)
        data.push_back(buf);
    inFile.close();
}

int getMax(int x, int y) {
    return x > y ? x : y;
}

void LCS(vector<string>& data) {
    unsigned int x = data[0].size();
    unsigned int y = data[0].size();
    int result[x+1][y+1];

    for (int i = 0; i <= x; ++i) {
        for (int j = 0; j <=y; ++j) {
            if (i == 0 || j == 0)
                result[i][j] = 0;
            else if (data[0][i-1] == data[1][j-1])
                result[i][j] = result[i-1][j-1] + 1;
            else
                result[i][j] = getMax(result[i-1][j], result[i][j-1]);
        }
    }

    cout << result[x][y] <<endl;
}

void print(vector<string> data) {
    for (int i = 0; i !=data.size(); ++i)
        cout << data[i] << endl;
}