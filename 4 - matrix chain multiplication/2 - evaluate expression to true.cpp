#include <bits/stdc++.h>
using namespace std;

int dp[101][101][2];
int mcm(string &s, int i, int j, bool isTrue)
{
    if (i > j)
        return false;

    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];

    if (i == j)
        return dp[i][j][isTrue] = isTrue ? s[i] == 'T' : s[i] == 'F';

    int ans = 0, lt, lf, rt, rf;
    for (int k = i + 1; k < j; k += 2)
    {
        lt = dp[i][k - 1][1] != -1 ? dp[i][k - 1][1] : mcm(s, i, k - 1, true);
        lf = dp[i][k - 1][0] != -1 ? dp[i][k - 1][0] : mcm(s, i, k - 1, false);
        rt = dp[k + 1][j][1] != -1 ? dp[k + 1][j][1] : mcm(s, k + 1, j, true);
        rf = dp[k + 1][j][0] != -1 ? dp[k + 1][j][0] : mcm(s, k + 1, j, false);

        if (s[k] == '&')
        {
            if (isTrue == true)
                ans += lt * rt;
            else
                ans += lf * rf + lf * rt + lt * rf;
        }
        else if (s[k] == '|')
        {
            if (isTrue == true)
                ans += lf * rt + lt * rf + lt * rt;
            else
                ans += lf * rf;
        }
        else if (s[k] == '^')
        {
            if (isTrue == true)
                ans += lf * rt + lt * rf;
            else
                ans += lf * rf + lt * rt;
        }
    }
    return dp[i][j][isTrue] = ans;
}

int main()
{
    memset(dp, -1, sizeof dp);
    string expression = "T&F^T|F^T&F|T";
    // string expression = "T|T&F^T";
    int n = expression.length();
    cout << mcm(expression, 0, n - 1, true); // evaluating the ways in which the given expression is going to be true. You can change it calculate the number of ways for false as well.
    return 0;
}