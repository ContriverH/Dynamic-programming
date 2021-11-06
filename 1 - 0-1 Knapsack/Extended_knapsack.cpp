#include <bits/stdc++.h>
using namespace std;

// To store the dp values
int dp[502][902][502];

int maxProfit(int profit[], int weight[], int n, int max_W, int max_E, int pos, int times)
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= max_W; j++)
            for (int k = 1; k <= max_E; k++)
                if (j >= weight[i - 1])
                    dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - weight[i - 1]][k - 1] + (k == pos ? profit[i - 1] * times : profit[i - 1]));
                else
                    dp[i][j][k] = dp[i - 1][j][k];
    return dp[n][max_W][max_E];
}

int main()
{
    int N = 3;
    int CT = 4;
    int C[] = {1, 1, 2};
    vector<vector<int>> cards = {{800, 7}, {500, 3}, {300, 1}, {800, 2}};
    int max_weight = 900;
    int P = 10, Q = 9, R = 2, S = 7;

    int profit[CT], weight[CT];

    for (int i = 0; i < CT; i++)
    {
        weight[i] = cards[0][i];
        profit[i] = cards[1][i];
    }

    int alice = 0, bob = 0;

    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < N; i++)
        alice += maxProfit(profit, weight, CT, max_weight, C[i], P, Q);

    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < N; i++)
        bob += maxProfit(profit, weight, CT, max_weight, C[i], R, S);

    if (alice == bob)
        cout << "Draw";
    else if (alice > bob)
        cout << "Alice " << (alice - bob) << endl;
    else
        cout << "Bob " << (bob - alice) << endl;

    return 0;
}
