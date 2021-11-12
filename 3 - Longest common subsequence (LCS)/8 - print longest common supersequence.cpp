#include <bits/stdc++.h>
using namespace std;

void print_lcs(string s1, string s2, int m, int n)
{
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    string ans = "";
    while (n > 0 and m > 0)
    {
        if (s1[m - 1] == s2[n - 1]) // remember to compare for the characters
        {
            ans.push_back(s1[m - 1]);
            m--;
            n--;
        }
        else
        {
            if (dp[m - 1][n] > dp[m][n - 1])
            {
                m--;
                ans.push_back(s1[m]);
            }
            else
            {
                n--;
                ans.push_back(s2[n]);
            }
        }
    }

    while (m > 0)
    {
        m--;
        ans.push_back(s1[m]);
    }

    while (n > 0)
    {
        n--;
        ans.push_back(s1[n]);
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}

int main()
{
    string s1 = "ABCDEF", s2 = "BSDDTFW";
    print_lcs(s1, s2, s1.size(), s2.size());
    return 0;
}