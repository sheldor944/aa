#include <bits/stdc++.h>
using namespace std;

#define ll long long 

ll dp[102][102];
ll smoke[102][102];
ll arr[102];
ll n;

ll mcm()
{
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = arr[i];
        smoke[i][i] = 0;
    }
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            smoke[i][j] = INT_MAX;
            ll newVal = 0;

            for (int k = i; k < j; k++)
            {
                ll temp = dp[i][k] * dp[k + 1][j];
                ll score = temp + smoke[i][k] + smoke[k + 1][j];
                if (smoke[i][j] > score)
                {
                    newVal = k;
                    smoke[i][j] = score;
                }
            }
            dp[i][j] = (dp[i][newVal] + dp[newVal + 1][j]) % 100;
        }
    }

    return smoke[1][n];
}

int main()
{
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        cout << mcm() << endl;
    }
}