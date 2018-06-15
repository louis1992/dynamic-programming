#include "knapsack.hpp"

KnapSack DP;
int main(int argc, char** argv) {
    int capacity = 50;
    vector<int> weight;
    vector<int> value;
    DP.loadData(weight, value);
    int maxProfit = DP.knapSack(capacity, weight, value, value.size());
    DP.print(capacity, weight, value, maxProfit);
    return 0;
}