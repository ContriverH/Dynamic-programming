#include <bits/stdc++.h>
using namespace std;

int dp[102][102];
int lcs(string s1, string s2, int m, int n)
{
    if (m == 0 or n == 0)
        return dp[m][n] = 0;

    if (dp[m][n] != -1)
        return dp[m][n];

    if (s1[m - 1] == s2[n - 1])
        return dp[m][n] = 1 + lcs(s1, s2, m - 1, n - 1);
    return dp[m][n] = max(lcs(s1, s2, m - 1, n), lcs(s1, s2, m, n - 1));
}

int main()
{
    memset(dp, -1, sizeof dp);
    string s1 = "ABDJHW", s2 = "ANDJWBW";
    int m = s1.size(), n = s2.size();
    cout << (n + m - lcs(s1, s2, m, n));

    return 0;
}