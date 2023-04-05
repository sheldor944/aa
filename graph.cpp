#include <bits/stdc++.h>
using namespace std;

#define pi pair<pair<int, int>, int>

vector<pair<int, int>> adjList[102];
int fuelCost[102];
int dist[102][102];
int visited[102][102];

int dijkstra(int capacity, int src, int t, int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            dist[i][j] = INT_MAX;
        }
    }
    priority_queue<pi, vector<pi>, greater<pi>> pq;
   // pq.pop();
    dist[src][0] = 0;
    pq.push({{0,src},0});
    while (!pq.empty())
    {
        auto crrnt = pq.top();
        int price = crrnt.first.first;
        int node = crrnt.first.second;
        int remFuel = crrnt.second;
        pq.pop();
        // cout<<node<<endl;
        if (node == t)
        {
            return price;
        }
        if (remFuel + 1 <= capacity && dist[node][remFuel + 1] > dist[node][remFuel] + fuelCost[node])
        {
            dist[node][remFuel + 1] = dist[node][remFuel] + fuelCost[node];

            // cout<<"ekhane ";
            pq.push({{dist[node][remFuel + 1], node},remFuel+1 });
            //  visited[node][remFuel + 1] = 1;
        }
        for (auto next : adjList[node])
        {
            int v = next.first;
            int len = next.second;
            if (dist[v][remFuel] < price )
                continue;
            if (len > remFuel)
            {
                continue;
            }
            if (dist[v][remFuel - len] > dist[node][remFuel])
            {
                dist[v][remFuel - len] = dist[node][remFuel];
                pq.push({{price, v}, remFuel-len});
            }
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test, cs = 1;
    cin >> test;
    while (test--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            cin >> fuelCost[i];
        }
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});
        }
        int q;
        cin >> q;
        cout << "Case " << cs << ":\n";
        while (q--)
        {
            int capacity, s, t;
            cin >> capacity >> s >> t;

            int x = dijkstra(capacity, s, t, n);
            if (x == -1)
                cout << "impossible\n";

            else
                cout << x << "\n";
            memset(dist, INT_MAX, sizeof(dist));
            memset(visited, 0, sizeof(visited));
        }
        cs++;
        for (int i = 0; i <= n; i++)
        {
            adjList[i].clear();
            fuelCost[i] = 0;
        }
    }
}