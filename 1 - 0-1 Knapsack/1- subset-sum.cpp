#include <bits/stdc++.h>
using namespace std;

int knapsack(int arr[], int n, int W)
{
    bool dp[n + 2][W + 2];

    for (int i = 0; i < (n + 1); i++)
    {
        for (int j = 0; j < (W + 1); j++)
        {
            if (i == 0)
                dp[i][j] = false; // making the first row as false, as we can not have any sum from an empty array (n  = 0)
            if (j == 0)
                dp[i][j] = true; // making the first column as true, as we can have 0 sum with any given length of the array

            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] or dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][W];
}

int main()
{
    int arr[] = {3, 34, 4, 12, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int W = 9;
    cout << knapsack(arr, n, W);
    return 0;
}