#include <bits/stdc++.h>
using namespace std;

int dp[102][102];
int knapsack(vector<int> &value, vector<int> &weights, int n, int W)
{
    if (n == 0 or W == 0)
        return dp[n][W] = 0;

    if (dp[n][W] != -1)
        return dp[n][W];

    if (weights[n - 1] <= W)
        return dp[n][W] = max(value[n - 1] + knapsack(value, weights, n, W - weights[n - 1]), knapsack(value, weights, n - 1, W));

    return dp[n][W] = knapsack(value, weights, n - 1, W);
}

int main()
{
    vector<int> wt = {2, 3, 6, 7, 9};
    vector<int> val = {1, 2, 3, 4, 7};
    int n = 5;
    int W = 7;

    // initialization
    memset(dp, -1, sizeof dp);

    cout << knapsack(val, wt, n, W);

    return 0;
}