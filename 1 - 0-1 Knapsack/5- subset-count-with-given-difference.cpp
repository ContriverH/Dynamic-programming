#include <bits/stdc++.h>
using namespace std;

int dp[102][102];
bool knapsack(vector<int> &arr, int n, int target)
{
    if (target == 0)
        return true;
    if (n == 0)
        return false;

    if (dp[n][target] != -1)
        return dp[n][target];

    if (arr[n - 1] <= target)
        return knapsack(arr, n - 1, target - arr[n - 1]) + knapsack(arr, n - 1, target);

    return knapsack(arr, n - 1, target);
}

int main()
{
    vector<int> arr = {2, 3, 5, 6, 8, 9};
    int n = arr.size();
    int diff = 3;

    int total_sum = 0;
    for (auto i : arr)
        total_sum += i;

    // s1 - s2 = diff
    // s1 - (total_sum - s1) = diff
    // 2*s1 - total_sum = diff
    // s1 = (diff + total_sum) / 2

    memset(dp, -1, sizeof dp);
    cout << knapsack(arr, n, (diff + total_sum) / 2);

    return 0;
}