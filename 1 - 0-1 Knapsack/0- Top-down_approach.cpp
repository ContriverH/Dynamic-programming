#include <bits/stdc++.h>
using namespace std;

// Top down approach for 0-1 knapsack
int knapsack(int val[], int wt[], int n, int W)
{
    // initialization
    int dp[n + 1][W + 1];

    // interative method
    for (int i = 0; i < (n + 1); i++)
    {
        for (int j = 0; j < (W + 1); j++)
        {
            // modified base condition
            if (i == 0 or j == 0)
            {
                dp[i][j] = 0;
            }
            // same as recursive condition ( n -> i , and  w -> j   )
            else if (wt[i - 1] <= j) // since we are calculating not at a fixed weight, instead at a smaller weight. That is why it becomes the subproblem.
            {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
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
    int wt[] = {2, 3, 6, 7, 9};
    int val[] = {1, 2, 3, 4, 7};
    int n = 5;
    int W = 7;

    cout << knapsack(val, wt, n, W);

    return 0;
}