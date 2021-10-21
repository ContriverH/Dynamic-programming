#include <bits/stdc++.h>
using namespace std;

int dp[102][102];
bool knapsack(vector<int> &arr, int n, int target)
{
    if (target == 0)
        return dp[n][target] = true;
    if (n == 0)
        return dp[n][target] = false;

    if (dp[n][target] != -1)
        return dp[n][target];

    if (arr[n - 1] <= target)
        return dp[n][target] = knapsack(arr, n - 1, target - arr[n - 1]) or knapsack(arr, n - 1, target);

    return dp[n][target] = knapsack(arr, n - 1, target);
}

int main()
{
    vector<int> arr = {2, 3, 5, 6, 8, 9};
    int n = arr.size();

    int total_sum = 0;
    for (auto i : arr)
        total_sum += i;

    // s1 - s2 = min_diff
    // total_sum - s2 - s2 = min_diff
    // total_sum - 2*s2 = min_diff
    // total_sum - 2*s2 >= 0
    // s2 <= (total_sum / 2)

    knapsack(arr, n, total_sum / 2);

    int mn = INT_MAX;
    for (int i = 1; i <= total_sum / 2; i++)
        if (dp[n][i])
            mn = min(mn, total_sum - 2 * i);

    cout << "Minimum difference of two subsets is:" << mn << endl;
    return 0;
}