#include <bits/stdc++.h>
using namespace std;

int dp[102][102];

int knapsack(int arr[], int n, int target)
{
    if (target == 0)
        return dp[n][target] = 1;
    if (n == 0)
        return dp[n][target] = 0;

    if (dp[n][target] != -1)
        return dp[n][target];

    if (dp[n][target] != -1)
        return dp[n][target];

    if (arr[n - 1] <= target)
        return dp[n][target] = knapsack(arr, n - 1, target - arr[n - 1]) + knapsack(arr, n - 1, target);
    else
        return knapsack(arr, n - 1, target);
}

int main()
{
    memset(dp, -1, sizeof dp);
    int arr[] = {1, 2, 3, 4, 5, 8, 10, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 9;

    memset(dp, -1, sizeof dp);

    cout << knapsack(arr, n, target);

    return 0;
}