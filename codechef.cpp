#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long
#define TC(t) \
    int t;    \
    cin >> t; \
    while (t--)
#define FL(t) for (int i = 0; i < t; i++)
#define Y cout << "YES\n"
#define N cout << "NO\n"
#define ff first
#define ss second
#define pb push_back
#define pf push_front

#define Fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define read freopen("out.txt", "w", stdout)

const int mx = 1e6 +5;

vector<int> adj[mx];
string s;

ll ans = 0;
bool visited[mx];
int pos = 1;
map<int, int> mp;
string d;

void dfs(int u)
{
    // cout << u << " ";
    visited[u] = true;
    d+=s[u-1];
    

    for (auto v : adj[u])
    {
        if (visited[v] == false)
        {
            dfs(v);
            string dd=d;
            cout<<d<<endl;
            reverse(dd.begin(),dd.end());
            if(d==dd){
                ans++;
            }

        }
    }
}

int main()
{
    Fastio

        int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {
        cout << "Case " << tt << ": ";
        ll n;
        cin >> n;
        ans = 0;

        memset(visited, false, sizeof(visited));

        // adj.clear();
        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
        }

        cin >> s;
        d[0]=s[0];

        for (int i = 0; i < n - 1; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        dfs(1);

        int gcd = __gcd(ans, n);
        ans /= gcd;
        n /= gcd;
        cout << ans << '/' << n << endl;
    }

    return 0;
}