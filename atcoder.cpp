#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll pre[2000033];
ll pp[2000033];

int main()
{
    ll n;
    cin >> n;
    ll arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    pre[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + arr[i];
    }
    pp[0] = pre[0];
    for (int i = 1; i < n; i++)
    {
        pp[i] = pp[i - 1] + pre[i];
    }
    ll half = 0, full = 0;
    ll ans = 0;
    for(int i=0 ; i< n ; i++)
    {
        if(i>0) half=max(half,pre[i-1]);
        if(i!=n-1){
            ans=max((pp[i]+half),ans);
        }
        else{
            ans=max(ans,pp[i]);
        }
     
    }
    cout << ans << endl;
}