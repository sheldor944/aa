#include <bits/stdc++.h>
using namespace std;

int dp[20][(1 << 17)];
int matrix[20][20];

int solve(int i, int mask, int n)
{
    if (i > n)
    {
        return 0;
    }
    if (dp[i][mask] != -1)
    {
        return dp[i][mask];
    }
    int ans = 0;
    for (int k = 1; k <= n; k++)
    {
        if (mask & (1 << (k - 1)))
        {
            ans = max(ans, matrix[i][k] + solve(i + 1, mask ^ (1 << (k - 1)), n));
        }
    }
    return dp[i][mask] = ans;
}

int main()
{
    int test,cs=1;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> matrix[i][j];
            }
        }
        int mask = 1;
        mask = (mask << n) - 1;
        memset(dp, -1, sizeof(dp));
        cout<<"Case "<<cs<<": ";
        cout << solve(1, mask, n) << endl;
        cs++;
    }
}