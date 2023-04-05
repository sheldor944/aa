#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll preCalculation[300];
ll dp[300][300];
ll n;
string s;

ll lenCheck(ll start, ll k, ll end)
{
    ll partOne = k - start + 1;
    ll partTwo = end - k;
    ll oneInPartOne = 0;
    ll oneInPartTwo = 0;
    if (s[start - 1] == '1')
    {
        oneInPartTwo = preCalculation[k] - preCalculation[start] + 1;
    }
    else
    {
        oneInPartOne = preCalculation[k] - preCalculation[start];
    }

    if (s[k + 1] == '1')
    {
        oneInPartTwo = preCalculation[end] - preCalculation[k + 1] + 1;
    }
    else
    {
        oneInPartTwo = preCalculation[end] - preCalculation[k + 1];
    }

    ll zero1 = partOne - oneInPartOne ; 
    ll zero2 = partTwo - oneInPartTwo ; 
    ll ans = 0 ;
    if(zero1 < oneInPartOne)
    {
        ans+= partOne ;
    }
    if(zero2 < oneInPartTwo)
    {
        ans+=partTwo ; 
    }
    return ans ; 
}
ll solve()
{
    for (int len = 2; len <= n; len++)
    {
        for (int start = 1; start <= n - len + 1; start++)
        {
            ll end = start + len - 1;
            ll val = -1;
            int cnt = preCalculation[end] - preCalculation[start-1] ;
            if(cnt*2  > len ) val = len ; 

            for (int k = start; k < end; k++)
            {
                ll temp = dp[start][k] + dp[k+1][end] ; 

                 val = max(val,temp);
            }
            dp[start][end] = val;
        }
    }
    return dp[1][n];
}

void print()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    ll test;
    cin >> test;
    while (test--)
    {
        memset(dp , 0 , sizeof(dp ));
        cin >> n;
        cin >> s;
        n = s.size();
        memset(preCalculation, 0, sizeof(preCalculation));
        int cnt = 0;
        for (int i = 1; i <= s.size(); i++)
        {

            if (s[i - 1] == '0')
            {
                dp[i][i] = 0;
            }
            else
            {
                cnt++;
                dp[i][i] = 1;
            }
            preCalculation[i] = cnt;
        }
        cout << solve() << endl;
        // print();
    }
}
