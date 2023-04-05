#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
#define ll long long
const int N = 3e5 + 10;

unsigned long long power(unsigned long long x, int y, int p)
{
    unsigned long long res = 1;
    x = x % p; 
	while (y > 0)
    {

        if (y & 1)
            res = (res * x) % p;

        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
unsigned long long modInverse(unsigned long long n, int p)
{
    return power(n, p - 2, p);
}

unsigned long long nCrModPFermat(unsigned long long n, int r, int p)
{
    if (n < r)
        return 0;
    if (r == 0)
        return 1;

    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;

    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}

int large(int a, int b, int c)
{
    vector<int> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    sort(v.begin(), v.end());
    if (v[0] == v[2])
    {
        return 3;
    }
    else if (v[0] == v[1])
    {
        return 2;
    }
    return 1;
}

int main()
{
    int test;
    // cin >> test;
    test = 1;
    
    while (test--)
    {
        int n;
        cin >> n;

        long long ans = 1;
        // long long comb = C(n / 3, n / 6);
        ll ncr = nCrModPFermat(n/3 , n/6 , mod );
        // cout<< ncr <<endl;
        // long long c = (fact[n / 3] * inv[(n / 3) - (n / 6)]) % mod;

        // cout << comb << " " << c << endl;
        for (int i = 0; i < n / 3; i++)
        {
            ll a, b, c;
            cin >> a >> b >> c;
            //  cout << large(a, b, c) << endl;
            // ans *= (large(a, b, c));
            ans = ( ans % mod ) * (large(a,b,c) % mod ) ;
            ans%= mod ;
        }
        // cout<<ans<<endl;
        cout << (ncr*ans)%mod << endl;
    }
}