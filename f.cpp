#include <bits/stdc++.h>
using namespace std;

#define ll long long 
int mod = (1e9 + 7);

ll height[100000];
ll value[100000];
ll dp[100000];

ll solve(ll csum, int idx, int n )
{
    if (idx == n)
    {
        return 0;
    }
    if (dp[idx] != 1)
    {
        return dp[idx];
    }

    if (height[idx] > height[idx + 1])
    {
        int w1 = solve(csum - value[idx], idx++, n);
        int w2 = solve(csum - value[idx + 1], idx++, n);
        return dp[idx] = max(csum - value[idx], csum - value[idx+1]);
    }
    int w3= solve(csum,idx++,n);
    return dp[idx] = csum;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
    }
    memset(dp, -1, sizeof(dp));
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
        sum+=value[i];
    }
    dp[n-2]=sum;
    cout<<solve(sum,0,n)<<endl;
}