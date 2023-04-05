#include <bits/stdc++.h>
using namespace std;

#define ll long long 

const ll N = 1000000 +1 ;

vector<ll> phi(N + 11),res(N+11,1);


void phi_1_to_n(ll n)
{
    for (ll i = 0; i <= n; i++)
        phi[i] = i;

    for (ll i = 2; i <= n; i++)
    {
        if (phi[i] == i)
        {
            for (ll j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}

void solve()
{
    for(ll i=2 ; i<=N ; i++)
    {
        for(ll j=i ; j <=N ; j+=i)
        {
            res[j]+= (phi[i]*i);
            
        }
    }
    for(ll i=1 ; i<=N ; i++)
    {
        res[i]*=i;
        res[i]-=i;
        res[i]+= 2*i;
        res[i]/=2;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                    
    cout.tie(NULL);
    ll test;
    cin >> test;
    phi_1_to_n(N);
    solve();

    while (test--)
    {

        ll n;
        cin >> n;
        cout<<res[n]<<"\n";
    }
}