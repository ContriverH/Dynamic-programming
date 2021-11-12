#include <bits/stdc++.h>
using namespace std;

int dp[101][101];
int mcm(vector<int> &ar, int i, int j)
{
    if (i >= j)
        return dp[i][j] = 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int temp, ans = INT_MAX, left, right;
    for (int k = i; k < j; k++)
    {
        left = dp[i][k] != -1 ? dp[i][k] : dp[i][k] = mcm(ar, i, k);
        right = dp[k + 1][j] != -1 ? dp[k + 1][j] : dp[k + 1][j] = mcm(ar, k + 1, j);
        temp = left + right + ar[i - 1] * ar[k] * ar[j];
        ans = min(ans, temp);
    }
    return dp[i][j] = ans;
}

int main()
{
    memset(dp, -1, sizeof dp);
    vector<int> ar = {2, 4, 5, 3, 2, 6, 7};
    int n = ar.size();
    cout << mcm(ar, 1, n - 1);
    return 0;
}