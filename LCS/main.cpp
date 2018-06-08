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
    print(data);
    LCS(data);
    
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
    
    // Print LCS
    int index = result[x][y];
    int col = x, row = y;
    char lcs[index];
    while (col > 0 && row > 0) {
        if (data[0][col-1] == data[1][row-1]) {
            lcs[index-1] = data[0][col-1];
            --col, --row, --index;
        }
        else if (result[col-1][row] > result[col][row-1])
            --col;
        else
            --row;
    }
    cout << "// LCS : "<< lcs << endl;
    cout << "// Length : " << result[x][y] <<endl;
    cout << "////////////////////////////////"  << endl;
}

void print(vector<string> data) {
    cout << "////////////////////////////////"  << endl;
    for (int i = 0; i !=data.size(); ++i)
        cout << "// data "<< i << " : " << data[i] << endl;
}