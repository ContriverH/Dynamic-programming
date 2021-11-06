#include <bits/stdc++.h>
using namespace std;

int topDownLCS(string s1, string s2, int m, int n)
{
    int t[m + 1][n + 1];

    // initialization
    for (int i = 0; i <= m; i++)
        t[i][0] = 0;

    for (int i = 0; i <= n; i++)
        t[0][i] = 0;

    // top down approach
    int mx = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                t[i][j] = 1 + t[i - 1][j - 1];
                mx = max(mx, t[i][j]);
            }
            else
                t[i][j] = 0;
        }
    }

    return mx;
}

int dp[102][102];
int lcs(string s1, string s2, int m, int n)
{
    if (m == 0 or n == 0) // base condition
        return dp[m][n] = 0;

    if (dp[m][n] != -1)
        return dp[m][n];

    if (s1[m - 1] == s2[n - 1]) // letters match
        return dp[m][n] = 1 + lcs(s1, s2, m - 1, n - 1);

    lcs(s1, s2, m - 1, n);
    lcs(s1, s2, m, n - 1);
    return dp[m][n] = 0;
}

int main()
{
    memset(dp, -1, sizeof dp);
    string s1 = "ABCDEF", s2 = "ACDEHAB";
    lcs(s1, s2, s1.size(), s2.size());

    int mx = 0;
    for (int i = 1; i <= s1.size(); i++)
        for (int j = 1; j <= s2.size(); j++)
            mx = max(mx, dp[i][j]);

    cout << "Bottom-up: " << mx << endl;

    cout << "Top-down: " << topDownLCS(s1, s2, s1.size(), s2.size());

    return 0;
}