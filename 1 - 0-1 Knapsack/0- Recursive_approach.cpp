#include <bits/stdc++.h>
using namespace std;
// Recursive approach of 0-1 knapsack

int dp[102][1002];

int knapsack(int val[], int wt[], int n, int W)
{
    // Base condition
    if (n == 0 or W == 0)
        return 0;

    // Memoization
    if (dp[n][W] != -1)
        return dp[n][W];

    // Code on choice diagram
    if (wt[n - 1] <= W)
    {
        return dp[n][W] = max(val[n - 1] + knapsack(val, wt, n - 1, W - wt[n - 1]), knapsack(val, wt, W, n - 1));
    }
    else // if (wt[n - 1] > W)
    {
        return dp[n][W] = knapsack(val, wt, n - 1, W);
    }
}

int main()
{
    int wt[] = {2, 3, 6, 7, 9};
    int val[] = {1, 2, 3, 4, 7};
    int n = 5;
    int W = 7;

    // initialization
    memset(dp, -1, sizeof dp);

    cout << knapsack(val, wt, n, W);

    return 0;
}