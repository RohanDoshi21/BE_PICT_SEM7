#include <iostream>
#include<vector>
using namespace std;

int knapsack(int index, int current_weight, const vector<int>& weights,const  vector<int>& values, const int& n, const int& max_capacity, vector<vector<int>>& dp ){
    if(index >= n )
        return 0;

    if(dp[index][current_weight] != -1)
        return dp[index][current_weight];

    int notPick = knapsack(index + 1, current_weight, weights, values, n, max_capacity, dp);
    int pick = 0;

    if (max_capacity >= current_weight + weights[index])
        pick = values[index] + knapsack(index + 1, current_weight + weights[index], weights, values, n, max_capacity, dp);

    return dp[index][current_weight] = max(pick, notPick);
}

int main() {
    vector<int> weights = {95, 4, 60, 32, 23, 72, 80, 62, 65, 46};
    vector<int> values = {55, 10, 47, 5, 4, 50, 8, 61, 85, 87};
    int n = 10;
    int capacity = 269;

    vector<vector<int>> dp(n, vector<int>(capacity, -1));

    cout << "Max Profit " << knapsack(0, 0, weights, values, n, capacity, dp) << endl;
    return 0;
}