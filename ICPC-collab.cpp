#include <bits/stdc++.h>
using namespace std;

const int N = 3e4 + 9;
#define ll long long

vector<int> adjList[N];

long long dist[N];
long long val[N];
long long vis[N];

pair<ll, ll> bfs(int s, int n)
{
    ll black = 0, white = 0;

    memset(vis, 0, sizeof(vis));

    queue<pair<int, int>> q;
    q.push({s, 0});
    vis[s] = 1;
    dist[s] = 0;
    int ans = 0;
    white = val[s];
    while (!q.empty())
    {
        int node = q.front().first;
        int level = q.front().second;
        q.pop();
        for (auto u : adjList[node])
        {
            if (vis[u])
            {
                continue;
            }
            dist[u] += dist[node] + 1;
            if (dist[u] % 2 == 1)
            {
                black += val[u];
            }
            else
            {
                white += val[u];
            }
            q.push({u, level + 1});
            vis[u] = 1;
        }
    }
    pair<ll, ll> p = {white, black};
    return p;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test, ip = 1;
    cin >> test;
    for (int tt = 1; tt <= test; tt++)
    {
        cout << "Case " << tt << ": ";
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> val[i];
        }
        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        pair<ll, ll> p = bfs(1, n);
        ll W = 0, B = 0;
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] & 1)
            {
                B++;
            }
            else
            {
                W++;
            }
        }
        ll white = p.first;
        ll black = p.second;

        // cout << white << " " << black << endl;
        // cout<<W<<" "<<B<<endl;
        ll ans = INT_MIN,res;
        for (int i = 1; i <= n; i++)
        {
            ll cur = 0;
            if (dist[i] & 1)
            {
                cur = (B * val[i] - black) - (W * val[i] - white);
            }
            else
            {
                cur = -(B * val[i] - black) + (W * val[i] - white);
            }
            // cout<<cur<<endl;
            if(cur> ans)
            {
                ans=cur;
                res=i;
            }
        }
        cout << res << endl;
        // if it  is a white node
        // then we add W*root - white + (  B*root - black);

        for (int i = 0; i <= n; i++)
        {
            adjList[i].clear();
            dist[i] = 0;
            val[i] = 0;
            vis[i] = 0;
        }
        ip++;
    }
}