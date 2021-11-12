#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int i, int j)
{
    if (i == j)
        return true;

    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++, j--;
    }

    return true;
}

int static dp[101][101];
int mcm(string &s, int i, int j)
{
    if (i >= j or isPalindrome(s, i, j))
        return dp[i][j] = 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX, temp, left, right;
    for (int k = i; k < j; k++)
    {
        left = dp[i][k] != -1 ? dp[i][k] : dp[i][k] = mcm(s, i, k);
        right = dp[k + 1][j] != -1 ? dp[k + 1][j] : dp[k + 1][j] = mcm(s, k + 1, j);
        temp = left + right + 1;
        ans = min(ans, temp);
    }

    return dp[i][j] = ans;
}

int main()
{
    memset(dp, -1, sizeof dp);
    string s = "anwweniw";
    int n = s.size();
    cout << mcm(s, 0, n - 1);
    return 0;
}