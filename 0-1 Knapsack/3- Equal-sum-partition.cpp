#include <bits/stdc++.h>
using namespace std;

int dp[102][102];
bool knapsack(int arr[], int n, int W) // subset-sum logic
{
    if (W == 0)
        return dp[n][W] = true;
    if (n == 0)
        return dp[n][W] = false;

    if (dp[n][W] != -1)
        return dp[n][W];

    if (arr[n - 1] <= W)
        return knapsack(arr, n - 1, W - arr[n - 1]) or knapsack(arr, n - 1, W);

    return knapsack(arr, n - 1, W);
}

int main()
{

    int arr[] = {2, 4, 5, 6, 7, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    if (sum % 2)
    {
        cout << 0;
        return 0;
    }

    memset(dp, -1, sizeof dp);
    cout << (knapsack(arr, n, sum / 2) ? 1 : 0);
    return 0;
}