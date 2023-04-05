#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1e9 + 7;
const ll N = 1e5 + 123;

ll arr[N];
ll allPhi[100];

ll phi(ll n)
{
    ll result = n;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

ll fastExpo(ll a, ll b, ll m)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = (res * a) % m;
        }
        a = a * a;
        a %= m;
        b = b >> 1;
    }
    return res;
}

ll solve(ll l, ll r, ll range, ll m)
{
    if (l == r)
    {
        return (arr[r] % allPhi[range]);
    }
    // cout << arr[r] << " " << allPhi[range] << endl;
    // c = allPhi[range] + (arr[r] % allPhi[range]);
    ll c = arr[r];
    // range--;
    ll res = c;
    // cout << res << " " << range << "  he " << l << " " << r << endl;
    for (int i = r - 1; i >= l; i--)
    {
        c = (c % allPhi[range]) + allPhi[range];
        res = fastExpo(arr[i], (c), allPhi[range - 1]);

        // bhul eikhane
        // co prime na hoile case ta to handle korla na bro

        // cout << arr[i] << " " << res << "   ";
        // cout << allPhi[range] << endl;
        range--;

        c = res;
        // cout<<i<<endl;
    }
    // cout<<endl;
    return res;
}

int check(int l, int r, int range)
{
    int right = ((r - l + 1) >= 4) ? (r + 4) : r;
    ll res;

    ll c = arr[right];
    res = c;
    // cout<<c << " "<< right<<" "<< l <<endl;
    right--;

    for (int i = right; i > l; i--)
    {
        if (arr[i] * c > 32)
        {
            return -3;
        }
        res = pow(arr[i], c);
        c = res;
        if (res > range)
        {
            return -3;
        }
    }
    // cout<<res<<endl;
    return res;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    int q;
    cin >> q;
    ll p = m;
    int range = log2(m);
    //  cout<<range<<endl;
    for (int i = 1; i <= 50; i++)
    {
        allPhi[i] = p;
        //   cout << p << endl;

        if (p <= 1)
        {
            range = i;
            break;
        }
        p = phi(p);
    }
    // cout<<range <<endl;
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        if (l == r)
        {
            cout << arr[r] % m << endl;
            continue;
        }
        int report = -1;
        if (l + range > r)
        {
            report = check(l, r, range);
        }
        else
        {
            report = check(l, l + range, range);
        }

        if (report != -3)
        {
            cout << fastExpo(arr[l], report, m) << endl;
        }
        else
        {
            int dummy = range;
            if ((r - l + 1) > range)
            {
                dummy = range;
                r = dummy + l - 1;
            }
            else
            {
                dummy = r;
                //  cout<<dummy<<" ";
                dummy -= l;
                dummy++;
            }

            // cout << l << " " << r;
            //  cout << " right side is " << dummy << endl;

            cout << (solve(l, r, dummy, m)) % m << endl;
        }
    }
}
