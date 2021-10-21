#include <bits/stdc++.h>
using namespace std;

// this is the same as the subset-count-with given difference

int dp[102][102];

bool knapsack(vector<int> &arr, int n, int t)
{
    if (t == 0)
        return dp[n][t] = true;
    if (n == 0)
        return dp[n][t] = false;

    if (dp[n][t] != -1)
        return dp[n][t];

    if (arr[n - 1] >= t)
        return dp[n][t] = knapsack(arr, n - 1, t - arr[n - 1]) + knapsack(arr, n - 1, t);

    return dp[n][t] = knapsack(arr, n - 1, t);
}

int main()
{
    vector<int> arr = {2, 3, 5, 6, 8, 9};
    int n = arr.size();
    int target_sum = 3;

    int total_sum = 0;
    for (auto i : arr)
        total_sum += i;

    memset(dp, -1, sizeof dp);
    cout << knapsack(arr, n, (target_sum + target_sum) / 2);

    return 0;
}